#include "vipedviewer.h"
#include "math.h"

#include <QPainter>

#define PI 3.14159265

// /////////////////////////////////////////////////////////////////////////////////////////
// Widget qui affiche un graph radial
VipedViewer::VipedViewer(QWidget *parent) : QFrame(parent)
{
// ♥ ♥ ♥
myMin = 0;
myMax = 0;
myMinBound = 0;
myMaxBound = 0;
myNbTicks = 6;
myTickSize = 0;
mySectionAngle = 0;
myNbSection = 0;
myChartRect = QRect();
myValuesRect = QRect();
myTitleRect = QRect();
myTitle = "";
myMarginX = 30;
myMarginY = 20;
mySelectedSection = "";

    setAutoFillBackground(false);        //pour que ce soit utile, il faut
    setBackgroundRole(QPalette::Base);  //utiliser ces variables dans mon paintEvent
    setMouseTracking(false);    //otherwise VipedViewer will receive moveEvent even if user press no mousse buttons during moves
}

void VipedViewer::setModel(QMap<QString, int> &model)
{
    myModel.clear();
    myModel.unite(model);
    checkModelConformity();
    updateChart();
}

void VipedViewer::checkModelConformity()
{
    QMap<QString, int>::iterator i;
    for (i = myModel.begin(); i != myModel.end(); ++i)
        {
        if ( i.value() < 0 )
            i.value() = 0;
        myMax = qMax(i.value(), myMax);
        }
}

bool VipedViewer::setData(QString key, int value)
{
    bool flag;
    //only positive values accepted
    if ( value < 0 )
        {
        myModel.insert( key, 0 );
        updateChart();
        update();
        emit dataChanged( key, value);
        flag = false;
        }
    //insert new data and keep model's max value
    else
        {
        myModel.insert( key, value );
        myMax = qMax(value, myMax);
        updateChart();
        update();
        emit dataChanged( key, value);
        flag = true;
        }
    return flag;
}

void VipedViewer::clearData()
{
    QMap<QString, int>::iterator i;
    for (i = myModel.begin(); i != myModel.end(); ++i)
        i.value() = 0;

    update();
}

void VipedViewer::setTickNumber(int Nb)
{
    myNbTicks = Nb;
}

void VipedViewer::setTitle(QString title)
{
    myTitle = title;
}

void VipedViewer::setMargin(int x, int y)
{
     myMarginX = x;
     myMarginY = y;
}

void VipedViewer::updateChart()
{
    updateRects();
    updateValues();
}

void VipedViewer::updateRects()
{
    // the Chart's rect is widget's rect reduced by Margins values
    myChartRect = QRect( myMarginX, myMarginY, (rect().width()-2*myMarginX), (rect().height()-2*myMarginY) );
    // the Title rect lay the entire bottom of Chart's rect
    if ( myTitle != "")
        {
        QFontMetrics metrics( font() );
        int metricsH = metrics.height();
        int h = metricsH + 20;
        myTitleRect = myChartRect;
        myTitleRect.setTop( myChartRect.bottom() - h );
        myChartRect.setBottom( myTitleRect.top() );
        }
    else
        myTitleRect = QRect();

    // Values Rect is the biggest square winthin Chart rect
    int w = qMin( myChartRect.width(), myChartRect.height() );
    myValuesRect = QRect( -w/2, -w/2, w, w );
    myValuesRect.translate( myChartRect.center().x(), myChartRect.center().y() );
    mycenterChart = myValuesRect.center();
}

void VipedViewer::updateValues()
{
    // check if the max value will overflow chart => adapte ticks number
    if ( myMax > myNbTicks+1 )
        setTickNumber(myMax+1);

    myNbSection = myModel.count();
    mySectionAngle = 360/myNbSection;
    qreal w = myValuesRect.width();
    myCenterHoleDiam =  w * 0.2;
    myMinBound = myCenterHoleDiam/2;
    myMaxBound = w/2;
    myTickSize = (myMaxBound - myMinBound)/ (myNbTicks-1);
}

void VipedViewer::paintEvent(QPaintEvent * event)
{
    QPainter painter( this );
    painter.setClipRect( event->rect() );
    paintChart( painter );
}

void VipedViewer::paintChart(QPainter & painter)
{
    painter.save();
    painter.setRenderHints( QPainter::Antialiasing | QPainter::TextAntialiasing );

    int n=0;
    QMap<QString, int>::const_iterator i;
    for (i = myModel.constBegin(); i != myModel.constEnd(); ++i)
        {
        paintValue( painter, n, i.value() );
        paintTextAxis( painter, n, i.key() );
        n++;
        }

    paintAxis(painter);
    paintTitle(painter);
    painter.restore();
}

void VipedViewer::paintAxis( QPainter& painter ) const
{
    painter.save();
    paintTicks( painter );
    qreal currentAngle = 0;
    QRect rectangle( -(myMaxBound+5), -(myMaxBound+5), 2*(myMaxBound+5), 2*(myMaxBound+5) );
    rectangle.translate( myValuesRect.center() );

    QPainterPath pathCenter;
    QRect rectangle2( -myCenterHoleDiam/2, -myCenterHoleDiam/2, myCenterHoleDiam, myCenterHoleDiam );
    rectangle2.translate( myValuesRect.center() );
    pathCenter.addEllipse( rectangle2 );

    for (int i=0; i< myNbSection; i++)
        {
        QPainterPath AxisPath;
        AxisPath.moveTo( myValuesRect.center() );
        AxisPath.arcTo( rectangle, currentAngle, 1 );
        AxisPath.closeSubpath();
        AxisPath = AxisPath.subtracted( pathCenter );
        painter.drawPath( AxisPath );
        currentAngle += mySectionAngle;
        }
    painter.restore();
}

void VipedViewer::paintTicks( QPainter& painter ) const
{
    QColor c = QColor( Qt::lightGray );
    c.setAlpha( 100 );
    painter.setPen( QPen( c , 1.5) );
    qreal y = myMinBound;
    while ( y <= myMaxBound )
        {
        QRectF rectangle( -y, -y , 2*y , 2*y );
        rectangle.translate( myValuesRect.center() );
        QPainterPath path;
        path.addEllipse( rectangle );
        painter.drawPath( path );
        y += myTickSize;
        }
}

void VipedViewer::paintTextAxis( QPainter& painter, int i, QVariant v ) const
{
painter.save();
    QString textSection = v.toString();
    qreal startAngle = mySectionAngle*i + mySectionAngle/2;
    qreal currentRadAngle =  -(startAngle * PI) / 180.0;
    qreal distance = myMaxBound + myTickSize/2;
    QPointF startPoint;
    startPoint.setX( cos( currentRadAngle )*distance + mycenterChart.x() );
    startPoint.setY( sin( currentRadAngle )*distance + mycenterChart.y() );

    QFontMetrics metrics( font() );
    int h = metrics.height();
    int w = metrics.width( textSection );
    QRectF textRect( startPoint.x(), startPoint.y() , w, h );

    if ( 0<=startAngle && startAngle<90 )
        textRect.translate( 0, -textRect.height() );
    else
        {
        if ( 90<=startAngle && startAngle<180 )
           textRect.translate( -textRect.width() , -textRect.height()  );
        else
            {
            if ( 180<=startAngle && startAngle<270 )
               textRect.translate( -textRect.width(), 0 );
            }
        }

    painter.drawText(textRect, Qt::AlignHCenter | Qt::AlignVCenter | Qt::TextWordWrap, textSection );
painter.restore();
}

void VipedViewer::paintValue( QPainter& painter, int i, QVariant v ) const
{
painter.save();
painter.setPen( QPen( QColor( 0x0839A1 ), 2 ) );
painter.setBrush( QBrush( 0x68B9FF ) );

    // compute param of the visual shape of value v at section i
    int value = v.toInt();
    qreal DiamValue = valueToPx(value);
    qreal startAngle = mySectionAngle*i;
    QRect rectangle( -DiamValue, -DiamValue, 2*DiamValue, 2*DiamValue );
    rectangle.translate( myValuesRect.center() );
    QPainterPath ValuePath;
    ValuePath.moveTo( myValuesRect.center() );
    ValuePath.arcTo( rectangle, startAngle+2, mySectionAngle-4 );
    ValuePath.closeSubpath();
    QPainterPath pathCenter;
    QRect rectangle2( -myCenterHoleDiam/2, -myCenterHoleDiam/2, myCenterHoleDiam, myCenterHoleDiam );
    rectangle2.translate( myValuesRect.center() );
    pathCenter.addEllipse( rectangle2 );
    ValuePath = ValuePath.subtracted( pathCenter );
    painter.drawPath( ValuePath );

painter.restore();
}

void VipedViewer::paintTitle(QPainter &painter) const
{
    if ( myTitleRect.isNull() )
        return;

    painter.drawText( myTitleRect, Qt::AlignHCenter | Qt::AlignTop | Qt::TextWordWrap, myTitle );
}

qreal VipedViewer::valueToPx(int value) const
{
    return value*myTickSize + myCenterHoleDiam/2;
}

int VipedViewer::PxToValue(qreal px) const
{
    return floor( (px - myCenterHoleDiam/2)/ myTickSize );
}

int VipedViewer::PointToValue(QPoint p) const
{
    QPoint distVect = p-mycenterChart;
    qreal dist = sqrt(pow(distVect.x(), 2) + pow(distVect.y(), 2));
    return PxToValue(dist);
}

int VipedViewer::PointToSection(QPoint p) const
{
    QPoint distVect = p-mycenterChart;
    qreal dist = sqrt(pow(distVect.x(), 2) + pow(distVect.y(), 2));
    if (dist == 0)
        return 0;

    qreal alpha = acos( distVect.x() / dist );
    if ( distVect.y() < 0 )
        alpha = 2*PI-alpha;

    qreal beta = 2*PI-alpha;
    return floor( (beta*180/PI) /mySectionAngle );
}

QSize VipedViewer::sizeHint() const
{
    return QFrame::sizeHint();
}

void VipedViewer::resizeEvent(QResizeEvent * event)
{
    updateChart();
    return QFrame::resizeEvent(event);
}

void VipedViewer::mousePressEvent(QMouseEvent * event)
{
    QPoint pos = event->pos();
    int section = PointToSection(pos);
    QMap<QString, int>::const_iterator i = myModel.constBegin();
    int j = section;
    while ( j>0 && i != myModel.constEnd() ) { i++;  j--; }
    mySelectedSection = i.key();
    // change mousepointer
}

/*
void VipedViewer::mouseMoveEvent(QMouseEvent * event)
{

}*/

void VipedViewer::mouseReleaseEvent(QMouseEvent * event)
{
    // change mousepointer
    QPoint pos = event->pos();
    int newValue = PointToValue(pos);
    if ( newValue > myNbTicks-1 )
        newValue = myNbTicks-1;

    setData(mySelectedSection, newValue );
}

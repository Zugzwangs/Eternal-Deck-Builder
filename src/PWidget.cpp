#include "PWidget.h"
#include "mainwindow.h"
#include <QDrag>
#include <QStyle>

#define PI 3.14159265

// /////////////////////////////////////////////////////////////////////////////////////////
// Distributeur de blood
PFrame::PFrame(QWidget *parent) : QFrame(parent)
{
    setObjectName("bourse");
    setGeometry(1170,0,116,94);
    show();
    setVisible(true);
    setFrameStyle(QFrame::Sunken | QFrame::Box);
    setLineWidth(2);
    //setStyleSheet("background-image: url(" + QCoreApplication::applicationDirPath() + "/Images/bourse.png)");
    //BloodPxm = new QPixmap(QCoreApplication::applicationDirPath() + "/Images/Blood.png");
}

void PFrame::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        { startPos = event->pos(); }
}

void PFrame::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        { startDrag(); }
    }
}

void PFrame::startDrag()
{
    //QImage IconeDrag;
    QDrag *Drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("Blood Marqueur");
    mimeData->setImageData(*BloodPxm);
    Drag->setPixmap(*BloodPxm);
    Drag->setHotSpot(QPoint(20,20));
    Drag->setMimeData(mimeData);
    Drag->exec(Qt::CopyAction);
}

// /////////////////////////////////////////////////////////////////////////////////////////
// Widget symbolisant une discipline
DisciplineButton::DisciplineButton(QWidget *parent) : QPushButton(parent)
{
    state = DisciplineButton::RequestNothing;
    sql_request ="";
}

void DisciplineButton::setupDiscipline(QString dis)
{
    // verrue pour une exception de merde !
    if ( dis.left(4) == "vis2" )
        discipline = "vis2";
    else
        discipline = dis.left(3);

    //setText(discipline);
    setToolTip(discipline);
    icone = QPixmap(":/icons/disc/" + discipline + ".png");
    setIconSize(QSize(30,30));
    setIcon(icone);
}

void DisciplineButton::paintEvent(QPaintEvent *e)
{
    switch (state)
    {
        case DisciplineButton::RequestNothing:
            {
            QStyleOptionButton option;
            option.initFrom(this);
            option.icon = this->icon();
            option.iconSize = this->iconSize();
            option.features |= QStyleOptionButton::Flat;
            option.state = ! QStyle::State_Enabled;
            QPainter painter(this);
            style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);
            }   break;

        case DisciplineButton::RequestDiscipline:
            {
            QPushButton::paintEvent(e);
            }   break;

        case DisciplineButton::RequestNotDiscipline:
            {
            // draw button
            QStyleOptionButton option;
            option.initFrom(this);
            option.icon = this->icon();
            option.iconSize = this->iconSize();
            QPainter painter(this);
            style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);
            // draw the cross
            QRect myRect = option.rect;
            myRect.adjust(6,6,-6,-6);
            painter.drawPixmap( myRect, QPixmap(":icons/cross.png") );
            }   break;
    }

/*
    switch (state)
    {
        case DisciplineButton::RequestNothing:
            painter.setPen( Qt::NoPen );
            painter.setBrush( QBrush(QColor(150,150,150,150), Qt::SolidPattern) );
            rect.adjust(5,5, -5,-5);
            painter.drawPixmap( rect, icone );
            painter.drawRect(rect);
            break;

        case DisciplineButton::RequestDiscipline:

            rect.adjust(1,1, -1,-1);
            painter.setPen( Qt::black );
            painter.setBrush( QBrush( QRadialGradient() ) );
            painter.drawRoundedRect( rect, 10, 10, Qt::RelativeSize );
            rect.adjust(4,4, -4,-4);
            painter.drawPixmap( rect, icone );
            break;

        case DisciplineButton::RequestNotDiscipline:

            rect.adjust(1,1, -1,-1);
            painter.setPen( Qt::black );
            painter.setBrush( QBrush(Qt::black, Qt::RadialGradientPattern) );
            painter.drawRoundedRect( rect, 10, 10, Qt::RelativeSize );
            rect.adjust(4,4, -4,-4);
            painter.drawPixmap( rect, icone );

            painter.setPen( QPen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin) );
            painter.drawEllipse(rect);
            rect.adjust(5,5,-5,-5);
            painter.drawLine(rect.bottomLeft(), rect.topRight());
            break;
    }
*/
}

void DisciplineButton::nextCheckState()
{
    switch (state)
    {
        case DisciplineButton::RequestNothing:
            state = DisciplineButton::RequestDiscipline;
            sql_request = " AND Discipline like '%" + discipline + "%'";
            setIconSize( QSize(34,34) );
            break;

        case DisciplineButton::RequestDiscipline:
            state = DisciplineButton::RequestNotDiscipline;
            sql_request = " AND NOT Discipline like '%" + discipline + "%'";
            break;

        case DisciplineButton::RequestNotDiscipline:
            state = DisciplineButton::RequestNothing;
            sql_request = "";
            setIconSize(QSize(30,30));
            break;
    }
}

void DisciplineButton::resetState()
{
    state = DisciplineButton::RequestNothing;
    sql_request = "";
    this->update();
}

QString DisciplineButton::get_sql_request()
{
    return sql_request;
}

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
myMarginX = 15;
myMarginY = 15;

    setAutoFillBackground(true);        //pour que ce soit utile, il faut
    setBackgroundRole(QPalette::Base);  //utiliser ces variables dans mon paintEvent
    setMouseTracking(false);    //otherwise VipedViewer will receive moveEvent even if user press no mousse buttons during moves
}

void VipedViewer::setModel(QMap<QString, int> model)
{
    // a default model fot tests
    setData("Bleed", 4);
    setData("Defense", 2);
    setData("Combat", 0);
    setData("Diplomaty", 5);
    setData("Pentex", 0);
}

bool VipedViewer::setData(QString key, int value)
{
    //only positive values accepted
    if ( value < 0 )
        return false;
    //insert new data and keep model's max value
    myModel.insert( key, value );
    myMax = qMax(value, myMax);
    updateChart();
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
    int h = 0;
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
    //painter.setRenderHint( QPainter::Antialiasing, false );
    qreal currentAngle = 0;
    QRect rectangle( -myMaxBound, -myMaxBound, 2*myMaxBound, 2*myMaxBound );
    rectangle.translate( myValuesRect.center() );

    QPainterPath pathCenter;
    QRect rectangle2( -myCenterHoleDiam/2, -myCenterHoleDiam/2, myCenterHoleDiam, myCenterHoleDiam );
    rectangle2.translate( myValuesRect.center() );
    pathCenter.addEllipse( rectangle2 );

    for (int i=0; i< myNbSection; i++)
        {
        QPainterPath AxisPath;
        AxisPath.moveTo( myValuesRect.center() );
        AxisPath.arcTo( rectangle, currentAngle, mySectionAngle );
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

    QRectF textRect( startPoint.x(), startPoint.y() , 50, 20 );

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
    qreal DiamValue = value*myTickSize + myCenterHoleDiam/2;
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
 return value*myTickSize;
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


//
void VipedViewer::mousePressEvent(QMouseEvent * event)
{
    QPoint pos = event->pos();
}

void VipedViewer::mouseMoveEvent(QMouseEvent * event)
{

}

void VipedViewer::mouseReleaseEvent(QMouseEvent * event)
{
    QPoint pos = event->pos();
}


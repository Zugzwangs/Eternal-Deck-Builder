#include "PWidget.h"
#include "mainwindow.h"
#include <QDrag>
#include <QStyle>

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
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);
    setMouseTracking(false); //otherwise VipedViewer will receive moveEvent even if user press no mousse buttons
}

QSize VipedViewer::sizeHint() const
{

}

void VipedViewer::paintEvent(QPaintEvent * event)
{

}

void VipedViewer::resizeEvent(QResizeEvent * event)
{

}

void VipedViewer::mousePressEvent(QMouseEvent * event)
{

}

void VipedViewer::mouseMoveEvent(QMouseEvent * event)
{

}

void VipedViewer::mouseReleaseEvent(QMouseEvent * event)
{

}


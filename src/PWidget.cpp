#include "PWidget.h"
#include "mainwindow.h"
#include <QDrag>

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
// Drop zone to add cards in the deck model
PDeckDropArea::PDeckDropArea(QWidget *parent) : QLabel(parent){

    setAcceptDrops(true);
    setFrameStyle(QFrame::Sunken | QFrame::Box);
}

void PDeckDropArea::dragEnterEvent(QDragEnterEvent *event){

    if (event->mimeData()->hasFormat("text/plain"))
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PDeckDropArea::dragMoveEvent(QDragMoveEvent *event){

    if (event->mimeData()->hasFormat("text/plain"))
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PDeckDropArea::dropEvent(QDropEvent *event){

QString TempData;
QStringList ListofData;

    // on recup les données du drop | on les split | on chope le nom de la carte
    TempData = event->mimeData()->text();
    ListofData = TempData.split("\n",QString::KeepEmptyParts);
    //qDebug() << ListofData;

    // emit the datas
    emit card_dropped( ListofData );
}

PDeckDropArea::~PDeckDropArea() {}

// /////////////////////////////////////////////////////////////////////////////////////////
// Widget symbolisant une discipline
DisciplineButton::DisciplineButton(QWidget *parent) : QPushButton(parent)
{
    state = DisciplineButton::RequestNothing;
    sql_request ="";
}

void DisciplineButton::setupDiscipline(QString dis)
{
    if ( dis.left(4) == "vis2" )
        discipline = "vis2";
    else
        discipline = dis.left(3);

    //setText(discipline);
    setToolTip(discipline);
    icone = QPixmap(":/icons/disc/" + discipline + ".png");
    setIcon(icone);
}
/*
void DisciplineButton::paintEvent(QPaintEvent *e)
{
    QRect rect( e->rect() );
    QPainter painter( this );
    painter.setRenderHint(QPainter::Antialiasing, true);
    //painter.setClipRect( rect );

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
}*/

void DisciplineButton::nextCheckState()
{
    switch (state)
    {
        case DisciplineButton::RequestNothing:
            state = DisciplineButton::RequestDiscipline;
            sql_request = " AND Discipline like '%" + discipline + "%'";
            break;

        case DisciplineButton::RequestDiscipline:
            state = DisciplineButton::RequestNotDiscipline;
            sql_request = " AND NOT Discipline like '%" + discipline + "%'";
            break;

        case DisciplineButton::RequestNotDiscipline:
            state = DisciplineButton::RequestNothing;
            sql_request = "";

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

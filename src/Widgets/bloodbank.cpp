#include "bloodbank.h"

#include <QDrag>
#include <QApplication>
#include <QMimeData>

// /////////////////////////////////////////////////////////////////////////////////////////
// Distributeur de blood
BloodBank::BloodBank(QWidget *parent) : QFrame(parent)
{
    setObjectName("bourse");
    setFrameStyle(QFrame::Sunken | QFrame::Box);
    setLineWidth(2);
    setMaximumWidth(116);
    setMinimumWidth(116);
    setMaximumHeight(94);
    setMinimumHeight(94);
    setStyleSheet( "background-image: url("":/icons/bourse.png"")" );
    BloodPxm = new QPixmap(":/icons/Blood.png");
}

void BloodBank::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        { startPos = event->pos(); }
}

void BloodBank::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        { startDrag(); }
    }
}

void BloodBank::startDrag()
{
    //QImage IconeDrag;
    QDrag *Drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("Blood Marqueur");
    mimeData->setImageData( QImage( ":/icons/Blood.png" ) );
    Drag->setPixmap(*BloodPxm);
    Drag->setHotSpot(QPoint(20,20));
    Drag->setMimeData(mimeData);
    Drag->exec(Qt::CopyAction);
}

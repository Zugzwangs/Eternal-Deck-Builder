#include "bloodbank.h"

#include <QDrag>
#include <QApplication>
#include <QMimeData>
//#include <QDebug>

// /////////////////////////////////////////////////////////////////////////////////////////
// Distributeur de blood
BloodBank::BloodBank(QWidget *parent) : QFrame(parent)
{
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
            startDrag();
    }
}

void BloodBank::startDrag()
{
    //qDebug() << "le nom de la baquue est: " << this->objectName();
    //QImage IconeDrag;
    QDrag *Drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("Blood");
    Drag->setPixmap(*BloodPxm);
    Drag->setHotSpot(QPoint(0,0));
    //Drag->setHotSpot(QPoint(BloodPxm->width()/2,BloodPxm->height()/2));
    // maybe set QCoreApplication::setCursor temporaly to BloodPmp ?
    Drag->setMimeData(mimeData);
    Drag->exec(Qt::CopyAction);
}

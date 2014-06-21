#include <QWheelEvent>
#include <QDebug>
#include <QMimeData>
#include <QCoreApplication>

#include "playground.h"
#include "math.h"

// ///////////////////////////////////////////////////////////////////////////////////////////
//
PGraphicsView::PGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setBackgroundBrush(QBrush(QColor(77,120,58)));
    setAcceptDrops(true);
    setInteractive(true);
    setDragMode(QGraphicsView::ScrollHandDrag); //defini le comportement de la Vue qd on drag la souris dans une zone vide
}

void PGraphicsView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, event->delta() / 240.0));
}

void PGraphicsView::scaleView(qreal scaleFactor)
{
    qreal factor = matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor<0.1 || factor>1.1)  {return;}
    scale(scaleFactor, scaleFactor);
}

void PGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    QGraphicsView::contextMenuEvent(event); //sert à propager le signal
    if (!event->isAccepted())
        {
        QMenu *menu = new QMenu();
        menu->addAction("Relancer la partie");
        menu->addAction("Tout supprimer");
        menu->popup(event->globalPos());
        connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(ContextMenuSlot(QAction*)));
        }
}

void PGraphicsView::ContextMenuSlot(QAction *ActionChoisie)
{
    qDebug()<< ActionChoisie->text();
}

void PGraphicsView::dragEnterEvent(QDragEnterEvent * event)
{
qDebug() << "PGraphicsView::dragEnterEvent";
    if ( !event->mimeData()->hasText() || !scene() )
        {
        event->ignore();
        return;
        }
    QGraphicsView::dragEnterEvent(event);
    //event->accept();
}

void PGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
qDebug() << "PGraphicsView::dragMoveEvent";
    if ( !event->mimeData()->hasText() || !scene() )
        {
        event->ignore();
        return;
        }
    QGraphicsView::dragMoveEvent(event);
    //event->accept();
}

void PGraphicsView::dragLeaveEvent(QDragLeaveEvent * event)
{
qDebug() << "PGraphicsView::dragLeaveEvent";
    QGraphicsView::dragLeaveEvent(event);
    //event->accept();
}

void PGraphicsView::dropEvent(QDropEvent * event)
{
qDebug() << "PGraphicsView::dropEvent";
    if ( !event->mimeData()->hasText() || !scene() )
        {
        event->ignore();
        return;
        }

    QPoint DropPos = event->pos();
    if ( itemAt(DropPos) )
        {
        //we propagate event to the scene
        QGraphicsView::dropEvent(event);
        }
    else
        {
        if ( event->mimeData()->text() == "Blood" )
            {
            qDebug() << "##################### View handle a blood drop ! ########################";
            PGraphicsBlood *newBloob = new PGraphicsBlood();
            scene()->addItem( newBloob );
            newBloob->setPos( mapToScene(DropPos) );
            event->accept();
            }
        else
            event->ignore();
        }
}

// ///////////////////////////////////////////////////////////////////////////////////////////
//
PGraphicsScene::PGraphicsScene(QWidget* parent) : QGraphicsScene(parent)
{
    setSceneRect(-4000,-4000,8000,8000);
}

void PGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
qDebug() << "PGraphicsScene::dragEnterEvent";
    QGraphicsScene::dragEnterEvent(event);
    //event->accept();
}

void PGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
qDebug() << "PGraphicsScene::dragMoveEvent";
    QGraphicsScene::dragMoveEvent(event);
    event->setDropAction(Qt::CopyAction);
    event->accept();
}

void PGraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
qDebug() << "PGraphicsScene::dragLeaveEvent";
    QGraphicsScene::dragLeaveEvent(event);
    //event->accept();
}

void PGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
qDebug() << "PGraphicsScene::dropEvent";
    QGraphicsScene::dropEvent(event);
}

// ///////////////////////////////////////////////////////////////////////////////////////////
// Card item
PGraphicsPixmapItem::PGraphicsPixmapItem(Carte *C, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    //setttings corresponding to card/game datas
    card = C;
    setTaped(false);
    setTurned(false);

    //settings paths to pictures
    if ( path_list.initPaths() )
        FacePixmapPath = path_list.getCardPath() + QString("/") + card->getImageFile();
    else
        FacePixmapPath = ":/icons/bourse.png";

    switch ( C->getKind() )
        {
        case VtesInfo::LibraryType:
            TailPixmapPath = ":/icons/Vtes_Tanlarge.gif";
            break;
        case VtesInfo::CryptType:
            TailPixmapPath = ":/icons/Vtes_Grelarge.gif";
            break;
        default:
            TailPixmapPath = ":/icons/Vtes_Grelarge.gif";
            break;
        }

    //settings corresponding to QGraphicsPixmapItem part
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    setCursor( QPixmap(":/icons/evil.png") );
    setPixmap( QPixmap(FacePixmapPath) );
    setTransformOriginPoint( boundingRect().center() );
    setAcceptDrops(true);
    setAcceptHoverEvents(true);

    origin = QPointF( boundingRect().center() );
    origin.setY( origin.y()-100 );
    radius = (boundingRect().width()*32)/100;
    mySpreadingAngle = 0.62831853071;
    i = 0;
}

CardType PGraphicsPixmapItem::getCardType()
{
    return(card->getKind());
}

void PGraphicsPixmapItem::setTaped(bool T)
{
    Taped = T;
    if ( Taped )
        setRotation(90);
    else
        setRotation(0);
}

void PGraphicsPixmapItem::setTurned(bool T)
{
    Turned = T;
    if ( Turned )
        setPixmap(QPixmap(TailPixmapPath));
    else
        setPixmap(QPixmap(FacePixmapPath));
}

bool PGraphicsPixmapItem::isTaped()
{
    return Taped;
}

bool PGraphicsPixmapItem::isTurned()
{
    return Turned;
}

void PGraphicsPixmapItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if ( isTaped() )
        setTaped(false);
    else
        setTaped(true);
}

void PGraphicsPixmapItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    event->setAccepted(true);
    QMenu *menu = new QMenu();
    menu->addAction("Retourner la carte");
    menu->popup(event->screenPos());
    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(ContextMenuSlot(QAction*)));
}

void PGraphicsPixmapItem::ContextMenuSlot(QAction *ActionChoisie)
{
    if (ActionChoisie->text() == "Retourner la carte")
        setTurned(!isTurned());
}

void PGraphicsPixmapItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "PGraphicsPixmapItem::dragEnterEvent";
    if (event->source()->objectName() == "bourse")
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PGraphicsPixmapItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
qDebug() << "PGraphicsPixmapItem::dragMoveEvent";
    if (event->source()->objectName() == "bourse")
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PGraphicsPixmapItem::dragLeaveEvent(QGraphicsSceneDragDropEvent * event)
{
qDebug() << "PGraphicsPixmapItem::dragLeaveEvent";
    event->accept();
}


void PGraphicsPixmapItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
qDebug() << "PGraphicsPixmapItem::dropEvent";
    if (event->source()->objectName() == "bourse")
        {
        PGraphicsBlood *newBloob = new PGraphicsBlood();
        newBloob->setParentItem(this);
        QPointF currentBloodPos;
        currentBloodPos.setX( origin.x()+ radius*cos(mySpreadingAngle*i) );
        currentBloodPos.setY( origin.y()+ radius*sin(mySpreadingAngle*i) );
        newBloob->setPos(currentBloodPos);
        i++;
        event->accept();
        }
}

void PGraphicsPixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    //qDebug() << "PGraphicsPixmapItem::hoverEnterEvent !!!";
}

void PGraphicsPixmapItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
    //qDebug() << "PGraphicsPixmapItem::hoverMoveEvent !!!";
}

void PGraphicsPixmapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    //qDebug() << "PGraphicsPixmapItem::hoverLeaveEvent !!!";
}


// ///////////////////////////////////////////////////////////////////////////////////////////
// blood item
PGraphicsBlood::PGraphicsBlood() : QGraphicsPixmapItem()
{
    setAcceptDrops(false);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setPixmap( QPixmap(":/icons/Blood.png") );
}

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

// ///////////////////////////////////////////////////////////////////////////////////////////
//
PGraphicsScene::PGraphicsScene(QWidget* parent) : QGraphicsScene(parent)
{
    setSceneRect(-4000,-4000,8000,8000);
}

void PGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "PGraphicsScene::dragEnterEvent !!!";
    if (event->source()->objectName() == "bourse")
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "PGraphicsScene::dragMoveEvent !!!";
    if (event->source()->objectName() == "bourse")
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "PGraphicsScene::dropEvent !!!";
    QPointF DropPos = event->pos();

    if (event->source()->objectName() == "bourse")
        {
        QImage image = qvariant_cast<QImage>(event->mimeData()->imageData());
        QGraphicsPixmapItem *NouveauBlood = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        NouveauBlood->setFlag(QGraphicsItem::ItemIsSelectable, true);
        NouveauBlood->setFlag(QGraphicsItem::ItemIsMovable, true);
        NouveauBlood->setPos(DropPos); //ne marche pas
        this->addItem( NouveauBlood );
        }
}

// ///////////////////////////////////////////////////////////////////////////////////////////
//
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

// GESTION DES EVENTS //
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
    qDebug() << "PGraphicsPixmapItem::dragEnterEvent !!!";
    if (event->source()->objectName() == "bourse")
        {
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PGraphicsPixmapItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "PGraphicsPixmapItem::dragMoveEvent !!!";
    if (event->source()->objectName() == "bourse")
        {
        qDebug() << "item DragMoveEvent !!!";
        event->setDropAction(Qt::CopyAction);
        event->accept();
        }
}

void PGraphicsPixmapItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QPixmap DFGH;
    qDebug() << "PGraphicsPixmapItem::dropEvent !!!";

    if (event->source()->objectName() == "bourse")
        {
        qDebug() << "item dropEvent !!!";
        DFGH = event->mimeData()->imageData().value<QPixmap>();
        QGraphicsPixmapItem *NouveauBlood = new QGraphicsPixmapItem(DFGH,this);
        NouveauBlood->setFlag(QGraphicsItem::ItemIsSelectable, true);
        NouveauBlood->setFlag(QGraphicsItem::ItemIsMovable, true);
        }
}

void PGraphicsPixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    qDebug() << "PGraphicsPixmapItem::hoverEnterEvent !!!";
}

void PGraphicsPixmapItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
    qDebug() << "PGraphicsPixmapItem::hoverMoveEvent !!!";
}

void PGraphicsPixmapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    qDebug() << "PGraphicsPixmapItem::hoverLeaveEvent !!!";
}


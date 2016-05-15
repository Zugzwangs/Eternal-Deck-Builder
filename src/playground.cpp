#include <QWheelEvent>
#include <QDebug>
#include <QDrag>
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
    if (factor<0.1 || factor>1.1)
        return;
    scale(scaleFactor, scaleFactor);
}

void PGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    QGraphicsView::contextMenuEvent(event); //sert a propager le signal
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
//qDebug() << "PGraphicsView::dragEnterEvent";
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
//qDebug() << "PGraphicsView::dragMoveEvent";
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
    setSceneRect(-4000,-2500,8000,5000);
    uncontroledZone = new GraphicsZone();
    addItem(uncontroledZone);
    uncontroledZone->setGeometry(-4000, 1800, 3000, 680);
    uncapacitedZone = new GraphicsZone();
    addItem(uncapacitedZone);
    uncapacitedZone->setGeometry(1000, 1800, 3000, 680);
}

void PGraphicsScene::setSource(Deck *d)
{
    currentDeck = d;
    connect(currentDeck, SIGNAL(cardPlayedFromHand(Carte*)), this, SLOT(AddCard(Carte*)));
    connect(currentDeck, SIGNAL(cardSendtoUncontroled(Carte*)), this, SLOT(addCardtoUncontroled(Carte*)));
}

void PGraphicsScene::AddCard(Carte *C)
{
    PGraphicsPixmapItem *newCard = new PGraphicsPixmapItem(C);
    addItem(newCard);
    newCard->setPos(0, 0);
}

void PGraphicsScene::addCardtoUncontroled(Carte *C)
{
    PGraphicsPixmapItem *newCard = new PGraphicsPixmapItem(C);
    dynamic_cast<QGraphicsLinearLayout *>(uncontroledZone->layout())->addItem(newCard);
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

// /////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic view that show the hand
HandGraphicsView::HandGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    setAcceptDrops(true);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void HandGraphicsView::resizeEvent(QResizeEvent * event)
{
    QGraphicsView::resizeEvent(event);
    scaleView();
}

void HandGraphicsView::scaleView()
{
    qreal scalef = height()/526.0;
    setMatrix( QMatrix(scalef, 0, 0, scalef, 0, 0 ), false);
}

void HandGraphicsView::wheelEvent(QWheelEvent *event)
{
    QGraphicsView::wheelEvent(event);
}

void HandGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QGraphicsView::mouseDoubleClickEvent(event);
}

void HandGraphicsView::dragEnterEvent(QDragEnterEvent * event)  //on ne gere que les drops de cartesde lib
{
    if( event->mimeData()->text() != "library card" )
    {
        event->ignore();
        return;
    }
    QGraphicsView::dragEnterEvent(event);
}

void HandGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    //qDebug() << "HandGraphicsView::dragMoveEvent";
    QGraphicsView::dragMoveEvent(event);
}

void HandGraphicsView::dragLeaveEvent(QDragLeaveEvent * event)
{

}

void HandGraphicsView::dropEvent(QDropEvent * event)
{
    //qDebug() << "HandGraphicsView::dropEvent";
    QGraphicsView::dropEvent(event);
}

void HandGraphicsView::contextMenuEvent(QContextMenuEvent *event){} // pas forcement

void HandGraphicsView::ContextMenuSlot(QAction *ActionChoisie){}    // besoin

// ///////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic scene who host the Hand
HandGraphicsScene::HandGraphicsScene(QWidget* parent) : QGraphicsScene(parent)
{
    setSceneRect(-2000,-261,4000,522);
    QGraphicsLinearLayout *handLayout = new QGraphicsLinearLayout();
    handLayout->setSpacing(20);
    graphicsContainer = new QGraphicsWidget();
    graphicsContainer->setLayout(handLayout);
    addItem(graphicsContainer);
    graphicsContainer->setY(-261);
    startPos = QPointF();
}

void HandGraphicsScene::setSource(Deck *d)
{
    currentDeck = d;
    connect(currentDeck, SIGNAL(cardSendtoHand(Carte*)), this, SLOT(AddCardtoHand(Carte*)));
}

void HandGraphicsScene::AddCardtoHand(Carte *C)
{
    PGraphicsPixmapItem* CardItem  = new PGraphicsPixmapItem(C);
    dynamic_cast<QGraphicsLinearLayout *>( graphicsContainer->layout() )->addItem(CardItem);
    graphicsContainer->setX(-graphicsContainer->geometry().width()/2);
}

void HandGraphicsScene::removeCardFromHand(PGraphicsPixmapItem *currentItem)
{
    removeItem(currentItem);
    currentItem->deleteLater();
}

void HandGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    //qDebug() << "HandGraphicsScene::mouseDoubleClickEvent";
    if ( PGraphicsPixmapItem *crt_item = dynamic_cast<PGraphicsPixmapItem *>( itemAt( mouseEvent->scenePos(), QTransform() ) ) )
        {
        currentDeck->playCardFromHand( crt_item->getCardref() );
        removeCardFromHand(crt_item);
        mouseEvent->accept();
        return;
        }
}

void HandGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dynamic_cast<PGraphicsPixmapItem *>( itemAt( event->scenePos(), QTransform() ) ))
        {
        //qDebug() << "HandGraphicsScene::mousePressEvent on a card";
        startPos = event->scenePos();
        event->accept();
        }
    else
        {
        startPos = QPointF();
        QGraphicsScene::mousePressEvent(event);
        }
}

void HandGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "HandGraphicsScene::mouseMoveEvent";
    if (event->buttons() & Qt::LeftButton && !startPos.isNull() )
        {
        event->accept();
        //qDebug() << "move event accepted";
        int distance = (event->scenePos() - startPos).manhattanLength();
        if ( distance >= 8 )
            startDrag();
        return;
        }
    QGraphicsScene::mouseMoveEvent(event);
}

void HandGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    //qDebug() << "HandGraphicsScene::dragEnterEvent";
    event->accept();
}

void HandGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    //qDebug() << "HandGraphicsScene::dragMoveEvent";
    event->accept();
}

void HandGraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    //qDebug() << "HandGraphicsScene::dragLeaveEvent";
    QGraphicsScene::dragLeaveEvent(event);
}

void HandGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    //qDebug() << "HandGraphicsScene::dropEvent";
    if (event->mimeData()->text() == "library card" && draggedItem)
        {
        qDebug() << "drop & il est interne pasque draggedItem not null";
        //event->scenePos()
        draggedItem->show();
        dynamic_cast<QGraphicsLinearLayout *>(graphicsContainer->layout())->insertItem(-1, draggedItem);
        }
}

void HandGraphicsScene::startDrag()
{
QMimeData *DraggedData = new QMimeData;
QDrag *Drag = new QDrag(this);

    qDebug() << "HandGraphicsScene::startDrag()";
    draggedItem = dynamic_cast<PGraphicsPixmapItem *>( itemAt( startPos, QTransform() ) );
    dynamic_cast<QGraphicsLinearLayout *>(graphicsContainer->layout())->removeItem(draggedItem);
    draggedItem->hide();
    DraggedData->setText( "library card" );
    Drag->setPixmap( draggedItem->pixmap().scaled( QSize(150, 150),Qt::KeepAspectRatio, Qt::FastTransformation) );
    Drag->setMimeData( DraggedData );
    Drag->exec(Qt::MoveAction);
}

// ///////////////////////////////////////////////////////////////////////////////////////////
// Card item
PGraphicsPixmapItem::PGraphicsPixmapItem(Carte *C, QGraphicsItem *parent) : QGraphicsPixmapItem(parent), QGraphicsLayoutItem()
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

    //settings corresponding to the QGraphicsPixmapItem part
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
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

    //settings corresponding to the QGraphicsLayoutItem part
    setGraphicsItem(this);
}

CardType PGraphicsPixmapItem::getCardType()
{
    return(card->getKind());
}

QString PGraphicsPixmapItem::getCardName()
{
    return( card->getName() );
}

Carte* PGraphicsPixmapItem::getCardref()
{
    return( card );
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
    setTaped( !isTaped() );
    event->ignore();
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

    if ( event->mimeData()->text() == "Blood" )
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

QSizeF PGraphicsPixmapItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    return boundingRect().size();
}

void PGraphicsPixmapItem::setGeometry(const QRectF &rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(rect);
    setPos(rect.topLeft());
}

void PGraphicsPixmapItem::updateGeometry()
{
    QGraphicsLayoutItem::updateGeometry();
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

// ///////////////////////////////////////////////////////////////////////////////////////////
// subzone item :

GraphicsZone::GraphicsZone(QGraphicsItem* parent) : QGraphicsWidget(parent)
{
    // adjust geometry and layout
    setContentsMargins(80, 80, 80, 80);
    QGraphicsLinearLayout *EmbeddedLayout = new QGraphicsLinearLayout();
    EmbeddedLayout->setSpacing(80);
    setLayout(EmbeddedLayout);

    // adjust behavior
    setAcceptDrops(true);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
    setFlag(QGraphicsItem::ItemIsMovable, false);
}

void GraphicsZone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen( QPen( QBrush(Qt::white), 18, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin) );
    painter->drawRoundedRect( rect(), 10, 10 );
    painter->restore();
}


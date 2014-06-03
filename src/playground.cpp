#include "playground.h"
#include "math.h"

#include <QWheelEvent>
#include <QDebug>
#include <QMimeData>
#include <QCoreApplication>

//#include "mainwindow.h"

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
    setSceneRect(-5000,-5000,10000,10000);
}
void PGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
if (event->source()->objectName() == "bourse")
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}
void PGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
if (event->source()->objectName() == "bourse")
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}
void PGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
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
PGraphicsPixmapItem::PGraphicsPixmapItem(const QPixmap& pixmap, TypesdeCarte type, QGraphicsItem *parent) : QGraphicsPixmapItem(pixmap,parent), DosCarteLibrarie("Vtes_Grelarge.gif"), DosCartecrypt("Vtes_Tanlarge.gif")
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->setAcceptDrops(true);
    this->setTransformOriginPoint(this->boundingRect().center());
    DossierAppli.setPath(QCoreApplication::applicationDirPath());
    FaceCarte = pixmap;
    FaceVisible = true;
    setTypeCarte(type);
}

// IMPLEMENTATION DES METHODES //
void PGraphicsPixmapItem::setTypeCarte(PGraphicsPixmapItem::TypesdeCarte type)
{
 QString PathDosCarte;

 TypeCarte = type;

 if (DossierAppli.cd("Images"))
    {
     PathDosCarte = DossierAppli.absolutePath();
    }

 switch (type)
    {
    case 0 : DosCarte.load(PathDosCarte +"/" + DosCarteLibrarie);  break;
    case 1 : DosCarte.load(PathDosCarte +"/" + DosCartecrypt);     break;
    case 2 : DosCarte.load(PathDosCarte +"/" + DosCarteLibrarie);  break;
    }
}
int PGraphicsPixmapItem::getTypeCarte()
{
    return(TypeCarte);
}

// GESTION DES EVENTS //
void PGraphicsPixmapItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (rotation() == 0)
        this->setRotation(90);
    else
        this->setRotation(0);
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
    {
    if (FaceVisible)
        {FaceVisible = false; this->setPixmap(DosCarte);}
    else
        {FaceVisible = true; this->setPixmap(FaceCarte);}
    }
}
void PGraphicsPixmapItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "item DragEnterEvent !!!";
if (event->source()->objectName() == "bourse")
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}
void PGraphicsPixmapItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "item DragEnterEvent !!!";
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
qDebug() << "item DragEnterEvent !!!";

if (event->source()->objectName() == "bourse")
    {
    qDebug() << "item dropEvent !!!";
    DFGH = event->mimeData()->imageData().value<QPixmap>();
    QGraphicsPixmapItem *NouveauBlood = new QGraphicsPixmapItem(DFGH,this);
    NouveauBlood->setFlag(QGraphicsItem::ItemIsSelectable, true);
    NouveauBlood->setFlag(QGraphicsItem::ItemIsMovable, true);
    }
}

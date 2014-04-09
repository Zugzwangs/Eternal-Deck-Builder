#ifndef PGRAPHICS_H
#define PGRAPHICS_H

#include <QDir>
#include <QMenu>
#include <QAction>
#include <QGraphicsSceneContextMenuEvent>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneDragDropEvent>

///////////////////////////////////////////////////////////////////////////////////////////
// Ma Subclass de QGraphicsView
class PGraphicsView : public QGraphicsView
{
   Q_OBJECT

public:
    explicit PGraphicsView(QWidget* parent=0);

protected:
    void wheelEvent(QWheelEvent *event);
    void scaleView(qreal scaleFactor);
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void ContextMenuSlot(QAction *ActionChoisie);
};


/////////////////////////////////////////////////////////////////////////////////////////////
//Ma Subclass de PGraphicsScene
class PGraphicsScene : public QGraphicsScene
{
   Q_OBJECT

public:
    explicit PGraphicsScene(QWidget* parent=0);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

private:

};

///////////////////////////////////////////////////////////////////////////////////////////
// Ma Subclass de QGraphicsPixmapItem
class PGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT

public:
    enum TypesdeCarte { CarteSansType = 0, CartedeLibrairie = 1, CartedeVampire = 2 };

    explicit PGraphicsPixmapItem(const QPixmap & pixmap, TypesdeCarte type=CarteSansType, QGraphicsItem* parent=0);

    void setTypeCarte(PGraphicsPixmapItem::TypesdeCarte type);
    int getTypeCarte();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

private:
    const QString DosCarteLibrarie;
    const QString DosCartecrypt;
    int TypeCarte; //type de carte : vampire ou de librairie
    bool FaceVisible;
    QDir DossierAppli;
    QPixmap DosCarte;
    QPixmap FaceCarte;

private slots:
    void ContextMenuSlot(QAction *ActionChoisie);

};

#endif // PGRAPHICS_H

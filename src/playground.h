#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QDir>
#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneContextMenuEvent>

#include "game_element.h"

// /////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic view that show the playground
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


// ///////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic scene who host the game
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

// /////////////////////////////////////////////////////////////////////////////////////////
// A card in the graphic scene
class PGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT

public:
    explicit PGraphicsPixmapItem(Carte *C, QGraphicsItem* parent=0);
    void setTaped(bool T = true);
    void setTurned(bool T = true);
    bool isTaped();
    bool isTurned();
    int getCardType();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

private:
    bool Taped;
    bool Turned;
    QString FacePixmapPath;
    QString TailPixmapPath;
    Carte *card;

private slots:
    void ContextMenuSlot(QAction *ActionChoisie);
};

#endif // PLAYGROUND_H

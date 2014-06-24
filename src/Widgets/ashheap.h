#ifndef ASHHEAP_H
#define ASHHEAP_H

#include <QFrame>
#include "game_element.h"

namespace Ui { class AshHeap; }

class AshHeap : public QFrame
{
    Q_OBJECT

public:
    explicit AshHeap(QWidget *parent = 0);
    void setSource(Deck *d);
    ~AshHeap();

public slots:
    void AddCardtoAshHeap(Carte *C);

private:
    Ui::AshHeap *ui;
    Deck *currentDeck;

private slots:
    void open_browser();
};

#endif // ASHHEAP_H

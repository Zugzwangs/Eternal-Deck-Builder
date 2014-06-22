#ifndef CARDSSTACKVIEW_H
#define CARDSSTACKVIEW_H

#include <QFrame>
#include "game_element.h"

namespace Ui { class CardsStackView; }

class CardsStackView : public QFrame
{
    Q_OBJECT

public:
    explicit CardsStackView(QWidget *parent = 0);
    void setSource(Deck *d);
    ~CardsStackView();

private:
    Ui::CardsStackView *ui;
    Deck *currentDeck;

private slots:
    bool draw();
    bool burn();
    bool shuffle();
    void browse();

};

#endif // CARDSSTACKVIEW_H

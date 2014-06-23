#ifndef LIBRARY_H
#define LIBRARY_H

#include <QFrame>
#include "game_element.h"

namespace Ui { class Library; }

class Library : public QFrame
{
    Q_OBJECT

public:
    explicit Library(QWidget *parent = 0);
    void setSource(Deck *d);
    ~Library();

private:
    Ui::Library *ui;
    Deck *currentDeck;

private slots:
    bool draw();
    bool burn();
    bool shuffle();
    void browse();

};

#endif

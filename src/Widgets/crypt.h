#ifndef CRYPT_H
#define CRYPT_H

#include <QFrame>
#include "game_element.h"

namespace Ui { class Crypt; }

class Crypt : public QFrame
{
    Q_OBJECT

public:
    explicit Crypt(QWidget *parent = 0);
    void setSource(Deck *d);
    ~Crypt();

private:
    Ui::Crypt *ui;
    Deck *currentDeck;

private slots:
    void open_browser();
    void readDeckInfo();
};

#endif // CRYPT_H

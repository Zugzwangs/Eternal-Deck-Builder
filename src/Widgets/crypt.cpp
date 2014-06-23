#include "crypt.h"
#include "ui_crypt.h"

Crypt::Crypt(QWidget *parent) : QFrame(parent), ui(new Ui::Crypt)
{
    ui->setupUi(this);
}

void Crypt::setSource(Deck *d)
{
    currentDeck = d;
}

Crypt::~Crypt()
{
    delete ui;
}

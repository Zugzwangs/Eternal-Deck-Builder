#include <QDebug>
#include "crypt.h"
#include "ui_crypt.h"

Crypt::Crypt(QWidget *parent) : QFrame(parent), ui(new Ui::Crypt)
{
    ui->setupUi(this);
}

void Crypt::setSource(Deck *d)
{
    currentDeck = d;
    // connect user actions toward locals or deck's slots
    connect (ui->pbShuffle, SIGNAL( clicked() ), currentDeck, SLOT( crypt_shuffle() ));
    connect (ui->pbDraw,    SIGNAL( clicked() ), currentDeck, SLOT( drawCrypt()) );
    connect (ui->pbBurn,    SIGNAL( clicked() ), currentDeck, SLOT( burnCrypt()) );
    connect (ui->pbBrowse,  SIGNAL( clicked() ), this,        SLOT( open_browser()) );
    // connect relevants signals coming from deck to locals slots
    connect (currentDeck,   SIGNAL( deck_loaded() ), this,    SLOT( readDeckInfo() ));
}

void Crypt::open_browser()
{
    qDebug() << "Browsing crypt";
}

void Crypt::readDeckInfo()
{
    QString cNbr = QString::number( currentDeck->Crypt.count() );
    ui->CardCount->setText( cNbr + " / " + cNbr);
}

Crypt::~Crypt()
{
    delete ui;
}

#include <QDebug>
#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent) : QFrame(parent), ui(new Ui::Library)
{
    ui->setupUi(this);
}

void Library::setSource(Deck *d)
{
    currentDeck = d;
    // connect user actions toward locals or deck's slots
    connect (ui->pbShuffle, SIGNAL( clicked() ), currentDeck, SLOT( library_shuffle() ));
    connect (ui->pbDraw,    SIGNAL( clicked() ), currentDeck, SLOT( drawLib() ));
    connect (ui->pbBurn,    SIGNAL( clicked() ), currentDeck, SLOT( burnLib() ));
    connect (ui->pbBrowse,  SIGNAL( clicked() ), this,        SLOT( open_browser() ));
    // connect relevants signals coming from deck to locals slots
    connect (currentDeck,   SIGNAL( deck_loaded() ), this,    SLOT( readDeckInfo() ));
}

void Library::open_browser()
{
    qDebug() << "Browsing library";
}

void Library::readDeckInfo()
{
    QString cNbr = QString::number( currentDeck->Library.count() );
    ui->CardCount->setText( cNbr + " / " + cNbr);
}

Library::~Library()
{
    delete ui;
}

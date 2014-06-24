#include <QDebug>
#include "ashheap.h"
#include "ui_ashheap.h"

AshHeap::AshHeap(QWidget *parent) : QFrame(parent), ui(new Ui::AshHeap)
{
    ui->setupUi(this);
    // connect user actions
    connect (ui->pbBrowse,  SIGNAL( clicked() ), this, SLOT( open_browser()) );
}

void AshHeap::setSource(Deck *d)
{
    currentDeck = d;
    // connect relevants signals coming from deck to locals slots
    connect (currentDeck,   SIGNAL(cardSendtoAshHeap(Carte*)), this,SLOT(AddCardtoAshHeap(Carte*)));
}

void AshHeap::AddCardtoAshHeap(Carte *C)
{
    ui->CardCount->setText( QString::number(currentDeck->ashHeap.count()) );
}

void AshHeap::open_browser()
{
    qDebug() << "Browsing crypt";
}

AshHeap::~AshHeap()
{
    delete ui;
}

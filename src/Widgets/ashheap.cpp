#include <QDebug>
#include "ashheap.h"
#include "ui_ashheap.h"

AshHeap::AshHeap(QWidget *parent) : QFrame(parent), ui(new Ui::AshHeap)
{
    ui->setupUi(this);
}

void AshHeap::setSource(Deck *d)
{
    currentDeck = d;
}

void AshHeap::open_browser()
{
    qDebug() << "Browsing crypt";
}

AshHeap::~AshHeap()
{
    delete ui;
}

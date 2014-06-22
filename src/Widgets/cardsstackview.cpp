#include "cardsstackview.h"
#include "ui_cardsstackview.h"

CardsStackView::CardsStackView(QWidget *parent) : QFrame(parent), ui(new Ui::CardsStackView)
{
    ui->setupUi(this);

    //setStyleSheet( "background-image: url("":/icons/bourse.png"")" );

    connect( ui->pbBrowse,  SIGNAL(clicked()), this, SLOT(browse()) );
    connect( ui->pbBurn,    SIGNAL(clicked()), this, SLOT(burn()) );
    connect( ui->pbDraw,    SIGNAL(clicked()), this, SLOT(draw()) );
    connect( ui->pbShuffle, SIGNAL(clicked()), this, SLOT(shuffle()) );
}

void CardsStackView::setSource(Deck *d)
{
    currentDeck = d;
}

bool CardsStackView::draw()
{

}

bool CardsStackView::burn()
{

}

bool CardsStackView::shuffle()
{

}

void CardsStackView::browse()
{

}

CardsStackView::~CardsStackView()
{
    delete ui;
}

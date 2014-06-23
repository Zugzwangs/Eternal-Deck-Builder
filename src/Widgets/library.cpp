#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent) : QFrame(parent), ui(new Ui::Library)
{
    ui->setupUi(this);

    /*connect( ui->pbBrowse,  SIGNAL(clicked()), this, SLOT(browse()) );
    connect( ui->pbBurn,    SIGNAL(clicked()), this, SLOT(burn()) );
    connect( ui->pbDraw,    SIGNAL(clicked()), this, SLOT(draw()) );
    connect( ui->pbShuffle, SIGNAL(clicked()), this, SLOT(shuffle()) );*/
}

void Library::setSource(Deck *d)
{
    currentDeck = d;
    connect (ui->pbDraw, SIGNAL( clicked() ), currentDeck, SLOT( request_game_restart() ) );
}

bool Library::draw()
{

}

bool Library::burn()
{

}

bool Library::shuffle()
{

}

void Library::browse()
{

}

Library::~Library()
{
    delete ui;
}

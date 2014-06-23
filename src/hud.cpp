#include "hud.h"
#include "ui_hud.h"

Hud::Hud(QWidget *parent) : QScrollArea(parent), ui(new Ui::Hud)
{
    ui->setupUi(this);

    connect( ui->pBOpenDeck,    SIGNAL( pressed() ), this, SIGNAL( request_deck_load() ) );
    connect( ui->pBRestartGame, SIGNAL( pressed() ), this, SIGNAL( request_drawing() ) );
    connect (ui->pBdrawLibrary, SIGNAL( pressed() ), this, SIGNAL( request_game_restart() ) );
}

Hud::~Hud()
{
    delete ui;
}

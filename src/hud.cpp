#include "hud.h"
#include "ui_hud.h"

Hud::Hud(QWidget *parent) : QScrollArea(parent), ui(new Ui::Hud)
{
    ui->setupUi(this);

    connect( ui->pBOpenDeck,    SIGNAL( clicked() ), this, SIGNAL( request_deck_load() ) );
    connect (ui->pBRestartGame, SIGNAL( clicked() ), this, SIGNAL( request_game_restart() ) );
}

Hud::~Hud()
{
    delete ui;
}

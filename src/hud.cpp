#include "hud.h"
#include "ui_hud.h"

Hud::Hud(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::Hud)
{
    ui->setupUi(this);
}

Hud::~Hud()
{
    delete ui;
}

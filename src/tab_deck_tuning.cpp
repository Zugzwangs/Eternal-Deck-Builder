#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"

tab_deck_tuning::tab_deck_tuning(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_deck_tuning)
{
    ui->setupUi(this);

    // on map la vue définie private dans l'ui vers un membre de classe public
    DeckView = ui->PTreeViewDeckList;

    // on assigne le model de données
    ModeleDeck = new PTreeModel();
    ui->PTreeViewDeckList->setModel(ModeleDeck);

    // on assigne le delegate
    PDelegateDeck *DelegateDeck = new PDelegateDeck();
    ui->PTreeViewDeckList->setItemDelegate(DelegateDeck);
}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

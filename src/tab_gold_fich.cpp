#include <QFileDialog>
#include <QDebug>

#include "tab_gold_fich.h"
#include "ui_tab_gold_fich.h"
#include "Widgets/bloodbank.h"

tab_gold_fich::tab_gold_fich(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_gold_fich)
{
    ui->setupUi(this);
    currentDeck = new Deck(this);
    BloodBank* Bourse = new BloodBank(this);
    Hud *testHud = new Hud(this);
    ui->TopBoard->layout()->addWidget(testHud);
    ui->SideBoard->layout()->addWidget(Bourse);
    Scenedejeu = new PGraphicsScene();
    ui->TabledeJeu->setScene(Scenedejeu);

    connect( ui->pBOpenDeck, SIGNAL( pressed() ), this, SLOT( load_deck() ) );
    connect( ui->pBRestartGame, SIGNAL( pressed() ), this, SLOT( restart_game() ) );
    connect (ui->pBdrawLibrary, SIGNAL( pressed() ), this, SLOT( test_draw() ) );
}

void tab_gold_fich::initialisation(DeckTranslator *DT)
{
    if ( ! path_list.initPaths() )
        qDebug() << "ca a chier !";

    PathCartes = path_list.getCardPath();
    PathDeck = path_list.getDeckPath();
    translator = DT;
}

tab_gold_fich::~tab_gold_fich()
{
    delete ui;
}

void tab_gold_fich::load_deck()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Deck"), PathDeck, tr("Deck Files (*.edb)"));
    if ( fileName.isEmpty() )
        return;

    translator->EdbToDeck(fileName, currentDeck);
}

void tab_gold_fich::test_draw()
{
    Carte* carte_pioched = currentDeck->drawLib();
    if ( !carte_pioched )
        {
        qDebug() << "la biblio est vide !";
        return;
        }

    PGraphicsPixmapItem* CardItem  = new PGraphicsPixmapItem(carte_pioched);
    CardItem->setPos(400, 600);
    Scenedejeu->addItem(CardItem);
}

void tab_gold_fich::restart_game()
{

}


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

    connect( ui->pBOpenDeck, SIGNAL(pressed()), this, SLOT(load_deck()) );
    connect( ui->pBRestartGame, SIGNAL(pressed()), this, SLOT(restart_game()) );
}

void tab_gold_fich::initialisation(DeckTranslator *DT)
{
    if ( ! path_list.initPaths() )
        qDebug() << "ca a chier !";
    PathCartes = path_list.getCardPath();
    PathDeck = path_list.getDeckPath();

    translator = DT;

    //PGraphicsPixmapItem* CardItem  = new PGraphicsPixmapItem( QPixmap(PathCartes + "/" + "44magnum.jpg") );
    //PGraphicsPixmapItem* CardItem2 = new PGraphicsPixmapItem( QPixmap(PathCartes + "/" + "abiku.jpg") );

    /*CardItem2->setPos(1000,1000);
    CardItem3->setPos(400,600);
    Scenedejeu->addItem(CardItem);
    Scenedejeu->addItem(CardItem2);*/
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

void tab_gold_fich::restart_game()
{

}


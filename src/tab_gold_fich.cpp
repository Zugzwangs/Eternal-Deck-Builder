#include <QFileDialog>
#include <QDebug>

#include "tab_gold_fich.h"
#include "ui_tab_gold_fich.h"

tab_gold_fich::tab_gold_fich(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_gold_fich)
{
    ui->setupUi(this);

    // setup splitter
    splitter = new QSplitter();
    splitter->setOrientation(Qt::Vertical);
    ui->GameBoard->layout()->addWidget(splitter);
    splitter->addWidget(ui->TabledeJeu);
    splitter->addWidget(ui->HandView);

    // allocation/setup of custom widgets
    currentDeck = new Deck(this);
    //Bourse = new BloodBank(this);
    testHud = new Hud(this);
    LibraryWidget = new Library(this);
    CryptWidget = new Crypt(this);
    AshHeapWidget = new AshHeap(this);
    LibraryWidget->setSource(currentDeck);
    CryptWidget->setSource(currentDeck);
    AshHeapWidget->setSource(currentDeck);

    // insertion into layouts
    ui->TopBoard->layout()->addWidget(testHud);
    //ui->TopBoard->layout()->addWidget(Bourse);
    ui->SideBoard->layout()->addWidget(AshHeapWidget);
    ui->SideBoard->layout()->addWidget(CryptWidget);
    ui->SideBoard->layout()->addWidget(LibraryWidget);

    // setup the scenes
    Scenedejeu = new PGraphicsScene(this);
    HandZone = new HandGraphicsScene(this);
    ui->TabledeJeu->setScene(Scenedejeu);
    ui->HandView->setScene(HandZone);
    Scenedejeu->setSource(currentDeck);
    HandZone->setSource(currentDeck);

    // Hud connections
    connect( testHud, SIGNAL( request_deck_load() ), this, SLOT( load_deck() ) );
    connect( testHud, SIGNAL( request_game_restart() ), this, SLOT( restart_game()) );
}

void tab_gold_fich::initialisation(DeckTranslator *DT)
{
    if ( ! path_list.initPaths() )
        qDebug() << "ca a chier !";

    PathCartes = path_list.getCardPath();
    PathDeck = path_list.getDeckPath();
    translator = DT;
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

tab_gold_fich::~tab_gold_fich()
{
    delete ui;
}



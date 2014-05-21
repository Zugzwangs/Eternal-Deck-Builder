#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{

// ////////////////////////////////////////////////
//  INITIALISATION DES PATHS DE L'APPLI

    if ( ! path_list.initPaths() )
        {
        qDebug() << "ca a chier !";
        }
    PathCartes = path_list.getCardPath();
    PathDeck = path_list.getDeckPath();


// ////////////////////////////////////////////////
//  INITIALISATION DU MODULE DE TELECHARGEMENT

    downloader = new update_manager( this );
    downloader->set_card_directory( PathCartes );
    downloader->set_serv_settings( "127.0.0.1", "jr", "pass" );


// ////////////////////////////////////////////////
//  OUVERTURE DE LA BDD 'VtesCardsListDB'

    this->SqlDB = QSqlDatabase::addDatabase("QSQLITE");
    this->SqlDB.setDatabaseName("VtesCardsListDB");
    if (!this->SqlDB.open())
        {
         QMessageBox::warning(this, "Erreur", this->SqlDB.lastError().text());
         return;
        }

// ////////////////////////////////////////////////
//  MISE EN FORME DE LA FENETRE PRINCIPALE

    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);


// ///////////////////////////////////////////////
// SETUP MAIN TABS

    test_tuning = new tab_deck_tuning();
    ui->OngletProba->layout()->addWidget(test_tuning);

    advanced_library_search_tab = new tab_search_library();
    advanced_library_search_tab->setupDeckModel(test_tuning->ModeleDeck);
    ui->OngletRechercheCarte->layout()->addWidget(advanced_library_search_tab);

    advanced_crypt_search_tab = new tab_search_crypt();
    advanced_crypt_search_tab->setupDeckModel(test_tuning->ModeleDeck);
    ui->OngletRechercheCrypte->layout()->addWidget(advanced_crypt_search_tab);

    playground_tab = new tab_gold_fich();
    playground_tab->initialisation(PathCartes);
    ui->OngletGoldFish->layout()->addWidget(playground_tab);

// ////////////////////////////////////////////////
//  SETUP MANAGER IMPORT/EXPORT DECK DATAS

    queryModel = new QSqlQueryModel;
    inOutDecksManager = FFFF(test_tuning->ModeleDeck, queryModel );

// ///////////////////////////////////////////////
// DEFINITION DES CONNEXIONS

    connect( ui->actionEnregistrer_le_Deck, SIGNAL( triggered() ), this, SLOT( SaveDeck() ) ) ;
    connect( ui->actionImprimer_le_Deck,    SIGNAL( triggered() ), this, SLOT( PrintDeck() ) );
    connect( ui->actionOptions,             SIGNAL( triggered() ), this, SLOT( OuvrirMenuOption() ) );
    connect( ui->actionOpen_a_deck,         SIGNAL( triggered() ), this, SLOT( OpenDeck() ) );
    connect( ui->actionClose_deck,          SIGNAL( triggered() ), this, SLOT( CloseDeck()) );
    connect( ui->actionNew_Deck,            SIGNAL( triggered() ), this, SLOT( NewDeck()  ) );
    connect( this,                          SIGNAL( DeckLoaded()), test_tuning, SLOT(refresh_widgets() ) );

    //connect( downloader, SIGNAL( picture_downloaded() ), this, SLOT( AfficheImageCarte(QString) ) );

}

void MainWindow::SaveDeck()
{
    QString fileName = test_tuning->ModeleDeck->deckName();
    if ( fileName.length() > 2 )
        {
        fileName.prepend("/");
        fileName.prepend(PathDeck);
        fileName.append(".edb");
        }
    else
        {
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), PathDeck, tr("Images (*.edb)"));
        if ( fileName.isEmpty() )
            return;
        }


    emit DeckSaved();
    inOutDecksManager.deckModelToEdb( fileName );
}

void MainWindow::ExportDeck(QString fileName, int Format)
{
    switch (Format)
    {
    case VtesInfo::format_edb:
        {

        } break;

    case VtesInfo::format_ardb:
        {

        } break;

    case VtesInfo::format_txt:
        {

        } break;

    default:
        break;
    }
}

void MainWindow::PrintDeck()
{

}

void MainWindow::OpenDeck()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Deck"), PathDeck, tr("Deck Files (*.edb)"));
    if ( fileName.isEmpty() )
        return;

    if ( inOutDecksManager.EdbToDeckModel( fileName ) );
        emit DeckLoaded();
}

void MainWindow::CloseDeck()
{
    if ( test_tuning->ModeleDeck->isModified() )
        {
        QMessageBox msgBox;
        msgBox.setText("Close current deck without save changes ?");
        msgBox.setInformativeText("All your modifications will be lost");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch ( ret )
            {
            case QMessageBox::Save:
                {
                SaveDeck();
                test_tuning->ModeleDeck->clearDeck();
                }   break;

            case QMessageBox::Discard:
                {
                test_tuning->ModeleDeck->clearDeck();
                }   break;

            case QMessageBox::Cancel:
                {
                return;
                }   break;

            default:
                break;
            }
        }
    else
        {
        test_tuning->ModeleDeck->clearDeck();
        emit DeckClosed();
        }
}


void MainWindow::NewDeck()
{
    CloseDeck();
}


void MainWindow::OuvrirMenuOption()
{
     // Création de notre fenêtre modale
     DialogOptions Options(this);
     // On rend visible et modale notre fenêtre avec la méthode exec()
     Options.exec();
}


MainWindow::~MainWindow()
{
    /* On ferme la BDD */
    this->SqlDB.close();
    /* On detruit le reste de la fenêtre */
    delete ui;
}

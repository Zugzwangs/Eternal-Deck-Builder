#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Sauvegarde.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{

// ////////////////////////////////////////////////
//  INITIALISATION DES PATHS DE L'APPLI
{
DossierAppli.setPath(QCoreApplication::applicationDirPath());
if (DossierAppli.cd("Cartes"))
    {
    PathCartes = DossierAppli.absolutePath();
    qDebug() << "path des cartes = " << PathCartes;
    }
else
    QMessageBox::warning(this, "Erreur","le dossier des cartes est manquant !");


DossierAppli.cd("..");
if (DossierAppli.cd("Decks"))
    {
    PathDeck = DossierAppli.absolutePath();
    qDebug() << "path des Decks = " << PathDeck;
    }
else
    QMessageBox::warning(this, "Erreur","le dossier des Decks est manquant !");
}

// ////////////////////////////////////////////////
//  INITIALISATION DU MODULE DE TELECHARGEMENT
{
downloader = new update_manager( this );
downloader->set_card_directory( PathCartes );
downloader->set_serv_settings( "127.0.0.1", "jr", "pass" );
}

// ////////////////////////////////////////////////
//  OUVERTURE DE LA BDD 'VtesCardsListDB'
{
this->SqlDB = QSqlDatabase::addDatabase("QSQLITE");
this->SqlDB.setDatabaseName("VtesCardsListDB");
if (!this->SqlDB.open())
    {
     QMessageBox::warning(this, "Erreur", this->SqlDB.lastError().text());
     return;
    }
}

// ////////////////////////////////////////////////
//  MISE EN FORME DE LA FENETRE PRINCIPALE
{
ui->setupUi(this);
this->setWindowState(Qt::WindowMaximized);
}

// ///////////////////////////////////////////////
// MISE EN FORME DU TAB 'DECK TUNING'
{
    QHBoxLayout *layout = new QHBoxLayout;
    test_tuning = new tab_deck_tuning();
    layout->addWidget(test_tuning);
    ui->OngletProba->setLayout(layout);
}

// ////////////////////////////////////////////////
// MISE EN FORME DU TAB 'RECHERCHE CARTE'
{
    QHBoxLayout *layout = new QHBoxLayout;
    test_search = new tab_search_library();
    layout->addWidget(test_search);
    ui->OngletRechercheCarte->setLayout(layout);
    test_search->setupDeckModel(test_tuning->ModeleDeck);
}

// ///////////////////////////////////////////////
// MISE EN FORME DU TAB 'RECHERCHE  CRYPT'
{
    QHBoxLayout *layout = new QHBoxLayout;
    test_crypt = new tab_search_crypt();
    layout->addWidget(test_crypt);
    ui->OngletRechercheCrypte->setLayout(layout);
    test_crypt->setupDeckModel(test_tuning->ModeleDeck);
}

// ///////////////////////////////////////////////
// MISE EN FORME DU TAB 'gold fish'
{
    QHBoxLayout *layout = new QHBoxLayout;
    test_goldfish = new tab_gold_fich();
    test_goldfish->initialisation(PathCartes);
    layout->addWidget(test_goldfish);
    ui->OngletGoldFish->setLayout(layout);
}

// ///////////////////////////////////////////////
// DEFINITION DES CONNEXIONS
{
    connect(ui->actionEnregistrer_le_Deck, SIGNAL(triggered()), this, SLOT(EnregistreDeck()));
    connect(ui->actionImprimer_le_Deck, SIGNAL(triggered()), this, SLOT(ImprimeDeck()));
    connect(ui->actionOptions, SIGNAL(triggered()), this, SLOT(OuvrirMenuOption()));
  //connect( downloader, SIGNAL( picture_downloaded() ), this, SLOT( AfficheImageCarte(QString) ) );
}

// ///////////////////////////////////////////////
// FINITIONS
{
    ui->tabEditorModule->setCurrentIndex(0);
}

}

void MainWindow::EnregistreDeck()
{
    QString fileName = "TestDeck3.xml";
    Deck *CurrentDeck = new Deck();
    Deck2Xml(*CurrentDeck, PathDeck + "/" + fileName);
}

void MainWindow::ImprimeDeck()
{/* TODO integrer ds deck model
int NbPage,NbEx,k,x,y;
float NbCarteParPage;
QList<QStandardItem *> ItemCrypte = ModelDeckCourant->findItems("CRYPTE");
QList<QStandardItem *> ItemLibrary = ModelDeckCourant->findItems("BIBLIOTHEQUE");
QList<QStandardItem *> ItemMetadonnees = ModelDeckCourant->findItems("METADONNEES");
QList<QString> ListPathImageCarte;
QList<QImage *> Planches;
QPainter PlanchePainter;
QString DeckName, PrintFormat;

//On recupère le nom du deck
DeckName = ItemMetadonnees[0]->child(0)->data(Qt::DisplayRole).toString();

//On crée la liste de tous les chemins vers les images necesaires
for (int i=0; i<ItemCrypte[0]->rowCount(); i++)
    {
    NbEx = ItemCrypte[0]->child(i)->data(Qt::UserRole+2).toInt();
    for (int j=1; j<=NbEx; j++)
        {
        ListPathImageCarte.append(PathCartes + "/" + ItemCrypte[0]->child(i)->data(Qt::UserRole).toStringList().at(3) + ".jpg");
        }
    }
for (int i=0; i<ItemLibrary[0]->rowCount(); i++)
    {
    NbEx = ItemLibrary[0]->child(i)->data(Qt::UserRole+2).toInt();
    for (int j=1; j<=NbEx; j++)
        {
        ListPathImageCarte.append(PathCartes + "/" + ItemLibrary[0]->child(i)->data(Qt::UserRole).toStringList().at(3) + ".jpg");
        }
    }

//On va chercher les options d'impression.
QSettings settings("./cfg.ini", QSettings::IniFormat);
PrintFormat = settings.value("PrintFormat", "A4").toString();
if (PrintFormat == "A4")
   {
    NbCarteParPage = 8;
    //En fonction du nombre de carte trouvées, on détermine le nombre de planches nécessaires
    NbPage = ceil(ListPathImageCarte.count()/NbCarteParPage);
    //On construit les planches
    for (int i=1; i<=NbPage; i++)
        {
        Planches.append(new QImage(1440,1000,QImage::Format_RGB666));
        PlanchePainter.begin(Planches.at(i-1));
        for(int j=(i-1)*NbCarteParPage; (j<=(i*NbCarteParPage)-1) && (j<ListPathImageCarte.count()); j++)
            {
            k = j-((i-1)*NbCarteParPage)+1;
            x = (k-1)%4;
            y = ceil(k/4.0)-1;
            QPixmap CarteCourante(ListPathImageCarte.at(j));
            PlanchePainter.drawPixmap(x*360,y*500,CarteCourante);
            }
        PlanchePainter.end();
        }
    }
else
   {
    NbCarteParPage = 18;
    //En fonction du nombre de carte trouvées, on détermine le nombre de planches nécessaires
    NbPage = ceil(ListPathImageCarte.count()/NbCarteParPage);
    //On construit les planches
    for (int i=1; i<=NbPage; i++)
        {
        Planches.append(new QImage(2160,1500,QImage::Format_RGB666));
        PlanchePainter.begin(Planches.at(i-1));
        for(int j=(i-1)*NbCarteParPage; (j<=(i*NbCarteParPage)-1) && (j<ListPathImageCarte.count()); j++)
            {
            k = j-((i-1)*NbCarteParPage)+1;
            x = (k-1)%6;
            y = ceil(k/6.0)-1;
            QPixmap CarteCourante(ListPathImageCarte.at(j));
            PlanchePainter.drawPixmap(x*360,y*500,CarteCourante);
            }
        PlanchePainter.end();
        }
    }

//On crée la page de garde et on l'imprime:
//QString html;
//QWebView webView;
//webView.setHtml(html);
//webView.print(&printer);

//Maitenant on imprime les planches que l'on a créé :
QPrinter DeckPrinter(QPrinter::ScreenResolution);
QPainter PrintPainter;

DeckPrinter.setOrientation(QPrinter::Landscape);
if ( PrintFormat == "A4" ) DeckPrinter.setPaperSize(QPrinter::A4); else DeckPrinter.setPaperSize(QPrinter::A3);
DeckPrinter.setOutputFormat(QPrinter::PdfFormat);
DeckPrinter.setOutputFileName("./Decks/" + DeckName + ".pdf");
DeckPrinter.setPageMargins(10,10,0,0,QPrinter::Millimeter);
DeckPrinter.setResolution(150);

PrintPainter.begin(&DeckPrinter);
for(int i=0; i<Planches.count(); i++)
    {
    PrintPainter.drawImage(QPoint(0,0),*Planches.at(i));
    DeckPrinter.newPage();
    }
PrintPainter.end();*/
}

void MainWindow::OuvrirMenuOption()
{
 // Création de notre fenêtre modale
 DialogOptions test(this);
 // On rend visible et modale notre fenêtre avec la méthode exec()
 test.exec();
}

QString MainWindow::getPathCartes()
{
    return(PathCartes);
}

MainWindow::~MainWindow()
{
    /* On ferme la BDD */
    this->SqlDB.close();
    /* On detruit le reste de la fenêtre */
    delete ui;
}

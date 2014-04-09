#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //Generation de la fen�tre designed :
    ui->setupUi(this);

    //D�finition des connections :
    this->connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(testSlot()));
    this->connect(ui->btnSend, SIGNAL(clicked()), SLOT(slotSend()));

    //Op�rations suppl�mentaires au load :
    ui->TXPathText->setText("D:\\LackeyCCG\\plugins\\vtes\\sets\\allsets - Copy.txt");
    this->SqlDB = QSqlDatabase::addDatabase("QSQLITE");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testSlot()
{

    //On cr�e le mod�le :
    modele = new QStandardItemModel(3520,15);

    //On d�clare les objets pour la lecture du fichier:
    QString fileName = ui->TXPathText->text();
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    //On lit la premiere ligne qui contient les noms des champs
    QString Entete = flux.readLine();
    QChar Sep(9);
    QStringList EnteteSplitted = Entete.split(Sep);
    for(int i=0 ; i<EnteteSplitted.size() ; i++)
        {
        //DataEnteteSplitted.at(i);
        }

    //On lit et on traite le fichier texte de lackeyCCG ligne par ligne:
    int i = 0;
    while(! flux.atEnd())
        {
        //Lecture d'une ligne :
        QString ligne = flux.readLine();

        //On split les donn�es de la ligne (Sep = tabulation) :
        QStringList DataSplitted = ligne.split(Sep);

        //On �crit dans le mod�le les donn�es :
        for(int j=0 ; j<DataSplitted.size() ; j++)
            {
            modele->setItem(i,j,new QStandardItem(DataSplitted.at(j)));
            }
        i += 1;
        }
    //On connect le mod�le � la vue :
    ui->tableView->setModel(modele);
}

void MainWindow::slotSend()
{
    /* Initialisation du nom de la BDD */
    this->SqlDB = QSqlDatabase::addDatabase("QSQLITE");
    this->SqlDB.setDatabaseName("TestDB2");

    /* Ouverture de la base de donn�e */
    if (this->SqlDB.open())
        {
         QMessageBox::warning(this, "Debug", "La BDD � bien �t� ouverte !");
        }
    else
        {
         QMessageBox::warning(this, "Erreur", this->SqlDB.lastError().text());
         return;
        }

    /* Cr�ation de la table 'VtesCardList' */
    QSqlQuery CreateTableQuery;
    if ( CreateTableQuery.prepare("create table VtesCardList (id int primary key, Name varchar(20), Sets varchar(20), ImageFile varchar(20), Expansion varchar(20), Rarity varchar(20), Type varchar(20), Clan varchar(20), Grouping varchar(20), Capacity varchar(20), Discipline varchar(20) ,PCost varchar(20), BCost varchar(20), Text varchar(250), Artist varchar(20))") )
        {
         QMessageBox::warning(this, "Debug", "La requete � bien �t� prepar�e !");
        }
    else
        {
         QMessageBox::warning(this, "Erreur", CreateTableQuery.lastError().text());
         return;
        }

    if ( CreateTableQuery.exec() )
        {
         QMessageBox::warning(this, "Debug", "La requete � bien �t� execut�e !");
        }
        else
        {
         QMessageBox::warning(this, "Erreur", CreateTableQuery.lastError().text());
         return;
        }

/************************************************* nouveau new *******************************************************/
// Cr�ation de la table 'VampireList'

    if ( CreateTableQuery.prepare("create table VampireList (id int primary key, Name varchar(20), Sets varchar(20), ImageFile varchar(20), Expansion varchar(20), Rarity varchar(20), Type varchar(20), Clan varchar(20), Grouping varchar(20), Capacity varchar(20), Discipline varchar(20) ,Sect varchar(20), Trait varchar(50), Text varchar(250), Artist varchar(20))") )
    {
     QMessageBox::warning(this, "Debug", "La requete � bien �t� prepar�e !");
    }
else
    {
     QMessageBox::warning(this, "Erreur", CreateTableQuery.lastError().text());
     return;
    }

if ( CreateTableQuery.exec() )
    {
     QMessageBox::warning(this, "Debug", "La requete � bien �t� execut�e !");
    }
    else
    {
     QMessageBox::warning(this, "Erreur", CreateTableQuery.lastError().text());
     return;
    }

// Cr�ation de la table 'CardList'
if ( CreateTableQuery.prepare("create table CardList (id int primary key, Name varchar(20), Sets varchar(20), ImageFile varchar(20), Expansion varchar(20), Rarity varchar(20), Type varchar(20), SubType varchar(20), Clan varchar(20), Capacity varchar(20), Discipline varchar(20) ,PCost varchar(20), BCost varchar(20), Trait varchar(50), Text varchar(250), Artist varchar(20))") )
    {
     QMessageBox::warning(this, "Debug", "La requete � bien �t� prepar�e !");
    }
else
    {
     QMessageBox::warning(this, "Erreur", CreateTableQuery.lastError().text());
     return;
    }

if ( CreateTableQuery.exec() )
    {
     QMessageBox::warning(this, "Debug", "La requete � bien �t� execut�e !");
    }
    else
    {
     QMessageBox::warning(this, "Erreur", CreateTableQuery.lastError().text());
     return;
    }

/*********************************************************************************************************************/


    /*Remplissage de la table 'VtesCardList par les donn�es recolt�es dans le modele*/
    QSqlQuery InsertCardQuery;
    InsertCardQuery.prepare("insert into VtesCardList (id, Name, Sets, ImageFile, Expansion, Rarity, Type, Clan, Grouping, Capacity, Discipline, PCost, BCost, Text, Artist) values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    for(int cpt=1;cpt<=3520;cpt++)
        {
         InsertCardQuery.bindValue(0,cpt,QSql::In);
         for (int i=0; i<14;i++)
             {
              InsertCardQuery.bindValue(i+1,modele->item(cpt-1,i)->text(),QSql::In);
             }
         InsertCardQuery.exec();
        }

    QSqlQuery querytest;
    if ( querytest.exec("select * from VtesCardList") )
        {
         QMessageBox::warning(this,"Succes","requete des donn�es ok !");
        }
    else
        {
         QMessageBox::warning(this,"Erreur","probleme lors de la requete des donn�es : " + querytest.lastError().text());
         return;
        }

    this->showResult(querytest);

    // Ne pas oublier de fermer la base de donn�es
    this->SqlDB.close();
}

void MainWindow::showResult(QSqlQuery query)
{
    //QSqlRecord pour r�cup�rer les headers et le nombre de colonnes
    QSqlRecord rec = query.record();

    //Initialisation du tableau
    ui->tableResult->clear();
    ui->tableResult->setRowCount(3520);
    ui->tableResult->setColumnCount(15);
    //ui->tableResult->setColumnCount(rec.count());

    QStringList lst;
    for(int k=0; k< rec.count(); k++)
        {
        lst.append(rec.fieldName(k));
        }

    /*affectation des headers*/
    ui->tableResult->setHorizontalHeaderLabels(lst);

    int i = 0; // ligne
    while (query.next() /*&& i<3519*/) // parcours de chaque lignes du r�sultat
        {
         int j = 0; // colonne
         //ui->tableResult->insertRow(i);
         while (j < rec.count())
            {
             QLabel *lblCol = new QLabel(query.value(j).toString());
             ui->tableResult->setCellWidget(i, j, lblCol);
             j++;
            }
         i++;
        }
}




















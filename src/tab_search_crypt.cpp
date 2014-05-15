#include "tab_search_crypt.h"
#include "ui_tab_search_crypt.h"

#include "PWidget.h"

tab_search_crypt::tab_search_crypt(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_search_crypt)
{
    ui->setupUi(this);

    //On parcours toutes les ComboBox de la Frame regroupant les disciplines :
    QList<QComboBox *> ListDisciplineComboBox = ui->groupBoxDiscipline->findChildren<QComboBox *>(QString(), Qt::FindDirectChildrenOnly);
        foreach( QComboBox* CurrentComboBox, ListDisciplineComboBox )
        {
        CurrentComboBox->addItems(VtesInfo::DisciplineLvlList);
        }

    ui->cBSet_2->addItem("   <vide>");
    ui->cBSet_2->addItems(VtesInfo::ExpList);

    ui->cBRarity_2->addItem("   <vide>");
    ui->cBRarity_2->addItems(VtesInfo::RarityList);

    ui->cBSect->addItem("   <vide>");
    ui->cBSect->addItems(VtesInfo::SectsList);

    ui->cBClan->addItem("   <vide>");
    ui->cBClan->addItems(VtesInfo::ClansList);
    ui->cBClan->addItems(VtesInfo::CreedList);

    ui->cBTitle->addItem("   <vide>");
    ui->cBTitle->addItems(VtesInfo::TitlesList);

    ui->cBGroup->addItems(VtesInfo::OperatorList);
    ui->cBCapa->addItems(VtesInfo::OperatorList);

    // init card display area
    DosCrypt = QPixmap(":/icons/Vtes_Tanlarge.gif");
    ui->VisuelCrypt->setPixmap(DosCrypt);

    path_list.initPaths();
    PathCartes = path_list.getCardPath();

    // SETUP THE BDD MODEL
    ModelReponseCrypt = new PSqlTableModel();
    ModelReponseCrypt->setTable("VampireList");
    ModelReponseCrypt->select();


    // SETUP THE BDD VIEW
    ui->PTVCryptResults->setObjectName("PTVCryptResults");
    PDelegateCryptResult *DelegateCrypt = new PDelegateCryptResult();
    ui->PTVCryptResults->setItemDelegate(DelegateCrypt);
    ui->PTVCryptResults->setModel(ModelReponseCrypt);
    BddSelectionModel =  ui->PTVCryptResults->selectionModel();
    ui->PTVCryptResults->hideColumn(0);
    for (int i=2; i<=7; i++)        { ui->PTVCryptResults->hideColumn(i); }
    for (int i=15; i<=19; i++)      { ui->PTVCryptResults->hideColumn(i); }
    ui->PTVCryptResults->setVisible(true);
    ui->PTVCryptResults->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->PTVCryptResults->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Fixed);
    ui->PTVCryptResults->horizontalHeader()->setSectionResizeMode(9, QHeaderView::Fixed);
    ui->PTVCryptResults->horizontalHeader()->setSectionResizeMode(10, QHeaderView::Fixed);
    ui->PTVCryptResults->horizontalHeader()->resizeSection( 8, 60 );
    ui->PTVCryptResults->horizontalHeader()->resizeSection( 9, 75 );
    ui->PTVCryptResults->horizontalHeader()->resizeSection( 10, 75 );
    ui->PTVCryptResults->horizontalHeader()->setStretchLastSection(true);
    ui->PTVCryptResults->verticalHeader()->setDefaultSectionSize( 40 ); //set the default height of rows a bit taller for a better lisibility

    // SETUP THE COMPLETER FOR CARD NAME FIELD
    Completer = new QCompleter( this );
    Completer->setCaseSensitivity( Qt::CaseInsensitive );
    Completer->setCompletionColumn( 1 );
    Completer->setCompletionRole( Qt::DisplayRole );
    Completer->setMaxVisibleItems( 8 );
    Completer->setModel( ModelReponseCrypt );
    ui->lENameCard->setCompleter( Completer );

    // Connection des boutons
    connect( ui->pBCryptSearch,    SIGNAL( clicked() ), this, SLOT( RechercheCarte() ) );
    connect( ui->pBCryptClearForm, SIGNAL( clicked() ), this, SLOT( ClearForm() )      );
    connect( ui->pBAddtoDeck,      SIGNAL( clicked() ), this, SLOT( AddSelectedCard()) );

    // Connection de la vue des resultats de recherche
    connect(ui->PTVCryptResults, SIGNAL( clicked(QModelIndex) ), this, SLOT(request_affichage(QModelIndex)));
    connect(ui->PTVCryptResults->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(request_affichage(QModelIndex)));
    // Connection de la vue de la liste partielle du deck
    connect(ui->CryptView, SIGNAL( clicked(QModelIndex)), this, SLOT( deck_request_affichage(QModelIndex)) );
    // Connection du reste
    connect(this,  SIGNAL( new_card_selected(QString) ), this, SLOT( AfficheImageCrypt(QString) ));
}

// Setup the Crypt View
void tab_search_crypt::setupDeckModel(PTreeModel* deckModel)
{
    ui->CryptView->setModel(deckModel);
    ui->CryptView->setRootIndex(deckModel->itemCrypt->index());
}

void tab_search_crypt::AddSelectedCard()
{
    //we get all the card info from the bdd model:
    QModelIndexList SelectedItems = BddSelectionModel->selectedIndexes();
    if ( SelectedItems.isEmpty() )
        return;

    QModelIndex FirstSelectedItems = SelectedItems.first();
    QStringList dataValue;
    for (int i=0; i< ModelReponseCrypt->columnCount(); i++)
        {
        dataValue.append( ModelReponseCrypt->index(FirstSelectedItems.row(),i).data(Qt::DisplayRole).toString().trimmed() );
        }
    ui->CryptView->AddCardToDeck(dataValue.join("\n"));
}

void tab_search_crypt::RechercheCarte()
{
QString Requete,NameRequete,TextRequete,ArtistRequete;

    /* On construit la requete SQL avec selon les options selectionnées par USER */
    Requete = "(Type = 'Vampire' OR Type = 'Imbued')"; //condition tjrs vrai

    NameRequete = ui->lENameCard->text().trimmed();
    if (NameRequete.length() >= 1)
        {Requete += " AND Name like '%" + NameRequete + "%'";}

    TextRequete = ui->lETextCard->text().trimmed();
    if (TextRequete.length() >= 1)
        {Requete += " AND Text like '%" + TextRequete + "%'";}

    ArtistRequete = ui->lEArtist->text().trimmed();
    if (ArtistRequete.length() >= 1)
        {Requete += " AND Artist like '%" + ArtistRequete + "%'";}

    if (ui->cBSet_2->currentText() != "   <vide>")
        {Requete += " AND Expansion = '" + ui->cBSet_2->currentText() + "'";}

    if (ui->sBGroup->value() > 0 && ui->cBGroup->currentText() != "")
        {Requete += " AND (Grouping " + ui->cBGroup->currentText() + " " + QString::number(ui->sBGroup->value()) + ")";}

    if (ui->sBCapa->value() > 0 && ui->cBCapa->currentText() != "")
        {Requete += " AND (Capacity " + ui->cBCapa->currentText() + " '" + QString::number(ui->sBCapa->value()) +"')";}

    if (ui->cBSect->currentText() != "   <vide>")
        {Requete += " AND Sect like '%" + ui->cBSect->currentText() + "%'";}

    if (ui->cBClan->currentText()!= "   <vide>")
        {Requete += " AND Clan like '" + ui->cBClan->currentText() + "'";}

    if (ui->cBTitle->currentText()!= "   <vide>")
        {Requete += " AND Title like '%" + ui->cBTitle->currentText() + "%'";}

    //On parcours toutes les QCheckBox du QFrame regroupant les Traits
    QList<QCheckBox *> ListTraitCheckBox = ui->groupBoxTrait->findChildren<QCheckBox *>();
    for (int i=0; i<ListTraitCheckBox.count(); i++)
        {
        if (ListTraitCheckBox.at(i)->isChecked())
            {
            QString CurrentName =  ListTraitCheckBox.at(i)->text();
            Requete += " AND Trait like '%" + CurrentName + "%'";
            }
        }

    //On parcours toutes les ComboBox de la Frame regroupant les disciplines
    QList<QComboBox *> ListDisciplineComboBox = ui->groupBoxDiscipline->findChildren<QComboBox *>(QString(), Qt::FindDirectChildrenOnly);;
    foreach( QComboBox* CurrentComboBox, ListDisciplineComboBox )
        {
         QString CurrentName = CurrentComboBox->objectName().left(3); //left3 �  cause fortitude : on peut pas nommer un objet 'for'
         switch(CurrentComboBox->currentIndex())
            {
             case 0 : {/*pas de conditions supplémentaires */} break;
             case 1 : {Requete += " AND Discipline glob '*" + CurrentName.toLower() + "*'";} break;
             case 2 : {Requete += " AND Discipline like '%" + CurrentName + "%'";} break;
             case 3 : {Requete += " AND Discipline glob '*" + CurrentName.toUpper() + "*'";} break;
             case 4 : {Requete += " AND NOT Discipline like '%" + CurrentName + "%'";} break;
             default: {/*ne doit jamais arriver*/} break;
            }
        }

    //On parcours toutes les ComboBox de la Frame regroupant les virtues
    QList<QComboBox *> ListVirtuesComboBox = ui->groupBoxVirtues->findChildren<QComboBox *>(QString(), Qt::FindDirectChildrenOnly);;
    foreach( QComboBox* CurrentComboBox, ListVirtuesComboBox )
        {
         QString CurrentName = CurrentComboBox->objectName();
         switch(CurrentComboBox->currentIndex())
            {
             case 0 : {/*pas de conditions supplémentaires */} break;
             case 1 : {Requete += " AND Discipline like '%" + CurrentName + "%'";} break;
             case 2 : {Requete += " AND NOT Discipline like '%" + CurrentName + "%'";} break;
             default: {/*ne doit jamais arriver*/} break;
            }
        }

    /* On met en place la clause SQL OrderBy */

    /* On set le filtre et la View affiche la requete automatiquement */
    ModelReponseCrypt->setFilter(Requete);
    //PTVCryptResults->resizeColumnsToContents();
}

void tab_search_crypt::ClearForm()
{
QList<QGroupBox *> ListFrameFormulaireCrypt = ui->CryptSearchFrame->findChildren<QGroupBox *>();

for (int i=0; i<ListFrameFormulaireCrypt.count(); i++)
    {

    QList<QComboBox *> CurrentComboBoxList = ListFrameFormulaireCrypt.at(i)->findChildren<QComboBox *>();
    for(int j=0; j<CurrentComboBoxList.count() ; j++)
        { CurrentComboBoxList.at(j)->setCurrentIndex(0); }

    QList<QCheckBox *> CurrentCCheckBoxList = ListFrameFormulaireCrypt.at(i)->findChildren<QCheckBox *>();
    for(int k=0; k<CurrentCCheckBoxList.count() ; k++)
        { CurrentCCheckBoxList.at(k)->setChecked(0); }

    QList<QLineEdit *> CurrentLabelList = ListFrameFormulaireCrypt.at(i)->findChildren<QLineEdit *>();
    for(int l=0; l<CurrentLabelList.count() ; l++)
        { CurrentLabelList.at(l)->setText(""); }

    QList<QSpinBox *> CurrentSpinBoxList = ListFrameFormulaireCrypt.at(i)->findChildren<QSpinBox *>();
    for(int m=0; m<CurrentSpinBoxList.count() ; m++)
        { CurrentSpinBoxList.at(m)->setValue(0); }

    }
ModelReponseCrypt->setFilter(""); //On nettoie le filtre
}

void tab_search_crypt::request_affichage(QModelIndex Idx)
{
    if (Idx.isValid())
        {
        const QAbstractItemModel *CurrentModel;
        CurrentModel = Idx.model();
        QString CardName = CurrentModel->index(Idx.row(),3).data().toString();
        CardName = CardName + ".jpg";
        emit new_card_selected(CardName);
        }
}

void tab_search_crypt::deck_request_affichage(QModelIndex Idx)
{
    if ( Idx.isValid() )
        {
        QString CardName = Idx.data(VtesInfo::ImageFileRole).toString();
        CardName = CardName + ".jpg";
        emit new_card_selected(CardName);
        }
}

void tab_search_crypt::keyPressEvent(QKeyEvent *e)
{
    //if user type enter when crypt search tab is the active tab do the SQL select
    //verify the AutoRepeat flag garanty that a long press doesn't perform many time the same request
    if( !e->isAutoRepeat() && (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) )
        {
        RechercheCarte();
        }
    else
        QScrollArea::keyPressEvent(e);
}

void tab_search_crypt::AfficheImageCrypt(QString CardName)
{
    QImage Image;
    if (Image.load(PathCartes + "/" + CardName))
        {ui->VisuelCrypt->setPixmap(QPixmap::fromImage(Image));}
    else
        {
        emit card_picture_missing(CardName);
        /*Afficher un truc par defaut genre Vtes_Grelarge.gif*/
        }
}

tab_search_crypt::~tab_search_crypt()
{
    delete ui;
}

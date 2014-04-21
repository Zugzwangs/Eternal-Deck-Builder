#include "tab_search_library.h"
#include "ui_tab_search_library.h"

tab_search_library::tab_search_library(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_search_library)
{
    ui->setupUi(this);

    // setup des listes
    ui->cBBloodCost->addItems(VtesInfo::OperatorList);
    ui->cBPoolCost->addItems(VtesInfo::OperatorList);
    ui->cBConvictionCost->addItems(VtesInfo::OperatorList);

    ui->cBSet->addItem("   <vide>");
    ui->cBSet->addItems(VtesInfo::ExpList);

    ui->cBRarity->addItem("   <vide>");
    ui->cBRarity->addItems(VtesInfo::RarityList);

    ui->cBSect_2->addItem("   <vide>");
    ui->cBSect_2->addItems(VtesInfo::SectsList);

    ui->cBClan_2->addItem("   <vide>");
    ui->cBClan_2->addItems(VtesInfo::ClansList);

    ui->cBTitle_2->addItem("   <vide>");
    ui->cBTitle_2->addItems(VtesInfo::TitlesList);

    ui->cBType->addItem("   <vide>");
    ui->cBType->addItems(VtesInfo::CardTypeList);

    ui->cBSousType->addItem("   <vide>");

    //setup des boutons des disciplines et virtues
    QList<DisciplineButton *> ListDisciplineBt = ui->CardgroupBoxDiscipline->findChildren<DisciplineButton *>(QString(), Qt::FindDirectChildrenOnly);

    foreach( DisciplineButton* current_discipline_bt, ListDisciplineBt )
        {
        current_discipline_bt->setupDiscipline( current_discipline_bt->objectName() );
        }

    QList<DisciplineButton *> ListVirtuesCheckBox = ui->CardgroupBoxVirtues->findChildren<DisciplineButton *>(QString(), Qt::FindDirectChildrenOnly);

    foreach( DisciplineButton* current_virtues_bt, ListVirtuesCheckBox )
        {
        current_virtues_bt->setupDiscipline( current_virtues_bt->objectName() );
        }

    // init card display area
    DosCarte = QPixmap(":/icons/Vtes_Grelarge.gif");
    ui->VisuelCarte->setPixmap(DosCarte);

    // Init the MVC //

    // Model
    ModelReponseCarte = new PSqlTableModel();
    ModelReponseCarte->setTable("CardList");
    ModelReponseCarte->select();

    // Delegate
    PDelegateCardResult *DelegateCarte = new PDelegateCardResult();

    // View
    ui->PTVCardsResults->setObjectName("PTVCardsResults");
    ui->PTVCardsResults->setItemDelegate(DelegateCarte);
    ui->PTVCardsResults->setModel(ModelReponseCarte);
    ui->PTVCardsResults->setFrameShape(QFrame::NoFrame);
    ui->PTVCardsResults->hideColumn(0);
    for (int i=2; i<=6; i++)    { ui->PTVCardsResults->hideColumn(i); }
    ui->PTVCardsResults->hideColumn(8);
    ui->PTVCardsResults->hideColumn(10);
    for (int i=16; i<=22; i++)  { ui->PTVCardsResults->hideColumn(i); }

    ui->PTVCardsResults->setVisible(true);
    ui->PTVCardsResults->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->PTVCardsResults->horizontalHeader()->setSectionResizeMode( 9, QHeaderView::Fixed);
    ui->PTVCardsResults->horizontalHeader()->setSectionResizeMode( 13, QHeaderView::Fixed);
    ui->PTVCardsResults->horizontalHeader()->setSectionResizeMode( 14, QHeaderView::Fixed);
    ui->PTVCardsResults->horizontalHeader()->resizeSection( 9, 60 );
    ui->PTVCardsResults->horizontalHeader()->resizeSection( 13, 60 );
    ui->PTVCardsResults->horizontalHeader()->resizeSection( 14, 60 );
    ui->PTVCardsResults->horizontalHeader()->setStretchLastSection(true);
    ui->PTVCardsResults->verticalHeader()->setDefaultSectionSize( 40 ); //set the default height of rows a bit taller for a better lisibility

    // Add the completer to the main search label ( card name)
    Completer = new QCompleter( this );
    Completer->setCaseSensitivity( Qt::CaseInsensitive );
    //Completer->setFilterMode( Qt::MatchStartsWith );
    Completer->setCompletionColumn( 1 );
    Completer->setCompletionRole( Qt::DisplayRole );
    Completer->setMaxVisibleItems( 8 );
    Completer->setModel( ModelReponseCarte );
    ui->lENameCard_2->setCompleter( Completer );

    // connections du bordel
    connect( ui->cBType, SIGNAL( activated(int )),     this, SLOT( AdapteSousType() ) );
    connect( ui->pBCardClearForm, SIGNAL( clicked() ), this, SLOT( ClearForm() ) );
    connect( ui->pBCardSearch, SIGNAL( clicked() ),    this, SLOT( RechercheCarte() ) );
    connect( ui->PTVCardsResults, SIGNAL( clicked(QModelIndex) ), this, SLOT( request_affichage(QModelIndex) ) );
    connect (ui->PTVCardsResults->selectionModel(), SIGNAL( currentRowChanged(QModelIndex,QModelIndex) ), this, SLOT( request_affichage(QModelIndex) ) );

    connect(this, SIGNAL( new_card_selected(QString) ), this, SLOT( AfficheImageCarte(QString) ));
    connect( ui->dropLabel, SIGNAL(card_dropped(QStringList)), this, SIGNAL(card_dropped(QStringList)) );
}

void tab_search_library::RechercheCarte()
{
QString Requete,NameRequete,TextRequete,ArtistRequete;

/* On construit la requete SQL correspondant aux options selectionnées par USER */
Requete = "(Type != 'Vampire' AND Type != 'Imbued')"; //condition tjrs vraie

    /******************* Cadre general*******************/
    NameRequete = ui->lENameCard_2->text().trimmed();
    if (NameRequete.length() >= 1)  {Requete += " AND Name like '%" + NameRequete + "%'";}

    TextRequete = ui->lETextCard_2->text().trimmed();
    if (TextRequete.length() >= 1)  {Requete += " AND Text like '%" + TextRequete + "%'";}

    ArtistRequete = ui->lEArtist_2->text().trimmed();
    if (ArtistRequete.length() >= 1)    {Requete += " AND Artist like '%" + ArtistRequete + "%'";}

    if (ui->cBRarity->currentText()!= "   <vide>")   {Requete += " AND Rarity = '" + ui->cBRarity->currentText() + "'";}

    if (ui->cBSet->currentText()!= "   <vide>")      {Requete += " AND Sets = '" + ui->cBSet->currentText() + "'";}

    /******************* Cadre Filters *******************/
    if (ui->cBType->currentText() != "   <vide>")    {Requete += " AND Type like '" + ui->cBType->currentText() + "'";}

    if (ui->cBSousType->currentText()!= "   <vide>") {Requete += " AND SubType like '" + ui->cBType->currentText() + "'";}

    /******************* Cadre Cout *******************/
    if (ui->sBBloodCost->value() > 0 && ui->cBBloodCost->currentText() != "")   {Requete += " AND (BCost " + ui->cBBloodCost->currentText() + " " + QString::number(ui->sBBloodCost->value()) + ")";}

    if (ui->sBPoolCost->value() > 0 && ui->cBPoolCost->currentText() != "")     {Requete += " AND (PCost " + ui->cBPoolCost->currentText() + " " + QString::number(ui->sBPoolCost->value()) + ")";}

    if (ui->sBConvictionCost->value() > 0 && ui->cBConvictionCost->currentText() != "")   {Requete += " AND (CCost " + ui->cBConvictionCost->currentText() + " " + QString::number(ui->sBConvictionCost->value()) + ")";}

    /******************* Cadre Requirements *******************/
    if (ui->cBClan_2->currentText()!= "   <vide>")  {Requete += " AND Clan = '" + ui->cBClan_2->currentText() + "'";}

    if (ui->cBSect_2->currentText()!= "   <vide>")  {Requete += " AND Sect like '%" + ui->cBSect_2->currentText() + "%'";}

    if (ui->cBTitle_2->currentText()!= "   <vide>") {Requete += " AND Title like '%" + ui->cBTitle_2->currentText() + "%'";}

    QList<QCheckBox *> ListRequirementCheckBox = ui->CardgroupBoxRequirements->findChildren<QCheckBox *>();
    for (int i=0; i<ListRequirementCheckBox.count(); i++)
        {
        if (ListRequirementCheckBox.at(i)->isChecked())
            {
            QString CurrentName =  ListRequirementCheckBox.at(i)->text();
            Requete += " AND Trait like '%" + CurrentName + "%'";
            }
        }

    /******************* Cadre Mots Clef *******************/
    QList<QCheckBox *> ListOthersCheckBox = ui->CardgroupBoxOthers->findChildren<QCheckBox *>();
    for (int i=0; i<ListOthersCheckBox.count(); i++)
        {
        if (ListOthersCheckBox.at(i)->isChecked())
            {
            QString CurrentName =  ListOthersCheckBox.at(i)->text();
            Requete += " AND KeyWords like '%" + CurrentName + "%'";
            }
        }

    /******************* Cadre Disciplines et cadre Virtues *******************/
    QList<DisciplineButton *> ListDisciplineBt = ui->CardgroupBoxDiscipline->findChildren<DisciplineButton *>(QString(), Qt::FindDirectChildrenOnly);
    foreach( DisciplineButton* current_discipline_bt, ListDisciplineBt )
        {
        Requete += current_discipline_bt->get_sql_request();
        }

    QList<DisciplineButton *> ListVirtuesCheckBox = ui->CardgroupBoxVirtues->findChildren<DisciplineButton *>(QString(), Qt::FindDirectChildrenOnly);
    foreach( DisciplineButton* current_virtues_bt, ListVirtuesCheckBox )
        {
        Requete += current_virtues_bt->get_sql_request();
        }

    /* On set le filtre et la View affiche la requete automatiquement */
    ModelReponseCarte->setFilter(Requete);
    //PTVCardsResults->resizeColumnsToContents();
}

void tab_search_library::AdapteSousType()
{
    switch(ui->cBType->currentIndex())
        {
        /* pour les cas ou des sous type existent, on remplie la combobox. Sinon on vide la liste */
        case 1  :
            ui->cBSousType->clear();
            ui->cBSousType->addItem("   <vide>");
            ui->cBSousType->addItems(VtesInfo::MasterSubTypeList);
            break;

        case 3 :
            ui->cBSousType->clear();
            ui->cBSousType->addItem("   <vide>");
            ui->cBSousType->addItems(VtesInfo::EventSubTypeList);
            break;

        default :
            ui->cBSousType->clear();
            ui->cBSousType->addItem("   <vide>");
            break;
        }
}

void tab_search_library::request_affichage(QModelIndex Idx)
{
    if (Idx.isValid())
        {
        const QAbstractItemModel *CurrentModel;
        CurrentModel = Idx.model();
        QString CardName = CurrentModel->index(Idx.row(),3).data().toString();
        CardName = "/" + CardName + ".jpg";

        emit new_card_selected(CardName);
        }
}

void tab_search_library::ClearForm()
{
QList<QGroupBox *> ListFrameFormulaireCrypt = ui->CardSearchFrame->findChildren<QGroupBox *>();

for (int i=0; i<ListFrameFormulaireCrypt.count(); i++) //TODO revoir l'algo il est moche non ?
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

QList<DisciplineButton *> ListDisciplineBt = ui->CardgroupBoxDiscipline->findChildren<DisciplineButton *>(QString(), Qt::FindDirectChildrenOnly);
foreach( DisciplineButton* current_discipline_bt, ListDisciplineBt )
    {
    current_discipline_bt->resetState();
    }

QList<DisciplineButton *> ListVirtuesCheckBox = ui->CardgroupBoxVirtues->findChildren<DisciplineButton *>(QString(), Qt::FindDirectChildrenOnly);
foreach( DisciplineButton* current_virtues_bt, ListVirtuesCheckBox )
    {
    current_virtues_bt->resetState();
    }

ModelReponseCarte->setFilter(""); //On nettoie le filtre
}

void tab_search_library::AfficheImageCarte(QString CardName)
{
    // !!!!!!!!!! dépannage
    QString PathCartes;
    PathCartes = "D:\\Eternal-Deck-Builder\\bin\\debug\\Cartes\\";
    // !!!!!!!!!! dépannage
    QImage Image;
    if (Image.load(PathCartes + CardName))
        { ui->VisuelCarte->setPixmap(QPixmap::fromImage(Image)); }
    else
        {
        emit card_picture_missing(CardName);
        /*Afficher un truc par defaut genre Vtes_Grelarge.gif*/
        }
}

/* GESTION DES EVENEMENTS */
void tab_search_library::keyPressEvent(QKeyEvent *e)
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

tab_search_library::~tab_search_library()
{
    delete ui;
}

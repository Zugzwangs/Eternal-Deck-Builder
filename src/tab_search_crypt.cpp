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

    ui->cBTitle->addItem("   <vide>");
    ui->cBTitle->addItems(VtesInfo::TitlesList);

    ui->cBGroup->addItems(VtesInfo::OperatorList);
    ui->cBCapa->addItems(VtesInfo::OperatorList);

    //init du delegate
    PDelegateCryptResult *DelegateCrypt = new PDelegateCryptResult();

    //init du modèle de données
    ModelReponseCrypt = new PSqlTableModel();
    ModelReponseCrypt->setTable("VampireList");
    ModelReponseCrypt->select();

    //init de la vue
    ui->PTVCryptResults->setObjectName("PTVCryptResults");
    ui->PTVCryptResults->setItemDelegate(DelegateCrypt);
    ui->PTVCryptResults->setModel(ModelReponseCrypt);
    ui->PTVCryptResults->hideColumn(0);
    for (int i=2; i<=7; i++)
        { ui->PTVCryptResults->hideColumn(i); }
    //ui->PTVCryptResults->hideColumn(15);
    ui->PTVCryptResults->hideColumn(16);
    ui->PTVCryptResults->hideColumn(17);
    ui->PTVCryptResults->hideColumn(18);
    ui->PTVCryptResults->hideColumn(19);

    ui->PTVCryptResults->setVisible(true);
    ui->PTVCryptResults->resizeColumnsToContents();

    // connections
    connect(ui->pBCryptSearch, SIGNAL( clicked() ),    this, SLOT( RechercheCarte() ));
    connect(ui->pBCryptClearForm, SIGNAL( clicked() ), this, SLOT( ClearForm() ));
    connect(ui->PTVCryptResults, SIGNAL( clicked(QModelIndex) ), this, SLOT(request_affichage(QModelIndex)));
    connect(ui->PTVCryptResults->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(request_affichage(QModelIndex)));
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
         QString CurrentName = CurrentComboBox->objectName().left(3); //left3 à cause fortitude : on peut pas nommer un objet 'for'
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
        CardName = "/" + CardName + ".jpg";

        emit new_card_selected(CardName);
        }
}

tab_search_crypt::~tab_search_crypt()
{
    delete ui;
}

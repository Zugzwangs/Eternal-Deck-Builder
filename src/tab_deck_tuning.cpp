#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"
#include "Global.h"

#include <QDebug>

tab_deck_tuning::tab_deck_tuning(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_deck_tuning)
{
    ui->setupUi(this);

    // on map la deck view définie private dans l'ui vers un membre de classe public
    // TODO : verifié si ce lien est toujours utile
    DeckView = ui->PTreeViewDeckList;

    // SETUP DECK MODEL //
    ModeleDeck = new PTreeModel();
    ui->PTreeViewDeckList->setModel(ModeleDeck);
    PDelegateDeck *DelegateDeck = new PDelegateDeck();
    ui->PTreeViewDeckList->setItemDelegate(DelegateDeck);

    // SETUP TAB OVERVIEW //

    // setup widgets that show decks metas and link them to the model
    ui->cBFormat->addItems(VtesInfo::DeckFormat);

    mapper.SetModel(ModeleDeck);
    mapper.AddWidget( ui->lE_name,    VtesInfo::MetasList[VtesInfo::indexName] );
    mapper.AddWidget( ui->lE_author,  VtesInfo::MetasList[VtesInfo::indexAuthor] );
    mapper.AddWidget( ui->pT_summary, VtesInfo::MetasList[VtesInfo::indexdescription] );
    mapper.AddWidget( ui->cBFormat,   VtesInfo::MetasList[VtesInfo::indexFormat] );
    mapper.AddWidget( ui->sB_gp,      VtesInfo::MetasList[VtesInfo::indexGamesPlayed] );
    mapper.AddWidget( ui->sB_gw,      VtesInfo::MetasList[VtesInfo::indexGameWin] );
    mapper.AddWidget( ui->sB_tw,      VtesInfo::MetasList[VtesInfo::indexTournamentWin] );
    mapper.AddWidget( ui->sB_vp,      VtesInfo::MetasList[VtesInfo::indexVictoryPoint] );

    // setup viped viewer and link it to the model
    DeckViped = new VipedViewer(this);
    for (int i=0; i<VtesInfo::VipedList.count(); i++)
        DeckViped->setData( VtesInfo::VipedList.at(i), 0 );
    ui->frame_viped->layout()->addWidget(DeckViped);
    connect( DeckViped, SIGNAL(dataChanged(QString, int)), ModeleDeck, SLOT(setVipedMeta(QString,int))  );

    // model that keep stats of card's types repartition
    CardTypeModel = new StatsModel(VtesInfo::CardTypeList.count(), 1, this);
    CardTypeView = new PieChart();
    CardTypeView->setLegend("Cards types");
    for (int i=0; i<VtesInfo::CardTypeList.count(); i++)
        {
        CardTypeModel->setHeaderData(i, Qt::Vertical, VtesInfo::CardTypeList[i]);
        }
    CardTypeView->setModel(CardTypeModel);
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( CardTypeView, 0, 0 );

    // model that keep stats of card's cost repartition
    CardCostModel = new StatsModel(7, 1, this);
    for (int i=0; i<CardCostModel->rowCount(); i++)
        CardCostModel->setHeaderData(i, Qt::Vertical, "Cost " + QString::number(i) );
    CardCostView = new PieChart();
    CardCostView->setLegend("Cards costs");
    CardCostView->setModel(CardCostModel);
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( CardCostView, 0, 1 );

    // model that keep stats of crypt capacity repartition
    CapacityModel = new StatsModel(11, 1, this);
    CapacityModel->setHeaderData(0, Qt::Horizontal, "Capacity curve");
    CapacityView = new LinearChart();
    CapacityView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CapacityView->setModel( CapacityModel );
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( CapacityView, 1, 0 );

    // model that keep stats of crypt grouping repartition
    GroupingModel = new StatsModel(6, 1, this);
    GroupingModel->setHeaderData(0, Qt::Horizontal, "Grouping repartition");
    GroupingView = new LinearChart();
    GroupingView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ChartStyle style = GroupingView->columnStyle( 0 );
    style.setType( Marb::Bar );
    GroupingView->setColumnStyle( 0, style );
    GroupingView->setModel( GroupingModel );
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( GroupingView, 1, 1 );

    // models that keep stats of disciplines spread in the Library
    DisciplineLibModel   = new StatsModel(1, VtesInfo::DisciplinesList.count(), this);
    QString temp;
    QModelIndex temp_index;
    for (int i=0; i<VtesInfo::DisciplinesList.count(); i++)
        {
        temp = VtesInfo::DisciplinesSigleList[i];
        temp_index = DisciplineLibModel->index(0, i);
        DisciplineLibModel->setHeaderData(i, Qt::Horizontal, temp);
        if ( temp_index.isValid() ){
            DisciplineLibModel->setData( temp_index, QIcon(":/icons/disc/" + temp + ".png" ) , Qt::DecorationRole);
            DisciplineLibModel->setData( temp_index, 0, Qt::DisplayRole );
            }
        }
    DisciplineLibView = new QTableView(this);
    DisciplineLibView->setModel(DisciplineLibModel);
    DisciplineLibView->verticalHeader()->hide();
    DisciplineLibView->horizontalHeader()->hide();
    DisciplineLibView->setIconSize( QSize(45,45) );
    dynamic_cast<QGridLayout *>( ui->disciplineLibrary->layout() )->addWidget( DisciplineLibView, 0, 0 );

    // models that keep stats of disciplines spread in the Crypt
    DisciplineCryptModel = new StatsModel(2, VtesInfo::DisciplinesSigleList.count(), this);
    for (int i=0; i<VtesInfo::DisciplinesSigleList.count(); i++)
        {
        temp = VtesInfo::DisciplinesSigleList[i];
        DisciplineCryptModel->setHeaderData(i, Qt::Horizontal, temp);
        temp_index = DisciplineCryptModel->index(0, i);
        if ( temp_index.isValid() ){
            DisciplineCryptModel->setData( temp_index, QIcon(":/icons/disc/" + temp + ".png" ) , Qt::DecorationRole);
            DisciplineCryptModel->setData( temp_index, 0, Qt::DisplayRole );
            }
        temp_index = DisciplineCryptModel->index(1, i);
        if ( temp_index.isValid() ){
            DisciplineCryptModel->setData( temp_index, QIcon(":/icons/disc/" + temp + "-sup.png" ) , Qt::DecorationRole);
            DisciplineCryptModel->setData( temp_index, 0, Qt::DisplayRole );
            }
        }
    DisciplineCryptView = new QTableView(this);
    DisciplineCryptView->setModel(DisciplineCryptModel);
    DisciplineCryptView->verticalHeader()->hide();
    DisciplineCryptView->horizontalHeader()->hide();
    DisciplineCryptView->setIconSize( QSize(45,45) );
    dynamic_cast<QGridLayout *>( ui->disciplineCrypt->layout() )->addWidget( DisciplineCryptView, 0, 0 );

    // SETUP TAB CRYPT DETAILS
    cryptGalerie = new QListView();
    cryptGalerie->setFixedHeight(450);
    cryptGalerie->setUniformItemSizes(true);
    cryptGalerie->setGridSize( QSize(150,210) );
    cryptGalerie->setIconSize( QSize(144,200) );
    cryptGalerie->setWrapping(true);
    cryptGalerie->setMovement(QListView::Static);
    cryptGalerie->setDragDropMode(QAbstractItemView::InternalMove);
    cryptGalerie->setFrameShape(QFrame::NoFrame);
    cryptGalerie->setModel(ModeleDeck);
    cryptGalerie->setModelColumn(0);
    cryptGalerie->setRootIndex(ModeleDeck->itemCrypt->index());
    ui->frameCrypt->layout()->addWidget( cryptGalerie );

    // SETUP TAB LIBRARY DETAILS
    LibraryGalerie = new QListView();
    LibraryGalerie->setFixedHeight(660);
    LibraryGalerie->setUniformItemSizes(true);
    LibraryGalerie->setGridSize( QSize(150,210) );
    LibraryGalerie->setIconSize( QSize(144,200) );
    LibraryGalerie->setWrapping(true);
    LibraryGalerie->setMovement(QListView::Static);
    LibraryGalerie->setDragDropMode(QAbstractItemView::InternalMove);
    LibraryGalerie->setFrameShape(QFrame::NoFrame);
    LibraryGalerie->setModel(ModeleDeck);
    LibraryGalerie->setModelColumn(0);
    LibraryGalerie->setRootIndex(ModeleDeck->itemLib->index());
    ui->frameLibrary->layout()->addWidget( LibraryGalerie );

    // CONNECTIONS
    /* connect the fake buttons nested in CardItem */
    connect( ui->PTreeViewDeckList, SIGNAL(request_increment(QModelIndex)), ModeleDeck, SLOT(IncrementCardItem(QModelIndex)) );
    connect( ui->PTreeViewDeckList, SIGNAL(request_decrement(QModelIndex)), ModeleDeck, SLOT(DecrementCardItem(QModelIndex)) );
    connect( ui->PTreeViewDeckList, SIGNAL(request_delete(QModelIndex))   , ModeleDeck, SLOT(RemoveCardITem(QModelIndex))    );
    /* connect Stats model to changes of the deck model for syncs purposes */
    connect( ModeleDeck, SIGNAL( DeckChanged(QModelIndex) ), this, SLOT( refresh_stat_model(QModelIndex) ) );
    connect( ModeleDeck, SIGNAL( DeckCleared() ), this, SLOT( clear_stat_model() ) );
    connect( ModeleDeck, SIGNAL( DeckCleared() ), this, SLOT( clear_widgets()) );
}

void tab_deck_tuning::refresh_widgets()
{   //get meta value from model and set widgets with !

    ui->lE_author->setText(ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexAuthor] ));
    ui->lE_name->setText(ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexName] ));
    ui->sB_gp->setValue( ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexGamesPlayed] ).toInt() );
    ui->sB_gw->setValue( ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexGameWin] ).toInt() );
    ui->sB_tw->setValue( ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexTournamentWin] ).toInt() );
    ui->sB_vp->setValue( ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexVictoryPoint] ).toInt() );
    int formatIndex = ui->cBFormat->findText( ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexFormat] ) );
    ui->cBFormat->setCurrentIndex(formatIndex);
    ui->pT_summary->setPlainText( ModeleDeck->meta_list.value( VtesInfo::MetasList[VtesInfo::indexdescription] ) );
    for (int i=0; i<VtesInfo::VipedList.count(); i++)
        DeckViped->setData( VtesInfo::VipedList[i], ModeleDeck->meta_list.value(VtesInfo::VipedList[i]).toInt() );
}

void tab_deck_tuning::clear_widgets()
{
    DeckViped->clearData();
    ui->lE_author->setText("");
    ui->lE_name->setText("");
    ui->sB_gp->setValue(0);
    ui->sB_gw->setValue(0);
    ui->sB_tw->setValue(0);
    ui->sB_vp->setValue(0);
    ui->cBFormat->setCurrentIndex(0);
    ui->pT_summary->clear();
}

void tab_deck_tuning::clear_stat_model()
{
    CardTypeModel->clearData();
    CardCostModel->clearData();
    CapacityModel->clearData();
    GroupingModel->clearData();
    DisciplineCryptModel->clearData();
    DisciplineLibModel->clearData();
}

/*void tab_deck_tuning::sync_stats_model( QModelIndex new_item )
{

}*/

void tab_deck_tuning::refresh_stat_model(QModelIndex parent_index)
{
    if ( parent_index.isValid() )
        {
        if ( parent_index.data(Qt::DisplayRole).toString() == "BIBLIOTHEQUE" )
            {
            CardTypeModel->clearData(0);
            CardCostModel->clearData(0);
            DisciplineLibModel->clearData(0, true);

            QStandardItem *current_stat_item;
            QStandardItem *current_item;
            QStandardItem *parent_item = ModeleDeck->itemFromIndex(parent_index);

            for(int i=0; i<parent_item->rowCount(); i++)
                {
                current_item = parent_item->child(i,0);
                int multiplicateur = current_item->data(VtesInfo::ExemplairRole).toInt();

                // compute Card Type stats
                QString TypesOfNewCard = current_item->data(VtesInfo::TypeRole).toString();
                QStringList TypeList = TypesOfNewCard.split("/", QString::SkipEmptyParts);
                for ( int k=0; k<TypeList.count(); k++)
                    {
                    for (int j=0; j<VtesInfo::CardTypeList.count(); j++)
                        {
                        if ( (QString::compare(VtesInfo::CardTypeList[j], TypeList[k].trimmed(), Qt::CaseInsensitive)) == 0 )
                            {
                            current_stat_item = CardTypeModel->item(j, 0);
                            current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur, Qt::DisplayRole );
                            break;
                            }
                        }
                    }

                // compute card costs stats
                int Bloodcost = current_item->data(VtesInfo::BCostRole).toInt();
                int Poolcost = current_item->data(VtesInfo::PCostRole).toInt();
                int cost = qMax( Bloodcost, Poolcost);
                current_stat_item = CardCostModel->item(cost, 0);
                current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur, Qt::DisplayRole );

                // compute discipline spread stats
                QStringList Disciplines = current_item->data(VtesInfo::DisciplineRole).toString().split(" ", QString::SkipEmptyParts);
                for ( int k=0; k<Disciplines.count(); k++)
                    {
                    int DisciplineIndex = VtesInfo::DisciplinesSigleList.indexOf(Disciplines[k]);
                    if (DisciplineIndex > -1 )
                        {
                        current_stat_item = DisciplineLibModel->item( 0, DisciplineIndex );
                        current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur, Qt::DisplayRole );
                        }
                    }
                }
            }

        else if ( parent_index.data(Qt::DisplayRole).toString() == "CRYPTE" )
            {
            CapacityModel->clearData(0);
            GroupingModel->clearData(0);
            DisciplineCryptModel->clearData(0, true);

            QStandardItem *current_stat_item;
            QStandardItem *current_item;
            QStandardItem *parent_item = ModeleDeck->itemFromIndex(parent_index);

            for(int i=0; i<parent_item->rowCount(); i++)
                {
                current_item = parent_item->child(i,0);
                //for each different vampires, get his capa (X for exemple) then increment item(X,0) value by one per exemplair
                int generation = current_item->data(VtesInfo::CapacityRole).toInt();
                int multiplicateur = current_item->data(VtesInfo::ExemplairRole).toInt();
                current_stat_item = CapacityModel->item( generation-1, 0);
                if ( current_stat_item )
                    current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur , Qt::DisplayRole );
                else
                    qDebug() << "soucis de capacité ! capa =" << generation;

                // same thing for grouping
                int group = current_item->data(VtesInfo::GroupingRole).toInt();
                current_stat_item = GroupingModel->item( group-1 ,0);
                if ( current_stat_item )
                    current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur, Qt::DisplayRole );
                else
                    qDebug() << "soucis de grouping ! group =" << group;

                // compute discipline spread stats
                QStringList Disciplines = current_item->data(VtesInfo::DisciplineRole).toString().split(" ", QString::SkipEmptyParts);
                for ( int k=0; k<Disciplines.count(); k++)
                    {
                    int DisciplineIndex = VtesInfo::DisciplinesSigleList.indexOf( Disciplines[k].toLower() );
                    if ( DisciplineIndex > -1 && Disciplines[k] < Disciplines[k].toLower() )
                        {
                        current_stat_item = DisciplineCryptModel->item( 1, DisciplineIndex );
                        current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur, Qt::DisplayRole );
                        }
                    else
                        {
                        current_stat_item = DisciplineCryptModel->item( 0, DisciplineIndex );
                        current_stat_item->setData( current_stat_item->data(Qt::DisplayRole).toInt()+multiplicateur, Qt::DisplayRole );
                        }
                    }
                }
            }

        GroupingView->repaint();
        CapacityView->repaint();
        }
}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

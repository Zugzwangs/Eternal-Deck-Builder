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

    // setup des widgets affichant les metas
    ui->cBFormat->addItem("Choose a format");
    ui->cBFormat->addItems(VtesInfo::DeckFormat);

    // setup viped viewer
    for (int i=0; i<VtesInfo::VipedList.count(); i++)
        VipedDatas.insert( VtesInfo::VipedList[i], i);
    DeckViped = new VipedViewer(this);
    DeckViped->setModel(VipedDatas);
    ui->frame_viped->layout()->addWidget(DeckViped);

    // SETUP DECK METADATA MAPPER
    WidgetMetaMapper mapper(this);
    mapper.SetModel(ModeleDeck);
    mapper.AddWidget(ui->lE_name,"name");
    mapper.AddWidget(ui->lE_author,"author");
    //mapper.AddWidget(ui->TE_description,"description");

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
    CapacityModel->setData( CapacityModel->index(0,0), 10, Qt::DisplayRole);
    CapacityModel->setHeaderData(0, Qt::Horizontal, "Capacity curve");
    CapacityView = new LinearChart();
    CapacityView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CapacityView->setModel( CapacityModel );
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( CapacityView, 1, 0 );

    // model that keep stats of crypt grouping repartition
    GroupingModel = new StatsModel(6, 1, this);
    GroupingModel->setData( GroupingModel->index(0, 0), 10, Qt::DisplayRole);
    GroupingModel->setHeaderData(0, Qt::Horizontal, "Grouping repartition");
    GroupingView = new LinearChart();
    GroupingView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ChartStyle style = GroupingView->columnStyle( 0 );
    style.setType( Marb::Bar );
    GroupingView->setColumnStyle( 0, style );
    GroupingView->setModel( GroupingModel );
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( GroupingView, 1, 1 );

    // SETUP TAB CRYPT DETAILS
    cryptGalerie = new QListView();
    //cryptGalerie->setFixedHeight(450);
    cryptGalerie->setUniformItemSizes(true);
    cryptGalerie->setGridSize( QSize(150,210) );
    cryptGalerie->setIconSize( QSize(144,200) );
    cryptGalerie->setWrapping(true);
    cryptGalerie->setFrameShape(QFrame::NoFrame);
    cryptGalerie->setModel(ModeleDeck);
    cryptGalerie->setModelColumn(0);
    cryptGalerie->setRootIndex(ModeleDeck->itemCrypt->index());
    ui->frameCrypt->layout()->addWidget( cryptGalerie );

    // SETUP TAB LIBRARY DETAILS
    LibraryGalerie = new QListView();
    //LibraryGalerie->setFixedHeight(660);
    LibraryGalerie->setUniformItemSizes(true);
    LibraryGalerie->setGridSize( QSize(150,210) );
    LibraryGalerie->setIconSize( QSize(144,200) );
    LibraryGalerie->setWrapping(true);
    LibraryGalerie->setFrameShape(QFrame::NoFrame);
    LibraryGalerie->setModel(ModeleDeck);
    LibraryGalerie->setModelColumn(0);
    LibraryGalerie->setRootIndex(ModeleDeck->itemLib->index());
    ui->frameLibrary->layout()->addWidget( LibraryGalerie );

    // CONNECTIONS
    /*connect the fake buttons nested in CardItem*/
    connect( ui->PTreeViewDeckList, SIGNAL(request_increment(QModelIndex)), ModeleDeck, SLOT(IncrementCardItem(QModelIndex)) );
    connect( ui->PTreeViewDeckList, SIGNAL(request_decrement(QModelIndex)), ModeleDeck, SLOT(DecrementCardItem(QModelIndex)) );
    connect( ui->PTreeViewDeckList, SIGNAL(request_delete(QModelIndex))   , ModeleDeck, SLOT(RemoveCardITem(QModelIndex))    );
    /*connect Stats model to changes of the deck model for syncs purposes*/
    connect( ModeleDeck, SIGNAL( DeckChanged(QModelIndex) ), this, SLOT( refresh_stat_model(QModelIndex) ) );
}

void tab_deck_tuning::sync_stats_model( QModelIndex new_item )
{// the deck model has been changed, so we update datas in the stats/overview model
/*  TODO : fonction à reécrire !!! */
}

void tab_deck_tuning::refresh_stat_model(QModelIndex parent_index)
{
    if ( parent_index.isValid() )
        {
        if ( parent_index.data(Qt::DisplayRole).toString() == "BIBLIOTHEQUE" )
            {
            CardTypeModel->clearData(0);
            CardCostModel->clearData(0);
            QStandardItem *current_stat_item;
            QStandardItem *current_item;
            QStandardItem *parent_item = ModeleDeck->itemFromIndex(parent_index);

            for(int i=0; i<parent_item->rowCount(); i++)
                {
                current_item = parent_item->child(i,0);
                int multiplicateur = current_item->data(VtesInfo::ExemplairRole).toInt();

                // compute Card Type stats
                QString TypesOfNewCard = current_item->data(VtesInfo::TypeRole).toString();
                QStringList TypeList = TypesOfNewCard.split(" /*|*/ ", QString::SkipEmptyParts);
                /* !!!!! BUG : le type Action Modifier se split en 2 => formater la BDD "type1|type2|..." */
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

                }
            }

        else if ( parent_index.data(Qt::DisplayRole).toString() == "CRYPTE" )
            {
            CapacityModel->clearData(0);
            GroupingModel->clearData(0);
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
                }
            }

        }
}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

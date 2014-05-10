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

    // on assigne le model de données
    ModeleDeck = new PTreeModel();
    ui->PTreeViewDeckList->setModel(ModeleDeck);

    // on assigne le delegate
    PDelegateDeck *DelegateDeck = new PDelegateDeck();
    ui->PTreeViewDeckList->setItemDelegate(DelegateDeck);

    //on setup le mapper des metadonnées du model
    WidgetMetaMapper mapper(this);
    mapper.SetModel(ModeleDeck);
    mapper.AddWidget(ui->lE_name,"name");
    mapper.AddWidget(ui->lE_author,"author");
    mapper.AddWidget(ui->lE_description,"description");

    // On construit le modéle de stats qui se construit sur le DeckModel (static size [11,2] )
    model_test = new StatsModel;
    model_test->setData( model_test->index( 0, 0 ), 5, Qt::DisplayRole );
    model_test->setData( model_test->index( 0, 1 ), 5, Qt::DisplayRole );
    model_test->setData( model_test->index( 0, 2 ), 5, Qt::DisplayRole );

    for (int i = 1; i < model_test->rowCount(); i++ ) {
        model_test->setData( model_test->index( i, 0 ), 0, Qt::DisplayRole );
        model_test->setData( model_test->index( i, 1 ), 0, Qt::DisplayRole );
        model_test->setData( model_test->index( i, 2 ), 0, Qt::DisplayRole );
    }
    for (int i=0; i<VtesInfo::CardTypeList.count() && i<model_test->rowCount(); i++)
        {
        model_test->setHeaderData(i, Qt::Vertical, VtesInfo::CardTypeList[i], Qt::EditRole);
        }

    // Connect the fake buttons nested in CardItem
    connect( DeckView, SIGNAL(request_increment(QModelIndex)), ModeleDeck, SLOT(IncrementCardItem(QModelIndex)) );
    connect( DeckView, SIGNAL(request_decrement(QModelIndex)), ModeleDeck, SLOT(DecrementCardItem(QModelIndex)) );
    connect( DeckView, SIGNAL(request_delete(QModelIndex))   , ModeleDeck, SLOT(RemoveCardITem(QModelIndex))    );

    // Connect Stats model to changes of the deck model for syncs purposes
    connect( ModeleDeck, SIGNAL( DeckChanged(QModelIndex, QModelIndex) ), this, SLOT( sync_stats_model(QModelIndex, QModelIndex) ) );

    // Setup tab OverView
    QHBoxLayout *layout_overView = new QHBoxLayout;
    ui->tab_overView->setLayout(layout_overView);
    layout_overView->addWidget(ui->frameOverView);
    testPie = new PieChart();
    testPie->setLegend("Type repartition");
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( testPie, 0, 0 );
    testPie->setModel(model_test);
    testPie->setActiveColumn(2);
    testLinear = new LinearChart();
    testLinear->setModel( model_test );
    ChartStyle style = testLinear->columnStyle( 0 );
    style.setType( Marb::Bar );
    testLinear->setColumnStyle( 0, style );
    dynamic_cast<QGridLayout *>(ui->frameOverView->layout())->addWidget( testLinear, 0, 1 );

    // Setup tab crypt
    QHBoxLayout *layout_crypt = new QHBoxLayout;
    ui->tab_crypt->setLayout(layout_crypt);
    layout_crypt->addWidget(ui->frameCrypt);

    cryptGalerie = new QListView();
    cryptGalerie->setMinimumHeight(450);
    cryptGalerie->setUniformItemSizes(true);
    cryptGalerie->setGridSize( QSize(150,210) );
    cryptGalerie->setIconSize( QSize(144,200) );
    cryptGalerie->setWrapping(true);
    cryptGalerie->setFrameShape(QFrame::NoFrame);
    cryptGalerie->setModel(ModeleDeck);
    cryptGalerie->setModelColumn(0);
    cryptGalerie->setRootIndex(ModeleDeck->itemCrypt->index());

    dynamic_cast<QVBoxLayout *>(ui->frameCrypt->layout())->addWidget( cryptGalerie );

    // Setup tab crypt
    QHBoxLayout *layout_library= new QHBoxLayout;
    ui->tab_library->setLayout(layout_library);
    layout_library->addWidget(ui->frameLibrary);

    LibraryGalerie = new QListView();
    LibraryGalerie->setMinimumHeight(450);
    LibraryGalerie->setUniformItemSizes(true);
    LibraryGalerie->setGridSize( QSize(150,210) );
    LibraryGalerie->setIconSize( QSize(144,200) );
    LibraryGalerie->setWrapping(true);
    LibraryGalerie->setFrameShape(QFrame::NoFrame);
    LibraryGalerie->setModel(ModeleDeck);
    LibraryGalerie->setModelColumn(0);
    LibraryGalerie->setRootIndex(ModeleDeck->itemLib->index());

    dynamic_cast<QVBoxLayout *>(ui->frameLibrary->layout())->addWidget( LibraryGalerie );
}

// the deck model has been changed, so we update datas in the stats/overview model
void tab_deck_tuning::sync_stats_model(QModelIndex parent_index, QModelIndex new_item)
{
    if ( parent_index.isValid() )
        {
        if ( parent_index.data(Qt::DisplayRole).toString() == "BIBLIOTHEQUE" )
            {
            QStandardItem *youpi;
            QString TypeOfNewCard = new_item.data(VtesInfo::TypeRole).toString();
            for (int i=0; i<VtesInfo::CardTypeList.count(); i++)
                {
                if ( VtesInfo::CardTypeList[i] == TypeOfNewCard )
                    {
                    youpi = model_test->item(i,2);
                    youpi->setData( youpi->data(Qt::DisplayRole).toInt()+1, Qt::DisplayRole );
                    }
                }
            }
        else if ( parent_index.data(Qt::DisplayRole).toString() == "CRYPTE" )
            {
            //a new vamp is added, get his gen (X for exemple) then increment item(X,0) value by one
            int generation = new_item.data(VtesInfo::CapacityRole).toInt();
            QStandardItem *youpi = model_test->item( generation-1, 0);
            if ( youpi )
                youpi->setData( youpi->data(Qt::DisplayRole).toInt()+1 , Qt::DisplayRole );
            else
                qDebug() << "soucis de capacité ! capa =" << generation;

            // same thing for grouping
            int group = new_item.data(VtesInfo::GroupingRole).toInt();
            youpi = model_test->item( group-1 ,1);
            if ( youpi )
                youpi->setData( youpi->data(Qt::DisplayRole).toInt()+1, Qt::DisplayRole );
            else
                qDebug() << "soucis de grouping ! group =" << group;
            }
        }
}

void tab_deck_tuning::sync_crypt_stat()
{
    //TODO read all cryptItem then comput stats into the stats model

}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

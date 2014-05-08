#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"
#include "Global.h"

#include <QDebug>

tab_deck_tuning::tab_deck_tuning(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_deck_tuning)
{
    ui->setupUi(this);

    // on map la deck view définie private dans l'ui vers un membre de classe public
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

    // Model de stats qui se construit sur le Deck model (static size [11,2] )
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

    // Connect Stats model to changes of the deck model for syncs purposes
    connect( ModeleDeck, SIGNAL( CardAdded(QModelIndex, QModelIndex) ), this, SLOT( sync_stats_model(QModelIndex, QModelIndex) ) );
    connect( ModeleDeck, SIGNAL( CardRemoved() ), this, SLOT( sync_crypt_stat() ) );

    // LA VUE PIECHART
    testPie = new PieChart();
    testPie->setLegend("Type repartition");
    //testPie->setRing(True);
    dynamic_cast<QGridLayout *>(ui->frame_3->layout())->addWidget( testPie, 0, 0 );
    testPie->setModel(model_test);
    testPie->setActiveColumn(2);

    // LA VUE HISTOGRAMME
    testLinear = new LinearChart();
    testLinear->setModel( model_test );
    ChartStyle style = testLinear->columnStyle( 0 );
    style.setType( Marb::Bar );
    testLinear->setColumnStyle( 0, style );
    dynamic_cast<QGridLayout *>(ui->frame_3->layout())->addWidget( testLinear, 0, 1 );
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

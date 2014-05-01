#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"

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

    // Model de stats qui se construit sur le Deck model
    model_test = new StatsModel;                                    // Model with 2 column and 11 rows (no choice)
    qsrand( QDateTime::currentDateTime().toTime_t() );                      // Init random function
    for (int i = 0; i < model_test->rowCount(); i++ ) {                     // Fill the model
      qreal v = (qrand() % ( 30 - 10) + 10);                                // random value between 10 and 30
      model_test->setData( model_test->index( i, 0 ), 0 /*v*/, Qt::DisplayRole ); // Set data for the row 'i'
    }

    // Connect Stats model to changes of the deck model for syncs purposes
    connect( ModeleDeck, SIGNAL( CardAdded(QModelIndex, QModelIndex) ), this, SLOT( sync_stats_model(QModelIndex, QModelIndex) ) );

    // LA VUE PIECHART
    testPie = new PieChart();
    ui->frame_3->layout()->addWidget( testPie );
    testPie->setModel(model_test);

    // LA VUE HISTOGRAMME
    testLinear = new LinearChart();
    /*testLinear->setModel( model_test );
    ChartStyle style = testLinear->columnStyle( 0 );
    style.setType( Marb::Bar );
    testLinear->setColumnStyle( 0, style );
    ui->frame_3->layout()->addWidget( testLinear );*/
}

// the deck model has been changed, so we update datas in the stats/overview model
void tab_deck_tuning::sync_stats_model(QModelIndex parent_index, QModelIndex new_item)
{
    if ( parent_index.isValid() )
        {
        // temporaire !!!
        qDebug() << "un item à été rajouter dans la catégortie : " << parent_index.data(Qt::DisplayRole).toString();
        qDebug() << "la carte s'appelle " << new_item.data(Qt::DisplayRole).toString();
        qDebug() << "elle contient maintenant " << parent_index.data(Qt::UserRole+1).toString() << " cartes !";

        if ( parent_index.data(Qt::DisplayRole).toString() == "BIBLIOTHEQUE" )
            {

            }
        else if ( parent_index.data(Qt::DisplayRole).toString() == "CRYPTE" )
            {
            //a new vamp is added, get his gen (X for exemple) then increment item(X,0) value by one
            int generation = new_item.data(Qt::UserRole+2).toStringList().at(10).toInt() ;
            QStandardItem *youpi = model_test->item( generation, 0);
            youpi->setData( youpi->data(Qt::DisplayRole).toInt()+1 , Qt::DisplayRole );
            }
        }
}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

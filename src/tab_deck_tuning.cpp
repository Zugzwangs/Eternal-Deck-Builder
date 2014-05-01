#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"

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

    // on setup un model de test
    model_test = new QStandardItemModel( 6, 1 );                            // Model with 1 column and 6 rows
    qsrand( QDateTime::currentDateTime().toTime_t() );                      // Init random function
    for (int i = 0; i < model_test->rowCount(); ++i ) {                     // Fill the model
      qreal v = (qrand() % ( 30 - 10) + 10);                                // random value between 10 and 30
      model_test->setData( model_test->index( i, 0 ), v, Qt::DisplayRole ); // Set data for the row 'i'
    }

    // on test le proxy pour la crypte
    test_crypt_proxy = new CryptProxy();
    test_crypt_proxy->setSourceModel(ModeleDeck);
    test_crypt_view = new LinearChart();
    test_crypt_view->setModel( test_crypt_proxy );
    ui->frame_3->layout()->addWidget( test_crypt_view );
    //test_crypt_view->setModel(ModeleDeck);
    //test_crypt_view->setRootIndex(ModeleDeck->itemCrypt->index());

    // on declare une vue camenbert
    testPie = new PieChart();
    ui->frame_3->layout()->addWidget( testPie );
    testPie->setModel(model_test);

    // on test l'histogramme
    testLinear = new LinearChart();
    ui->frame_3->layout()->addWidget( testLinear );
    testLinear->setModel( model_test );
    ChartStyle style = testLinear->columnStyle( 0 );
    style.setType( Marb::Bar );
    testLinear->setColumnStyle( 0, style );

}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

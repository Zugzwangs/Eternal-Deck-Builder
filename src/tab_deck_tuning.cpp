#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"

tab_deck_tuning::tab_deck_tuning(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_deck_tuning)
{
    ui->setupUi(this);

    // on map la vue définie private dans l'ui vers un membre de classe public
    DeckView = ui->PTreeViewDeckList;

    // on assigne le model de données
    ModeleDeck = new PTreeModel();
    ui->PTreeViewDeckList->setModel(ModeleDeck);

    // on assigne le delegate
    PDelegateDeck *DelegateDeck = new PDelegateDeck();
    ui->PTreeViewDeckList->setItemDelegate(DelegateDeck);

    // on test le pie chart
    QStandardItemModel model( 6, 1 ); // Model with 1 column and 6 rows
    qsrand( QDateTime::currentDateTime().toTime_t() );          // Init random function
    for (int i = 0; i < model.rowCount(); ++i ) {              // Fill the model
      qreal v = (qrand() % ( 30 - 10) + 10);                    // random value between 10 and 30
      model.setData( model.index( i, 0 ), v, Qt::DisplayRole ); // Set data for the row 'i'
    }
    testPie = new PieChart(ui->frame);
    //testPie->setGeometry(0, 0, 300, 300);
    testPie->setModel(&model);
    testPie->show();

}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}

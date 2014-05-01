#ifndef TAB_DECK_TUNING_H
#define TAB_DECK_TUNING_H

#include <QScrollArea>
//#include <QTableView>
#include <QStandardItemModel>

#include "mvddeck.h"
#include "Charts/piechart.h"
#include "Charts/linearchart.h"

namespace Ui {
class tab_deck_tuning;
}

class tab_deck_tuning : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_deck_tuning(QWidget *parent = 0);
    PTreeView *DeckView;
    ~tab_deck_tuning();


private:
    Ui::tab_deck_tuning *ui;

    // Models
    PTreeModel *ModeleDeck;
    StatsModel *model_test;
    // Proxies
    CryptProxy *test_crypt_proxy;
    // Views
    PieChart *testPie;
    LinearChart *testLinear;
    LinearChart *test_crypt_view;

private slots:
    void sync_stats_model(QModelIndex parent_index, QModelIndex new_item);

signals:

};

#endif // TAB_DECK_TUNING_H

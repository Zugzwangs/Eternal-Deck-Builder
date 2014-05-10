#ifndef TAB_DECK_TUNING_H
#define TAB_DECK_TUNING_H

#include <QScrollArea>
#include <QStandardItemModel>
#include <QListView>

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
    // Main model !
    PTreeModel *ModeleDeck;

private:
    Ui::tab_deck_tuning *ui;
    // Stats Model
    StatsModel *model_test;
    // Views
    QListView *cryptGalerie;
    QListView *LibraryGalerie;
    PieChart *testPie;
    LinearChart *testLinear;
    LinearChart *test_crypt_view;

private slots:
    void sync_stats_model(QModelIndex parent_index, QModelIndex new_item);
    void sync_crypt_stat();

signals:

};

#endif // TAB_DECK_TUNING_H

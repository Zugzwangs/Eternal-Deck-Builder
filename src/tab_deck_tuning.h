#ifndef TAB_DECK_TUNING_H
#define TAB_DECK_TUNING_H

#include <QScrollArea>
#include <QStandardItemModel>
#include <QListView>
#include <QTableView>

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
    StatsModel *CardTypeModel;
    StatsModel *CardCostModel;
    StatsModel *CapacityModel;
    StatsModel *GroupingModel;

    // Views
    PieChart *CardTypeView;
    PieChart *CardCostView;
    LinearChart *CapacityView;
    LinearChart *GroupingView;

    QListView *cryptGalerie;
    QListView *LibraryGalerie;

private slots:
    void sync_stats_model(QModelIndex new_item);
    void refresh_stat_model(QModelIndex parent_index);

signals:

};

#endif // TAB_DECK_TUNING_H

#ifndef TAB_DECK_TUNING_H
#define TAB_DECK_TUNING_H

#include <QScrollArea>
#include <QStandardItemModel>
#include <QListView>
#include <QTableView>

#include "mvddeck.h"
#include "Widgets/vipedviewer.h"
#include "Charts/piechart.h"
#include "Charts/linearchart.h"
#include "Charts/radialchart.h"

namespace Ui {
class tab_deck_tuning;
}

class tab_deck_tuning : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_deck_tuning(QWidget *parent = 0);
    ~tab_deck_tuning();

public:
    PTreeModel *ModeleDeck;
    PTreeView *DeckView; //to make the view reachable from outside

private:
    Ui::tab_deck_tuning *ui;
    // Stats Model
    StatsModel *CardTypeModel;
    StatsModel *CardCostModel;
    StatsModel *CapacityModel;
    StatsModel *GroupingModel;
    StatsDisciplineModel *DisciplineLibModel;
    StatsDisciplineModel *DisciplineCryptModel;

    // Views
    PieChart *CardTypeView;
    PieChart *CardCostView;
    LinearChart *CapacityView;
    LinearChart *GroupingView;
    QListView *cryptGalerie;
    QListView *LibraryGalerie;
    VipedViewer *DeckViped;
    QTableView *DisciplineLibView;
    QTableView *DisciplineCryptView;

    WidgetMetaMapper mapper;

private slots:
    void clear_widgets();
    void refresh_widgets();
    void refresh_disciplinesLib_view(QStandardItem *);
    void refresh_disciplinesCrypt_view(QStandardItem *);
    void clear_stat_model();
    void refresh_stat_model(QModelIndex parent_index);

signals:

};

#endif // TAB_DECK_TUNING_H

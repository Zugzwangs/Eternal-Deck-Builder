#ifndef TAB_DECK_TUNING_H
#define TAB_DECK_TUNING_H

#include <QScrollArea>
#include <QStandardItemModel>

#include "pitemview.h"

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
    PTreeModel *ModeleDeck;

public slots:

signals:

};

#endif // TAB_DECK_TUNING_H

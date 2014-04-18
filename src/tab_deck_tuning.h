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
    void AfficheCartesDeck(QModelIndex Idx);

private:
    Ui::tab_deck_tuning *ui;
    // On déclare le Modèle pour la gestion du deck
    PTreeModel *ModeleDeck;

signals:
    void card_picture_missing(QString);

};

#endif // TAB_DECK_TUNING_H

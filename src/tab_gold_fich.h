#ifndef TAB_GOLD_FICH_H
#define TAB_GOLD_FICH_H

#include <QScrollArea>
#include "Widgets/bloodbank.h"
#include "Widgets/cardsstackview.h"
#include "playground.h"
#include "hud.h"
#include "Global.h"
#include "game_element.h"
#include "Sauvegarde.h"

namespace Ui {  class tab_gold_fich;    }

class tab_gold_fich : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_gold_fich(QWidget *parent = 0);
    void initialisation(DeckTranslator *DT);
    ~tab_gold_fich();

private:
    Ui::tab_gold_fich *ui;

    PathProvider path_list;
    QString PathCartes;
    QString PathDeck;
    DeckTranslator *translator;
    QGraphicsScene *Scenedejeu;
    Hud *testHud;
    BloodBank* Bourse;
    Deck *currentDeck;
    CardsStackView *LibraryWidget;

public slots:
    void load_deck();
    void restart_game();
    void test_draw();
};

#endif // TAB_GOLD_FICH_H

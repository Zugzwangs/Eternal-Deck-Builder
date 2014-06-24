#ifndef TAB_GOLD_FICH_H
#define TAB_GOLD_FICH_H

#include <QScrollArea>
#include <QSplitter>
#include "Widgets/bloodbank.h"
#include "Widgets/crypt.h"
#include "Widgets/library.h"
#include "Widgets/ashheap.h"
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
    QSplitter *splitter;
    DeckTranslator *translator;
    PGraphicsScene *Scenedejeu;
    HandGraphicsScene* HandZone;
    Hud *testHud;
    BloodBank* Bourse;
    Deck *currentDeck;
    Library *LibraryWidget;
    Crypt *CryptWidget;
    AshHeap *AshHeapWidget;

public slots:
    void load_deck();
    void restart_game();

};

#endif // TAB_GOLD_FICH_H

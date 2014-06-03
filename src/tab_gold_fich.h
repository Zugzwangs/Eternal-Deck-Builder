#ifndef TAB_GOLD_FICH_H
#define TAB_GOLD_FICH_H

#include <QScrollArea>
#include "playground.h"

namespace Ui {  class tab_gold_fich;    }

class tab_gold_fich : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_gold_fich(QWidget *parent = 0);
    void initialisation(QString path);
    ~tab_gold_fich();

private:
    Ui::tab_gold_fich *ui;

    QString PathCartes;
    QGraphicsScene *Scenedejeu;
};

#endif // TAB_GOLD_FICH_H

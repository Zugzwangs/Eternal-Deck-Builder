#ifndef TAB_DECK_TUNING_H
#define TAB_DECK_TUNING_H

#include <QScrollArea>

namespace Ui {
class tab_deck_tuning;
}

class tab_deck_tuning : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_deck_tuning(QWidget *parent = 0);
    ~tab_deck_tuning();

private:
    Ui::tab_deck_tuning *ui;
};

#endif // TAB_DECK_TUNING_H

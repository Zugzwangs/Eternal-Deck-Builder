#ifndef HUD_H
#define HUD_H

#include <QScrollArea>

namespace Ui { class Hud; }

class Hud : public QScrollArea
{
    Q_OBJECT

public:
    explicit Hud(QWidget *parent = 0);
    ~Hud();

private:
    Ui::Hud *ui;

signals:
    void request_deck_load();
    void request_game_restart();
};

#endif // HUD_H

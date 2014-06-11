#ifndef HUD_H
#define HUD_H

#include <QScrollArea>

namespace Ui {
class Hud;
}

class Hud : public QScrollArea
{
    Q_OBJECT

public:
    explicit Hud(QWidget *parent = 0);
    ~Hud();

private:
    Ui::Hud *ui;
};

#endif // HUD_H

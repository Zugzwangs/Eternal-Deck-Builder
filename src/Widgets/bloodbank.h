#ifndef BLOODBANK_H
#define BLOODBANK_H

#include <QFrame>
#include <QMouseEvent>

// /////////////////////////////////////////////////////////////////////////////////////////
// Distributeur de blood
class BloodBank : public QFrame
{
    Q_OBJECT

public:
    explicit BloodBank(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void startDrag();
    QPixmap *BloodPxm;
    QPoint startPos;

};

#endif // BLOODBANK_H

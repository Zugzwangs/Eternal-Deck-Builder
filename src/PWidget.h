#ifndef PWIDGET_H
#define PWIDGET_H

#include <QFrame>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QPushButton>

// /////////////////////////////////////////////////////////////////////////////////////////
// Ma Subclass de QFrame

class PFrame : public QFrame
{
   //Q_OBJECT

public:
    explicit PFrame(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void startDrag();
    QPixmap *BloodPxm;
    QPoint startPos;
};

// /////////////////////////////////////////////////////////////////////////////////////////
//
class DisciplineButton : public QAbstractButton
{
public:
    explicit DisciplineButton(QWidget *parent = 0);
    void setupDiscipline(QString dis);
    void resetState();
    QString get_sql_request();

protected:
    void paintEvent(QPaintEvent *e);
    void nextCheckState();

private:
    int state;
    enum state_list{ RequestNothing, RequestDiscipline, RequestNotDiscipline };
    QString discipline;
    QPixmap icone;
    QString sql_request;
};

// /////////////////////////////////////////////////////////////////////////////////////////
//
class PDeckDropArea : public QFrame
{
    Q_OBJECT

public:
    explicit PDeckDropArea(QWidget *parent = 0);
    ~PDeckDropArea();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:


};

#endif // PWIDGET_H



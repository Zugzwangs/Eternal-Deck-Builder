#ifndef PWIDGET_H
#define PWIDGET_H

#include <QFrame>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QPushButton>

// /////////////////////////////////////////////////////////////////////////////////////////
// Distributeur de blood

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
class DisciplineButton : public QPushButton
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

class VipedViewer : public QFrame
{
    Q_OBJECT

public:
    explicit VipedViewer(QWidget *parent = 0 );
    virtual QSize sizeHint() const;

protected:
    virtual void paintEvent(QPaintEvent * event);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);

private:

};

#endif // PWIDGET_H


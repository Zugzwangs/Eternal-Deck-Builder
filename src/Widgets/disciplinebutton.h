#ifndef DISCIPLINEBUTTON_H
#define DISCIPLINEBUTTON_H

#include <QPushButton>

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

#endif // DISCIPLINEBUTTON_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <Qfile>
#include <QString>
#include <QStandardItemModel>
#include <QtSql>
#include <QMessageBox>
#include <QLabel>

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QSqlDatabase SqlDB;

    QStandardItemModel *modele;
    void showResult(QSqlQuery query);

private slots:
    void testSlot();
    void slotSend();

};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <Qfile>
#include <QList>
#include <QtSql>
#include <QtPrintSupport/QPrinter>

#include "dialogoptions.h"
#include "update_manager.h"
#include "tab_search_library.h"
#include "tab_search_crypt.h"
#include "tab_gold_fich.h"
#include "tab_deck_tuning.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    QString getPathCartes();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // On déclare l'objet BDD
    QSqlDatabase SqlDB;
    // On déclare le gestionnaire de téléchargements
    update_manager* downloader;
    // On déclare les variable de paths
    QDir DossierAppli;
    QString PathCartes;
    QString PathRessources;
    QString PathDeck;
    // Main Tabs
    tab_search_library  *advanced_library_search_tab;
    tab_search_crypt *advanced_crypt_search_tab;
    tab_deck_tuning *test_tuning;
    tab_gold_fich * playground_tab;

private slots:
    void EnregistreDeck();
    void ExportDeck(int Format);
    void ImprimeDeck();
    void OuvrirMenuOption();

signals:

};

#endif // MAINWINDOW_H

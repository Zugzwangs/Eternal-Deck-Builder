#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QtSql>
#include <QtPrintSupport/QPrinter>

#include "dialogoptions.h"
#include "update_manager.h"
#include "tab_search_library.h"
#include "tab_search_crypt.h"
#include "tab_gold_fich.h"
#include "tab_deck_tuning.h"
#include "Sauvegarde.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase SqlDB;         // La BDD embarquée
    update_manager* downloader; // gestionnaire de téléchargement
    PathProvider path_list;     // gestionnaire de path de paths
    FFFF inOutDecksManager;     // implémente import/export des decks
    QSqlQueryModel *queryModel;
    QString PathCartes;
    QString PathRessources;
    QString PathDeck;
    // Main Tabs
    tab_search_library  *advanced_library_search_tab;
    tab_search_crypt *advanced_crypt_search_tab;
    tab_deck_tuning *test_tuning;
    tab_gold_fich * playground_tab;

private slots:
    void SaveDeck();
    void ExportDeck(QString fileName, int Format);
    void PrintDeck();
    void OpenDeck();
    void CloseDeck();
    void NewDeck();

    void OuvrirMenuOption();

signals:
    void DeckLoaded();
    void DeckClosed();
    void DeckSaved();

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <Qfile>
#include <QList>
#include <QtSql>
#include <QStandardItemModel>
#include <QtPrintSupport/QPrinter>

#include <math.h>

#include "pitemview.h"
#include "dialogoptions.h"
#include "tab_search_library.h"
#include "tab_search_crypt.h"
#include "tab_gold_fich.h"
#include "tab_deck_tuning.h"
#include "update_manager.h"

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
    // On déclare et initialise des ressources
    QPixmap DosCarte;
    QPixmap DosCrypt;
    // On déclare le Modèle pour la gestion du deck
    PTreeModel *ModeleDeck;

    //les contenus des onglets
    tab_search_library  *test_search;
    tab_search_crypt *test_crypt;
    tab_deck_tuning *test_tuning;
    tab_gold_fich * test_goldfish;

private slots:
    void AfficheImageCarte(QString CardName);
    void AfficheImageCrypt(QString CardName);
    void AfficheCartesDeck(QModelIndex Idx);
    void ChangeVisuel(int IndexCourant);
    void EnregistreDeck();
    void ImprimeDeck();
    void OuvrirMenuOption();

signals:
    void card_picture_missing(QString);
};

#endif // MAINWINDOW_H

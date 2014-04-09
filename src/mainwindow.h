#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <Qfile>
#include <QList>
#include <QtSql>
#include <QGraphicsScene>
#include <QStandardItemModel>
#include <QtPrintSupport/QPrinter>

#include <math.h>

#include "pitemview.h"
#include "PGraphics.h"
#include "dialogoptions.h"
#include "tab_search_library.h"
#include "tab_search_crypt.h"
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
    // On d�clare l'objet BDD
    QSqlDatabase SqlDB;
    // On d�clare le gestionnaire de t�l�chargements
    update_manager* downloader;
    // On d�clare les variable de paths
    QDir DossierAppli;
    QString PathCartes;
    QString PathRessources;
    QString PathDeck;
    // On d�clare et initialise des ressources
    QPixmap DosCarte;
    QPixmap DosCrypt;
    // On d�clare les Views
    PTreeView* PTreeViewDeckList;
    PGraphicsView* TabledeJeu;
    // On d�clare les modules ET les sc�nes
    PTreeModel *ModeleDeck;
    QGraphicsScene *Scenedejeu;

    //test
    tab_search_library  *test_search;
    tab_search_crypt *test_crypt;

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

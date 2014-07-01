/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnregistrer_le_Deck;
    QAction *actionImprimer_le_Deck;
    QAction *actionOptions;
    QAction *actionExport_Deck;
    QAction *actionNew_Deck;
    QAction *actionOpen_a_deck;
    QAction *actionClose_deck;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabEditorModule;
    QWidget *OngletRechercheCarte;
    QHBoxLayout *horizontalLayout;
    QWidget *OngletRechercheCrypte;
    QHBoxLayout *horizontalLayout_2;
    QWidget *OngletProba;
    QHBoxLayout *horizontalLayout_3;
    QWidget *OngletGoldFish;
    QHBoxLayout *horizontalLayout_4;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuParam_trages;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1680, 1050);
        MainWindow->setMinimumSize(QSize(600, 400));
        actionEnregistrer_le_Deck = new QAction(MainWindow);
        actionEnregistrer_le_Deck->setObjectName(QStringLiteral("actionEnregistrer_le_Deck"));
        actionImprimer_le_Deck = new QAction(MainWindow);
        actionImprimer_le_Deck->setObjectName(QStringLiteral("actionImprimer_le_Deck"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionExport_Deck = new QAction(MainWindow);
        actionExport_Deck->setObjectName(QStringLiteral("actionExport_Deck"));
        actionNew_Deck = new QAction(MainWindow);
        actionNew_Deck->setObjectName(QStringLiteral("actionNew_Deck"));
        actionOpen_a_deck = new QAction(MainWindow);
        actionOpen_a_deck->setObjectName(QStringLiteral("actionOpen_a_deck"));
        actionClose_deck = new QAction(MainWindow);
        actionClose_deck->setObjectName(QStringLiteral("actionClose_deck"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 0);
        tabEditorModule = new QTabWidget(centralWidget);
        tabEditorModule->setObjectName(QStringLiteral("tabEditorModule"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabEditorModule->sizePolicy().hasHeightForWidth());
        tabEditorModule->setSizePolicy(sizePolicy);
        tabEditorModule->setAutoFillBackground(false);
        tabEditorModule->setStyleSheet(QStringLiteral(""));
        tabEditorModule->setTabPosition(QTabWidget::North);
        tabEditorModule->setTabShape(QTabWidget::Rounded);
        tabEditorModule->setDocumentMode(false);
        OngletRechercheCarte = new QWidget();
        OngletRechercheCarte->setObjectName(QStringLiteral("OngletRechercheCarte"));
        horizontalLayout = new QHBoxLayout(OngletRechercheCarte);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tabEditorModule->addTab(OngletRechercheCarte, QString());
        OngletRechercheCrypte = new QWidget();
        OngletRechercheCrypte->setObjectName(QStringLiteral("OngletRechercheCrypte"));
        horizontalLayout_2 = new QHBoxLayout(OngletRechercheCrypte);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabEditorModule->addTab(OngletRechercheCrypte, QString());
        OngletProba = new QWidget();
        OngletProba->setObjectName(QStringLiteral("OngletProba"));
        horizontalLayout_3 = new QHBoxLayout(OngletProba);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabEditorModule->addTab(OngletProba, QString());
        OngletGoldFish = new QWidget();
        OngletGoldFish->setObjectName(QStringLiteral("OngletGoldFish"));
        horizontalLayout_4 = new QHBoxLayout(OngletGoldFish);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabEditorModule->addTab(OngletGoldFish, QString());

        gridLayout->addWidget(tabEditorModule, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1680, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuParam_trages = new QMenu(menuBar);
        menuParam_trages->setObjectName(QStringLiteral("menuParam_trages"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuParam_trages->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFichier->addAction(actionEnregistrer_le_Deck);
        menuFichier->addAction(actionExport_Deck);
        menuFichier->addAction(actionImprimer_le_Deck);
        menuFichier->addAction(actionNew_Deck);
        menuFichier->addAction(actionOpen_a_deck);
        menuFichier->addAction(actionClose_deck);
        menuParam_trages->addAction(actionOptions);

        retranslateUi(MainWindow);

        tabEditorModule->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vampire, the eternal deck builder", 0));
        actionEnregistrer_le_Deck->setText(QApplication::translate("MainWindow", "Save Deck", 0));
        actionEnregistrer_le_Deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionImprimer_le_Deck->setText(QApplication::translate("MainWindow", "Print proxy", 0));
        actionImprimer_le_Deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0));
        actionExport_Deck->setText(QApplication::translate("MainWindow", "Export Deck", 0));
        actionExport_Deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionNew_Deck->setText(QApplication::translate("MainWindow", "New Deck", 0));
        actionNew_Deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen_a_deck->setText(QApplication::translate("MainWindow", "Open a deck", 0));
        actionOpen_a_deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionClose_deck->setText(QApplication::translate("MainWindow", "Close deck", 0));
        actionClose_deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletRechercheCarte), QApplication::translate("MainWindow", "Library search", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletRechercheCrypte), QApplication::translate("MainWindow", "Crypt search", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletProba), QApplication::translate("MainWindow", "Deck View", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletGoldFish), QApplication::translate("MainWindow", "Playground", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Files", 0));
        menuParam_trages->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

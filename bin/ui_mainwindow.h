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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *FrameVisuel;
    QLabel *VisuelDeck;
    QLabel *VisuelCrypt;
    QLabel *VisuelCarte;
    QTabWidget *tabEditorModule;
    QWidget *OngletRechercheCarte;
    QWidget *OngletRechercheCrypte;
    QWidget *OngletGoldFish;
    QWidget *OngletProba;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuParam_trages;
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        FrameVisuel = new QFrame(centralWidget);
        FrameVisuel->setObjectName(QStringLiteral("FrameVisuel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrameVisuel->sizePolicy().hasHeightForWidth());
        FrameVisuel->setSizePolicy(sizePolicy);
        FrameVisuel->setMinimumSize(QSize(360, 500));
        FrameVisuel->setMaximumSize(QSize(360, 5000));
        FrameVisuel->setFrameShape(QFrame::Box);
        FrameVisuel->setFrameShadow(QFrame::Raised);
        FrameVisuel->setLineWidth(0);
        VisuelDeck = new QLabel(FrameVisuel);
        VisuelDeck->setObjectName(QStringLiteral("VisuelDeck"));
        VisuelDeck->setGeometry(QRect(3, 3, 360, 500));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(VisuelDeck->sizePolicy().hasHeightForWidth());
        VisuelDeck->setSizePolicy(sizePolicy1);
        VisuelDeck->setMinimumSize(QSize(360, 500));
        VisuelDeck->setMaximumSize(QSize(360, 500));
        VisuelDeck->setLineWidth(0);
        VisuelCrypt = new QLabel(FrameVisuel);
        VisuelCrypt->setObjectName(QStringLiteral("VisuelCrypt"));
        VisuelCrypt->setGeometry(QRect(3, 3, 360, 500));
        sizePolicy1.setHeightForWidth(VisuelCrypt->sizePolicy().hasHeightForWidth());
        VisuelCrypt->setSizePolicy(sizePolicy1);
        VisuelCrypt->setMinimumSize(QSize(360, 500));
        VisuelCrypt->setMaximumSize(QSize(360, 500));
        VisuelCrypt->setFrameShape(QFrame::StyledPanel);
        VisuelCrypt->setFrameShadow(QFrame::Sunken);
        VisuelCrypt->setLineWidth(0);
        VisuelCrypt->setPixmap(QPixmap(QString::fromUtf8("../../../../jr/Desktop/Vtes_Grelarge.gif")));
        VisuelCarte = new QLabel(FrameVisuel);
        VisuelCarte->setObjectName(QStringLiteral("VisuelCarte"));
        VisuelCarte->setGeometry(QRect(3, 3, 360, 500));
        sizePolicy1.setHeightForWidth(VisuelCarte->sizePolicy().hasHeightForWidth());
        VisuelCarte->setSizePolicy(sizePolicy1);
        VisuelCarte->setMinimumSize(QSize(360, 500));
        VisuelCarte->setMaximumSize(QSize(360, 500));
        VisuelCarte->setFrameShape(QFrame::StyledPanel);
        VisuelCarte->setFrameShadow(QFrame::Sunken);
        VisuelCarte->setLineWidth(0);
        VisuelCarte->setPixmap(QPixmap(QString::fromUtf8("../../../../jr/Desktop/Vtes_Grelarge.gif")));

        gridLayout->addWidget(FrameVisuel, 0, 0, 1, 1);

        tabEditorModule = new QTabWidget(centralWidget);
        tabEditorModule->setObjectName(QStringLiteral("tabEditorModule"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabEditorModule->sizePolicy().hasHeightForWidth());
        tabEditorModule->setSizePolicy(sizePolicy2);
        tabEditorModule->setAutoFillBackground(false);
        tabEditorModule->setStyleSheet(QStringLiteral(""));
        tabEditorModule->setTabPosition(QTabWidget::North);
        tabEditorModule->setTabShape(QTabWidget::Rounded);
        tabEditorModule->setDocumentMode(false);
        OngletRechercheCarte = new QWidget();
        OngletRechercheCarte->setObjectName(QStringLiteral("OngletRechercheCarte"));
        tabEditorModule->addTab(OngletRechercheCarte, QString());
        OngletRechercheCrypte = new QWidget();
        OngletRechercheCrypte->setObjectName(QStringLiteral("OngletRechercheCrypte"));
        tabEditorModule->addTab(OngletRechercheCrypte, QString());
        OngletGoldFish = new QWidget();
        OngletGoldFish->setObjectName(QStringLiteral("OngletGoldFish"));
        tabEditorModule->addTab(OngletGoldFish, QString());
        OngletProba = new QWidget();
        OngletProba->setObjectName(QStringLiteral("OngletProba"));
        tabEditorModule->addTab(OngletProba, QString());

        gridLayout->addWidget(tabEditorModule, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1680, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuParam_trages = new QMenu(menuBar);
        menuParam_trages->setObjectName(QStringLiteral("menuParam_trages"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuParam_trages->menuAction());
        menuFichier->addAction(actionEnregistrer_le_Deck);
        menuFichier->addAction(actionImprimer_le_Deck);
        menuParam_trages->addAction(actionOptions);

        retranslateUi(MainWindow);

        tabEditorModule->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vampire, the eternal deck builder", 0));
        actionEnregistrer_le_Deck->setText(QApplication::translate("MainWindow", "Enregistrer le Deck", 0));
        actionEnregistrer_le_Deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionImprimer_le_Deck->setText(QApplication::translate("MainWindow", "Imprimer le Deck", 0));
        actionImprimer_le_Deck->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0));
        VisuelDeck->setText(QString());
        VisuelCrypt->setText(QString());
        VisuelCarte->setText(QString());
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletRechercheCarte), QApplication::translate("MainWindow", "Recherche Carte", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletRechercheCrypte), QApplication::translate("MainWindow", "Recherche Crypte", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletGoldFish), QApplication::translate("MainWindow", "Gold Fish", 0));
        tabEditorModule->setTabText(tabEditorModule->indexOf(OngletProba), QApplication::translate("MainWindow", "Atelier Probabilit\303\251s", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuParam_trages->setTitle(QApplication::translate("MainWindow", "Param\303\250trages", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

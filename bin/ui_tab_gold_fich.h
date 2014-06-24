/********************************************************************************
** Form generated from reading UI file 'tab_gold_fich.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_GOLD_FICH_H
#define UI_TAB_GOLD_FICH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "playground.h"

QT_BEGIN_NAMESPACE

class Ui_tab_gold_fich
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFrame *TopBoard;
    QHBoxLayout *horizontalLayout;
    QFrame *MainFrame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *GameBoard;
    QVBoxLayout *verticalLayout_3;
    PGraphicsView *TabledeJeu;
    QGraphicsView *HandView;
    QFrame *SideBoard;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QScrollArea *tab_gold_fich)
    {
        if (tab_gold_fich->objectName().isEmpty())
            tab_gold_fich->setObjectName(QStringLiteral("tab_gold_fich"));
        tab_gold_fich->resize(1111, 797);
        tab_gold_fich->setFrameShape(QFrame::NoFrame);
        tab_gold_fich->setFrameShadow(QFrame::Plain);
        tab_gold_fich->setLineWidth(0);
        tab_gold_fich->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1111, 797));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TopBoard = new QFrame(scrollAreaWidgetContents);
        TopBoard->setObjectName(QStringLiteral("TopBoard"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TopBoard->sizePolicy().hasHeightForWidth());
        TopBoard->setSizePolicy(sizePolicy);
        TopBoard->setMinimumSize(QSize(0, 140));
        TopBoard->setMaximumSize(QSize(16777215, 140));
        TopBoard->setFrameShape(QFrame::NoFrame);
        TopBoard->setFrameShadow(QFrame::Plain);
        TopBoard->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(TopBoard);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(TopBoard);

        MainFrame = new QFrame(scrollAreaWidgetContents);
        MainFrame->setObjectName(QStringLiteral("MainFrame"));
        MainFrame->setFrameShape(QFrame::NoFrame);
        MainFrame->setFrameShadow(QFrame::Plain);
        MainFrame->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(MainFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        GameBoard = new QFrame(MainFrame);
        GameBoard->setObjectName(QStringLiteral("GameBoard"));
        GameBoard->setFrameShape(QFrame::NoFrame);
        GameBoard->setFrameShadow(QFrame::Plain);
        GameBoard->setLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(GameBoard);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        TabledeJeu = new PGraphicsView(GameBoard);
        TabledeJeu->setObjectName(QStringLiteral("TabledeJeu"));
        TabledeJeu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TabledeJeu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_3->addWidget(TabledeJeu);

        HandView = new QGraphicsView(GameBoard);
        HandView->setObjectName(QStringLiteral("HandView"));
        HandView->setMinimumSize(QSize(0, 150));
        HandView->setMaximumSize(QSize(16777215, 300));
        QBrush brush(QColor(170, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        HandView->setBackgroundBrush(brush);

        verticalLayout_3->addWidget(HandView);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addWidget(GameBoard);

        SideBoard = new QFrame(MainFrame);
        SideBoard->setObjectName(QStringLiteral("SideBoard"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SideBoard->sizePolicy().hasHeightForWidth());
        SideBoard->setSizePolicy(sizePolicy1);
        SideBoard->setMinimumSize(QSize(250, 0));
        SideBoard->setMaximumSize(QSize(250, 16777215));
        SideBoard->setFrameShape(QFrame::NoFrame);
        SideBoard->setFrameShadow(QFrame::Plain);
        SideBoard->setLineWidth(0);
        verticalLayout_2 = new QVBoxLayout(SideBoard);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_2->addWidget(SideBoard);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(MainFrame);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        tab_gold_fich->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_gold_fich);

        QMetaObject::connectSlotsByName(tab_gold_fich);
    } // setupUi

    void retranslateUi(QScrollArea *tab_gold_fich)
    {
        tab_gold_fich->setWindowTitle(QApplication::translate("tab_gold_fich", "ScrollArea", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_gold_fich: public Ui_tab_gold_fich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_GOLD_FICH_H

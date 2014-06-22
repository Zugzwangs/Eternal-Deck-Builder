/********************************************************************************
** Form generated from reading UI file 'tab_gold_fich.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
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
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    PGraphicsView *TabledeJeu;
    QFrame *SideBoard;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pBRestartGame;
    QPushButton *pBOpenDeck;
    QPushButton *pBdrawLibrary;

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
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TopBoard = new QFrame(scrollAreaWidgetContents);
        TopBoard->setObjectName(QStringLiteral("TopBoard"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TopBoard->sizePolicy().hasHeightForWidth());
        TopBoard->setSizePolicy(sizePolicy);
        TopBoard->setMinimumSize(QSize(0, 160));
        TopBoard->setMaximumSize(QSize(16777215, 160));
        TopBoard->setFrameShape(QFrame::StyledPanel);
        TopBoard->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(TopBoard);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(TopBoard);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TabledeJeu = new PGraphicsView(frame);
        TabledeJeu->setObjectName(QStringLiteral("TabledeJeu"));

        horizontalLayout_2->addWidget(TabledeJeu);

        SideBoard = new QFrame(frame);
        SideBoard->setObjectName(QStringLiteral("SideBoard"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SideBoard->sizePolicy().hasHeightForWidth());
        SideBoard->setSizePolicy(sizePolicy1);
        SideBoard->setMinimumSize(QSize(200, 0));
        SideBoard->setMaximumSize(QSize(200, 16777215));
        SideBoard->setFrameShape(QFrame::StyledPanel);
        SideBoard->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(SideBoard);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pBRestartGame = new QPushButton(SideBoard);
        pBRestartGame->setObjectName(QStringLiteral("pBRestartGame"));

        verticalLayout_2->addWidget(pBRestartGame);

        pBOpenDeck = new QPushButton(SideBoard);
        pBOpenDeck->setObjectName(QStringLiteral("pBOpenDeck"));

        verticalLayout_2->addWidget(pBOpenDeck);

        pBdrawLibrary = new QPushButton(SideBoard);
        pBdrawLibrary->setObjectName(QStringLiteral("pBdrawLibrary"));

        verticalLayout_2->addWidget(pBdrawLibrary);


        horizontalLayout_2->addWidget(SideBoard);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(frame);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        tab_gold_fich->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_gold_fich);

        QMetaObject::connectSlotsByName(tab_gold_fich);
    } // setupUi

    void retranslateUi(QScrollArea *tab_gold_fich)
    {
        tab_gold_fich->setWindowTitle(QApplication::translate("tab_gold_fich", "ScrollArea", 0));
        pBRestartGame->setText(QApplication::translate("tab_gold_fich", "restart game", 0));
        pBOpenDeck->setText(QApplication::translate("tab_gold_fich", "Open deck", 0));
        pBdrawLibrary->setText(QApplication::translate("tab_gold_fich", "draw library", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_gold_fich: public Ui_tab_gold_fich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_GOLD_FICH_H

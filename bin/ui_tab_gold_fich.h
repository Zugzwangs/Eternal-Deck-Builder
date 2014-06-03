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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    PGraphicsView *TabledeJeu;
    QFrame *SideBoard;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QScrollArea *tab_gold_fich)
    {
        if (tab_gold_fich->objectName().isEmpty())
            tab_gold_fich->setObjectName(QStringLiteral("tab_gold_fich"));
        tab_gold_fich->resize(1111, 797);
        tab_gold_fich->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1109, 795));
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
        TopBoard->setMinimumSize(QSize(0, 200));
        TopBoard->setMaximumSize(QSize(16777215, 200));
        TopBoard->setFrameShape(QFrame::StyledPanel);
        TopBoard->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(TopBoard);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


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
    } // retranslateUi

};

namespace Ui {
    class tab_gold_fich: public Ui_tab_gold_fich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_GOLD_FICH_H

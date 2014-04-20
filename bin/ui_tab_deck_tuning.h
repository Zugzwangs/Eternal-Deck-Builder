/********************************************************************************
** Form generated from reading UI file 'tab_deck_tuning.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_DECK_TUNING_H
#define UI_TAB_DECK_TUNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include "pitemview.h"

QT_BEGIN_NAMESPACE

class Ui_tab_deck_tuning
{
public:
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    PTreeView *PTreeViewDeckList;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *VisuelDeck;

    void setupUi(QScrollArea *tab_deck_tuning)
    {
        if (tab_deck_tuning->objectName().isEmpty())
            tab_deck_tuning->setObjectName(QStringLiteral("tab_deck_tuning"));
        tab_deck_tuning->resize(1426, 926);
        tab_deck_tuning->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1424, 924));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PTreeViewDeckList = new PTreeView(scrollAreaWidgetContents);
        PTreeViewDeckList->setObjectName(QStringLiteral("PTreeViewDeckList"));
        PTreeViewDeckList->setMinimumSize(QSize(200, 0));
        PTreeViewDeckList->setMaximumSize(QSize(450, 16777215));

        horizontalLayout->addWidget(PTreeViewDeckList);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        VisuelDeck = new QLabel(frame);
        VisuelDeck->setObjectName(QStringLiteral("VisuelDeck"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VisuelDeck->sizePolicy().hasHeightForWidth());
        VisuelDeck->setSizePolicy(sizePolicy);
        VisuelDeck->setMinimumSize(QSize(360, 500));
        VisuelDeck->setMaximumSize(QSize(360, 500));
        VisuelDeck->setLineWidth(0);

        gridLayout->addWidget(VisuelDeck, 0, 0, 1, 1);


        horizontalLayout->addWidget(frame);

        tab_deck_tuning->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_deck_tuning);

        QMetaObject::connectSlotsByName(tab_deck_tuning);
    } // setupUi

    void retranslateUi(QScrollArea *tab_deck_tuning)
    {
        tab_deck_tuning->setWindowTitle(QApplication::translate("tab_deck_tuning", "ScrollArea", 0));
        VisuelDeck->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tab_deck_tuning: public Ui_tab_deck_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DECK_TUNING_H

/********************************************************************************
** Form generated from reading UI file 'tab_deck_tuning.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
    QFrame *frame_2;
    QLabel *label_4;
    QFrame *frame_3;
    QLabel *label_3;
    QFrame *frame_4;
    QLabel *label;
    QFrame *frame_5;

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
        PTreeViewDeckList->setSelectionBehavior(QAbstractItemView::SelectItems);
        PTreeViewDeckList->setHeaderHidden(true);
        PTreeViewDeckList->header()->setVisible(false);
        PTreeViewDeckList->header()->setStretchLastSection(true);

        horizontalLayout->addWidget(PTreeViewDeckList);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(200, 200));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 150, 301, 61));

        gridLayout->addWidget(frame_2, 1, 1, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(200, 200));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 160, 331, 41));

        gridLayout->addWidget(frame_3, 1, 0, 1, 1);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(200, 200));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 170, 231, 71));

        gridLayout->addWidget(frame_4, 0, 0, 1, 1);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(350, 350));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_5, 0, 1, 1, 1);


        horizontalLayout->addWidget(frame);

        tab_deck_tuning->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_deck_tuning);

        QMetaObject::connectSlotsByName(tab_deck_tuning);
    } // setupUi

    void retranslateUi(QScrollArea *tab_deck_tuning)
    {
        tab_deck_tuning->setWindowTitle(QApplication::translate("tab_deck_tuning", "ScrollArea", 0));
        label_4->setText(QApplication::translate("tab_deck_tuning", "je sais pas quoi qui manque encore ", 0));
        label_3->setText(QApplication::translate("tab_deck_tuning", "Tirage de main et de sortie de crypt vers onglet 4 ??", 0));
        label->setText(QApplication::translate("tab_deck_tuning", "courbe de crypt (diagramme)", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_deck_tuning: public Ui_tab_deck_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DECK_TUNING_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mvddeck.h"

QT_BEGIN_NAMESPACE

class Ui_tab_deck_tuning
{
public:
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    PTreeView *PTreeViewDeckList;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QFrame *frame_3;

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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setMinimumSize(QSize(0, 130));
        frame_2->setMaximumSize(QSize(16777215, 130));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(419, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        textEdit = new QTextEdit(frame_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 2, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(419, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_3);


        horizontalLayout->addWidget(frame);

        tab_deck_tuning->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_deck_tuning);

        QMetaObject::connectSlotsByName(tab_deck_tuning);
    } // setupUi

    void retranslateUi(QScrollArea *tab_deck_tuning)
    {
        tab_deck_tuning->setWindowTitle(QApplication::translate("tab_deck_tuning", "ScrollArea", 0));
        label->setText(QApplication::translate("tab_deck_tuning", "Name", 0));
        label_2->setText(QApplication::translate("tab_deck_tuning", "Description", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_deck_tuning: public Ui_tab_deck_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DECK_TUNING_H

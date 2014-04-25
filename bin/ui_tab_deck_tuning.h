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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QFrame *frame_meta;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lE_author;
    QLineEdit *lE_name;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lE_description;
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
        horizontalLayout->setContentsMargins(7, 7, 7, 7);
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
        verticalLayout->setContentsMargins(10, 0, 10, 0);
        frame_meta = new QFrame(frame);
        frame_meta->setObjectName(QStringLiteral("frame_meta"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_meta->sizePolicy().hasHeightForWidth());
        frame_meta->setSizePolicy(sizePolicy1);
        frame_meta->setMinimumSize(QSize(0, 130));
        frame_meta->setMaximumSize(QSize(16777215, 130));
        frame_meta->setFrameShape(QFrame::StyledPanel);
        frame_meta->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_meta);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame_meta);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        lE_author = new QLineEdit(frame_meta);
        lE_author->setObjectName(QStringLiteral("lE_author"));

        gridLayout->addWidget(lE_author, 0, 4, 1, 1);

        lE_name = new QLineEdit(frame_meta);
        lE_name->setObjectName(QStringLiteral("lE_name"));

        gridLayout->addWidget(lE_name, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(419, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        label = new QLabel(frame_meta);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(419, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 5, 1, 1);

        label_2 = new QLabel(frame_meta);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lE_description = new QLineEdit(frame_meta);
        lE_description->setObjectName(QStringLiteral("lE_description"));

        gridLayout->addWidget(lE_description, 1, 2, 1, 3);


        verticalLayout->addWidget(frame_meta);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(0);

        verticalLayout->addWidget(frame_3);


        horizontalLayout->addWidget(frame);

        tab_deck_tuning->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_deck_tuning);

        QMetaObject::connectSlotsByName(tab_deck_tuning);
    } // setupUi

    void retranslateUi(QScrollArea *tab_deck_tuning)
    {
        tab_deck_tuning->setWindowTitle(QApplication::translate("tab_deck_tuning", "ScrollArea", 0));
        label_3->setText(QApplication::translate("tab_deck_tuning", "author", 0));
        label->setText(QApplication::translate("tab_deck_tuning", "Name", 0));
        label_2->setText(QApplication::translate("tab_deck_tuning", "Description", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_deck_tuning: public Ui_tab_deck_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DECK_TUNING_H

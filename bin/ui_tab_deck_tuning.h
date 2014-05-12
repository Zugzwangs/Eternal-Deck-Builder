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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mvddeck.h"

QT_BEGIN_NAMESPACE

class Ui_tab_deck_tuning
{
public:
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    PTreeView *PTreeViewDeckList;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_meta;
    QGridLayout *gridLayout;
    QComboBox *cBFormat;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lE_author;
    QLineEdit *lE_name;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lE_description;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tab_details;
    QWidget *tab_crypt;
    QFrame *frameCrypt;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_library;
    QFrame *frameLibrary;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *tab_overView;
    QFrame *frameOverView;
    QGridLayout *gridLayout_2;

    void setupUi(QScrollArea *tab_deck_tuning)
    {
        if (tab_deck_tuning->objectName().isEmpty())
            tab_deck_tuning->setObjectName(QStringLiteral("tab_deck_tuning"));
        tab_deck_tuning->resize(1426, 926);
        tab_deck_tuning->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1424, 924));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(7, 7, 7, 7);
        PTreeViewDeckList = new PTreeView(scrollAreaWidgetContents);
        PTreeViewDeckList->setObjectName(QStringLiteral("PTreeViewDeckList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PTreeViewDeckList->sizePolicy().hasHeightForWidth());
        PTreeViewDeckList->setSizePolicy(sizePolicy);
        PTreeViewDeckList->setMinimumSize(QSize(450, 0));
        PTreeViewDeckList->setMaximumSize(QSize(450, 16777215));
        PTreeViewDeckList->setSelectionBehavior(QAbstractItemView::SelectItems);
        PTreeViewDeckList->setHeaderHidden(true);
        PTreeViewDeckList->header()->setVisible(false);
        PTreeViewDeckList->header()->setStretchLastSection(true);

        gridLayout_3->addWidget(PTreeViewDeckList, 0, 0, 1, 1);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 0, 10, 0);
        frame_meta = new QFrame(frame);
        frame_meta->setObjectName(QStringLiteral("frame_meta"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_meta->sizePolicy().hasHeightForWidth());
        frame_meta->setSizePolicy(sizePolicy2);
        frame_meta->setMinimumSize(QSize(0, 130));
        frame_meta->setMaximumSize(QSize(16777215, 130));
        frame_meta->setFrameShape(QFrame::StyledPanel);
        frame_meta->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_meta);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cBFormat = new QComboBox(frame_meta);
        cBFormat->setObjectName(QStringLiteral("cBFormat"));
        cBFormat->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(cBFormat, 0, 6, 1, 1);

        label_4 = new QLabel(frame_meta);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 5, 1, 1);

        label_5 = new QLabel(frame_meta);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 5, 1, 1);

        lE_author = new QLineEdit(frame_meta);
        lE_author->setObjectName(QStringLiteral("lE_author"));

        gridLayout->addWidget(lE_author, 0, 4, 1, 1);

        lE_name = new QLineEdit(frame_meta);
        lE_name->setObjectName(QStringLiteral("lE_name"));

        gridLayout->addWidget(lE_name, 0, 2, 1, 1);

        label_3 = new QLabel(frame_meta);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label = new QLabel(frame_meta);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(frame_meta);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lE_description = new QLineEdit(frame_meta);
        lE_description->setObjectName(QStringLiteral("lE_description"));

        gridLayout->addWidget(lE_description, 1, 2, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);


        verticalLayout->addWidget(frame_meta);

        tab_details = new QTabWidget(frame);
        tab_details->setObjectName(QStringLiteral("tab_details"));
        tab_details->setTabPosition(QTabWidget::North);
        tab_details->setTabShape(QTabWidget::Rounded);
        tab_details->setElideMode(Qt::ElideNone);
        tab_details->setUsesScrollButtons(true);
        tab_details->setDocumentMode(false);
        tab_crypt = new QWidget();
        tab_crypt->setObjectName(QStringLiteral("tab_crypt"));
        frameCrypt = new QFrame(tab_crypt);
        frameCrypt->setObjectName(QStringLiteral("frameCrypt"));
        frameCrypt->setGeometry(QRect(20, 20, 871, 671));
        frameCrypt->setFrameShape(QFrame::StyledPanel);
        frameCrypt->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameCrypt);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tab_details->addTab(tab_crypt, QString());
        tab_library = new QWidget();
        tab_library->setObjectName(QStringLiteral("tab_library"));
        frameLibrary = new QFrame(tab_library);
        frameLibrary->setObjectName(QStringLiteral("frameLibrary"));
        frameLibrary->setGeometry(QRect(20, 20, 881, 651));
        frameLibrary->setFrameShape(QFrame::StyledPanel);
        frameLibrary->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameLibrary);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tab_details->addTab(tab_library, QString());
        tab_overView = new QWidget();
        tab_overView->setObjectName(QStringLiteral("tab_overView"));
        frameOverView = new QFrame(tab_overView);
        frameOverView->setObjectName(QStringLiteral("frameOverView"));
        frameOverView->setGeometry(QRect(50, 40, 731, 511));
        sizePolicy1.setHeightForWidth(frameOverView->sizePolicy().hasHeightForWidth());
        frameOverView->setSizePolicy(sizePolicy1);
        frameOverView->setFrameShape(QFrame::NoFrame);
        frameOverView->setFrameShadow(QFrame::Plain);
        frameOverView->setLineWidth(0);
        gridLayout_2 = new QGridLayout(frameOverView);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tab_details->addTab(tab_overView, QString());

        verticalLayout->addWidget(tab_details);


        gridLayout_3->addWidget(frame, 0, 1, 1, 1);

        tab_deck_tuning->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_deck_tuning);

        tab_details->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(tab_deck_tuning);
    } // setupUi

    void retranslateUi(QScrollArea *tab_deck_tuning)
    {
        tab_deck_tuning->setWindowTitle(QApplication::translate("tab_deck_tuning", "ScrollArea", 0));
        label_4->setText(QApplication::translate("tab_deck_tuning", "Format", 0));
        label_5->setText(QApplication::translate("tab_deck_tuning", "rating", 0));
        label_3->setText(QApplication::translate("tab_deck_tuning", "author", 0));
        label->setText(QApplication::translate("tab_deck_tuning", "Name", 0));
        label_2->setText(QApplication::translate("tab_deck_tuning", "Description", 0));
        tab_details->setTabText(tab_details->indexOf(tab_crypt), QApplication::translate("tab_deck_tuning", "Crypt details", 0));
        tab_details->setTabText(tab_details->indexOf(tab_library), QApplication::translate("tab_deck_tuning", "Library details", 0));
        tab_details->setTabText(tab_details->indexOf(tab_overView), QApplication::translate("tab_deck_tuning", "OverView", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_deck_tuning: public Ui_tab_deck_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DECK_TUNING_H

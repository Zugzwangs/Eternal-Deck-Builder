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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mvddeck.h"

QT_BEGIN_NAMESPACE

class Ui_tab_deck_tuning
{
public:
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    PTreeView *PTreeViewDeckList;
    QTabWidget *tab_details;
    QWidget *tab_overView;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_meta;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_refs;
    QGridLayout *gridLayout;
    QLineEdit *lE_author;
    QLabel *label_3;
    QLineEdit *lE_name;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QComboBox *cBFormat;
    QPlainTextEdit *pT_summary;
    QFrame *frame_results;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *sB_gw;
    QSpinBox *sB_vp;
    QSpinBox *sB_tw;
    QSpinBox *sB_gp;
    QFrame *frame_viped;
    QVBoxLayout *verticalLayout_4;
    QFrame *frameOverView;
    QGridLayout *gridLayout_2;
    QWidget *tab_crypt;
    QVBoxLayout *verticalLayout;
    QFrame *disciplineCrypt;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QFrame *frameCrypt;
    QVBoxLayout *verticalLayout_3;
    QWidget *tab_library;
    QVBoxLayout *verticalLayout_6;
    QFrame *disciplineLibrary;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QFrame *frameLibrary;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QScrollArea *tab_deck_tuning)
    {
        if (tab_deck_tuning->objectName().isEmpty())
            tab_deck_tuning->setObjectName(QStringLiteral("tab_deck_tuning"));
        tab_deck_tuning->resize(1426, 926);
        tab_deck_tuning->setFrameShape(QFrame::NoFrame);
        tab_deck_tuning->setFrameShadow(QFrame::Plain);
        tab_deck_tuning->setLineWidth(0);
        tab_deck_tuning->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1605, 905));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
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

        horizontalLayout_2->addWidget(PTreeViewDeckList);

        tab_details = new QTabWidget(scrollAreaWidgetContents);
        tab_details->setObjectName(QStringLiteral("tab_details"));
        tab_details->setTabPosition(QTabWidget::North);
        tab_details->setTabShape(QTabWidget::Rounded);
        tab_details->setElideMode(Qt::ElideNone);
        tab_details->setUsesScrollButtons(true);
        tab_details->setDocumentMode(false);
        tab_overView = new QWidget();
        tab_overView->setObjectName(QStringLiteral("tab_overView"));
        verticalLayout_5 = new QVBoxLayout(tab_overView);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 10, 0, 0);
        frame_meta = new QFrame(tab_overView);
        frame_meta->setObjectName(QStringLiteral("frame_meta"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_meta->sizePolicy().hasHeightForWidth());
        frame_meta->setSizePolicy(sizePolicy1);
        frame_meta->setMinimumSize(QSize(0, 160));
        frame_meta->setMaximumSize(QSize(16777215, 160));
        frame_meta->setFrameShape(QFrame::StyledPanel);
        frame_meta->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_meta);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 20, 0);
        frame_refs = new QFrame(frame_meta);
        frame_refs->setObjectName(QStringLiteral("frame_refs"));
        frame_refs->setFrameShape(QFrame::StyledPanel);
        frame_refs->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_refs);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        lE_author = new QLineEdit(frame_refs);
        lE_author->setObjectName(QStringLiteral("lE_author"));
        lE_author->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lE_author, 0, 3, 1, 1);

        label_3 = new QLabel(frame_refs);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        lE_name = new QLineEdit(frame_refs);
        lE_name->setObjectName(QStringLiteral("lE_name"));
        lE_name->setMinimumSize(QSize(200, 0));
        lE_name->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lE_name, 0, 1, 1, 1);

        label_4 = new QLabel(frame_refs);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        label = new QLabel(frame_refs);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(frame_refs);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        cBFormat = new QComboBox(frame_refs);
        cBFormat->setObjectName(QStringLiteral("cBFormat"));
        cBFormat->setMinimumSize(QSize(100, 0));
        cBFormat->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(cBFormat, 0, 5, 1, 1);

        pT_summary = new QPlainTextEdit(frame_refs);
        pT_summary->setObjectName(QStringLiteral("pT_summary"));

        gridLayout->addWidget(pT_summary, 2, 1, 1, 5);


        horizontalLayout->addWidget(frame_refs);

        frame_results = new QFrame(frame_meta);
        frame_results->setObjectName(QStringLiteral("frame_results"));
        frame_results->setMinimumSize(QSize(180, 0));
        frame_results->setFrameShape(QFrame::StyledPanel);
        frame_results->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_results);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(-1, 5, -1, 5);
        label_5 = new QLabel(frame_results);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_5);

        label_6 = new QLabel(frame_results);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_6);

        label_7 = new QLabel(frame_results);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_7);

        label_8 = new QLabel(frame_results);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_8);

        label_9 = new QLabel(frame_results);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_9);

        sB_gw = new QSpinBox(frame_results);
        sB_gw->setObjectName(QStringLiteral("sB_gw"));

        formLayout->setWidget(1, QFormLayout::LabelRole, sB_gw);

        sB_vp = new QSpinBox(frame_results);
        sB_vp->setObjectName(QStringLiteral("sB_vp"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sB_vp);

        sB_tw = new QSpinBox(frame_results);
        sB_tw->setObjectName(QStringLiteral("sB_tw"));

        formLayout->setWidget(3, QFormLayout::LabelRole, sB_tw);

        sB_gp = new QSpinBox(frame_results);
        sB_gp->setObjectName(QStringLiteral("sB_gp"));

        formLayout->setWidget(4, QFormLayout::LabelRole, sB_gp);


        horizontalLayout->addWidget(frame_results);

        frame_viped = new QFrame(frame_meta);
        frame_viped->setObjectName(QStringLiteral("frame_viped"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_viped->sizePolicy().hasHeightForWidth());
        frame_viped->setSizePolicy(sizePolicy2);
        frame_viped->setMinimumSize(QSize(240, 100));
        frame_viped->setAutoFillBackground(false);
        frame_viped->setFrameShape(QFrame::NoFrame);
        frame_viped->setFrameShadow(QFrame::Plain);
        frame_viped->setLineWidth(0);
        verticalLayout_4 = new QVBoxLayout(frame_viped);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_viped);


        verticalLayout_5->addWidget(frame_meta);

        frameOverView = new QFrame(tab_overView);
        frameOverView->setObjectName(QStringLiteral("frameOverView"));
        sizePolicy2.setHeightForWidth(frameOverView->sizePolicy().hasHeightForWidth());
        frameOverView->setSizePolicy(sizePolicy2);
        frameOverView->setFrameShape(QFrame::NoFrame);
        frameOverView->setFrameShadow(QFrame::Plain);
        frameOverView->setLineWidth(0);
        gridLayout_2 = new QGridLayout(frameOverView);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        verticalLayout_5->addWidget(frameOverView);

        tab_details->addTab(tab_overView, QString());
        frameOverView->raise();
        frame_meta->raise();
        tab_crypt = new QWidget();
        tab_crypt->setObjectName(QStringLiteral("tab_crypt"));
        verticalLayout = new QVBoxLayout(tab_crypt);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        disciplineCrypt = new QFrame(tab_crypt);
        disciplineCrypt->setObjectName(QStringLiteral("disciplineCrypt"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(disciplineCrypt->sizePolicy().hasHeightForWidth());
        disciplineCrypt->setSizePolicy(sizePolicy3);
        disciplineCrypt->setMinimumSize(QSize(0, 260));
        disciplineCrypt->setMaximumSize(QSize(16777215, 400));
        disciplineCrypt->setFrameShape(QFrame::StyledPanel);
        disciplineCrypt->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(disciplineCrypt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 373, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);


        verticalLayout->addWidget(disciplineCrypt);

        frameCrypt = new QFrame(tab_crypt);
        frameCrypt->setObjectName(QStringLiteral("frameCrypt"));
        frameCrypt->setFrameShape(QFrame::StyledPanel);
        frameCrypt->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameCrypt);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(frameCrypt);

        tab_details->addTab(tab_crypt, QString());
        tab_library = new QWidget();
        tab_library->setObjectName(QStringLiteral("tab_library"));
        verticalLayout_6 = new QVBoxLayout(tab_library);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        disciplineLibrary = new QFrame(tab_library);
        disciplineLibrary->setObjectName(QStringLiteral("disciplineLibrary"));
        sizePolicy3.setHeightForWidth(disciplineLibrary->sizePolicy().hasHeightForWidth());
        disciplineLibrary->setSizePolicy(sizePolicy3);
        disciplineLibrary->setMinimumSize(QSize(0, 170));
        disciplineLibrary->setMaximumSize(QSize(16777215, 400));
        disciplineLibrary->setFrameShape(QFrame::StyledPanel);
        disciplineLibrary->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(disciplineLibrary);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 373, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 0, 0, 1, 1);


        verticalLayout_6->addWidget(disciplineLibrary);

        frameLibrary = new QFrame(tab_library);
        frameLibrary->setObjectName(QStringLiteral("frameLibrary"));
        frameLibrary->setFrameShape(QFrame::StyledPanel);
        frameLibrary->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameLibrary);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout_6->addWidget(frameLibrary);

        tab_details->addTab(tab_library, QString());

        horizontalLayout_2->addWidget(tab_details);

        tab_deck_tuning->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_deck_tuning);

        tab_details->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(tab_deck_tuning);
    } // setupUi

    void retranslateUi(QScrollArea *tab_deck_tuning)
    {
        tab_deck_tuning->setWindowTitle(QApplication::translate("tab_deck_tuning", "ScrollArea", 0));
        label_3->setText(QApplication::translate("tab_deck_tuning", "author", 0));
        label_4->setText(QApplication::translate("tab_deck_tuning", "Format", 0));
        label->setText(QApplication::translate("tab_deck_tuning", "Name", 0));
        label_2->setText(QApplication::translate("tab_deck_tuning", "Sum up", 0));
        label_5->setText(QApplication::translate("tab_deck_tuning", "Decks Results", 0));
        label_6->setText(QApplication::translate("tab_deck_tuning", "Game Win", 0));
        label_7->setText(QApplication::translate("tab_deck_tuning", "Victory points", 0));
        label_8->setText(QApplication::translate("tab_deck_tuning", "Tournament Win", 0));
        label_9->setText(QApplication::translate("tab_deck_tuning", "Games played", 0));
        tab_details->setTabText(tab_details->indexOf(tab_overView), QApplication::translate("tab_deck_tuning", "OverView", 0));
        tab_details->setTabText(tab_details->indexOf(tab_crypt), QApplication::translate("tab_deck_tuning", "Crypt details", 0));
        tab_details->setTabText(tab_details->indexOf(tab_library), QApplication::translate("tab_deck_tuning", "Library details", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_deck_tuning: public Ui_tab_deck_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DECK_TUNING_H

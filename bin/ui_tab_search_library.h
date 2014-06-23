/********************************************************************************
** Form generated from reading UI file 'tab_search_library.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_SEARCH_LIBRARY_H
#define UI_TAB_SEARCH_LIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mvddeck.h>
#include "Widgets/disciplinebutton.h"
#include "mvdbdd.h"

QT_BEGIN_NAMESPACE

class Ui_tab_search_library
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *CardSearchFrame;
    QGridLayout *gridLayout_8;
    QGroupBox *CardgroupBoxVirtues;
    QHBoxLayout *horizontalLayout_2;
    DisciplineButton *def;
    DisciplineButton *inn;
    DisciplineButton *jud;
    DisciplineButton *mar;
    DisciplineButton *red;
    DisciplineButton *ven;
    DisciplineButton *vis2;
    QGroupBox *CardgroupBoxFilters;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *cBSousType;
    QComboBox *cBType;
    QLabel *label_43;
    QGroupBox *CardgroupBoxGeneral;
    QGridLayout *gridLayout_7;
    QLabel *label_31;
    QLineEdit *lENameCard_2;
    QLabel *label_35;
    QLineEdit *lEArtist_2;
    QLabel *label_33;
    QLineEdit *lETextCard_2;
    QGroupBox *CardgroupBoxDiscipline;
    QGridLayout *gridLayout;
    DisciplineButton *qui;
    DisciplineButton *dom;
    DisciplineButton *obt;
    DisciplineButton *aus;
    DisciplineButton *pot;
    DisciplineButton *tem;
    DisciplineButton *nec;
    DisciplineButton *vic;
    DisciplineButton *cel;
    DisciplineButton *san;
    DisciplineButton *dem;
    DisciplineButton *myt;
    DisciplineButton *tha;
    DisciplineButton *vis;
    DisciplineButton *obe;
    DisciplineButton *for_2;
    DisciplineButton *dai;
    DisciplineButton *abo;
    DisciplineButton *ser;
    DisciplineButton *chi;
    DisciplineButton *pre;
    DisciplineButton *ani;
    DisciplineButton *obf;
    DisciplineButton *val;
    DisciplineButton *stri;
    DisciplineButton *pro;
    DisciplineButton *spi;
    DisciplineButton *thn;
    DisciplineButton *mel;
    DisciplineButton *mal;
    QGroupBox *CardgroupBoxRequirements;
    QGridLayout *gridLayout_4;
    QLabel *label_49;
    QComboBox *cBClan_2;
    QCheckBox *Anarch;
    QCheckBox *Flight;
    QLabel *lSect_2;
    QComboBox *cBSect_2;
    QCheckBox *RedList;
    QCheckBox *BlackHand;
    QLabel *lTitle_2;
    QComboBox *cBTitle_2;
    QCheckBox *Infernal;
    QCheckBox *Seraph;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLabel *label_47;
    QComboBox *cBSet;
    QLabel *label_45;
    QComboBox *cBRarity;
    QGroupBox *CardgroupBoxOthers;
    QGridLayout *gridLayout_3;
    QCheckBox *BurnOption;
    QCheckBox *Anarch_3_Way;
    QCheckBox *Dual_discipline;
    QCheckBox *Multi_discipline;
    QCheckBox *Boon;
    QCheckBox *Grapple;
    QCheckBox *Frenzy;
    QCheckBox *Aim;
    QGroupBox *CardgroupBoxCout;
    QGridLayout *gridLayout_5;
    QLabel *label_37;
    QComboBox *cBBloodCost;
    QSpinBox *sBBloodCost;
    QLabel *label_39;
    QComboBox *cBPoolCost;
    QSpinBox *sBPoolCost;
    QLabel *label_41;
    QComboBox *cBConvictionCost;
    QSpinBox *sBConvictionCost;
    QSpacerItem *horizontalSpacer_2;
    PartialDeckView *LibraryView;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pBCardSearch;
    QPushButton *pBCardClearForm;
    QPushButton *pBAddtoDeck;
    QLabel *VisuelCarte;
    QSpacerItem *verticalSpacer_3;
    PItemView *PTVCardsResults;

    void setupUi(QScrollArea *tab_search_library)
    {
        if (tab_search_library->objectName().isEmpty())
            tab_search_library->setObjectName(QStringLiteral("tab_search_library"));
        tab_search_library->resize(1815, 1213);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab_search_library->sizePolicy().hasHeightForWidth());
        tab_search_library->setSizePolicy(sizePolicy);
        tab_search_library->setFrameShape(QFrame::NoFrame);
        tab_search_library->setFrameShadow(QFrame::Plain);
        tab_search_library->setLineWidth(0);
        tab_search_library->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tab_search_library->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tab_search_library->setWidgetResizable(true);
        tab_search_library->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1815, 1213));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
        CardSearchFrame = new QFrame(frame_2);
        CardSearchFrame->setObjectName(QStringLiteral("CardSearchFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CardSearchFrame->sizePolicy().hasHeightForWidth());
        CardSearchFrame->setSizePolicy(sizePolicy1);
        CardSearchFrame->setMinimumSize(QSize(1350, 300));
        CardSearchFrame->setMaximumSize(QSize(1350, 300));
        CardSearchFrame->setFrameShape(QFrame::NoFrame);
        CardSearchFrame->setFrameShadow(QFrame::Plain);
        CardSearchFrame->setLineWidth(0);
        gridLayout_8 = new QGridLayout(CardSearchFrame);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        CardgroupBoxVirtues = new QGroupBox(CardSearchFrame);
        CardgroupBoxVirtues->setObjectName(QStringLiteral("CardgroupBoxVirtues"));
        horizontalLayout_2 = new QHBoxLayout(CardgroupBoxVirtues);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        def = new DisciplineButton(CardgroupBoxVirtues);
        def->setObjectName(QStringLiteral("def"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(def->sizePolicy().hasHeightForWidth());
        def->setSizePolicy(sizePolicy2);
        def->setMinimumSize(QSize(40, 40));
        def->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(def);

        inn = new DisciplineButton(CardgroupBoxVirtues);
        inn->setObjectName(QStringLiteral("inn"));
        sizePolicy2.setHeightForWidth(inn->sizePolicy().hasHeightForWidth());
        inn->setSizePolicy(sizePolicy2);
        inn->setMinimumSize(QSize(40, 40));
        inn->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(inn);

        jud = new DisciplineButton(CardgroupBoxVirtues);
        jud->setObjectName(QStringLiteral("jud"));
        sizePolicy2.setHeightForWidth(jud->sizePolicy().hasHeightForWidth());
        jud->setSizePolicy(sizePolicy2);
        jud->setMinimumSize(QSize(40, 40));
        jud->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(jud);

        mar = new DisciplineButton(CardgroupBoxVirtues);
        mar->setObjectName(QStringLiteral("mar"));
        sizePolicy2.setHeightForWidth(mar->sizePolicy().hasHeightForWidth());
        mar->setSizePolicy(sizePolicy2);
        mar->setMinimumSize(QSize(40, 40));
        mar->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(mar);

        red = new DisciplineButton(CardgroupBoxVirtues);
        red->setObjectName(QStringLiteral("red"));
        sizePolicy2.setHeightForWidth(red->sizePolicy().hasHeightForWidth());
        red->setSizePolicy(sizePolicy2);
        red->setMinimumSize(QSize(40, 40));
        red->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(red);

        ven = new DisciplineButton(CardgroupBoxVirtues);
        ven->setObjectName(QStringLiteral("ven"));
        sizePolicy2.setHeightForWidth(ven->sizePolicy().hasHeightForWidth());
        ven->setSizePolicy(sizePolicy2);
        ven->setMinimumSize(QSize(40, 40));
        ven->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(ven);

        vis2 = new DisciplineButton(CardgroupBoxVirtues);
        vis2->setObjectName(QStringLiteral("vis2"));
        sizePolicy2.setHeightForWidth(vis2->sizePolicy().hasHeightForWidth());
        vis2->setSizePolicy(sizePolicy2);
        vis2->setMinimumSize(QSize(40, 40));
        vis2->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(vis2);


        gridLayout_8->addWidget(CardgroupBoxVirtues, 2, 3, 1, 1);

        CardgroupBoxFilters = new QGroupBox(CardSearchFrame);
        CardgroupBoxFilters->setObjectName(QStringLiteral("CardgroupBoxFilters"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(CardgroupBoxFilters->sizePolicy().hasHeightForWidth());
        CardgroupBoxFilters->setSizePolicy(sizePolicy3);
        CardgroupBoxFilters->setMinimumSize(QSize(0, 100));
        CardgroupBoxFilters->setMaximumSize(QSize(16777215, 130));
        gridLayout_2 = new QGridLayout(CardgroupBoxFilters);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        label_4 = new QLabel(CardgroupBoxFilters);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        cBSousType = new QComboBox(CardgroupBoxFilters);
        cBSousType->setObjectName(QStringLiteral("cBSousType"));

        gridLayout_2->addWidget(cBSousType, 1, 1, 1, 1);

        cBType = new QComboBox(CardgroupBoxFilters);
        cBType->setObjectName(QStringLiteral("cBType"));

        gridLayout_2->addWidget(cBType, 0, 1, 1, 1);

        label_43 = new QLabel(CardgroupBoxFilters);
        label_43->setObjectName(QStringLiteral("label_43"));
        sizePolicy.setHeightForWidth(label_43->sizePolicy().hasHeightForWidth());
        label_43->setSizePolicy(sizePolicy);
        label_43->setLayoutDirection(Qt::LeftToRight);
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_43, 0, 0, 1, 1);


        gridLayout_8->addWidget(CardgroupBoxFilters, 0, 1, 1, 1);

        CardgroupBoxGeneral = new QGroupBox(CardSearchFrame);
        CardgroupBoxGeneral->setObjectName(QStringLiteral("CardgroupBoxGeneral"));
        sizePolicy3.setHeightForWidth(CardgroupBoxGeneral->sizePolicy().hasHeightForWidth());
        CardgroupBoxGeneral->setSizePolicy(sizePolicy3);
        CardgroupBoxGeneral->setMinimumSize(QSize(450, 100));
        CardgroupBoxGeneral->setMaximumSize(QSize(16777215, 130));
        gridLayout_7 = new QGridLayout(CardgroupBoxGeneral);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(5, 5, 5, 5);
        label_31 = new QLabel(CardgroupBoxGeneral);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_7->addWidget(label_31, 0, 0, 1, 1);

        lENameCard_2 = new QLineEdit(CardgroupBoxGeneral);
        lENameCard_2->setObjectName(QStringLiteral("lENameCard_2"));

        gridLayout_7->addWidget(lENameCard_2, 0, 1, 1, 1);

        label_35 = new QLabel(CardgroupBoxGeneral);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_7->addWidget(label_35, 0, 2, 1, 1);

        lEArtist_2 = new QLineEdit(CardgroupBoxGeneral);
        lEArtist_2->setObjectName(QStringLiteral("lEArtist_2"));

        gridLayout_7->addWidget(lEArtist_2, 0, 3, 1, 1);

        label_33 = new QLabel(CardgroupBoxGeneral);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_7->addWidget(label_33, 1, 0, 1, 1);

        lETextCard_2 = new QLineEdit(CardgroupBoxGeneral);
        lETextCard_2->setObjectName(QStringLiteral("lETextCard_2"));
        lETextCard_2->setAutoFillBackground(false);

        gridLayout_7->addWidget(lETextCard_2, 1, 1, 1, 3);


        gridLayout_8->addWidget(CardgroupBoxGeneral, 0, 0, 1, 1);

        CardgroupBoxDiscipline = new QGroupBox(CardSearchFrame);
        CardgroupBoxDiscipline->setObjectName(QStringLiteral("CardgroupBoxDiscipline"));
        CardgroupBoxDiscipline->setMinimumSize(QSize(0, 220));
        gridLayout = new QGridLayout(CardgroupBoxDiscipline);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        qui = new DisciplineButton(CardgroupBoxDiscipline);
        qui->setObjectName(QStringLiteral("qui"));
        sizePolicy2.setHeightForWidth(qui->sizePolicy().hasHeightForWidth());
        qui->setSizePolicy(sizePolicy2);
        qui->setMinimumSize(QSize(40, 40));
        qui->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(qui, 2, 4, 1, 1);

        dom = new DisciplineButton(CardgroupBoxDiscipline);
        dom->setObjectName(QStringLiteral("dom"));
        sizePolicy2.setHeightForWidth(dom->sizePolicy().hasHeightForWidth());
        dom->setSizePolicy(sizePolicy2);
        dom->setMinimumSize(QSize(40, 40));
        dom->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(dom, 3, 1, 1, 1);

        obt = new DisciplineButton(CardgroupBoxDiscipline);
        obt->setObjectName(QStringLiteral("obt"));
        sizePolicy2.setHeightForWidth(obt->sizePolicy().hasHeightForWidth());
        obt->setSizePolicy(sizePolicy2);
        obt->setMinimumSize(QSize(40, 40));
        obt->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(obt, 2, 3, 1, 1);

        aus = new DisciplineButton(CardgroupBoxDiscipline);
        aus->setObjectName(QStringLiteral("aus"));
        sizePolicy2.setHeightForWidth(aus->sizePolicy().hasHeightForWidth());
        aus->setSizePolicy(sizePolicy2);
        aus->setMinimumSize(QSize(40, 40));
        aus->setMaximumSize(QSize(40, 40));
        aus->setFlat(false);

        gridLayout->addWidget(aus, 2, 0, 1, 1);

        pot = new DisciplineButton(CardgroupBoxDiscipline);
        pot->setObjectName(QStringLiteral("pot"));
        sizePolicy2.setHeightForWidth(pot->sizePolicy().hasHeightForWidth());
        pot->setSizePolicy(sizePolicy2);
        pot->setMinimumSize(QSize(40, 40));
        pot->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(pot, 3, 3, 1, 1);

        tem = new DisciplineButton(CardgroupBoxDiscipline);
        tem->setObjectName(QStringLiteral("tem"));
        sizePolicy2.setHeightForWidth(tem->sizePolicy().hasHeightForWidth());
        tem->setSizePolicy(sizePolicy2);
        tem->setMinimumSize(QSize(40, 40));
        tem->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(tem, 2, 5, 1, 1);

        nec = new DisciplineButton(CardgroupBoxDiscipline);
        nec->setObjectName(QStringLiteral("nec"));
        sizePolicy2.setHeightForWidth(nec->sizePolicy().hasHeightForWidth());
        nec->setSizePolicy(sizePolicy2);
        nec->setMinimumSize(QSize(40, 40));
        nec->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(nec, 3, 2, 1, 1);

        vic = new DisciplineButton(CardgroupBoxDiscipline);
        vic->setObjectName(QStringLiteral("vic"));
        sizePolicy2.setHeightForWidth(vic->sizePolicy().hasHeightForWidth());
        vic->setSizePolicy(sizePolicy2);
        vic->setMinimumSize(QSize(40, 40));
        vic->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(vic, 2, 6, 1, 1);

        cel = new DisciplineButton(CardgroupBoxDiscipline);
        cel->setObjectName(QStringLiteral("cel"));
        sizePolicy2.setHeightForWidth(cel->sizePolicy().hasHeightForWidth());
        cel->setSizePolicy(sizePolicy2);
        cel->setMinimumSize(QSize(40, 40));
        cel->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(cel, 3, 0, 1, 1);

        san = new DisciplineButton(CardgroupBoxDiscipline);
        san->setObjectName(QStringLiteral("san"));
        sizePolicy2.setHeightForWidth(san->sizePolicy().hasHeightForWidth());
        san->setSizePolicy(sizePolicy2);
        san->setMinimumSize(QSize(40, 40));
        san->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(san, 3, 4, 1, 1);

        dem = new DisciplineButton(CardgroupBoxDiscipline);
        dem->setObjectName(QStringLiteral("dem"));
        sizePolicy2.setHeightForWidth(dem->sizePolicy().hasHeightForWidth());
        dem->setSizePolicy(sizePolicy2);
        dem->setMinimumSize(QSize(40, 40));
        dem->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(dem, 2, 1, 1, 1);

        myt = new DisciplineButton(CardgroupBoxDiscipline);
        myt->setObjectName(QStringLiteral("myt"));
        sizePolicy2.setHeightForWidth(myt->sizePolicy().hasHeightForWidth());
        myt->setSizePolicy(sizePolicy2);
        myt->setMinimumSize(QSize(40, 40));
        myt->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(myt, 2, 2, 1, 1);

        tha = new DisciplineButton(CardgroupBoxDiscipline);
        tha->setObjectName(QStringLiteral("tha"));
        sizePolicy2.setHeightForWidth(tha->sizePolicy().hasHeightForWidth());
        tha->setSizePolicy(sizePolicy2);
        tha->setMinimumSize(QSize(40, 40));
        tha->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(tha, 3, 5, 1, 1);

        vis = new DisciplineButton(CardgroupBoxDiscipline);
        vis->setObjectName(QStringLiteral("vis"));
        sizePolicy2.setHeightForWidth(vis->sizePolicy().hasHeightForWidth());
        vis->setSizePolicy(sizePolicy2);
        vis->setMinimumSize(QSize(40, 40));
        vis->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(vis, 3, 6, 1, 1);

        obe = new DisciplineButton(CardgroupBoxDiscipline);
        obe->setObjectName(QStringLiteral("obe"));
        sizePolicy2.setHeightForWidth(obe->sizePolicy().hasHeightForWidth());
        obe->setSizePolicy(sizePolicy2);
        obe->setMinimumSize(QSize(40, 40));
        obe->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(obe, 0, 3, 1, 1);

        for_2 = new DisciplineButton(CardgroupBoxDiscipline);
        for_2->setObjectName(QStringLiteral("for_2"));
        sizePolicy2.setHeightForWidth(for_2->sizePolicy().hasHeightForWidth());
        for_2->setSizePolicy(sizePolicy2);
        for_2->setMinimumSize(QSize(40, 40));
        for_2->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(for_2, 0, 2, 1, 1);

        dai = new DisciplineButton(CardgroupBoxDiscipline);
        dai->setObjectName(QStringLiteral("dai"));
        sizePolicy2.setHeightForWidth(dai->sizePolicy().hasHeightForWidth());
        dai->setSizePolicy(sizePolicy2);
        dai->setMinimumSize(QSize(40, 40));
        dai->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(dai, 1, 1, 1, 1);

        abo = new DisciplineButton(CardgroupBoxDiscipline);
        abo->setObjectName(QStringLiteral("abo"));
        sizePolicy2.setHeightForWidth(abo->sizePolicy().hasHeightForWidth());
        abo->setSizePolicy(sizePolicy2);
        abo->setMinimumSize(QSize(40, 40));
        abo->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(abo, 0, 0, 1, 1);

        ser = new DisciplineButton(CardgroupBoxDiscipline);
        ser->setObjectName(QStringLiteral("ser"));
        sizePolicy2.setHeightForWidth(ser->sizePolicy().hasHeightForWidth());
        ser->setSizePolicy(sizePolicy2);
        ser->setMinimumSize(QSize(40, 40));
        ser->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(ser, 0, 5, 1, 1);

        chi = new DisciplineButton(CardgroupBoxDiscipline);
        chi->setObjectName(QStringLiteral("chi"));
        sizePolicy2.setHeightForWidth(chi->sizePolicy().hasHeightForWidth());
        chi->setSizePolicy(sizePolicy2);
        chi->setMinimumSize(QSize(40, 40));
        chi->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(chi, 0, 1, 1, 1);

        pre = new DisciplineButton(CardgroupBoxDiscipline);
        pre->setObjectName(QStringLiteral("pre"));
        sizePolicy2.setHeightForWidth(pre->sizePolicy().hasHeightForWidth());
        pre->setSizePolicy(sizePolicy2);
        pre->setMinimumSize(QSize(40, 40));
        pre->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(pre, 0, 4, 1, 1);

        ani = new DisciplineButton(CardgroupBoxDiscipline);
        ani->setObjectName(QStringLiteral("ani"));
        sizePolicy2.setHeightForWidth(ani->sizePolicy().hasHeightForWidth());
        ani->setSizePolicy(sizePolicy2);
        ani->setMinimumSize(QSize(40, 40));
        ani->setMaximumSize(QSize(40, 40));
        ani->setCheckable(false);
        ani->setFlat(false);

        gridLayout->addWidget(ani, 1, 0, 1, 1);

        obf = new DisciplineButton(CardgroupBoxDiscipline);
        obf->setObjectName(QStringLiteral("obf"));
        sizePolicy2.setHeightForWidth(obf->sizePolicy().hasHeightForWidth());
        obf->setSizePolicy(sizePolicy2);
        obf->setMinimumSize(QSize(40, 40));
        obf->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(obf, 1, 3, 1, 1);

        val = new DisciplineButton(CardgroupBoxDiscipline);
        val->setObjectName(QStringLiteral("val"));
        sizePolicy2.setHeightForWidth(val->sizePolicy().hasHeightForWidth());
        val->setSizePolicy(sizePolicy2);
        val->setMinimumSize(QSize(40, 40));
        val->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(val, 1, 6, 1, 1);

        stri = new DisciplineButton(CardgroupBoxDiscipline);
        stri->setObjectName(QStringLiteral("stri"));
        sizePolicy2.setHeightForWidth(stri->sizePolicy().hasHeightForWidth());
        stri->setSizePolicy(sizePolicy2);
        stri->setMinimumSize(QSize(40, 40));
        stri->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(stri, 3, 7, 1, 1);

        pro = new DisciplineButton(CardgroupBoxDiscipline);
        pro->setObjectName(QStringLiteral("pro"));
        sizePolicy2.setHeightForWidth(pro->sizePolicy().hasHeightForWidth());
        pro->setSizePolicy(sizePolicy2);
        pro->setMinimumSize(QSize(40, 40));
        pro->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(pro, 1, 4, 1, 1);

        spi = new DisciplineButton(CardgroupBoxDiscipline);
        spi->setObjectName(QStringLiteral("spi"));
        sizePolicy2.setHeightForWidth(spi->sizePolicy().hasHeightForWidth());
        spi->setSizePolicy(sizePolicy2);
        spi->setMinimumSize(QSize(40, 40));
        spi->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(spi, 1, 5, 1, 1);

        thn = new DisciplineButton(CardgroupBoxDiscipline);
        thn->setObjectName(QStringLiteral("thn"));
        sizePolicy2.setHeightForWidth(thn->sizePolicy().hasHeightForWidth());
        thn->setSizePolicy(sizePolicy2);
        thn->setMinimumSize(QSize(40, 40));
        thn->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(thn, 0, 6, 1, 1);

        mel = new DisciplineButton(CardgroupBoxDiscipline);
        mel->setObjectName(QStringLiteral("mel"));
        sizePolicy2.setHeightForWidth(mel->sizePolicy().hasHeightForWidth());
        mel->setSizePolicy(sizePolicy2);
        mel->setMinimumSize(QSize(40, 40));
        mel->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(mel, 1, 2, 1, 1);

        mal = new DisciplineButton(CardgroupBoxDiscipline);
        mal->setObjectName(QStringLiteral("mal"));
        sizePolicy2.setHeightForWidth(mal->sizePolicy().hasHeightForWidth());
        mal->setSizePolicy(sizePolicy2);
        mal->setMinimumSize(QSize(40, 40));
        mal->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(mal, 2, 7, 1, 1);


        gridLayout_8->addWidget(CardgroupBoxDiscipline, 0, 3, 2, 1);

        CardgroupBoxRequirements = new QGroupBox(CardSearchFrame);
        CardgroupBoxRequirements->setObjectName(QStringLiteral("CardgroupBoxRequirements"));
        CardgroupBoxRequirements->setMinimumSize(QSize(0, 140));
        CardgroupBoxRequirements->setMaximumSize(QSize(16777215, 180));
        gridLayout_4 = new QGridLayout(CardgroupBoxRequirements);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        label_49 = new QLabel(CardgroupBoxRequirements);
        label_49->setObjectName(QStringLiteral("label_49"));
        sizePolicy4.setHeightForWidth(label_49->sizePolicy().hasHeightForWidth());
        label_49->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(label_49, 0, 0, 1, 1);

        cBClan_2 = new QComboBox(CardgroupBoxRequirements);
        cBClan_2->setObjectName(QStringLiteral("cBClan_2"));
        cBClan_2->setMinimumSize(QSize(165, 0));

        gridLayout_4->addWidget(cBClan_2, 0, 1, 1, 1);

        Anarch = new QCheckBox(CardgroupBoxRequirements);
        Anarch->setObjectName(QStringLiteral("Anarch"));
        Anarch->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(Anarch, 0, 2, 1, 1);

        Flight = new QCheckBox(CardgroupBoxRequirements);
        Flight->setObjectName(QStringLiteral("Flight"));
        Flight->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(Flight, 0, 3, 1, 1);

        lSect_2 = new QLabel(CardgroupBoxRequirements);
        lSect_2->setObjectName(QStringLiteral("lSect_2"));
        sizePolicy4.setHeightForWidth(lSect_2->sizePolicy().hasHeightForWidth());
        lSect_2->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(lSect_2, 1, 0, 1, 1);

        cBSect_2 = new QComboBox(CardgroupBoxRequirements);
        cBSect_2->setObjectName(QStringLiteral("cBSect_2"));
        cBSect_2->setMinimumSize(QSize(160, 0));

        gridLayout_4->addWidget(cBSect_2, 1, 1, 1, 1);

        RedList = new QCheckBox(CardgroupBoxRequirements);
        RedList->setObjectName(QStringLiteral("RedList"));
        RedList->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(RedList, 1, 2, 1, 1);

        BlackHand = new QCheckBox(CardgroupBoxRequirements);
        BlackHand->setObjectName(QStringLiteral("BlackHand"));
        BlackHand->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(BlackHand, 1, 3, 1, 1);

        lTitle_2 = new QLabel(CardgroupBoxRequirements);
        lTitle_2->setObjectName(QStringLiteral("lTitle_2"));
        sizePolicy4.setHeightForWidth(lTitle_2->sizePolicy().hasHeightForWidth());
        lTitle_2->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(lTitle_2, 2, 0, 1, 1);

        cBTitle_2 = new QComboBox(CardgroupBoxRequirements);
        cBTitle_2->setObjectName(QStringLiteral("cBTitle_2"));
        cBTitle_2->setMinimumSize(QSize(160, 0));

        gridLayout_4->addWidget(cBTitle_2, 2, 1, 1, 1);

        Infernal = new QCheckBox(CardgroupBoxRequirements);
        Infernal->setObjectName(QStringLiteral("Infernal"));
        Infernal->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(Infernal, 2, 2, 1, 1);

        Seraph = new QCheckBox(CardgroupBoxRequirements);
        Seraph->setObjectName(QStringLiteral("Seraph"));
        Seraph->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(Seraph, 2, 3, 1, 1);


        gridLayout_8->addWidget(CardgroupBoxRequirements, 1, 0, 2, 1);

        groupBox = new QGroupBox(CardSearchFrame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(16777215, 130));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        label_47 = new QLabel(groupBox);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_47, 0, 0, 1, 1);

        cBSet = new QComboBox(groupBox);
        cBSet->setObjectName(QStringLiteral("cBSet"));

        gridLayout_6->addWidget(cBSet, 0, 1, 1, 1);

        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QStringLiteral("label_45"));
        sizePolicy4.setHeightForWidth(label_45->sizePolicy().hasHeightForWidth());
        label_45->setSizePolicy(sizePolicy4);
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_45, 1, 0, 1, 1);

        cBRarity = new QComboBox(groupBox);
        cBRarity->setObjectName(QStringLiteral("cBRarity"));

        gridLayout_6->addWidget(cBRarity, 1, 1, 1, 1);


        gridLayout_8->addWidget(groupBox, 0, 2, 1, 1);

        CardgroupBoxOthers = new QGroupBox(CardSearchFrame);
        CardgroupBoxOthers->setObjectName(QStringLiteral("CardgroupBoxOthers"));
        CardgroupBoxOthers->setMinimumSize(QSize(0, 140));
        CardgroupBoxOthers->setMaximumSize(QSize(16777215, 180));
        gridLayout_3 = new QGridLayout(CardgroupBoxOthers);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        BurnOption = new QCheckBox(CardgroupBoxOthers);
        BurnOption->setObjectName(QStringLiteral("BurnOption"));
        BurnOption->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(BurnOption, 0, 0, 1, 1);

        Anarch_3_Way = new QCheckBox(CardgroupBoxOthers);
        Anarch_3_Way->setObjectName(QStringLiteral("Anarch_3_Way"));
        Anarch_3_Way->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Anarch_3_Way, 0, 1, 1, 1);

        Dual_discipline = new QCheckBox(CardgroupBoxOthers);
        Dual_discipline->setObjectName(QStringLiteral("Dual_discipline"));
        Dual_discipline->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Dual_discipline, 1, 0, 1, 1);

        Multi_discipline = new QCheckBox(CardgroupBoxOthers);
        Multi_discipline->setObjectName(QStringLiteral("Multi_discipline"));
        Multi_discipline->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Multi_discipline, 1, 1, 1, 1);

        Boon = new QCheckBox(CardgroupBoxOthers);
        Boon->setObjectName(QStringLiteral("Boon"));
        Boon->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Boon, 2, 0, 1, 1);

        Grapple = new QCheckBox(CardgroupBoxOthers);
        Grapple->setObjectName(QStringLiteral("Grapple"));
        Grapple->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Grapple, 2, 1, 1, 1);

        Frenzy = new QCheckBox(CardgroupBoxOthers);
        Frenzy->setObjectName(QStringLiteral("Frenzy"));
        Frenzy->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Frenzy, 3, 0, 1, 1);

        Aim = new QCheckBox(CardgroupBoxOthers);
        Aim->setObjectName(QStringLiteral("Aim"));
        Aim->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(Aim, 3, 1, 1, 1);


        gridLayout_8->addWidget(CardgroupBoxOthers, 1, 1, 2, 1);

        CardgroupBoxCout = new QGroupBox(CardSearchFrame);
        CardgroupBoxCout->setObjectName(QStringLiteral("CardgroupBoxCout"));
        CardgroupBoxCout->setMinimumSize(QSize(0, 140));
        CardgroupBoxCout->setMaximumSize(QSize(16777215, 180));
        gridLayout_5 = new QGridLayout(CardgroupBoxCout);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(0);
        gridLayout_5->setContentsMargins(5, 5, 5, 5);
        label_37 = new QLabel(CardgroupBoxCout);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy);
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_37, 0, 0, 1, 1);

        cBBloodCost = new QComboBox(CardgroupBoxCout);
        cBBloodCost->setObjectName(QStringLiteral("cBBloodCost"));
        sizePolicy2.setHeightForWidth(cBBloodCost->sizePolicy().hasHeightForWidth());
        cBBloodCost->setSizePolicy(sizePolicy2);
        cBBloodCost->setMinimumSize(QSize(45, 0));
        cBBloodCost->setMaximumSize(QSize(45, 16777215));

        gridLayout_5->addWidget(cBBloodCost, 0, 1, 1, 1);

        sBBloodCost = new QSpinBox(CardgroupBoxCout);
        sBBloodCost->setObjectName(QStringLiteral("sBBloodCost"));
        sizePolicy2.setHeightForWidth(sBBloodCost->sizePolicy().hasHeightForWidth());
        sBBloodCost->setSizePolicy(sizePolicy2);
        sBBloodCost->setMinimumSize(QSize(40, 0));
        sBBloodCost->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        sBBloodCost->setFont(font);
        sBBloodCost->setMaximum(6);

        gridLayout_5->addWidget(sBBloodCost, 0, 2, 1, 1);

        label_39 = new QLabel(CardgroupBoxCout);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy);
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_39, 1, 0, 1, 1);

        cBPoolCost = new QComboBox(CardgroupBoxCout);
        cBPoolCost->setObjectName(QStringLiteral("cBPoolCost"));
        sizePolicy2.setHeightForWidth(cBPoolCost->sizePolicy().hasHeightForWidth());
        cBPoolCost->setSizePolicy(sizePolicy2);
        cBPoolCost->setMinimumSize(QSize(45, 0));
        cBPoolCost->setMaximumSize(QSize(45, 16777215));

        gridLayout_5->addWidget(cBPoolCost, 1, 1, 1, 1);

        sBPoolCost = new QSpinBox(CardgroupBoxCout);
        sBPoolCost->setObjectName(QStringLiteral("sBPoolCost"));
        sizePolicy2.setHeightForWidth(sBPoolCost->sizePolicy().hasHeightForWidth());
        sBPoolCost->setSizePolicy(sizePolicy2);
        sBPoolCost->setMinimumSize(QSize(40, 0));
        sBPoolCost->setMaximumSize(QSize(40, 16777215));
        sBPoolCost->setFont(font);
        sBPoolCost->setMaximum(6);

        gridLayout_5->addWidget(sBPoolCost, 1, 2, 1, 1);

        label_41 = new QLabel(CardgroupBoxCout);
        label_41->setObjectName(QStringLiteral("label_41"));
        sizePolicy4.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy4);
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_41, 2, 0, 1, 1);

        cBConvictionCost = new QComboBox(CardgroupBoxCout);
        cBConvictionCost->setObjectName(QStringLiteral("cBConvictionCost"));
        sizePolicy2.setHeightForWidth(cBConvictionCost->sizePolicy().hasHeightForWidth());
        cBConvictionCost->setSizePolicy(sizePolicy2);
        cBConvictionCost->setMinimumSize(QSize(45, 0));
        cBConvictionCost->setMaximumSize(QSize(45, 16777215));

        gridLayout_5->addWidget(cBConvictionCost, 2, 1, 1, 1);

        sBConvictionCost = new QSpinBox(CardgroupBoxCout);
        sBConvictionCost->setObjectName(QStringLiteral("sBConvictionCost"));
        sizePolicy2.setHeightForWidth(sBConvictionCost->sizePolicy().hasHeightForWidth());
        sBConvictionCost->setSizePolicy(sizePolicy2);
        sBConvictionCost->setMinimumSize(QSize(40, 0));
        sBConvictionCost->setMaximumSize(QSize(40, 16777215));
        sBConvictionCost->setFont(font);
        sBConvictionCost->setMaximum(6);

        gridLayout_5->addWidget(sBConvictionCost, 2, 2, 1, 1);


        gridLayout_8->addWidget(CardgroupBoxCout, 1, 2, 2, 1);


        horizontalLayout_3->addWidget(CardSearchFrame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        LibraryView = new PartialDeckView(frame_2);
        LibraryView->setObjectName(QStringLiteral("LibraryView"));
        LibraryView->setMinimumSize(QSize(220, 0));
        LibraryView->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_3->addWidget(LibraryView);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pBCardSearch = new QPushButton(frame_4);
        pBCardSearch->setObjectName(QStringLiteral("pBCardSearch"));
        sizePolicy2.setHeightForWidth(pBCardSearch->sizePolicy().hasHeightForWidth());
        pBCardSearch->setSizePolicy(sizePolicy2);
        pBCardSearch->setMinimumSize(QSize(75, 45));
        pBCardSearch->setMaximumSize(QSize(75, 45));

        horizontalLayout_4->addWidget(pBCardSearch);

        pBCardClearForm = new QPushButton(frame_4);
        pBCardClearForm->setObjectName(QStringLiteral("pBCardClearForm"));
        sizePolicy2.setHeightForWidth(pBCardClearForm->sizePolicy().hasHeightForWidth());
        pBCardClearForm->setSizePolicy(sizePolicy2);
        pBCardClearForm->setMinimumSize(QSize(75, 45));
        pBCardClearForm->setMaximumSize(QSize(75, 45));

        horizontalLayout_4->addWidget(pBCardClearForm);

        pBAddtoDeck = new QPushButton(frame_4);
        pBAddtoDeck->setObjectName(QStringLiteral("pBAddtoDeck"));
        sizePolicy2.setHeightForWidth(pBAddtoDeck->sizePolicy().hasHeightForWidth());
        pBAddtoDeck->setSizePolicy(sizePolicy2);
        pBAddtoDeck->setMinimumSize(QSize(75, 45));
        pBAddtoDeck->setMaximumSize(QSize(75, 45));

        horizontalLayout_4->addWidget(pBAddtoDeck);


        verticalLayout_2->addWidget(frame_4);

        VisuelCarte = new QLabel(frame_3);
        VisuelCarte->setObjectName(QStringLiteral("VisuelCarte"));
        sizePolicy2.setHeightForWidth(VisuelCarte->sizePolicy().hasHeightForWidth());
        VisuelCarte->setSizePolicy(sizePolicy2);
        VisuelCarte->setMinimumSize(QSize(360, 500));
        VisuelCarte->setMaximumSize(QSize(360, 500));
        VisuelCarte->setFrameShape(QFrame::StyledPanel);
        VisuelCarte->setFrameShadow(QFrame::Sunken);
        VisuelCarte->setLineWidth(0);
        VisuelCarte->setPixmap(QPixmap(QString::fromUtf8("../../jr/Desktop/Vtes_Grelarge.gif")));

        verticalLayout_2->addWidget(VisuelCarte);

        verticalSpacer_3 = new QSpacerItem(20, 310, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(frame_3);

        PTVCardsResults = new PItemView(frame);
        PTVCardsResults->setObjectName(QStringLiteral("PTVCardsResults"));
        PTVCardsResults->setMinimumSize(QSize(1130, 0));
        PTVCardsResults->setMaximumSize(QSize(16777215, 16777215));
        PTVCardsResults->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        PTVCardsResults->setFrameShape(QFrame::NoFrame);
        PTVCardsResults->setFrameShadow(QFrame::Plain);
        PTVCardsResults->setLineWidth(0);
        PTVCardsResults->setAlternatingRowColors(true);
        PTVCardsResults->setShowGrid(false);
        PTVCardsResults->setCornerButtonEnabled(false);

        horizontalLayout->addWidget(PTVCardsResults);


        verticalLayout->addWidget(frame);

        tab_search_library->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_search_library);

        QMetaObject::connectSlotsByName(tab_search_library);
    } // setupUi

    void retranslateUi(QScrollArea *tab_search_library)
    {
        tab_search_library->setWindowTitle(QApplication::translate("tab_search_library", "ScrollArea", 0));
        CardgroupBoxVirtues->setTitle(QApplication::translate("tab_search_library", "Virtues", 0));
        def->setText(QString());
        inn->setText(QString());
        jud->setText(QString());
        mar->setText(QString());
        red->setText(QString());
        ven->setText(QString());
        vis2->setText(QString());
        CardgroupBoxFilters->setTitle(QApplication::translate("tab_search_library", "Filters ", 0));
        label_4->setText(QApplication::translate("tab_search_library", "Sub-type", 0));
        label_43->setText(QApplication::translate("tab_search_library", "   Type", 0));
        CardgroupBoxGeneral->setTitle(QApplication::translate("tab_search_library", "General ", 0));
        label_31->setText(QApplication::translate("tab_search_library", "Name :", 0));
        label_35->setText(QApplication::translate("tab_search_library", "Artist :", 0));
        label_33->setText(QApplication::translate("tab_search_library", "Text ", 0));
        CardgroupBoxDiscipline->setTitle(QApplication::translate("tab_search_library", "Disciplines", 0));
        qui->setText(QString());
        dom->setText(QString());
        obt->setText(QString());
        aus->setText(QString());
        pot->setText(QString());
        tem->setText(QString());
        nec->setText(QString());
        vic->setText(QString());
        cel->setText(QString());
        san->setText(QString());
        dem->setText(QString());
        myt->setText(QString());
        tha->setText(QString());
        vis->setText(QString());
        obe->setText(QString());
        for_2->setText(QString());
        dai->setText(QString());
        abo->setText(QString());
        ser->setText(QString());
        chi->setText(QString());
        pre->setText(QString());
        ani->setText(QString());
        obf->setText(QString());
        val->setText(QString());
        stri->setText(QString());
        pro->setText(QString());
        spi->setText(QString());
        thn->setText(QString());
        mel->setText(QString());
        mal->setText(QString());
        CardgroupBoxRequirements->setTitle(QApplication::translate("tab_search_library", "Requirements ", 0));
        label_49->setText(QApplication::translate("tab_search_library", "Clan ", 0));
        Anarch->setText(QApplication::translate("tab_search_library", "Anarch", 0));
        Flight->setText(QApplication::translate("tab_search_library", "Flight", 0));
        lSect_2->setText(QApplication::translate("tab_search_library", "Sect", 0));
        RedList->setText(QApplication::translate("tab_search_library", "Red list", 0));
        BlackHand->setText(QApplication::translate("tab_search_library", "Black hand", 0));
        lTitle_2->setText(QApplication::translate("tab_search_library", "Title", 0));
        Infernal->setText(QApplication::translate("tab_search_library", "Infernal", 0));
        Seraph->setText(QApplication::translate("tab_search_library", "Seraph", 0));
        groupBox->setTitle(QApplication::translate("tab_search_library", "Edition", 0));
        label_47->setText(QApplication::translate("tab_search_library", "Set", 0));
        label_45->setText(QApplication::translate("tab_search_library", "Rarity", 0));
        CardgroupBoxOthers->setTitle(QApplication::translate("tab_search_library", "Key words ", 0));
        BurnOption->setText(QApplication::translate("tab_search_library", "Burn Option", 0));
        Anarch_3_Way->setText(QApplication::translate("tab_search_library", "Anarch 3-way", 0));
        Dual_discipline->setText(QApplication::translate("tab_search_library", "Dual disciplines", 0));
        Multi_discipline->setText(QApplication::translate("tab_search_library", "Multi discipline", 0));
        Boon->setText(QApplication::translate("tab_search_library", "Boon", 0));
        Grapple->setText(QApplication::translate("tab_search_library", "Grapple", 0));
        Frenzy->setText(QApplication::translate("tab_search_library", "Frenzy", 0));
        Aim->setText(QApplication::translate("tab_search_library", "Unique", 0));
        CardgroupBoxCout->setTitle(QApplication::translate("tab_search_library", "Costs", 0));
        label_37->setText(QApplication::translate("tab_search_library", "Blood cost", 0));
        label_39->setText(QApplication::translate("tab_search_library", "Pool cost", 0));
        label_41->setText(QApplication::translate("tab_search_library", "Conviction cost", 0));
        pBCardSearch->setText(QApplication::translate("tab_search_library", "Search", 0));
        pBCardClearForm->setText(QApplication::translate("tab_search_library", "Clear Form", 0));
        pBAddtoDeck->setText(QApplication::translate("tab_search_library", "Add to deck", 0));
        VisuelCarte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tab_search_library: public Ui_tab_search_library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_SEARCH_LIBRARY_H

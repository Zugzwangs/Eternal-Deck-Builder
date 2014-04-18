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
#include "PWidget.h"
#include "pitemview.h"

QT_BEGIN_NAMESPACE

class Ui_tab_search_library
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *CardSearchFrame;
    QGroupBox *CardgroupBoxVirtues;
    QHBoxLayout *horizontalLayout_2;
    DisciplineButton *def;
    DisciplineButton *inn;
    DisciplineButton *jud;
    DisciplineButton *mar;
    DisciplineButton *red;
    DisciplineButton *ven;
    DisciplineButton *vis2;
    QGroupBox *CardgroupBoxCout;
    QSpinBox *sBPoolCost;
    QLabel *label_39;
    QSpinBox *sBBloodCost;
    QComboBox *cBPoolCost;
    QLabel *label_41;
    QSpinBox *sBConvictionCost;
    QLabel *label_37;
    QComboBox *cBBloodCost;
    QComboBox *cBConvictionCost;
    QGroupBox *CardgroupBoxGeneral;
    QLineEdit *lENameCard_2;
    QLabel *label_31;
    QLabel *label_33;
    QLabel *label_35;
    QLineEdit *lEArtist_2;
    QLineEdit *lETextCard_2;
    QComboBox *cBSet;
    QLabel *label_47;
    QComboBox *cBRarity;
    QLabel *label_45;
    QGroupBox *CardgroupBoxOptions;
    QPushButton *pBCardSearch;
    QPushButton *pBCardClearForm;
    QGroupBox *CardgroupBoxFilters;
    QLabel *label_43;
    QComboBox *cBType;
    QLabel *label_4;
    QComboBox *cBSousType;
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
    QLabel *label_49;
    QCheckBox *Flight;
    QCheckBox *BlackHand;
    QCheckBox *Infernal;
    QCheckBox *RedList;
    QComboBox *cBClan_2;
    QComboBox *cBSect_2;
    QLabel *lSect_2;
    QCheckBox *Seraph;
    QLabel *lFortitude_4;
    QLabel *lTitle_2;
    QComboBox *cBTitle_2;
    QCheckBox *Anarch;
    QGroupBox *CardgroupBoxOthers;
    QCheckBox *BurnOption;
    QCheckBox *Anarch_3_Way;
    QCheckBox *Dual_discipline;
    QCheckBox *Multi_discipline;
    QLabel *lFortitude_3;
    QCheckBox *Boon;
    QCheckBox *Grapple;
    QCheckBox *Frenzy;
    QCheckBox *Aim;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *VisuelCarte;
    PItemView *PTVCardsResults;

    void setupUi(QScrollArea *tab_search_library)
    {
        if (tab_search_library->objectName().isEmpty())
            tab_search_library->setObjectName(QStringLiteral("tab_search_library"));
        tab_search_library->resize(1317, 830);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1296, 890));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        CardSearchFrame = new QFrame(frame_2);
        CardSearchFrame->setObjectName(QStringLiteral("CardSearchFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CardSearchFrame->sizePolicy().hasHeightForWidth());
        CardSearchFrame->setSizePolicy(sizePolicy1);
        CardSearchFrame->setMinimumSize(QSize(1025, 315));
        CardSearchFrame->setFrameShape(QFrame::NoFrame);
        CardSearchFrame->setFrameShadow(QFrame::Plain);
        CardSearchFrame->setLineWidth(0);
        CardgroupBoxVirtues = new QGroupBox(CardSearchFrame);
        CardgroupBoxVirtues->setObjectName(QStringLiteral("CardgroupBoxVirtues"));
        CardgroupBoxVirtues->setGeometry(QRect(700, 210, 391, 81));
        horizontalLayout_2 = new QHBoxLayout(CardgroupBoxVirtues);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        def = new DisciplineButton(CardgroupBoxVirtues);
        def->setObjectName(QStringLiteral("def"));
        sizePolicy1.setHeightForWidth(def->sizePolicy().hasHeightForWidth());
        def->setSizePolicy(sizePolicy1);
        def->setMinimumSize(QSize(40, 40));
        def->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(def);

        inn = new DisciplineButton(CardgroupBoxVirtues);
        inn->setObjectName(QStringLiteral("inn"));
        sizePolicy1.setHeightForWidth(inn->sizePolicy().hasHeightForWidth());
        inn->setSizePolicy(sizePolicy1);
        inn->setMinimumSize(QSize(40, 40));
        inn->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(inn);

        jud = new DisciplineButton(CardgroupBoxVirtues);
        jud->setObjectName(QStringLiteral("jud"));
        sizePolicy1.setHeightForWidth(jud->sizePolicy().hasHeightForWidth());
        jud->setSizePolicy(sizePolicy1);
        jud->setMinimumSize(QSize(40, 40));
        jud->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(jud);

        mar = new DisciplineButton(CardgroupBoxVirtues);
        mar->setObjectName(QStringLiteral("mar"));
        sizePolicy1.setHeightForWidth(mar->sizePolicy().hasHeightForWidth());
        mar->setSizePolicy(sizePolicy1);
        mar->setMinimumSize(QSize(40, 40));
        mar->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(mar);

        red = new DisciplineButton(CardgroupBoxVirtues);
        red->setObjectName(QStringLiteral("red"));
        sizePolicy1.setHeightForWidth(red->sizePolicy().hasHeightForWidth());
        red->setSizePolicy(sizePolicy1);
        red->setMinimumSize(QSize(40, 40));
        red->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(red);

        ven = new DisciplineButton(CardgroupBoxVirtues);
        ven->setObjectName(QStringLiteral("ven"));
        sizePolicy1.setHeightForWidth(ven->sizePolicy().hasHeightForWidth());
        ven->setSizePolicy(sizePolicy1);
        ven->setMinimumSize(QSize(40, 40));
        ven->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(ven);

        vis2 = new DisciplineButton(CardgroupBoxVirtues);
        vis2->setObjectName(QStringLiteral("vis2"));
        sizePolicy1.setHeightForWidth(vis2->sizePolicy().hasHeightForWidth());
        vis2->setSizePolicy(sizePolicy1);
        vis2->setMinimumSize(QSize(40, 40));
        vis2->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(vis2);

        CardgroupBoxCout = new QGroupBox(CardSearchFrame);
        CardgroupBoxCout->setObjectName(QStringLiteral("CardgroupBoxCout"));
        CardgroupBoxCout->setGeometry(QRect(189, 260, 501, 51));
        sBPoolCost = new QSpinBox(CardgroupBoxCout);
        sBPoolCost->setObjectName(QStringLiteral("sBPoolCost"));
        sBPoolCost->setGeometry(QRect(256, 19, 41, 22));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        sBPoolCost->setFont(font);
        sBPoolCost->setMaximum(6);
        label_39 = new QLabel(CardgroupBoxCout);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(167, 21, 51, 16));
        sBBloodCost = new QSpinBox(CardgroupBoxCout);
        sBBloodCost->setObjectName(QStringLiteral("sBBloodCost"));
        sBBloodCost->setGeometry(QRect(113, 20, 41, 22));
        sBBloodCost->setFont(font);
        sBBloodCost->setMaximum(6);
        cBPoolCost = new QComboBox(CardgroupBoxCout);
        cBPoolCost->setObjectName(QStringLiteral("cBPoolCost"));
        cBPoolCost->setGeometry(QRect(221, 19, 31, 22));
        label_41 = new QLabel(CardgroupBoxCout);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(311, 21, 81, 20));
        sBConvictionCost = new QSpinBox(CardgroupBoxCout);
        sBConvictionCost->setObjectName(QStringLiteral("sBConvictionCost"));
        sBConvictionCost->setGeometry(QRect(432, 21, 41, 22));
        sBConvictionCost->setFont(font);
        sBConvictionCost->setMaximum(6);
        label_37 = new QLabel(CardgroupBoxCout);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(18, 21, 61, 16));
        cBBloodCost = new QComboBox(CardgroupBoxCout);
        cBBloodCost->setObjectName(QStringLiteral("cBBloodCost"));
        cBBloodCost->setGeometry(QRect(78, 20, 31, 22));
        cBConvictionCost = new QComboBox(CardgroupBoxCout);
        cBConvictionCost->setObjectName(QStringLiteral("cBConvictionCost"));
        cBConvictionCost->setGeometry(QRect(397, 21, 31, 22));
        CardgroupBoxGeneral = new QGroupBox(CardSearchFrame);
        CardgroupBoxGeneral->setObjectName(QStringLiteral("CardgroupBoxGeneral"));
        CardgroupBoxGeneral->setGeometry(QRect(0, 0, 431, 120));
        lENameCard_2 = new QLineEdit(CardgroupBoxGeneral);
        lENameCard_2->setObjectName(QStringLiteral("lENameCard_2"));
        lENameCard_2->setGeometry(QRect(43, 23, 200, 22));
        label_31 = new QLabel(CardgroupBoxGeneral);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(6, 23, 32, 16));
        label_33 = new QLabel(CardgroupBoxGeneral);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(12, 56, 31, 16));
        label_35 = new QLabel(CardgroupBoxGeneral);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(254, 23, 31, 16));
        lEArtist_2 = new QLineEdit(CardgroupBoxGeneral);
        lEArtist_2->setObjectName(QStringLiteral("lEArtist_2"));
        lEArtist_2->setGeometry(QRect(289, 23, 133, 22));
        lETextCard_2 = new QLineEdit(CardgroupBoxGeneral);
        lETextCard_2->setObjectName(QStringLiteral("lETextCard_2"));
        lETextCard_2->setGeometry(QRect(43, 56, 379, 21));
        lETextCard_2->setAutoFillBackground(false);
        cBSet = new QComboBox(CardgroupBoxGeneral);
        cBSet->setObjectName(QStringLiteral("cBSet"));
        cBSet->setGeometry(QRect(42, 88, 181, 22));
        label_47 = new QLabel(CardgroupBoxGeneral);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(16, 88, 21, 16));
        cBRarity = new QComboBox(CardgroupBoxGeneral);
        cBRarity->setObjectName(QStringLiteral("cBRarity"));
        cBRarity->setGeometry(QRect(281, 88, 141, 22));
        label_45 = new QLabel(CardgroupBoxGeneral);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(233, 88, 41, 16));
        CardgroupBoxOptions = new QGroupBox(CardSearchFrame);
        CardgroupBoxOptions->setObjectName(QStringLiteral("CardgroupBoxOptions"));
        CardgroupBoxOptions->setGeometry(QRect(0, 260, 181, 51));
        pBCardSearch = new QPushButton(CardgroupBoxOptions);
        pBCardSearch->setObjectName(QStringLiteral("pBCardSearch"));
        pBCardSearch->setGeometry(QRect(19, 14, 71, 30));
        pBCardClearForm = new QPushButton(CardgroupBoxOptions);
        pBCardClearForm->setObjectName(QStringLiteral("pBCardClearForm"));
        pBCardClearForm->setGeometry(QRect(100, 14, 71, 30));
        CardgroupBoxFilters = new QGroupBox(CardSearchFrame);
        CardgroupBoxFilters->setObjectName(QStringLiteral("CardgroupBoxFilters"));
        CardgroupBoxFilters->setGeometry(QRect(438, 0, 251, 120));
        label_43 = new QLabel(CardgroupBoxFilters);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(40, 30, 31, 16));
        cBType = new QComboBox(CardgroupBoxFilters);
        cBType->setObjectName(QStringLiteral("cBType"));
        cBType->setGeometry(QRect(80, 30, 161, 22));
        label_4 = new QLabel(CardgroupBoxFilters);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 61, 16));
        cBSousType = new QComboBox(CardgroupBoxFilters);
        cBSousType->setObjectName(QStringLiteral("cBSousType"));
        cBSousType->setGeometry(QRect(80, 80, 161, 22));
        CardgroupBoxDiscipline = new QGroupBox(CardSearchFrame);
        CardgroupBoxDiscipline->setObjectName(QStringLiteral("CardgroupBoxDiscipline"));
        CardgroupBoxDiscipline->setGeometry(QRect(697, 1, 381, 211));
        gridLayout = new QGridLayout(CardgroupBoxDiscipline);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qui = new DisciplineButton(CardgroupBoxDiscipline);
        qui->setObjectName(QStringLiteral("qui"));
        sizePolicy1.setHeightForWidth(qui->sizePolicy().hasHeightForWidth());
        qui->setSizePolicy(sizePolicy1);
        qui->setMinimumSize(QSize(40, 40));
        qui->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(qui, 2, 4, 1, 1);

        dom = new DisciplineButton(CardgroupBoxDiscipline);
        dom->setObjectName(QStringLiteral("dom"));
        sizePolicy1.setHeightForWidth(dom->sizePolicy().hasHeightForWidth());
        dom->setSizePolicy(sizePolicy1);
        dom->setMinimumSize(QSize(40, 40));
        dom->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(dom, 3, 1, 1, 1);

        obt = new DisciplineButton(CardgroupBoxDiscipline);
        obt->setObjectName(QStringLiteral("obt"));
        sizePolicy1.setHeightForWidth(obt->sizePolicy().hasHeightForWidth());
        obt->setSizePolicy(sizePolicy1);
        obt->setMinimumSize(QSize(40, 40));
        obt->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(obt, 2, 3, 1, 1);

        aus = new DisciplineButton(CardgroupBoxDiscipline);
        aus->setObjectName(QStringLiteral("aus"));
        sizePolicy1.setHeightForWidth(aus->sizePolicy().hasHeightForWidth());
        aus->setSizePolicy(sizePolicy1);
        aus->setMinimumSize(QSize(40, 40));
        aus->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(aus, 2, 0, 1, 1);

        pot = new DisciplineButton(CardgroupBoxDiscipline);
        pot->setObjectName(QStringLiteral("pot"));
        sizePolicy1.setHeightForWidth(pot->sizePolicy().hasHeightForWidth());
        pot->setSizePolicy(sizePolicy1);
        pot->setMinimumSize(QSize(40, 40));
        pot->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(pot, 3, 3, 1, 1);

        tem = new DisciplineButton(CardgroupBoxDiscipline);
        tem->setObjectName(QStringLiteral("tem"));
        sizePolicy1.setHeightForWidth(tem->sizePolicy().hasHeightForWidth());
        tem->setSizePolicy(sizePolicy1);
        tem->setMinimumSize(QSize(40, 40));
        tem->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(tem, 2, 5, 1, 1);

        nec = new DisciplineButton(CardgroupBoxDiscipline);
        nec->setObjectName(QStringLiteral("nec"));
        sizePolicy1.setHeightForWidth(nec->sizePolicy().hasHeightForWidth());
        nec->setSizePolicy(sizePolicy1);
        nec->setMinimumSize(QSize(40, 40));
        nec->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(nec, 3, 2, 1, 1);

        vic = new DisciplineButton(CardgroupBoxDiscipline);
        vic->setObjectName(QStringLiteral("vic"));
        sizePolicy1.setHeightForWidth(vic->sizePolicy().hasHeightForWidth());
        vic->setSizePolicy(sizePolicy1);
        vic->setMinimumSize(QSize(40, 40));
        vic->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(vic, 2, 6, 1, 1);

        cel = new DisciplineButton(CardgroupBoxDiscipline);
        cel->setObjectName(QStringLiteral("cel"));
        sizePolicy1.setHeightForWidth(cel->sizePolicy().hasHeightForWidth());
        cel->setSizePolicy(sizePolicy1);
        cel->setMinimumSize(QSize(40, 40));
        cel->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(cel, 3, 0, 1, 1);

        san = new DisciplineButton(CardgroupBoxDiscipline);
        san->setObjectName(QStringLiteral("san"));
        sizePolicy1.setHeightForWidth(san->sizePolicy().hasHeightForWidth());
        san->setSizePolicy(sizePolicy1);
        san->setMinimumSize(QSize(40, 40));
        san->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(san, 3, 4, 1, 1);

        dem = new DisciplineButton(CardgroupBoxDiscipline);
        dem->setObjectName(QStringLiteral("dem"));
        sizePolicy1.setHeightForWidth(dem->sizePolicy().hasHeightForWidth());
        dem->setSizePolicy(sizePolicy1);
        dem->setMinimumSize(QSize(40, 40));
        dem->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(dem, 2, 1, 1, 1);

        myt = new DisciplineButton(CardgroupBoxDiscipline);
        myt->setObjectName(QStringLiteral("myt"));
        sizePolicy1.setHeightForWidth(myt->sizePolicy().hasHeightForWidth());
        myt->setSizePolicy(sizePolicy1);
        myt->setMinimumSize(QSize(40, 40));
        myt->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(myt, 2, 2, 1, 1);

        tha = new DisciplineButton(CardgroupBoxDiscipline);
        tha->setObjectName(QStringLiteral("tha"));
        sizePolicy1.setHeightForWidth(tha->sizePolicy().hasHeightForWidth());
        tha->setSizePolicy(sizePolicy1);
        tha->setMinimumSize(QSize(40, 40));
        tha->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(tha, 3, 5, 1, 1);

        vis = new DisciplineButton(CardgroupBoxDiscipline);
        vis->setObjectName(QStringLiteral("vis"));
        sizePolicy1.setHeightForWidth(vis->sizePolicy().hasHeightForWidth());
        vis->setSizePolicy(sizePolicy1);
        vis->setMinimumSize(QSize(40, 40));
        vis->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(vis, 3, 6, 1, 1);

        obe = new DisciplineButton(CardgroupBoxDiscipline);
        obe->setObjectName(QStringLiteral("obe"));
        sizePolicy1.setHeightForWidth(obe->sizePolicy().hasHeightForWidth());
        obe->setSizePolicy(sizePolicy1);
        obe->setMinimumSize(QSize(40, 40));
        obe->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(obe, 0, 3, 1, 1);

        for_2 = new DisciplineButton(CardgroupBoxDiscipline);
        for_2->setObjectName(QStringLiteral("for_2"));
        sizePolicy1.setHeightForWidth(for_2->sizePolicy().hasHeightForWidth());
        for_2->setSizePolicy(sizePolicy1);
        for_2->setMinimumSize(QSize(40, 40));
        for_2->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(for_2, 0, 2, 1, 1);

        dai = new DisciplineButton(CardgroupBoxDiscipline);
        dai->setObjectName(QStringLiteral("dai"));
        sizePolicy1.setHeightForWidth(dai->sizePolicy().hasHeightForWidth());
        dai->setSizePolicy(sizePolicy1);
        dai->setMinimumSize(QSize(40, 40));
        dai->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(dai, 1, 1, 1, 1);

        abo = new DisciplineButton(CardgroupBoxDiscipline);
        abo->setObjectName(QStringLiteral("abo"));
        sizePolicy1.setHeightForWidth(abo->sizePolicy().hasHeightForWidth());
        abo->setSizePolicy(sizePolicy1);
        abo->setMinimumSize(QSize(40, 40));
        abo->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(abo, 0, 0, 1, 1);

        ser = new DisciplineButton(CardgroupBoxDiscipline);
        ser->setObjectName(QStringLiteral("ser"));
        sizePolicy1.setHeightForWidth(ser->sizePolicy().hasHeightForWidth());
        ser->setSizePolicy(sizePolicy1);
        ser->setMinimumSize(QSize(40, 40));
        ser->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(ser, 0, 5, 1, 1);

        chi = new DisciplineButton(CardgroupBoxDiscipline);
        chi->setObjectName(QStringLiteral("chi"));
        sizePolicy1.setHeightForWidth(chi->sizePolicy().hasHeightForWidth());
        chi->setSizePolicy(sizePolicy1);
        chi->setMinimumSize(QSize(40, 40));
        chi->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(chi, 0, 1, 1, 1);

        pre = new DisciplineButton(CardgroupBoxDiscipline);
        pre->setObjectName(QStringLiteral("pre"));
        sizePolicy1.setHeightForWidth(pre->sizePolicy().hasHeightForWidth());
        pre->setSizePolicy(sizePolicy1);
        pre->setMinimumSize(QSize(40, 40));
        pre->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(pre, 0, 4, 1, 1);

        ani = new DisciplineButton(CardgroupBoxDiscipline);
        ani->setObjectName(QStringLiteral("ani"));
        sizePolicy1.setHeightForWidth(ani->sizePolicy().hasHeightForWidth());
        ani->setSizePolicy(sizePolicy1);
        ani->setMinimumSize(QSize(40, 40));
        ani->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(ani, 1, 0, 1, 1);

        obf = new DisciplineButton(CardgroupBoxDiscipline);
        obf->setObjectName(QStringLiteral("obf"));
        sizePolicy1.setHeightForWidth(obf->sizePolicy().hasHeightForWidth());
        obf->setSizePolicy(sizePolicy1);
        obf->setMinimumSize(QSize(40, 40));
        obf->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(obf, 1, 3, 1, 1);

        val = new DisciplineButton(CardgroupBoxDiscipline);
        val->setObjectName(QStringLiteral("val"));
        sizePolicy1.setHeightForWidth(val->sizePolicy().hasHeightForWidth());
        val->setSizePolicy(sizePolicy1);
        val->setMinimumSize(QSize(40, 40));
        val->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(val, 1, 6, 1, 1);

        stri = new DisciplineButton(CardgroupBoxDiscipline);
        stri->setObjectName(QStringLiteral("stri"));
        sizePolicy1.setHeightForWidth(stri->sizePolicy().hasHeightForWidth());
        stri->setSizePolicy(sizePolicy1);
        stri->setMinimumSize(QSize(40, 40));
        stri->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(stri, 3, 7, 1, 1);

        pro = new DisciplineButton(CardgroupBoxDiscipline);
        pro->setObjectName(QStringLiteral("pro"));
        sizePolicy1.setHeightForWidth(pro->sizePolicy().hasHeightForWidth());
        pro->setSizePolicy(sizePolicy1);
        pro->setMinimumSize(QSize(40, 40));
        pro->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(pro, 1, 4, 1, 1);

        spi = new DisciplineButton(CardgroupBoxDiscipline);
        spi->setObjectName(QStringLiteral("spi"));
        sizePolicy1.setHeightForWidth(spi->sizePolicy().hasHeightForWidth());
        spi->setSizePolicy(sizePolicy1);
        spi->setMinimumSize(QSize(40, 40));
        spi->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(spi, 1, 5, 1, 1);

        thn = new DisciplineButton(CardgroupBoxDiscipline);
        thn->setObjectName(QStringLiteral("thn"));
        sizePolicy1.setHeightForWidth(thn->sizePolicy().hasHeightForWidth());
        thn->setSizePolicy(sizePolicy1);
        thn->setMinimumSize(QSize(40, 40));
        thn->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(thn, 0, 6, 1, 1);

        mel = new DisciplineButton(CardgroupBoxDiscipline);
        mel->setObjectName(QStringLiteral("mel"));
        sizePolicy1.setHeightForWidth(mel->sizePolicy().hasHeightForWidth());
        mel->setSizePolicy(sizePolicy1);
        mel->setMinimumSize(QSize(40, 40));
        mel->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(mel, 1, 2, 1, 1);

        mal = new DisciplineButton(CardgroupBoxDiscipline);
        mal->setObjectName(QStringLiteral("mal"));
        sizePolicy1.setHeightForWidth(mal->sizePolicy().hasHeightForWidth());
        mal->setSizePolicy(sizePolicy1);
        mal->setMinimumSize(QSize(40, 40));
        mal->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(mal, 2, 7, 1, 1);

        CardgroupBoxRequirements = new QGroupBox(CardSearchFrame);
        CardgroupBoxRequirements->setObjectName(QStringLiteral("CardgroupBoxRequirements"));
        CardgroupBoxRequirements->setGeometry(QRect(0, 121, 431, 141));
        label_49 = new QLabel(CardgroupBoxRequirements);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(12, 22, 41, 16));
        Flight = new QCheckBox(CardgroupBoxRequirements);
        Flight->setObjectName(QStringLiteral("Flight"));
        Flight->setGeometry(QRect(353, 22, 61, 20));
        Flight->setLayoutDirection(Qt::RightToLeft);
        BlackHand = new QCheckBox(CardgroupBoxRequirements);
        BlackHand->setObjectName(QStringLiteral("BlackHand"));
        BlackHand->setGeometry(QRect(323, 62, 91, 20));
        BlackHand->setLayoutDirection(Qt::RightToLeft);
        Infernal = new QCheckBox(CardgroupBoxRequirements);
        Infernal->setObjectName(QStringLiteral("Infernal"));
        Infernal->setGeometry(QRect(242, 102, 71, 20));
        Infernal->setLayoutDirection(Qt::RightToLeft);
        RedList = new QCheckBox(CardgroupBoxRequirements);
        RedList->setObjectName(QStringLiteral("RedList"));
        RedList->setGeometry(QRect(242, 62, 71, 20));
        RedList->setLayoutDirection(Qt::RightToLeft);
        cBClan_2 = new QComboBox(CardgroupBoxRequirements);
        cBClan_2->setObjectName(QStringLiteral("cBClan_2"));
        cBClan_2->setGeometry(QRect(43, 22, 191, 22));
        cBSect_2 = new QComboBox(CardgroupBoxRequirements);
        cBSect_2->setObjectName(QStringLiteral("cBSect_2"));
        cBSect_2->setGeometry(QRect(43, 62, 191, 21));
        lSect_2 = new QLabel(CardgroupBoxRequirements);
        lSect_2->setObjectName(QStringLiteral("lSect_2"));
        lSect_2->setGeometry(QRect(12, 62, 31, 16));
        Seraph = new QCheckBox(CardgroupBoxRequirements);
        Seraph->setObjectName(QStringLiteral("Seraph"));
        Seraph->setGeometry(QRect(333, 102, 81, 20));
        Seraph->setLayoutDirection(Qt::RightToLeft);
        lFortitude_4 = new QLabel(CardgroupBoxRequirements);
        lFortitude_4->setObjectName(QStringLiteral("lFortitude_4"));
        lFortitude_4->setGeometry(QRect(327, 22, 29, 19));
        lFortitude_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/flight.gif")));
        lTitle_2 = new QLabel(CardgroupBoxRequirements);
        lTitle_2->setObjectName(QStringLiteral("lTitle_2"));
        lTitle_2->setGeometry(QRect(12, 102, 41, 16));
        cBTitle_2 = new QComboBox(CardgroupBoxRequirements);
        cBTitle_2->setObjectName(QStringLiteral("cBTitle_2"));
        cBTitle_2->setGeometry(QRect(43, 102, 191, 21));
        Anarch = new QCheckBox(CardgroupBoxRequirements);
        Anarch->setObjectName(QStringLiteral("Anarch"));
        Anarch->setGeometry(QRect(242, 22, 71, 20));
        Anarch->setLayoutDirection(Qt::RightToLeft);
        CardgroupBoxOthers = new QGroupBox(CardSearchFrame);
        CardgroupBoxOthers->setObjectName(QStringLiteral("CardgroupBoxOthers"));
        CardgroupBoxOthers->setGeometry(QRect(438, 121, 251, 141));
        BurnOption = new QCheckBox(CardgroupBoxOthers);
        BurnOption->setObjectName(QStringLiteral("BurnOption"));
        BurnOption->setGeometry(QRect(32, 17, 91, 20));
        BurnOption->setLayoutDirection(Qt::RightToLeft);
        Anarch_3_Way = new QCheckBox(CardgroupBoxOthers);
        Anarch_3_Way->setObjectName(QStringLiteral("Anarch_3_Way"));
        Anarch_3_Way->setGeometry(QRect(132, 17, 102, 20));
        Anarch_3_Way->setLayoutDirection(Qt::RightToLeft);
        Dual_discipline = new QCheckBox(CardgroupBoxOthers);
        Dual_discipline->setObjectName(QStringLiteral("Dual_discipline"));
        Dual_discipline->setGeometry(QRect(12, 47, 111, 20));
        Dual_discipline->setLayoutDirection(Qt::RightToLeft);
        Multi_discipline = new QCheckBox(CardgroupBoxOthers);
        Multi_discipline->setObjectName(QStringLiteral("Multi_discipline"));
        Multi_discipline->setGeometry(QRect(122, 47, 112, 20));
        Multi_discipline->setLayoutDirection(Qt::RightToLeft);
        lFortitude_3 = new QLabel(CardgroupBoxOthers);
        lFortitude_3->setObjectName(QStringLiteral("lFortitude_3"));
        lFortitude_3->setGeometry(QRect(12, 19, 19, 19));
        lFortitude_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/burn_option.gif")));
        Boon = new QCheckBox(CardgroupBoxOthers);
        Boon->setObjectName(QStringLiteral("Boon"));
        Boon->setGeometry(QRect(12, 77, 111, 20));
        Boon->setLayoutDirection(Qt::RightToLeft);
        Grapple = new QCheckBox(CardgroupBoxOthers);
        Grapple->setObjectName(QStringLiteral("Grapple"));
        Grapple->setGeometry(QRect(122, 77, 111, 20));
        Grapple->setLayoutDirection(Qt::RightToLeft);
        Frenzy = new QCheckBox(CardgroupBoxOthers);
        Frenzy->setObjectName(QStringLiteral("Frenzy"));
        Frenzy->setGeometry(QRect(12, 107, 111, 20));
        Frenzy->setLayoutDirection(Qt::RightToLeft);
        Aim = new QCheckBox(CardgroupBoxOthers);
        Aim->setObjectName(QStringLiteral("Aim"));
        Aim->setGeometry(QRect(122, 107, 111, 20));
        Aim->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(CardSearchFrame);

        horizontalSpacer = new QSpacerItem(215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        VisuelCarte = new QLabel(frame);
        VisuelCarte->setObjectName(QStringLiteral("VisuelCarte"));
        sizePolicy1.setHeightForWidth(VisuelCarte->sizePolicy().hasHeightForWidth());
        VisuelCarte->setSizePolicy(sizePolicy1);
        VisuelCarte->setMinimumSize(QSize(360, 500));
        VisuelCarte->setMaximumSize(QSize(360, 500));
        VisuelCarte->setFrameShape(QFrame::StyledPanel);
        VisuelCarte->setFrameShadow(QFrame::Sunken);
        VisuelCarte->setLineWidth(0);
        VisuelCarte->setPixmap(QPixmap(QString::fromUtf8("../../jr/Desktop/Vtes_Grelarge.gif")));

        horizontalLayout->addWidget(VisuelCarte);

        PTVCardsResults = new PItemView(frame);
        PTVCardsResults->setObjectName(QStringLiteral("PTVCardsResults"));
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
        CardgroupBoxVirtues->setTitle(QApplication::translate("tab_search_library", "Virtues :  ", 0));
        def->setText(QString());
        inn->setText(QString());
        jud->setText(QString());
        mar->setText(QString());
        red->setText(QString());
        ven->setText(QString());
        vis2->setText(QString());
        CardgroupBoxCout->setTitle(QApplication::translate("tab_search_library", "Costs", 0));
        label_39->setText(QApplication::translate("tab_search_library", "Pool cost :", 0));
        label_41->setText(QApplication::translate("tab_search_library", "Conviction cost :", 0));
        label_37->setText(QApplication::translate("tab_search_library", "Blood cost :", 0));
        CardgroupBoxGeneral->setTitle(QApplication::translate("tab_search_library", "General ", 0));
        label_31->setText(QApplication::translate("tab_search_library", "Name :", 0));
        label_33->setText(QApplication::translate("tab_search_library", "Text ", 0));
        label_35->setText(QApplication::translate("tab_search_library", "Artist :", 0));
        label_47->setText(QApplication::translate("tab_search_library", "Set :", 0));
        label_45->setText(QApplication::translate("tab_search_library", "Rarity", 0));
        CardgroupBoxOptions->setTitle(QApplication::translate("tab_search_library", "Actions ", 0));
        pBCardSearch->setText(QApplication::translate("tab_search_library", "Search", 0));
        pBCardClearForm->setText(QApplication::translate("tab_search_library", "Clear Form", 0));
        CardgroupBoxFilters->setTitle(QApplication::translate("tab_search_library", "Filters ", 0));
        label_43->setText(QApplication::translate("tab_search_library", "Type", 0));
        label_4->setText(QApplication::translate("tab_search_library", "Sous type", 0));
        CardgroupBoxDiscipline->setTitle(QApplication::translate("tab_search_library", "Disciplines : ", 0));
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
        label_49->setText(QApplication::translate("tab_search_library", "Clan :", 0));
        Flight->setText(QApplication::translate("tab_search_library", "Flight", 0));
        BlackHand->setText(QApplication::translate("tab_search_library", "Black hand", 0));
        Infernal->setText(QApplication::translate("tab_search_library", "Infernal", 0));
        RedList->setText(QApplication::translate("tab_search_library", "Red list", 0));
        lSect_2->setText(QApplication::translate("tab_search_library", "Sect", 0));
        Seraph->setText(QApplication::translate("tab_search_library", "Seraph", 0));
        lFortitude_4->setText(QString());
        lTitle_2->setText(QApplication::translate("tab_search_library", "Title :", 0));
        Anarch->setText(QApplication::translate("tab_search_library", "Anarch", 0));
        CardgroupBoxOthers->setTitle(QApplication::translate("tab_search_library", "Key words ", 0));
        BurnOption->setText(QApplication::translate("tab_search_library", "Burn Option", 0));
        Anarch_3_Way->setText(QApplication::translate("tab_search_library", "Anarch 3-way", 0));
        Dual_discipline->setText(QApplication::translate("tab_search_library", "Dual disciplines", 0));
        Multi_discipline->setText(QApplication::translate("tab_search_library", "Multi discipline", 0));
        lFortitude_3->setText(QString());
        Boon->setText(QApplication::translate("tab_search_library", "Boon", 0));
        Grapple->setText(QApplication::translate("tab_search_library", "Grapple", 0));
        Frenzy->setText(QApplication::translate("tab_search_library", "Frenzy", 0));
        Aim->setText(QApplication::translate("tab_search_library", "Aim", 0));
        VisuelCarte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tab_search_library: public Ui_tab_search_library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_SEARCH_LIBRARY_H

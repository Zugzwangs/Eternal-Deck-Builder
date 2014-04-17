/********************************************************************************
** Form generated from reading UI file 'tab_search_crypt.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_SEARCH_CRYPT_H
#define UI_TAB_SEARCH_CRYPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pitemview.h"

QT_BEGIN_NAMESPACE

class Ui_tab_search_crypt
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFrame *CryptSearchFrame;
    QGroupBox *groupBoxText;
    QLineEdit *lENameCard;
    QLabel *lName;
    QLabel *lCardText;
    QLabel *lArtist;
    QLineEdit *lEArtist;
    QLineEdit *lETextCard;
    QLabel *label_48;
    QComboBox *cBSet_2;
    QComboBox *cBRarity_2;
    QLabel *label_46;
    QGroupBox *groupBoxDiscipline;
    QGridLayout *gridLayout;
    QLabel *lAbombwe;
    QComboBox *abo;
    QLabel *lDominate;
    QComboBox *dom;
    QLabel *lObtenebration;
    QComboBox *obt;
    QLabel *lSpiritus;
    QComboBox *spi;
    QLabel *lAnimalism;
    QComboBox *ani;
    QLabel *lFortitude;
    QComboBox *for_2;
    QLabel *lPotence;
    QComboBox *pot;
    QLabel *lTemporis;
    QComboBox *tem;
    QLabel *lAuspex;
    QComboBox *aus;
    QLabel *lMelpominee;
    QComboBox *mel;
    QLabel *lPresence;
    QComboBox *pre;
    QLabel *lThanatosis;
    QComboBox *thn;
    QLabel *lCelerity;
    QComboBox *cel;
    QLabel *lMytherceria;
    QComboBox *myt;
    QLabel *lProtean;
    QComboBox *pro;
    QLabel *lThaumaturgy;
    QComboBox *tha;
    QLabel *lChimerstry;
    QComboBox *chi;
    QLabel *lNecromancy;
    QComboBox *nec;
    QLabel *lQuietus;
    QComboBox *qui;
    QLabel *lValeren;
    QComboBox *val;
    QLabel *lDaimoinon;
    QComboBox *dai;
    QLabel *lObeah;
    QComboBox *obe;
    QLabel *lSanguinus;
    QComboBox *san;
    QLabel *lVicissitude;
    QComboBox *vic;
    QLabel *lDementation;
    QComboBox *dem;
    QLabel *lObfuscate;
    QComboBox *obf;
    QLabel *lSerpentis;
    QComboBox *ser;
    QLabel *lVisceratika;
    QComboBox *vis;
    QGroupBox *groupBoxVirtues;
    QFormLayout *formLayout;
    QLabel *lDefense;
    QComboBox *def;
    QLabel *lInnocence;
    QComboBox *inn;
    QLabel *lJudgment;
    QComboBox *jud;
    QLabel *lMartyrdom;
    QComboBox *mar;
    QLabel *lRedemption;
    QComboBox *red;
    QLabel *lVengeance;
    QComboBox *ven;
    QLabel *lVision;
    QComboBox *vis2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QGroupBox *groupBoxTrait;
    QCheckBox *ckBFlight;
    QCheckBox *ckBInfernal;
    QCheckBox *ckBBlackHand;
    QCheckBox *ckBRedList;
    QCheckBox *ckBSeraph;
    QCheckBox *ckBSlave;
    QCheckBox *ckBBloodCurse;
    QCheckBox *ckBScare;
    QCheckBox *ckBSterile;
    QLabel *lSect;
    QComboBox *cBSect;
    QLabel *lClan;
    QComboBox *cBTitle;
    QLabel *lTitle;
    QComboBox *cBClan;
    QGroupBox *groupBox_2;
    QPushButton *pBCryptClearForm;
    QPushButton *pBCryptSearch;
    QGroupBox *groupBox;
    QLabel *label_21;
    QLabel *label_29;
    QSpinBox *sBGroup;
    QComboBox *cBCapa;
    QSpinBox *sBCapa;
    QComboBox *cBGroup;
    PItemView *PTVCryptResults;

    void setupUi(QScrollArea *tab_search_crypt)
    {
        if (tab_search_crypt->objectName().isEmpty())
            tab_search_crypt->setObjectName(QStringLiteral("tab_search_crypt"));
        tab_search_crypt->resize(1035, 650);
        tab_search_crypt->setWindowOpacity(0);
        tab_search_crypt->setAutoFillBackground(true);
        tab_search_crypt->setFrameShape(QFrame::NoFrame);
        tab_search_crypt->setFrameShadow(QFrame::Plain);
        tab_search_crypt->setLineWidth(0);
        tab_search_crypt->setWidgetResizable(true);
        tab_search_crypt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1042, 629));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        CryptSearchFrame = new QFrame(scrollAreaWidgetContents);
        CryptSearchFrame->setObjectName(QStringLiteral("CryptSearchFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CryptSearchFrame->sizePolicy().hasHeightForWidth());
        CryptSearchFrame->setSizePolicy(sizePolicy);
        CryptSearchFrame->setMinimumSize(QSize(1020, 340));
        CryptSearchFrame->setAutoFillBackground(true);
        CryptSearchFrame->setFrameShape(QFrame::NoFrame);
        CryptSearchFrame->setFrameShadow(QFrame::Plain);
        CryptSearchFrame->setLineWidth(0);
        groupBoxText = new QGroupBox(CryptSearchFrame);
        groupBoxText->setObjectName(QStringLiteral("groupBoxText"));
        groupBoxText->setGeometry(QRect(0, 0, 521, 130));
        lENameCard = new QLineEdit(groupBoxText);
        lENameCard->setObjectName(QStringLiteral("lENameCard"));
        lENameCard->setGeometry(QRect(50, 22, 200, 22));
        lName = new QLabel(groupBoxText);
        lName->setObjectName(QStringLiteral("lName"));
        lName->setGeometry(QRect(8, 22, 41, 16));
        lCardText = new QLabel(groupBoxText);
        lCardText->setObjectName(QStringLiteral("lCardText"));
        lCardText->setGeometry(QRect(16, 56, 31, 16));
        lArtist = new QLabel(groupBoxText);
        lArtist->setObjectName(QStringLiteral("lArtist"));
        lArtist->setGeometry(QRect(278, 22, 31, 16));
        lEArtist = new QLineEdit(groupBoxText);
        lEArtist->setObjectName(QStringLiteral("lEArtist"));
        lEArtist->setGeometry(QRect(316, 22, 165, 22));
        lETextCard = new QLineEdit(groupBoxText);
        lETextCard->setObjectName(QStringLiteral("lETextCard"));
        lETextCard->setGeometry(QRect(50, 56, 431, 21));
        label_48 = new QLabel(groupBoxText);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(20, 92, 21, 16));
        cBSet_2 = new QComboBox(groupBoxText);
        cBSet_2->setObjectName(QStringLiteral("cBSet_2"));
        cBSet_2->setGeometry(QRect(50, 91, 181, 22));
        cBRarity_2 = new QComboBox(groupBoxText);
        cBRarity_2->setObjectName(QStringLiteral("cBRarity_2"));
        cBRarity_2->setGeometry(QRect(331, 91, 151, 22));
        label_46 = new QLabel(groupBoxText);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(278, 92, 41, 16));
        groupBoxDiscipline = new QGroupBox(CryptSearchFrame);
        groupBoxDiscipline->setObjectName(QStringLiteral("groupBoxDiscipline"));
        groupBoxDiscipline->setGeometry(QRect(526, 0, 371, 331));
        groupBoxDiscipline->setAutoFillBackground(false);
        groupBoxDiscipline->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(groupBoxDiscipline);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 0, 6, 0);
        lAbombwe = new QLabel(groupBoxDiscipline);
        lAbombwe->setObjectName(QStringLiteral("lAbombwe"));
        sizePolicy.setHeightForWidth(lAbombwe->sizePolicy().hasHeightForWidth());
        lAbombwe->setSizePolicy(sizePolicy);
        lAbombwe->setMinimumSize(QSize(22, 22));
        lAbombwe->setMaximumSize(QSize(22, 22));
        lAbombwe->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/abo.png")));
        lAbombwe->setScaledContents(true);

        gridLayout->addWidget(lAbombwe, 0, 0, 1, 1);

        abo = new QComboBox(groupBoxDiscipline);
        abo->setObjectName(QStringLiteral("abo"));

        gridLayout->addWidget(abo, 0, 1, 1, 1);

        lDominate = new QLabel(groupBoxDiscipline);
        lDominate->setObjectName(QStringLiteral("lDominate"));
        lDominate->setMinimumSize(QSize(22, 22));
        lDominate->setMaximumSize(QSize(22, 22));
        lDominate->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/dom.png")));
        lDominate->setScaledContents(true);

        gridLayout->addWidget(lDominate, 0, 2, 1, 1);

        dom = new QComboBox(groupBoxDiscipline);
        dom->setObjectName(QStringLiteral("dom"));

        gridLayout->addWidget(dom, 0, 3, 1, 1);

        lObtenebration = new QLabel(groupBoxDiscipline);
        lObtenebration->setObjectName(QStringLiteral("lObtenebration"));
        lObtenebration->setMinimumSize(QSize(22, 22));
        lObtenebration->setMaximumSize(QSize(22, 22));
        lObtenebration->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/obt.png")));
        lObtenebration->setScaledContents(true);

        gridLayout->addWidget(lObtenebration, 0, 4, 1, 1);

        obt = new QComboBox(groupBoxDiscipline);
        obt->setObjectName(QStringLiteral("obt"));

        gridLayout->addWidget(obt, 0, 5, 1, 1);

        lSpiritus = new QLabel(groupBoxDiscipline);
        lSpiritus->setObjectName(QStringLiteral("lSpiritus"));
        sizePolicy.setHeightForWidth(lSpiritus->sizePolicy().hasHeightForWidth());
        lSpiritus->setSizePolicy(sizePolicy);
        lSpiritus->setMinimumSize(QSize(22, 22));
        lSpiritus->setMaximumSize(QSize(22, 22));
        lSpiritus->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/spi.png")));
        lSpiritus->setScaledContents(true);

        gridLayout->addWidget(lSpiritus, 0, 6, 1, 1);

        spi = new QComboBox(groupBoxDiscipline);
        spi->setObjectName(QStringLiteral("spi"));

        gridLayout->addWidget(spi, 0, 7, 1, 1);

        lAnimalism = new QLabel(groupBoxDiscipline);
        lAnimalism->setObjectName(QStringLiteral("lAnimalism"));
        sizePolicy.setHeightForWidth(lAnimalism->sizePolicy().hasHeightForWidth());
        lAnimalism->setSizePolicy(sizePolicy);
        lAnimalism->setMinimumSize(QSize(22, 22));
        lAnimalism->setMaximumSize(QSize(22, 22));
        lAnimalism->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/ani.png")));
        lAnimalism->setScaledContents(true);

        gridLayout->addWidget(lAnimalism, 1, 0, 1, 1);

        ani = new QComboBox(groupBoxDiscipline);
        ani->setObjectName(QStringLiteral("ani"));

        gridLayout->addWidget(ani, 1, 1, 1, 1);

        lFortitude = new QLabel(groupBoxDiscipline);
        lFortitude->setObjectName(QStringLiteral("lFortitude"));
        lFortitude->setMinimumSize(QSize(22, 22));
        lFortitude->setMaximumSize(QSize(22, 22));
        lFortitude->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/for.png")));
        lFortitude->setScaledContents(true);

        gridLayout->addWidget(lFortitude, 1, 2, 1, 1);

        for_2 = new QComboBox(groupBoxDiscipline);
        for_2->setObjectName(QStringLiteral("for_2"));

        gridLayout->addWidget(for_2, 1, 3, 1, 1);

        lPotence = new QLabel(groupBoxDiscipline);
        lPotence->setObjectName(QStringLiteral("lPotence"));
        sizePolicy.setHeightForWidth(lPotence->sizePolicy().hasHeightForWidth());
        lPotence->setSizePolicy(sizePolicy);
        lPotence->setMinimumSize(QSize(22, 22));
        lPotence->setMaximumSize(QSize(22, 22));
        lPotence->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/pot.png")));
        lPotence->setScaledContents(true);

        gridLayout->addWidget(lPotence, 1, 4, 1, 1);

        pot = new QComboBox(groupBoxDiscipline);
        pot->setObjectName(QStringLiteral("pot"));

        gridLayout->addWidget(pot, 1, 5, 1, 1);

        lTemporis = new QLabel(groupBoxDiscipline);
        lTemporis->setObjectName(QStringLiteral("lTemporis"));
        sizePolicy.setHeightForWidth(lTemporis->sizePolicy().hasHeightForWidth());
        lTemporis->setSizePolicy(sizePolicy);
        lTemporis->setMinimumSize(QSize(22, 22));
        lTemporis->setMaximumSize(QSize(22, 22));
        lTemporis->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/tem.png")));
        lTemporis->setScaledContents(true);

        gridLayout->addWidget(lTemporis, 1, 6, 1, 1);

        tem = new QComboBox(groupBoxDiscipline);
        tem->setObjectName(QStringLiteral("tem"));

        gridLayout->addWidget(tem, 1, 7, 1, 1);

        lAuspex = new QLabel(groupBoxDiscipline);
        lAuspex->setObjectName(QStringLiteral("lAuspex"));
        sizePolicy.setHeightForWidth(lAuspex->sizePolicy().hasHeightForWidth());
        lAuspex->setSizePolicy(sizePolicy);
        lAuspex->setMinimumSize(QSize(22, 22));
        lAuspex->setMaximumSize(QSize(22, 22));
        lAuspex->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/aus.png")));
        lAuspex->setScaledContents(true);

        gridLayout->addWidget(lAuspex, 2, 0, 1, 1);

        aus = new QComboBox(groupBoxDiscipline);
        aus->setObjectName(QStringLiteral("aus"));

        gridLayout->addWidget(aus, 2, 1, 1, 1);

        lMelpominee = new QLabel(groupBoxDiscipline);
        lMelpominee->setObjectName(QStringLiteral("lMelpominee"));
        lMelpominee->setMinimumSize(QSize(22, 22));
        lMelpominee->setMaximumSize(QSize(22, 22));
        lMelpominee->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/mel.png")));
        lMelpominee->setScaledContents(true);

        gridLayout->addWidget(lMelpominee, 2, 2, 1, 1);

        mel = new QComboBox(groupBoxDiscipline);
        mel->setObjectName(QStringLiteral("mel"));

        gridLayout->addWidget(mel, 2, 3, 1, 1);

        lPresence = new QLabel(groupBoxDiscipline);
        lPresence->setObjectName(QStringLiteral("lPresence"));
        sizePolicy.setHeightForWidth(lPresence->sizePolicy().hasHeightForWidth());
        lPresence->setSizePolicy(sizePolicy);
        lPresence->setMinimumSize(QSize(22, 22));
        lPresence->setMaximumSize(QSize(22, 22));
        lPresence->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/pre.png")));
        lPresence->setScaledContents(true);

        gridLayout->addWidget(lPresence, 2, 4, 1, 1);

        pre = new QComboBox(groupBoxDiscipline);
        pre->setObjectName(QStringLiteral("pre"));

        gridLayout->addWidget(pre, 2, 5, 1, 1);

        lThanatosis = new QLabel(groupBoxDiscipline);
        lThanatosis->setObjectName(QStringLiteral("lThanatosis"));
        sizePolicy.setHeightForWidth(lThanatosis->sizePolicy().hasHeightForWidth());
        lThanatosis->setSizePolicy(sizePolicy);
        lThanatosis->setMinimumSize(QSize(22, 22));
        lThanatosis->setMaximumSize(QSize(22, 22));
        lThanatosis->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/tha.png")));
        lThanatosis->setScaledContents(true);

        gridLayout->addWidget(lThanatosis, 2, 6, 1, 1);

        thn = new QComboBox(groupBoxDiscipline);
        thn->setObjectName(QStringLiteral("thn"));

        gridLayout->addWidget(thn, 2, 7, 1, 1);

        lCelerity = new QLabel(groupBoxDiscipline);
        lCelerity->setObjectName(QStringLiteral("lCelerity"));
        sizePolicy.setHeightForWidth(lCelerity->sizePolicy().hasHeightForWidth());
        lCelerity->setSizePolicy(sizePolicy);
        lCelerity->setMinimumSize(QSize(22, 22));
        lCelerity->setMaximumSize(QSize(22, 22));
        lCelerity->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/cel.png")));
        lCelerity->setScaledContents(true);

        gridLayout->addWidget(lCelerity, 3, 0, 1, 1);

        cel = new QComboBox(groupBoxDiscipline);
        cel->setObjectName(QStringLiteral("cel"));

        gridLayout->addWidget(cel, 3, 1, 1, 1);

        lMytherceria = new QLabel(groupBoxDiscipline);
        lMytherceria->setObjectName(QStringLiteral("lMytherceria"));
        lMytherceria->setMinimumSize(QSize(22, 22));
        lMytherceria->setMaximumSize(QSize(22, 22));
        lMytherceria->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/myt.png")));
        lMytherceria->setScaledContents(true);

        gridLayout->addWidget(lMytherceria, 3, 2, 1, 1);

        myt = new QComboBox(groupBoxDiscipline);
        myt->setObjectName(QStringLiteral("myt"));

        gridLayout->addWidget(myt, 3, 3, 1, 1);

        lProtean = new QLabel(groupBoxDiscipline);
        lProtean->setObjectName(QStringLiteral("lProtean"));
        sizePolicy.setHeightForWidth(lProtean->sizePolicy().hasHeightForWidth());
        lProtean->setSizePolicy(sizePolicy);
        lProtean->setMinimumSize(QSize(22, 22));
        lProtean->setMaximumSize(QSize(22, 22));
        lProtean->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/pro.png")));
        lProtean->setScaledContents(true);

        gridLayout->addWidget(lProtean, 3, 4, 1, 1);

        pro = new QComboBox(groupBoxDiscipline);
        pro->setObjectName(QStringLiteral("pro"));

        gridLayout->addWidget(pro, 3, 5, 1, 1);

        lThaumaturgy = new QLabel(groupBoxDiscipline);
        lThaumaturgy->setObjectName(QStringLiteral("lThaumaturgy"));
        sizePolicy.setHeightForWidth(lThaumaturgy->sizePolicy().hasHeightForWidth());
        lThaumaturgy->setSizePolicy(sizePolicy);
        lThaumaturgy->setMinimumSize(QSize(22, 22));
        lThaumaturgy->setMaximumSize(QSize(22, 22));
        lThaumaturgy->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/thn.png")));
        lThaumaturgy->setScaledContents(true);

        gridLayout->addWidget(lThaumaturgy, 3, 6, 1, 1);

        tha = new QComboBox(groupBoxDiscipline);
        tha->setObjectName(QStringLiteral("tha"));

        gridLayout->addWidget(tha, 3, 7, 1, 1);

        lChimerstry = new QLabel(groupBoxDiscipline);
        lChimerstry->setObjectName(QStringLiteral("lChimerstry"));
        sizePolicy.setHeightForWidth(lChimerstry->sizePolicy().hasHeightForWidth());
        lChimerstry->setSizePolicy(sizePolicy);
        lChimerstry->setMinimumSize(QSize(22, 22));
        lChimerstry->setMaximumSize(QSize(22, 22));
        lChimerstry->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/chi.png")));
        lChimerstry->setScaledContents(true);

        gridLayout->addWidget(lChimerstry, 4, 0, 1, 1);

        chi = new QComboBox(groupBoxDiscipline);
        chi->setObjectName(QStringLiteral("chi"));

        gridLayout->addWidget(chi, 4, 1, 1, 1);

        lNecromancy = new QLabel(groupBoxDiscipline);
        lNecromancy->setObjectName(QStringLiteral("lNecromancy"));
        lNecromancy->setMinimumSize(QSize(22, 22));
        lNecromancy->setMaximumSize(QSize(22, 22));
        lNecromancy->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/nec.png")));
        lNecromancy->setScaledContents(true);

        gridLayout->addWidget(lNecromancy, 4, 2, 1, 1);

        nec = new QComboBox(groupBoxDiscipline);
        nec->setObjectName(QStringLiteral("nec"));

        gridLayout->addWidget(nec, 4, 3, 1, 1);

        lQuietus = new QLabel(groupBoxDiscipline);
        lQuietus->setObjectName(QStringLiteral("lQuietus"));
        sizePolicy.setHeightForWidth(lQuietus->sizePolicy().hasHeightForWidth());
        lQuietus->setSizePolicy(sizePolicy);
        lQuietus->setMinimumSize(QSize(22, 22));
        lQuietus->setMaximumSize(QSize(22, 22));
        lQuietus->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/qui.png")));
        lQuietus->setScaledContents(true);

        gridLayout->addWidget(lQuietus, 4, 4, 1, 1);

        qui = new QComboBox(groupBoxDiscipline);
        qui->setObjectName(QStringLiteral("qui"));

        gridLayout->addWidget(qui, 4, 5, 1, 1);

        lValeren = new QLabel(groupBoxDiscipline);
        lValeren->setObjectName(QStringLiteral("lValeren"));
        sizePolicy.setHeightForWidth(lValeren->sizePolicy().hasHeightForWidth());
        lValeren->setSizePolicy(sizePolicy);
        lValeren->setMinimumSize(QSize(22, 22));
        lValeren->setMaximumSize(QSize(22, 22));
        lValeren->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/val.png")));
        lValeren->setScaledContents(true);

        gridLayout->addWidget(lValeren, 4, 6, 1, 1);

        val = new QComboBox(groupBoxDiscipline);
        val->setObjectName(QStringLiteral("val"));

        gridLayout->addWidget(val, 4, 7, 1, 1);

        lDaimoinon = new QLabel(groupBoxDiscipline);
        lDaimoinon->setObjectName(QStringLiteral("lDaimoinon"));
        sizePolicy.setHeightForWidth(lDaimoinon->sizePolicy().hasHeightForWidth());
        lDaimoinon->setSizePolicy(sizePolicy);
        lDaimoinon->setMinimumSize(QSize(22, 22));
        lDaimoinon->setMaximumSize(QSize(22, 22));
        lDaimoinon->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/dai.png")));
        lDaimoinon->setScaledContents(true);

        gridLayout->addWidget(lDaimoinon, 5, 0, 1, 1);

        dai = new QComboBox(groupBoxDiscipline);
        dai->setObjectName(QStringLiteral("dai"));

        gridLayout->addWidget(dai, 5, 1, 1, 1);

        lObeah = new QLabel(groupBoxDiscipline);
        lObeah->setObjectName(QStringLiteral("lObeah"));
        lObeah->setMinimumSize(QSize(22, 22));
        lObeah->setMaximumSize(QSize(22, 22));
        lObeah->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/obe.png")));
        lObeah->setScaledContents(true);

        gridLayout->addWidget(lObeah, 5, 2, 1, 1);

        obe = new QComboBox(groupBoxDiscipline);
        obe->setObjectName(QStringLiteral("obe"));

        gridLayout->addWidget(obe, 5, 3, 1, 1);

        lSanguinus = new QLabel(groupBoxDiscipline);
        lSanguinus->setObjectName(QStringLiteral("lSanguinus"));
        sizePolicy.setHeightForWidth(lSanguinus->sizePolicy().hasHeightForWidth());
        lSanguinus->setSizePolicy(sizePolicy);
        lSanguinus->setMinimumSize(QSize(22, 22));
        lSanguinus->setMaximumSize(QSize(22, 22));
        lSanguinus->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/san.png")));
        lSanguinus->setScaledContents(true);

        gridLayout->addWidget(lSanguinus, 5, 4, 1, 1);

        san = new QComboBox(groupBoxDiscipline);
        san->setObjectName(QStringLiteral("san"));

        gridLayout->addWidget(san, 5, 5, 1, 1);

        lVicissitude = new QLabel(groupBoxDiscipline);
        lVicissitude->setObjectName(QStringLiteral("lVicissitude"));
        sizePolicy.setHeightForWidth(lVicissitude->sizePolicy().hasHeightForWidth());
        lVicissitude->setSizePolicy(sizePolicy);
        lVicissitude->setMinimumSize(QSize(22, 22));
        lVicissitude->setMaximumSize(QSize(22, 22));
        lVicissitude->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/vic.png")));
        lVicissitude->setScaledContents(true);

        gridLayout->addWidget(lVicissitude, 5, 6, 1, 1);

        vic = new QComboBox(groupBoxDiscipline);
        vic->setObjectName(QStringLiteral("vic"));

        gridLayout->addWidget(vic, 5, 7, 1, 1);

        lDementation = new QLabel(groupBoxDiscipline);
        lDementation->setObjectName(QStringLiteral("lDementation"));
        sizePolicy.setHeightForWidth(lDementation->sizePolicy().hasHeightForWidth());
        lDementation->setSizePolicy(sizePolicy);
        lDementation->setMinimumSize(QSize(22, 22));
        lDementation->setMaximumSize(QSize(22, 22));
        lDementation->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/dem.png")));
        lDementation->setScaledContents(true);

        gridLayout->addWidget(lDementation, 6, 0, 1, 1);

        dem = new QComboBox(groupBoxDiscipline);
        dem->setObjectName(QStringLiteral("dem"));

        gridLayout->addWidget(dem, 6, 1, 1, 1);

        lObfuscate = new QLabel(groupBoxDiscipline);
        lObfuscate->setObjectName(QStringLiteral("lObfuscate"));
        lObfuscate->setMinimumSize(QSize(22, 22));
        lObfuscate->setMaximumSize(QSize(22, 22));
        lObfuscate->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/obf.png")));
        lObfuscate->setScaledContents(true);

        gridLayout->addWidget(lObfuscate, 6, 2, 1, 1);

        obf = new QComboBox(groupBoxDiscipline);
        obf->setObjectName(QStringLiteral("obf"));

        gridLayout->addWidget(obf, 6, 3, 1, 1);

        lSerpentis = new QLabel(groupBoxDiscipline);
        lSerpentis->setObjectName(QStringLiteral("lSerpentis"));
        sizePolicy.setHeightForWidth(lSerpentis->sizePolicy().hasHeightForWidth());
        lSerpentis->setSizePolicy(sizePolicy);
        lSerpentis->setMinimumSize(QSize(22, 22));
        lSerpentis->setMaximumSize(QSize(22, 22));
        lSerpentis->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/ser.png")));
        lSerpentis->setScaledContents(true);

        gridLayout->addWidget(lSerpentis, 6, 4, 1, 1);

        ser = new QComboBox(groupBoxDiscipline);
        ser->setObjectName(QStringLiteral("ser"));

        gridLayout->addWidget(ser, 6, 5, 1, 1);

        lVisceratika = new QLabel(groupBoxDiscipline);
        lVisceratika->setObjectName(QStringLiteral("lVisceratika"));
        sizePolicy.setHeightForWidth(lVisceratika->sizePolicy().hasHeightForWidth());
        lVisceratika->setSizePolicy(sizePolicy);
        lVisceratika->setMinimumSize(QSize(22, 22));
        lVisceratika->setMaximumSize(QSize(22, 22));
        lVisceratika->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/vis.png")));
        lVisceratika->setScaledContents(true);

        gridLayout->addWidget(lVisceratika, 6, 6, 1, 1);

        vis = new QComboBox(groupBoxDiscipline);
        vis->setObjectName(QStringLiteral("vis"));

        gridLayout->addWidget(vis, 6, 7, 1, 1);

        groupBoxVirtues = new QGroupBox(CryptSearchFrame);
        groupBoxVirtues->setObjectName(QStringLiteral("groupBoxVirtues"));
        groupBoxVirtues->setGeometry(QRect(900, 0, 110, 331));
        formLayout = new QFormLayout(groupBoxVirtues);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lDefense = new QLabel(groupBoxVirtues);
        lDefense->setObjectName(QStringLiteral("lDefense"));
        sizePolicy.setHeightForWidth(lDefense->sizePolicy().hasHeightForWidth());
        lDefense->setSizePolicy(sizePolicy);
        lDefense->setMinimumSize(QSize(22, 22));
        lDefense->setMaximumSize(QSize(22, 22));
        lDefense->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/def.png")));
        lDefense->setScaledContents(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, lDefense);

        def = new QComboBox(groupBoxVirtues);
        def->setObjectName(QStringLiteral("def"));

        formLayout->setWidget(1, QFormLayout::FieldRole, def);

        lInnocence = new QLabel(groupBoxVirtues);
        lInnocence->setObjectName(QStringLiteral("lInnocence"));
        sizePolicy.setHeightForWidth(lInnocence->sizePolicy().hasHeightForWidth());
        lInnocence->setSizePolicy(sizePolicy);
        lInnocence->setMinimumSize(QSize(22, 22));
        lInnocence->setMaximumSize(QSize(22, 22));
        lInnocence->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/inn.png")));
        lInnocence->setScaledContents(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, lInnocence);

        inn = new QComboBox(groupBoxVirtues);
        inn->setObjectName(QStringLiteral("inn"));
        inn->setFrame(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, inn);

        lJudgment = new QLabel(groupBoxVirtues);
        lJudgment->setObjectName(QStringLiteral("lJudgment"));
        sizePolicy.setHeightForWidth(lJudgment->sizePolicy().hasHeightForWidth());
        lJudgment->setSizePolicy(sizePolicy);
        lJudgment->setMinimumSize(QSize(22, 22));
        lJudgment->setMaximumSize(QSize(22, 22));
        lJudgment->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/jud.png")));
        lJudgment->setScaledContents(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, lJudgment);

        jud = new QComboBox(groupBoxVirtues);
        jud->setObjectName(QStringLiteral("jud"));

        formLayout->setWidget(5, QFormLayout::FieldRole, jud);

        lMartyrdom = new QLabel(groupBoxVirtues);
        lMartyrdom->setObjectName(QStringLiteral("lMartyrdom"));
        sizePolicy.setHeightForWidth(lMartyrdom->sizePolicy().hasHeightForWidth());
        lMartyrdom->setSizePolicy(sizePolicy);
        lMartyrdom->setMinimumSize(QSize(22, 22));
        lMartyrdom->setMaximumSize(QSize(22, 22));
        lMartyrdom->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/mar.png")));
        lMartyrdom->setScaledContents(true);

        formLayout->setWidget(7, QFormLayout::LabelRole, lMartyrdom);

        mar = new QComboBox(groupBoxVirtues);
        mar->setObjectName(QStringLiteral("mar"));

        formLayout->setWidget(7, QFormLayout::FieldRole, mar);

        lRedemption = new QLabel(groupBoxVirtues);
        lRedemption->setObjectName(QStringLiteral("lRedemption"));
        sizePolicy.setHeightForWidth(lRedemption->sizePolicy().hasHeightForWidth());
        lRedemption->setSizePolicy(sizePolicy);
        lRedemption->setMinimumSize(QSize(22, 22));
        lRedemption->setMaximumSize(QSize(22, 22));
        lRedemption->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/red.png")));
        lRedemption->setScaledContents(true);

        formLayout->setWidget(9, QFormLayout::LabelRole, lRedemption);

        red = new QComboBox(groupBoxVirtues);
        red->setObjectName(QStringLiteral("red"));

        formLayout->setWidget(9, QFormLayout::FieldRole, red);

        lVengeance = new QLabel(groupBoxVirtues);
        lVengeance->setObjectName(QStringLiteral("lVengeance"));
        sizePolicy.setHeightForWidth(lVengeance->sizePolicy().hasHeightForWidth());
        lVengeance->setSizePolicy(sizePolicy);
        lVengeance->setMinimumSize(QSize(22, 22));
        lVengeance->setMaximumSize(QSize(22, 22));
        lVengeance->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/ven.png")));
        lVengeance->setScaledContents(true);

        formLayout->setWidget(11, QFormLayout::LabelRole, lVengeance);

        ven = new QComboBox(groupBoxVirtues);
        ven->setObjectName(QStringLiteral("ven"));

        formLayout->setWidget(11, QFormLayout::FieldRole, ven);

        lVision = new QLabel(groupBoxVirtues);
        lVision->setObjectName(QStringLiteral("lVision"));
        sizePolicy.setHeightForWidth(lVision->sizePolicy().hasHeightForWidth());
        lVision->setSizePolicy(sizePolicy);
        lVision->setMinimumSize(QSize(22, 22));
        lVision->setMaximumSize(QSize(22, 22));
        lVision->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/vis2.png")));
        lVision->setScaledContents(true);

        formLayout->setWidget(13, QFormLayout::LabelRole, lVision);

        vis2 = new QComboBox(groupBoxVirtues);
        vis2->setObjectName(QStringLiteral("vis2"));

        formLayout->setWidget(13, QFormLayout::FieldRole, vis2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(14, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::LabelRole, verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::LabelRole, verticalSpacer_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::LabelRole, verticalSpacer_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(12, QFormLayout::FieldRole, verticalSpacer_8);

        groupBoxTrait = new QGroupBox(CryptSearchFrame);
        groupBoxTrait->setObjectName(QStringLiteral("groupBoxTrait"));
        groupBoxTrait->setGeometry(QRect(0, 130, 521, 141));
        ckBFlight = new QCheckBox(groupBoxTrait);
        ckBFlight->setObjectName(QStringLiteral("ckBFlight"));
        ckBFlight->setGeometry(QRect(356, 30, 61, 20));
        ckBFlight->setLayoutDirection(Qt::RightToLeft);
        ckBInfernal = new QCheckBox(groupBoxTrait);
        ckBInfernal->setObjectName(QStringLiteral("ckBInfernal"));
        ckBInfernal->setGeometry(QRect(346, 68, 71, 20));
        ckBInfernal->setLayoutDirection(Qt::RightToLeft);
        ckBBlackHand = new QCheckBox(groupBoxTrait);
        ckBBlackHand->setObjectName(QStringLiteral("ckBBlackHand"));
        ckBBlackHand->setGeometry(QRect(234, 30, 91, 20));
        ckBBlackHand->setLayoutDirection(Qt::RightToLeft);
        ckBRedList = new QCheckBox(groupBoxTrait);
        ckBRedList->setObjectName(QStringLiteral("ckBRedList"));
        ckBRedList->setGeometry(QRect(425, 108, 71, 20));
        ckBRedList->setLayoutDirection(Qt::RightToLeft);
        ckBSeraph = new QCheckBox(groupBoxTrait);
        ckBSeraph->setObjectName(QStringLiteral("ckBSeraph"));
        ckBSeraph->setGeometry(QRect(254, 68, 71, 20));
        ckBSeraph->setLayoutDirection(Qt::RightToLeft);
        ckBSlave = new QCheckBox(groupBoxTrait);
        ckBSlave->setObjectName(QStringLiteral("ckBSlave"));
        ckBSlave->setGeometry(QRect(435, 68, 61, 20));
        ckBSlave->setLayoutDirection(Qt::RightToLeft);
        ckBBloodCurse = new QCheckBox(groupBoxTrait);
        ckBBloodCurse->setObjectName(QStringLiteral("ckBBloodCurse"));
        ckBBloodCurse->setGeometry(QRect(336, 108, 81, 20));
        ckBBloodCurse->setLayoutDirection(Qt::RightToLeft);
        ckBScare = new QCheckBox(groupBoxTrait);
        ckBScare->setObjectName(QStringLiteral("ckBScare"));
        ckBScare->setGeometry(QRect(435, 30, 61, 20));
        ckBScare->setLayoutDirection(Qt::RightToLeft);
        ckBSterile = new QCheckBox(groupBoxTrait);
        ckBSterile->setObjectName(QStringLiteral("ckBSterile"));
        ckBSterile->setGeometry(QRect(254, 108, 71, 20));
        ckBSterile->setLayoutDirection(Qt::RightToLeft);
        lSect = new QLabel(groupBoxTrait);
        lSect->setObjectName(QStringLiteral("lSect"));
        lSect->setGeometry(QRect(10, 109, 31, 16));
        cBSect = new QComboBox(groupBoxTrait);
        cBSect->setObjectName(QStringLiteral("cBSect"));
        cBSect->setGeometry(QRect(43, 108, 185, 21));
        lClan = new QLabel(groupBoxTrait);
        lClan->setObjectName(QStringLiteral("lClan"));
        lClan->setGeometry(QRect(10, 29, 31, 16));
        cBTitle = new QComboBox(groupBoxTrait);
        cBTitle->setObjectName(QStringLiteral("cBTitle"));
        cBTitle->setGeometry(QRect(43, 68, 185, 21));
        lTitle = new QLabel(groupBoxTrait);
        lTitle->setObjectName(QStringLiteral("lTitle"));
        lTitle->setGeometry(QRect(10, 69, 31, 16));
        cBClan = new QComboBox(groupBoxTrait);
        cBClan->setObjectName(QStringLiteral("cBClan"));
        cBClan->setGeometry(QRect(43, 28, 185, 21));
        groupBox_2 = new QGroupBox(CryptSearchFrame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 270, 191, 61));
        pBCryptClearForm = new QPushButton(groupBox_2);
        pBCryptClearForm->setObjectName(QStringLiteral("pBCryptClearForm"));
        pBCryptClearForm->setGeometry(QRect(108, 20, 70, 30));
        pBCryptSearch = new QPushButton(groupBox_2);
        pBCryptSearch->setObjectName(QStringLiteral("pBCryptSearch"));
        pBCryptSearch->setGeometry(QRect(18, 20, 70, 30));
        groupBox = new QGroupBox(CryptSearchFrame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(197, 270, 324, 61));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 22, 41, 16));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(170, 22, 51, 16));
        sBGroup = new QSpinBox(groupBox);
        sBGroup->setObjectName(QStringLiteral("sBGroup"));
        sBGroup->setGeometry(QRect(108, 20, 41, 22));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        sBGroup->setFont(font);
        sBGroup->setMaximum(6);
        cBCapa = new QComboBox(groupBox);
        cBCapa->setObjectName(QStringLiteral("cBCapa"));
        cBCapa->setGeometry(QRect(225, 20, 41, 22));
        sBCapa = new QSpinBox(groupBox);
        sBCapa->setObjectName(QStringLiteral("sBCapa"));
        sBCapa->setGeometry(QRect(268, 20, 41, 22));
        sBCapa->setFont(font);
        sBCapa->setMaximum(11);
        cBGroup = new QComboBox(groupBox);
        cBGroup->setObjectName(QStringLiteral("cBGroup"));
        cBGroup->setGeometry(QRect(65, 20, 41, 22));

        verticalLayout->addWidget(CryptSearchFrame);

        PTVCryptResults = new PItemView(scrollAreaWidgetContents);
        PTVCryptResults->setObjectName(QStringLiteral("PTVCryptResults"));
        PTVCryptResults->setFrameShape(QFrame::NoFrame);
        PTVCryptResults->setAlternatingRowColors(true);
        PTVCryptResults->setShowGrid(false);

        verticalLayout->addWidget(PTVCryptResults);

        tab_search_crypt->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_search_crypt);

        QMetaObject::connectSlotsByName(tab_search_crypt);
    } // setupUi

    void retranslateUi(QScrollArea *tab_search_crypt)
    {
        tab_search_crypt->setWindowTitle(QApplication::translate("tab_search_crypt", "ScrollArea", 0));
        groupBoxText->setTitle(QApplication::translate("tab_search_crypt", "General : ", 0));
        lENameCard->setText(QString());
        lName->setText(QApplication::translate("tab_search_crypt", "Name", 0));
        lCardText->setText(QApplication::translate("tab_search_crypt", "Text", 0));
        lArtist->setText(QApplication::translate("tab_search_crypt", "Artist :", 0));
        label_48->setText(QApplication::translate("tab_search_crypt", "Set", 0));
        label_46->setText(QApplication::translate("tab_search_crypt", "Rarity", 0));
        groupBoxDiscipline->setTitle(QApplication::translate("tab_search_crypt", "Disciplines :  ", 0));
        lAbombwe->setText(QString());
        lDominate->setText(QString());
        lObtenebration->setText(QString());
        lSpiritus->setText(QString());
        lAnimalism->setText(QString());
        lFortitude->setText(QString());
        lPotence->setText(QString());
        lTemporis->setText(QString());
        lAuspex->setText(QString());
        lMelpominee->setText(QString());
        lPresence->setText(QString());
        lThanatosis->setText(QString());
        lMytherceria->setText(QString());
        lProtean->setText(QString());
        lThaumaturgy->setText(QString());
        lNecromancy->setText(QString());
        lQuietus->setText(QString());
        lValeren->setText(QString());
        lDaimoinon->setText(QString());
        lObeah->setText(QString());
        lSanguinus->setText(QString());
        lVicissitude->setText(QString());
        lDementation->setText(QString());
        lObfuscate->setText(QString());
        lSerpentis->setText(QString());
        lVisceratika->setText(QString());
        groupBoxVirtues->setTitle(QApplication::translate("tab_search_crypt", "Virtues :  ", 0));
        lDefense->setText(QString());
        def->clear();
        def->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        lInnocence->setText(QString());
        inn->clear();
        inn->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        lJudgment->setText(QString());
        jud->clear();
        jud->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        lMartyrdom->setText(QString());
        mar->clear();
        mar->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        lRedemption->setText(QString());
        red->clear();
        red->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        lVengeance->setText(QString());
        ven->clear();
        ven->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        lVision->setText(QString());
        vis2->clear();
        vis2->insertItems(0, QStringList()
         << QApplication::translate("tab_search_crypt", "Any", 0)
         << QApplication::translate("tab_search_crypt", "yes", 0)
         << QApplication::translate("tab_search_crypt", "None", 0)
        );
        groupBoxTrait->setTitle(QApplication::translate("tab_search_crypt", "Caracteristiques : ", 0));
        ckBFlight->setText(QApplication::translate("tab_search_crypt", "Flight", 0));
        ckBInfernal->setText(QApplication::translate("tab_search_crypt", "Infernal", 0));
        ckBBlackHand->setText(QApplication::translate("tab_search_crypt", "Black hand", 0));
        ckBRedList->setText(QApplication::translate("tab_search_crypt", "Red List", 0));
        ckBSeraph->setText(QApplication::translate("tab_search_crypt", "Seraph", 0));
        ckBSlave->setText(QApplication::translate("tab_search_crypt", "Slave", 0));
        ckBBloodCurse->setText(QApplication::translate("tab_search_crypt", "Blood curse", 0));
        ckBScare->setText(QApplication::translate("tab_search_crypt", "Scarce", 0));
        ckBSterile->setText(QApplication::translate("tab_search_crypt", "Sterile", 0));
        lSect->setText(QApplication::translate("tab_search_crypt", "Sect", 0));
        lClan->setText(QApplication::translate("tab_search_crypt", "Clan", 0));
        lTitle->setText(QApplication::translate("tab_search_crypt", "Title", 0));
        groupBox_2->setTitle(QApplication::translate("tab_search_crypt", "Options : ", 0));
        pBCryptClearForm->setText(QApplication::translate("tab_search_crypt", "Clear Form", 0));
        pBCryptSearch->setText(QApplication::translate("tab_search_crypt", "Recherche", 0));
        pBCryptSearch->setShortcut(QApplication::translate("tab_search_crypt", "F1", 0));
        groupBox->setTitle(QApplication::translate("tab_search_crypt", "GroupBox", 0));
        label_21->setText(QApplication::translate("tab_search_crypt", "Group", 0));
        label_29->setText(QApplication::translate("tab_search_crypt", "Capacity :", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_search_crypt: public Ui_tab_search_crypt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_SEARCH_CRYPT_H

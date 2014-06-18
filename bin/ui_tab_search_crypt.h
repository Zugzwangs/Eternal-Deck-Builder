/********************************************************************************
** Form generated from reading UI file 'tab_search_crypt.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include "mvdbdd.h"

QT_BEGIN_NAMESPACE

class Ui_tab_search_crypt
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *CryptSearchFrame;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBoxText;
    QGridLayout *gridLayout_6;
    QLabel *lName;
    QLineEdit *lENameCard;
    QLabel *lArtist;
    QLineEdit *lEArtist;
    QLabel *lCardText;
    QLineEdit *lETextCard;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_48;
    QComboBox *cBSet_2;
    QLabel *label_46;
    QComboBox *cBRarity_2;
    QGroupBox *groupBoxDiscipline;
    QGridLayout *gridLayout;
    QLabel *lAbombwe;
    QComboBox *abo;
    QLabel *lChimerstry;
    QComboBox *chi;
    QLabel *lFortitude;
    QComboBox *for_2;
    QLabel *lObeah;
    QComboBox *obe;
    QLabel *lPresence;
    QComboBox *pre;
    QLabel *lSerpentis;
    QComboBox *ser;
    QLabel *lThaumaturgy;
    QComboBox *tha;
    QLabel *lAnimalism;
    QComboBox *ani;
    QLabel *lDaimoinon;
    QComboBox *dai;
    QLabel *lMelpominee;
    QComboBox *mel;
    QLabel *lObfuscate;
    QComboBox *obf;
    QLabel *lProtean;
    QComboBox *pro;
    QLabel *lSpiritus;
    QComboBox *spi;
    QLabel *lValeren;
    QComboBox *val;
    QLabel *lAuspex;
    QComboBox *aus;
    QLabel *lDementation;
    QComboBox *dem;
    QLabel *lMytherceria;
    QComboBox *myt;
    QLabel *lObtenebration;
    QComboBox *obt;
    QLabel *lQuietus;
    QComboBox *qui;
    QLabel *lTemporis;
    QComboBox *tem;
    QLabel *lVicissitude;
    QComboBox *vic;
    QLabel *lCelerity;
    QComboBox *cel;
    QLabel *lDominate;
    QComboBox *dom;
    QLabel *lNecromancy;
    QComboBox *nec;
    QLabel *lPotence;
    QComboBox *pot;
    QLabel *lSanguinus;
    QComboBox *san;
    QLabel *lThanatosis;
    QComboBox *thn;
    QLabel *lVisceratika;
    QComboBox *vis;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_21;
    QComboBox *cBGroup;
    QSpinBox *sBGroup;
    QLabel *label_29;
    QComboBox *cBCapa;
    QSpinBox *sBCapa;
    QGroupBox *groupBoxVirtues;
    QHBoxLayout *horizontalLayout;
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
    QGroupBox *groupBoxTrait;
    QGridLayout *gridLayout_4;
    QLabel *lClan;
    QComboBox *cBClan;
    QCheckBox *ckBBlackHand;
    QCheckBox *ckBFlight;
    QCheckBox *ckBScare;
    QCheckBox *ckBSeraph;
    QCheckBox *ckBInfernal;
    QCheckBox *ckBSlave;
    QCheckBox *ckBSterile;
    QCheckBox *ckBBloodCurse;
    QCheckBox *ckBRedList;
    QComboBox *cBSect;
    QComboBox *cBTitle;
    QLabel *lSect;
    QLabel *lTitle;
    QSpacerItem *horizontalSpacer_2;
    PartialDeckView *CryptView;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pBCryptSearch;
    QPushButton *pBCryptClearForm;
    QPushButton *pBAddtoDeck;
    QSpacerItem *verticalSpacer_2;
    QLabel *VisuelCrypt;
    QSpacerItem *verticalSpacer;
    PItemView *PTVCryptResults;

    void setupUi(QScrollArea *tab_search_crypt)
    {
        if (tab_search_crypt->objectName().isEmpty())
            tab_search_crypt->setObjectName(QStringLiteral("tab_search_crypt"));
        tab_search_crypt->resize(1789, 1131);
        tab_search_crypt->setWindowOpacity(0);
        tab_search_crypt->setAutoFillBackground(true);
        tab_search_crypt->setFrameShape(QFrame::NoFrame);
        tab_search_crypt->setFrameShadow(QFrame::Plain);
        tab_search_crypt->setLineWidth(0);
        tab_search_crypt->setWidgetResizable(true);
        tab_search_crypt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1789, 1131));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 300));
        frame_2->setMaximumSize(QSize(16777215, 300));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        CryptSearchFrame = new QFrame(frame_2);
        CryptSearchFrame->setObjectName(QStringLiteral("CryptSearchFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CryptSearchFrame->sizePolicy().hasHeightForWidth());
        CryptSearchFrame->setSizePolicy(sizePolicy1);
        CryptSearchFrame->setMinimumSize(QSize(1250, 200));
        CryptSearchFrame->setMaximumSize(QSize(1400, 350));
        CryptSearchFrame->setAutoFillBackground(true);
        CryptSearchFrame->setFrameShape(QFrame::NoFrame);
        CryptSearchFrame->setFrameShadow(QFrame::Plain);
        CryptSearchFrame->setLineWidth(0);
        gridLayout_5 = new QGridLayout(CryptSearchFrame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(5);
        gridLayout_5->setVerticalSpacing(4);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBoxText = new QGroupBox(CryptSearchFrame);
        groupBoxText->setObjectName(QStringLiteral("groupBoxText"));
        groupBoxText->setMinimumSize(QSize(0, 120));
        gridLayout_6 = new QGridLayout(groupBoxText);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        lName = new QLabel(groupBoxText);
        lName->setObjectName(QStringLiteral("lName"));

        gridLayout_6->addWidget(lName, 0, 0, 1, 1);

        lENameCard = new QLineEdit(groupBoxText);
        lENameCard->setObjectName(QStringLiteral("lENameCard"));

        gridLayout_6->addWidget(lENameCard, 0, 1, 1, 1);

        lArtist = new QLabel(groupBoxText);
        lArtist->setObjectName(QStringLiteral("lArtist"));

        gridLayout_6->addWidget(lArtist, 0, 2, 1, 1);

        lEArtist = new QLineEdit(groupBoxText);
        lEArtist->setObjectName(QStringLiteral("lEArtist"));

        gridLayout_6->addWidget(lEArtist, 0, 3, 1, 1);

        lCardText = new QLabel(groupBoxText);
        lCardText->setObjectName(QStringLiteral("lCardText"));

        gridLayout_6->addWidget(lCardText, 1, 0, 1, 1);

        lETextCard = new QLineEdit(groupBoxText);
        lETextCard->setObjectName(QStringLiteral("lETextCard"));

        gridLayout_6->addWidget(lETextCard, 1, 1, 1, 3);


        gridLayout_5->addWidget(groupBoxText, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(CryptSearchFrame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 120));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        label_48 = new QLabel(groupBox_3);
        label_48->setObjectName(QStringLiteral("label_48"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_48->sizePolicy().hasHeightForWidth());
        label_48->setSizePolicy(sizePolicy2);
        label_48->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_48, 0, 0, 1, 1);

        cBSet_2 = new QComboBox(groupBox_3);
        cBSet_2->setObjectName(QStringLiteral("cBSet_2"));
        cBSet_2->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(cBSet_2, 0, 1, 1, 1);

        label_46 = new QLabel(groupBox_3);
        label_46->setObjectName(QStringLiteral("label_46"));
        sizePolicy2.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy2);
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_46, 1, 0, 1, 1);

        cBRarity_2 = new QComboBox(groupBox_3);
        cBRarity_2->setObjectName(QStringLiteral("cBRarity_2"));

        gridLayout_2->addWidget(cBRarity_2, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBoxDiscipline = new QGroupBox(CryptSearchFrame);
        groupBoxDiscipline->setObjectName(QStringLiteral("groupBoxDiscipline"));
        groupBoxDiscipline->setMinimumSize(QSize(0, 200));
        groupBoxDiscipline->setAutoFillBackground(false);
        groupBoxDiscipline->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(groupBoxDiscipline);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 5, 10, 5);
        lAbombwe = new QLabel(groupBoxDiscipline);
        lAbombwe->setObjectName(QStringLiteral("lAbombwe"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lAbombwe->sizePolicy().hasHeightForWidth());
        lAbombwe->setSizePolicy(sizePolicy3);
        lAbombwe->setMinimumSize(QSize(22, 22));
        lAbombwe->setMaximumSize(QSize(22, 22));
        lAbombwe->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/abo.png")));
        lAbombwe->setScaledContents(true);

        gridLayout->addWidget(lAbombwe, 0, 0, 1, 1);

        abo = new QComboBox(groupBoxDiscipline);
        abo->setObjectName(QStringLiteral("abo"));
        sizePolicy3.setHeightForWidth(abo->sizePolicy().hasHeightForWidth());
        abo->setSizePolicy(sizePolicy3);
        abo->setMinimumSize(QSize(52, 22));
        abo->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(abo, 0, 1, 1, 1);

        lChimerstry = new QLabel(groupBoxDiscipline);
        lChimerstry->setObjectName(QStringLiteral("lChimerstry"));
        sizePolicy3.setHeightForWidth(lChimerstry->sizePolicy().hasHeightForWidth());
        lChimerstry->setSizePolicy(sizePolicy3);
        lChimerstry->setMinimumSize(QSize(22, 22));
        lChimerstry->setMaximumSize(QSize(22, 22));
        lChimerstry->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/chi.png")));
        lChimerstry->setScaledContents(true);

        gridLayout->addWidget(lChimerstry, 0, 2, 1, 1);

        chi = new QComboBox(groupBoxDiscipline);
        chi->setObjectName(QStringLiteral("chi"));
        sizePolicy3.setHeightForWidth(chi->sizePolicy().hasHeightForWidth());
        chi->setSizePolicy(sizePolicy3);
        chi->setMinimumSize(QSize(52, 22));
        chi->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(chi, 0, 3, 1, 1);

        lFortitude = new QLabel(groupBoxDiscipline);
        lFortitude->setObjectName(QStringLiteral("lFortitude"));
        lFortitude->setMinimumSize(QSize(22, 22));
        lFortitude->setMaximumSize(QSize(22, 22));
        lFortitude->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/for.png")));
        lFortitude->setScaledContents(true);

        gridLayout->addWidget(lFortitude, 0, 4, 1, 1);

        for_2 = new QComboBox(groupBoxDiscipline);
        for_2->setObjectName(QStringLiteral("for_2"));
        sizePolicy3.setHeightForWidth(for_2->sizePolicy().hasHeightForWidth());
        for_2->setSizePolicy(sizePolicy3);
        for_2->setMinimumSize(QSize(52, 22));
        for_2->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(for_2, 0, 5, 1, 1);

        lObeah = new QLabel(groupBoxDiscipline);
        lObeah->setObjectName(QStringLiteral("lObeah"));
        lObeah->setMinimumSize(QSize(22, 22));
        lObeah->setMaximumSize(QSize(22, 22));
        lObeah->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/obe.png")));
        lObeah->setScaledContents(true);

        gridLayout->addWidget(lObeah, 0, 6, 1, 1);

        obe = new QComboBox(groupBoxDiscipline);
        obe->setObjectName(QStringLiteral("obe"));
        sizePolicy3.setHeightForWidth(obe->sizePolicy().hasHeightForWidth());
        obe->setSizePolicy(sizePolicy3);
        obe->setMinimumSize(QSize(52, 22));
        obe->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(obe, 0, 7, 1, 1);

        lPresence = new QLabel(groupBoxDiscipline);
        lPresence->setObjectName(QStringLiteral("lPresence"));
        sizePolicy3.setHeightForWidth(lPresence->sizePolicy().hasHeightForWidth());
        lPresence->setSizePolicy(sizePolicy3);
        lPresence->setMinimumSize(QSize(22, 22));
        lPresence->setMaximumSize(QSize(22, 22));
        lPresence->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/pre.png")));
        lPresence->setScaledContents(true);

        gridLayout->addWidget(lPresence, 0, 8, 1, 1);

        pre = new QComboBox(groupBoxDiscipline);
        pre->setObjectName(QStringLiteral("pre"));
        sizePolicy3.setHeightForWidth(pre->sizePolicy().hasHeightForWidth());
        pre->setSizePolicy(sizePolicy3);
        pre->setMinimumSize(QSize(52, 22));
        pre->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(pre, 0, 9, 1, 1);

        lSerpentis = new QLabel(groupBoxDiscipline);
        lSerpentis->setObjectName(QStringLiteral("lSerpentis"));
        sizePolicy3.setHeightForWidth(lSerpentis->sizePolicy().hasHeightForWidth());
        lSerpentis->setSizePolicy(sizePolicy3);
        lSerpentis->setMinimumSize(QSize(22, 22));
        lSerpentis->setMaximumSize(QSize(22, 22));
        lSerpentis->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/ser.png")));
        lSerpentis->setScaledContents(true);

        gridLayout->addWidget(lSerpentis, 0, 10, 1, 1);

        ser = new QComboBox(groupBoxDiscipline);
        ser->setObjectName(QStringLiteral("ser"));
        sizePolicy3.setHeightForWidth(ser->sizePolicy().hasHeightForWidth());
        ser->setSizePolicy(sizePolicy3);
        ser->setMinimumSize(QSize(52, 22));
        ser->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(ser, 0, 11, 1, 1);

        lThaumaturgy = new QLabel(groupBoxDiscipline);
        lThaumaturgy->setObjectName(QStringLiteral("lThaumaturgy"));
        sizePolicy3.setHeightForWidth(lThaumaturgy->sizePolicy().hasHeightForWidth());
        lThaumaturgy->setSizePolicy(sizePolicy3);
        lThaumaturgy->setMinimumSize(QSize(22, 22));
        lThaumaturgy->setMaximumSize(QSize(22, 22));
        lThaumaturgy->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/thn.png")));
        lThaumaturgy->setScaledContents(true);

        gridLayout->addWidget(lThaumaturgy, 0, 12, 1, 1);

        tha = new QComboBox(groupBoxDiscipline);
        tha->setObjectName(QStringLiteral("tha"));
        sizePolicy3.setHeightForWidth(tha->sizePolicy().hasHeightForWidth());
        tha->setSizePolicy(sizePolicy3);
        tha->setMinimumSize(QSize(52, 22));
        tha->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(tha, 0, 13, 1, 1);

        lAnimalism = new QLabel(groupBoxDiscipline);
        lAnimalism->setObjectName(QStringLiteral("lAnimalism"));
        sizePolicy3.setHeightForWidth(lAnimalism->sizePolicy().hasHeightForWidth());
        lAnimalism->setSizePolicy(sizePolicy3);
        lAnimalism->setMinimumSize(QSize(22, 22));
        lAnimalism->setMaximumSize(QSize(22, 22));
        lAnimalism->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/ani.png")));
        lAnimalism->setScaledContents(true);

        gridLayout->addWidget(lAnimalism, 1, 0, 1, 1);

        ani = new QComboBox(groupBoxDiscipline);
        ani->setObjectName(QStringLiteral("ani"));
        sizePolicy3.setHeightForWidth(ani->sizePolicy().hasHeightForWidth());
        ani->setSizePolicy(sizePolicy3);
        ani->setMinimumSize(QSize(52, 22));
        ani->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(ani, 1, 1, 1, 1);

        lDaimoinon = new QLabel(groupBoxDiscipline);
        lDaimoinon->setObjectName(QStringLiteral("lDaimoinon"));
        sizePolicy3.setHeightForWidth(lDaimoinon->sizePolicy().hasHeightForWidth());
        lDaimoinon->setSizePolicy(sizePolicy3);
        lDaimoinon->setMinimumSize(QSize(22, 22));
        lDaimoinon->setMaximumSize(QSize(22, 22));
        lDaimoinon->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/dai.png")));
        lDaimoinon->setScaledContents(true);

        gridLayout->addWidget(lDaimoinon, 1, 2, 1, 1);

        dai = new QComboBox(groupBoxDiscipline);
        dai->setObjectName(QStringLiteral("dai"));
        sizePolicy3.setHeightForWidth(dai->sizePolicy().hasHeightForWidth());
        dai->setSizePolicy(sizePolicy3);
        dai->setMinimumSize(QSize(52, 22));
        dai->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(dai, 1, 3, 1, 1);

        lMelpominee = new QLabel(groupBoxDiscipline);
        lMelpominee->setObjectName(QStringLiteral("lMelpominee"));
        lMelpominee->setMinimumSize(QSize(22, 22));
        lMelpominee->setMaximumSize(QSize(22, 22));
        lMelpominee->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/mel.png")));
        lMelpominee->setScaledContents(true);

        gridLayout->addWidget(lMelpominee, 1, 4, 1, 1);

        mel = new QComboBox(groupBoxDiscipline);
        mel->setObjectName(QStringLiteral("mel"));
        sizePolicy3.setHeightForWidth(mel->sizePolicy().hasHeightForWidth());
        mel->setSizePolicy(sizePolicy3);
        mel->setMinimumSize(QSize(52, 22));
        mel->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(mel, 1, 5, 1, 1);

        lObfuscate = new QLabel(groupBoxDiscipline);
        lObfuscate->setObjectName(QStringLiteral("lObfuscate"));
        lObfuscate->setMinimumSize(QSize(22, 22));
        lObfuscate->setMaximumSize(QSize(22, 22));
        lObfuscate->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/obf.png")));
        lObfuscate->setScaledContents(true);

        gridLayout->addWidget(lObfuscate, 1, 6, 1, 1);

        obf = new QComboBox(groupBoxDiscipline);
        obf->setObjectName(QStringLiteral("obf"));
        sizePolicy3.setHeightForWidth(obf->sizePolicy().hasHeightForWidth());
        obf->setSizePolicy(sizePolicy3);
        obf->setMinimumSize(QSize(52, 22));
        obf->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(obf, 1, 7, 1, 1);

        lProtean = new QLabel(groupBoxDiscipline);
        lProtean->setObjectName(QStringLiteral("lProtean"));
        sizePolicy3.setHeightForWidth(lProtean->sizePolicy().hasHeightForWidth());
        lProtean->setSizePolicy(sizePolicy3);
        lProtean->setMinimumSize(QSize(22, 22));
        lProtean->setMaximumSize(QSize(22, 22));
        lProtean->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/pro.png")));
        lProtean->setScaledContents(true);

        gridLayout->addWidget(lProtean, 1, 8, 1, 1);

        pro = new QComboBox(groupBoxDiscipline);
        pro->setObjectName(QStringLiteral("pro"));
        sizePolicy3.setHeightForWidth(pro->sizePolicy().hasHeightForWidth());
        pro->setSizePolicy(sizePolicy3);
        pro->setMinimumSize(QSize(52, 22));
        pro->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(pro, 1, 9, 1, 1);

        lSpiritus = new QLabel(groupBoxDiscipline);
        lSpiritus->setObjectName(QStringLiteral("lSpiritus"));
        sizePolicy3.setHeightForWidth(lSpiritus->sizePolicy().hasHeightForWidth());
        lSpiritus->setSizePolicy(sizePolicy3);
        lSpiritus->setMinimumSize(QSize(22, 22));
        lSpiritus->setMaximumSize(QSize(22, 22));
        lSpiritus->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/spi.png")));
        lSpiritus->setScaledContents(true);

        gridLayout->addWidget(lSpiritus, 1, 10, 1, 1);

        spi = new QComboBox(groupBoxDiscipline);
        spi->setObjectName(QStringLiteral("spi"));
        sizePolicy3.setHeightForWidth(spi->sizePolicy().hasHeightForWidth());
        spi->setSizePolicy(sizePolicy3);
        spi->setMinimumSize(QSize(52, 22));
        spi->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(spi, 1, 11, 1, 1);

        lValeren = new QLabel(groupBoxDiscipline);
        lValeren->setObjectName(QStringLiteral("lValeren"));
        sizePolicy3.setHeightForWidth(lValeren->sizePolicy().hasHeightForWidth());
        lValeren->setSizePolicy(sizePolicy3);
        lValeren->setMinimumSize(QSize(22, 22));
        lValeren->setMaximumSize(QSize(22, 22));
        lValeren->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/val.png")));
        lValeren->setScaledContents(true);

        gridLayout->addWidget(lValeren, 1, 12, 1, 1);

        val = new QComboBox(groupBoxDiscipline);
        val->setObjectName(QStringLiteral("val"));
        sizePolicy3.setHeightForWidth(val->sizePolicy().hasHeightForWidth());
        val->setSizePolicy(sizePolicy3);
        val->setMinimumSize(QSize(52, 22));
        val->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(val, 1, 13, 1, 1);

        lAuspex = new QLabel(groupBoxDiscipline);
        lAuspex->setObjectName(QStringLiteral("lAuspex"));
        sizePolicy3.setHeightForWidth(lAuspex->sizePolicy().hasHeightForWidth());
        lAuspex->setSizePolicy(sizePolicy3);
        lAuspex->setMinimumSize(QSize(22, 22));
        lAuspex->setMaximumSize(QSize(22, 22));
        lAuspex->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/aus.png")));
        lAuspex->setScaledContents(true);

        gridLayout->addWidget(lAuspex, 2, 0, 1, 1);

        aus = new QComboBox(groupBoxDiscipline);
        aus->setObjectName(QStringLiteral("aus"));
        sizePolicy3.setHeightForWidth(aus->sizePolicy().hasHeightForWidth());
        aus->setSizePolicy(sizePolicy3);
        aus->setMinimumSize(QSize(52, 22));
        aus->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(aus, 2, 1, 1, 1);

        lDementation = new QLabel(groupBoxDiscipline);
        lDementation->setObjectName(QStringLiteral("lDementation"));
        sizePolicy3.setHeightForWidth(lDementation->sizePolicy().hasHeightForWidth());
        lDementation->setSizePolicy(sizePolicy3);
        lDementation->setMinimumSize(QSize(22, 22));
        lDementation->setMaximumSize(QSize(22, 22));
        lDementation->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/dem.png")));
        lDementation->setScaledContents(true);

        gridLayout->addWidget(lDementation, 2, 2, 1, 1);

        dem = new QComboBox(groupBoxDiscipline);
        dem->setObjectName(QStringLiteral("dem"));
        sizePolicy3.setHeightForWidth(dem->sizePolicy().hasHeightForWidth());
        dem->setSizePolicy(sizePolicy3);
        dem->setMinimumSize(QSize(52, 22));
        dem->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(dem, 2, 3, 1, 1);

        lMytherceria = new QLabel(groupBoxDiscipline);
        lMytherceria->setObjectName(QStringLiteral("lMytherceria"));
        lMytherceria->setMinimumSize(QSize(22, 22));
        lMytherceria->setMaximumSize(QSize(22, 22));
        lMytherceria->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/myt.png")));
        lMytherceria->setScaledContents(true);

        gridLayout->addWidget(lMytherceria, 2, 4, 1, 1);

        myt = new QComboBox(groupBoxDiscipline);
        myt->setObjectName(QStringLiteral("myt"));
        sizePolicy3.setHeightForWidth(myt->sizePolicy().hasHeightForWidth());
        myt->setSizePolicy(sizePolicy3);
        myt->setMinimumSize(QSize(52, 22));
        myt->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(myt, 2, 5, 1, 1);

        lObtenebration = new QLabel(groupBoxDiscipline);
        lObtenebration->setObjectName(QStringLiteral("lObtenebration"));
        lObtenebration->setMinimumSize(QSize(22, 22));
        lObtenebration->setMaximumSize(QSize(22, 22));
        lObtenebration->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/obt.png")));
        lObtenebration->setScaledContents(true);

        gridLayout->addWidget(lObtenebration, 2, 6, 1, 1);

        obt = new QComboBox(groupBoxDiscipline);
        obt->setObjectName(QStringLiteral("obt"));
        sizePolicy3.setHeightForWidth(obt->sizePolicy().hasHeightForWidth());
        obt->setSizePolicy(sizePolicy3);
        obt->setMinimumSize(QSize(52, 22));
        obt->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(obt, 2, 7, 1, 1);

        lQuietus = new QLabel(groupBoxDiscipline);
        lQuietus->setObjectName(QStringLiteral("lQuietus"));
        sizePolicy3.setHeightForWidth(lQuietus->sizePolicy().hasHeightForWidth());
        lQuietus->setSizePolicy(sizePolicy3);
        lQuietus->setMinimumSize(QSize(22, 22));
        lQuietus->setMaximumSize(QSize(22, 22));
        lQuietus->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/qui.png")));
        lQuietus->setScaledContents(true);

        gridLayout->addWidget(lQuietus, 2, 8, 1, 1);

        qui = new QComboBox(groupBoxDiscipline);
        qui->setObjectName(QStringLiteral("qui"));
        sizePolicy3.setHeightForWidth(qui->sizePolicy().hasHeightForWidth());
        qui->setSizePolicy(sizePolicy3);
        qui->setMinimumSize(QSize(52, 22));
        qui->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(qui, 2, 9, 1, 1);

        lTemporis = new QLabel(groupBoxDiscipline);
        lTemporis->setObjectName(QStringLiteral("lTemporis"));
        sizePolicy3.setHeightForWidth(lTemporis->sizePolicy().hasHeightForWidth());
        lTemporis->setSizePolicy(sizePolicy3);
        lTemporis->setMinimumSize(QSize(22, 22));
        lTemporis->setMaximumSize(QSize(22, 22));
        lTemporis->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/tem.png")));
        lTemporis->setScaledContents(true);

        gridLayout->addWidget(lTemporis, 2, 10, 1, 1);

        tem = new QComboBox(groupBoxDiscipline);
        tem->setObjectName(QStringLiteral("tem"));
        sizePolicy3.setHeightForWidth(tem->sizePolicy().hasHeightForWidth());
        tem->setSizePolicy(sizePolicy3);
        tem->setMinimumSize(QSize(52, 22));
        tem->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(tem, 2, 11, 1, 1);

        lVicissitude = new QLabel(groupBoxDiscipline);
        lVicissitude->setObjectName(QStringLiteral("lVicissitude"));
        sizePolicy3.setHeightForWidth(lVicissitude->sizePolicy().hasHeightForWidth());
        lVicissitude->setSizePolicy(sizePolicy3);
        lVicissitude->setMinimumSize(QSize(22, 22));
        lVicissitude->setMaximumSize(QSize(22, 22));
        lVicissitude->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/vic.png")));
        lVicissitude->setScaledContents(true);

        gridLayout->addWidget(lVicissitude, 2, 12, 1, 1);

        vic = new QComboBox(groupBoxDiscipline);
        vic->setObjectName(QStringLiteral("vic"));
        sizePolicy3.setHeightForWidth(vic->sizePolicy().hasHeightForWidth());
        vic->setSizePolicy(sizePolicy3);
        vic->setMinimumSize(QSize(52, 22));
        vic->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(vic, 2, 13, 1, 1);

        lCelerity = new QLabel(groupBoxDiscipline);
        lCelerity->setObjectName(QStringLiteral("lCelerity"));
        sizePolicy3.setHeightForWidth(lCelerity->sizePolicy().hasHeightForWidth());
        lCelerity->setSizePolicy(sizePolicy3);
        lCelerity->setMinimumSize(QSize(22, 22));
        lCelerity->setMaximumSize(QSize(22, 22));
        lCelerity->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/cel.png")));
        lCelerity->setScaledContents(true);

        gridLayout->addWidget(lCelerity, 3, 0, 1, 1);

        cel = new QComboBox(groupBoxDiscipline);
        cel->setObjectName(QStringLiteral("cel"));
        sizePolicy3.setHeightForWidth(cel->sizePolicy().hasHeightForWidth());
        cel->setSizePolicy(sizePolicy3);
        cel->setMinimumSize(QSize(52, 22));
        cel->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(cel, 3, 1, 1, 1);

        lDominate = new QLabel(groupBoxDiscipline);
        lDominate->setObjectName(QStringLiteral("lDominate"));
        lDominate->setMinimumSize(QSize(22, 22));
        lDominate->setMaximumSize(QSize(22, 22));
        lDominate->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/dom.png")));
        lDominate->setScaledContents(true);

        gridLayout->addWidget(lDominate, 3, 2, 1, 1);

        dom = new QComboBox(groupBoxDiscipline);
        dom->setObjectName(QStringLiteral("dom"));
        sizePolicy3.setHeightForWidth(dom->sizePolicy().hasHeightForWidth());
        dom->setSizePolicy(sizePolicy3);
        dom->setMinimumSize(QSize(52, 22));
        dom->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(dom, 3, 3, 1, 1);

        lNecromancy = new QLabel(groupBoxDiscipline);
        lNecromancy->setObjectName(QStringLiteral("lNecromancy"));
        lNecromancy->setMinimumSize(QSize(22, 22));
        lNecromancy->setMaximumSize(QSize(22, 22));
        lNecromancy->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/nec.png")));
        lNecromancy->setScaledContents(true);

        gridLayout->addWidget(lNecromancy, 3, 4, 1, 1);

        nec = new QComboBox(groupBoxDiscipline);
        nec->setObjectName(QStringLiteral("nec"));
        sizePolicy3.setHeightForWidth(nec->sizePolicy().hasHeightForWidth());
        nec->setSizePolicy(sizePolicy3);
        nec->setMinimumSize(QSize(52, 22));
        nec->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(nec, 3, 5, 1, 1);

        lPotence = new QLabel(groupBoxDiscipline);
        lPotence->setObjectName(QStringLiteral("lPotence"));
        sizePolicy3.setHeightForWidth(lPotence->sizePolicy().hasHeightForWidth());
        lPotence->setSizePolicy(sizePolicy3);
        lPotence->setMinimumSize(QSize(22, 22));
        lPotence->setMaximumSize(QSize(22, 22));
        lPotence->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/pot.png")));
        lPotence->setScaledContents(true);

        gridLayout->addWidget(lPotence, 3, 6, 1, 1);

        pot = new QComboBox(groupBoxDiscipline);
        pot->setObjectName(QStringLiteral("pot"));
        sizePolicy3.setHeightForWidth(pot->sizePolicy().hasHeightForWidth());
        pot->setSizePolicy(sizePolicy3);
        pot->setMinimumSize(QSize(52, 22));
        pot->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(pot, 3, 7, 1, 1);

        lSanguinus = new QLabel(groupBoxDiscipline);
        lSanguinus->setObjectName(QStringLiteral("lSanguinus"));
        sizePolicy3.setHeightForWidth(lSanguinus->sizePolicy().hasHeightForWidth());
        lSanguinus->setSizePolicy(sizePolicy3);
        lSanguinus->setMinimumSize(QSize(22, 22));
        lSanguinus->setMaximumSize(QSize(22, 22));
        lSanguinus->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/san.png")));
        lSanguinus->setScaledContents(true);

        gridLayout->addWidget(lSanguinus, 3, 8, 1, 1);

        san = new QComboBox(groupBoxDiscipline);
        san->setObjectName(QStringLiteral("san"));
        sizePolicy3.setHeightForWidth(san->sizePolicy().hasHeightForWidth());
        san->setSizePolicy(sizePolicy3);
        san->setMinimumSize(QSize(52, 22));
        san->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(san, 3, 9, 1, 1);

        lThanatosis = new QLabel(groupBoxDiscipline);
        lThanatosis->setObjectName(QStringLiteral("lThanatosis"));
        sizePolicy3.setHeightForWidth(lThanatosis->sizePolicy().hasHeightForWidth());
        lThanatosis->setSizePolicy(sizePolicy3);
        lThanatosis->setMinimumSize(QSize(22, 22));
        lThanatosis->setMaximumSize(QSize(22, 22));
        lThanatosis->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/tha.png")));
        lThanatosis->setScaledContents(true);

        gridLayout->addWidget(lThanatosis, 3, 10, 1, 1);

        thn = new QComboBox(groupBoxDiscipline);
        thn->setObjectName(QStringLiteral("thn"));
        sizePolicy3.setHeightForWidth(thn->sizePolicy().hasHeightForWidth());
        thn->setSizePolicy(sizePolicy3);
        thn->setMinimumSize(QSize(52, 22));
        thn->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(thn, 3, 11, 1, 1);

        lVisceratika = new QLabel(groupBoxDiscipline);
        lVisceratika->setObjectName(QStringLiteral("lVisceratika"));
        sizePolicy3.setHeightForWidth(lVisceratika->sizePolicy().hasHeightForWidth());
        lVisceratika->setSizePolicy(sizePolicy3);
        lVisceratika->setMinimumSize(QSize(22, 22));
        lVisceratika->setMaximumSize(QSize(22, 22));
        lVisceratika->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/vis.png")));
        lVisceratika->setScaledContents(true);

        gridLayout->addWidget(lVisceratika, 3, 12, 1, 1);

        vis = new QComboBox(groupBoxDiscipline);
        vis->setObjectName(QStringLiteral("vis"));
        sizePolicy3.setHeightForWidth(vis->sizePolicy().hasHeightForWidth());
        vis->setSizePolicy(sizePolicy3);
        vis->setMinimumSize(QSize(52, 22));
        vis->setMaximumSize(QSize(52, 22));

        gridLayout->addWidget(vis, 3, 13, 1, 1);


        gridLayout_5->addWidget(groupBoxDiscipline, 0, 2, 2, 1);

        groupBox = new QGroupBox(CryptSearchFrame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(150, 0));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_21, 0, 0, 1, 1);

        cBGroup = new QComboBox(groupBox);
        cBGroup->setObjectName(QStringLiteral("cBGroup"));
        sizePolicy3.setHeightForWidth(cBGroup->sizePolicy().hasHeightForWidth());
        cBGroup->setSizePolicy(sizePolicy3);
        cBGroup->setMinimumSize(QSize(45, 0));
        cBGroup->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(cBGroup, 0, 1, 1, 1);

        sBGroup = new QSpinBox(groupBox);
        sBGroup->setObjectName(QStringLiteral("sBGroup"));
        sizePolicy3.setHeightForWidth(sBGroup->sizePolicy().hasHeightForWidth());
        sBGroup->setSizePolicy(sizePolicy3);
        sBGroup->setMinimumSize(QSize(40, 0));
        sBGroup->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        sBGroup->setFont(font);
        sBGroup->setMaximum(6);

        gridLayout_3->addWidget(sBGroup, 0, 2, 1, 1);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_29, 1, 0, 1, 1);

        cBCapa = new QComboBox(groupBox);
        cBCapa->setObjectName(QStringLiteral("cBCapa"));
        sizePolicy3.setHeightForWidth(cBCapa->sizePolicy().hasHeightForWidth());
        cBCapa->setSizePolicy(sizePolicy3);
        cBCapa->setMinimumSize(QSize(45, 0));
        cBCapa->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(cBCapa, 1, 1, 1, 1);

        sBCapa = new QSpinBox(groupBox);
        sBCapa->setObjectName(QStringLiteral("sBCapa"));
        sizePolicy3.setHeightForWidth(sBCapa->sizePolicy().hasHeightForWidth());
        sBCapa->setSizePolicy(sizePolicy3);
        sBCapa->setMinimumSize(QSize(40, 0));
        sBCapa->setMaximumSize(QSize(40, 16777215));
        sBCapa->setFont(font);
        sBCapa->setMaximum(11);

        gridLayout_3->addWidget(sBCapa, 1, 2, 1, 1);


        gridLayout_5->addWidget(groupBox, 1, 1, 2, 1);

        groupBoxVirtues = new QGroupBox(CryptSearchFrame);
        groupBoxVirtues->setObjectName(QStringLiteral("groupBoxVirtues"));
        groupBoxVirtues->setMinimumSize(QSize(65, 0));
        horizontalLayout = new QHBoxLayout(groupBoxVirtues);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 5, 10, 5);
        lDefense = new QLabel(groupBoxVirtues);
        lDefense->setObjectName(QStringLiteral("lDefense"));
        sizePolicy3.setHeightForWidth(lDefense->sizePolicy().hasHeightForWidth());
        lDefense->setSizePolicy(sizePolicy3);
        lDefense->setMinimumSize(QSize(22, 22));
        lDefense->setMaximumSize(QSize(22, 22));
        lDefense->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/def.png")));
        lDefense->setScaledContents(true);

        horizontalLayout->addWidget(lDefense);

        def = new QComboBox(groupBoxVirtues);
        def->setObjectName(QStringLiteral("def"));
        sizePolicy3.setHeightForWidth(def->sizePolicy().hasHeightForWidth());
        def->setSizePolicy(sizePolicy3);
        def->setMinimumSize(QSize(52, 22));
        def->setMaximumSize(QSize(52, 22));

        horizontalLayout->addWidget(def);

        lInnocence = new QLabel(groupBoxVirtues);
        lInnocence->setObjectName(QStringLiteral("lInnocence"));
        sizePolicy3.setHeightForWidth(lInnocence->sizePolicy().hasHeightForWidth());
        lInnocence->setSizePolicy(sizePolicy3);
        lInnocence->setMinimumSize(QSize(22, 22));
        lInnocence->setMaximumSize(QSize(22, 22));
        lInnocence->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/inn.png")));
        lInnocence->setScaledContents(true);

        horizontalLayout->addWidget(lInnocence);

        inn = new QComboBox(groupBoxVirtues);
        inn->setObjectName(QStringLiteral("inn"));
        sizePolicy3.setHeightForWidth(inn->sizePolicy().hasHeightForWidth());
        inn->setSizePolicy(sizePolicy3);
        inn->setMinimumSize(QSize(52, 22));
        inn->setMaximumSize(QSize(52, 22));
        inn->setFrame(true);

        horizontalLayout->addWidget(inn);

        lJudgment = new QLabel(groupBoxVirtues);
        lJudgment->setObjectName(QStringLiteral("lJudgment"));
        sizePolicy3.setHeightForWidth(lJudgment->sizePolicy().hasHeightForWidth());
        lJudgment->setSizePolicy(sizePolicy3);
        lJudgment->setMinimumSize(QSize(22, 22));
        lJudgment->setMaximumSize(QSize(22, 22));
        lJudgment->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/jud.png")));
        lJudgment->setScaledContents(true);

        horizontalLayout->addWidget(lJudgment);

        jud = new QComboBox(groupBoxVirtues);
        jud->setObjectName(QStringLiteral("jud"));
        sizePolicy3.setHeightForWidth(jud->sizePolicy().hasHeightForWidth());
        jud->setSizePolicy(sizePolicy3);
        jud->setMinimumSize(QSize(52, 22));
        jud->setMaximumSize(QSize(52, 22));

        horizontalLayout->addWidget(jud);

        lMartyrdom = new QLabel(groupBoxVirtues);
        lMartyrdom->setObjectName(QStringLiteral("lMartyrdom"));
        sizePolicy3.setHeightForWidth(lMartyrdom->sizePolicy().hasHeightForWidth());
        lMartyrdom->setSizePolicy(sizePolicy3);
        lMartyrdom->setMinimumSize(QSize(22, 22));
        lMartyrdom->setMaximumSize(QSize(22, 22));
        lMartyrdom->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/mar.png")));
        lMartyrdom->setScaledContents(true);

        horizontalLayout->addWidget(lMartyrdom);

        mar = new QComboBox(groupBoxVirtues);
        mar->setObjectName(QStringLiteral("mar"));
        sizePolicy3.setHeightForWidth(mar->sizePolicy().hasHeightForWidth());
        mar->setSizePolicy(sizePolicy3);
        mar->setMinimumSize(QSize(52, 22));
        mar->setMaximumSize(QSize(52, 22));

        horizontalLayout->addWidget(mar);

        lRedemption = new QLabel(groupBoxVirtues);
        lRedemption->setObjectName(QStringLiteral("lRedemption"));
        sizePolicy3.setHeightForWidth(lRedemption->sizePolicy().hasHeightForWidth());
        lRedemption->setSizePolicy(sizePolicy3);
        lRedemption->setMinimumSize(QSize(22, 22));
        lRedemption->setMaximumSize(QSize(22, 22));
        lRedemption->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/red.png")));
        lRedemption->setScaledContents(true);

        horizontalLayout->addWidget(lRedemption);

        red = new QComboBox(groupBoxVirtues);
        red->setObjectName(QStringLiteral("red"));
        sizePolicy3.setHeightForWidth(red->sizePolicy().hasHeightForWidth());
        red->setSizePolicy(sizePolicy3);
        red->setMinimumSize(QSize(52, 22));
        red->setMaximumSize(QSize(52, 22));

        horizontalLayout->addWidget(red);

        lVengeance = new QLabel(groupBoxVirtues);
        lVengeance->setObjectName(QStringLiteral("lVengeance"));
        sizePolicy3.setHeightForWidth(lVengeance->sizePolicy().hasHeightForWidth());
        lVengeance->setSizePolicy(sizePolicy3);
        lVengeance->setMinimumSize(QSize(22, 22));
        lVengeance->setMaximumSize(QSize(22, 22));
        lVengeance->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/ven.png")));
        lVengeance->setScaledContents(true);

        horizontalLayout->addWidget(lVengeance);

        ven = new QComboBox(groupBoxVirtues);
        ven->setObjectName(QStringLiteral("ven"));
        sizePolicy3.setHeightForWidth(ven->sizePolicy().hasHeightForWidth());
        ven->setSizePolicy(sizePolicy3);
        ven->setMinimumSize(QSize(52, 22));
        ven->setMaximumSize(QSize(52, 22));

        horizontalLayout->addWidget(ven);

        lVision = new QLabel(groupBoxVirtues);
        lVision->setObjectName(QStringLiteral("lVision"));
        sizePolicy3.setHeightForWidth(lVision->sizePolicy().hasHeightForWidth());
        lVision->setSizePolicy(sizePolicy3);
        lVision->setMinimumSize(QSize(22, 22));
        lVision->setMaximumSize(QSize(22, 22));
        lVision->setPixmap(QPixmap(QString::fromUtf8(":/icons/disc/vis2.png")));
        lVision->setScaledContents(true);

        horizontalLayout->addWidget(lVision);

        vis2 = new QComboBox(groupBoxVirtues);
        vis2->setObjectName(QStringLiteral("vis2"));
        sizePolicy3.setHeightForWidth(vis2->sizePolicy().hasHeightForWidth());
        vis2->setSizePolicy(sizePolicy3);
        vis2->setMinimumSize(QSize(52, 22));
        vis2->setMaximumSize(QSize(52, 22));

        horizontalLayout->addWidget(vis2);


        gridLayout_5->addWidget(groupBoxVirtues, 2, 2, 1, 1);

        groupBoxTrait = new QGroupBox(CryptSearchFrame);
        groupBoxTrait->setObjectName(QStringLiteral("groupBoxTrait"));
        groupBoxTrait->setMinimumSize(QSize(150, 0));
        gridLayout_4 = new QGridLayout(groupBoxTrait);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        lClan = new QLabel(groupBoxTrait);
        lClan->setObjectName(QStringLiteral("lClan"));
        sizePolicy2.setHeightForWidth(lClan->sizePolicy().hasHeightForWidth());
        lClan->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lClan, 0, 0, 1, 1);

        cBClan = new QComboBox(groupBoxTrait);
        cBClan->setObjectName(QStringLiteral("cBClan"));
        cBClan->setMinimumSize(QSize(160, 0));

        gridLayout_4->addWidget(cBClan, 0, 1, 1, 1);

        ckBBlackHand = new QCheckBox(groupBoxTrait);
        ckBBlackHand->setObjectName(QStringLiteral("ckBBlackHand"));
        ckBBlackHand->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBBlackHand, 0, 2, 1, 1);

        ckBFlight = new QCheckBox(groupBoxTrait);
        ckBFlight->setObjectName(QStringLiteral("ckBFlight"));
        ckBFlight->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBFlight, 0, 3, 1, 1);

        ckBScare = new QCheckBox(groupBoxTrait);
        ckBScare->setObjectName(QStringLiteral("ckBScare"));
        ckBScare->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBScare, 0, 4, 1, 1);

        ckBSeraph = new QCheckBox(groupBoxTrait);
        ckBSeraph->setObjectName(QStringLiteral("ckBSeraph"));
        ckBSeraph->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBSeraph, 1, 2, 1, 1);

        ckBInfernal = new QCheckBox(groupBoxTrait);
        ckBInfernal->setObjectName(QStringLiteral("ckBInfernal"));
        ckBInfernal->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBInfernal, 1, 3, 1, 1);

        ckBSlave = new QCheckBox(groupBoxTrait);
        ckBSlave->setObjectName(QStringLiteral("ckBSlave"));
        ckBSlave->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBSlave, 1, 4, 1, 1);

        ckBSterile = new QCheckBox(groupBoxTrait);
        ckBSterile->setObjectName(QStringLiteral("ckBSterile"));
        ckBSterile->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBSterile, 2, 2, 1, 1);

        ckBBloodCurse = new QCheckBox(groupBoxTrait);
        ckBBloodCurse->setObjectName(QStringLiteral("ckBBloodCurse"));
        ckBBloodCurse->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBBloodCurse, 2, 3, 1, 1);

        ckBRedList = new QCheckBox(groupBoxTrait);
        ckBRedList->setObjectName(QStringLiteral("ckBRedList"));
        ckBRedList->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(ckBRedList, 2, 4, 1, 1);

        cBSect = new QComboBox(groupBoxTrait);
        cBSect->setObjectName(QStringLiteral("cBSect"));
        cBSect->setMinimumSize(QSize(160, 0));

        gridLayout_4->addWidget(cBSect, 1, 1, 1, 1);

        cBTitle = new QComboBox(groupBoxTrait);
        cBTitle->setObjectName(QStringLiteral("cBTitle"));
        cBTitle->setMinimumSize(QSize(160, 0));

        gridLayout_4->addWidget(cBTitle, 2, 1, 1, 1);

        lSect = new QLabel(groupBoxTrait);
        lSect->setObjectName(QStringLiteral("lSect"));
        sizePolicy2.setHeightForWidth(lSect->sizePolicy().hasHeightForWidth());
        lSect->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lSect, 1, 0, 1, 1);

        lTitle = new QLabel(groupBoxTrait);
        lTitle->setObjectName(QStringLiteral("lTitle"));
        sizePolicy2.setHeightForWidth(lTitle->sizePolicy().hasHeightForWidth());
        lTitle->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lTitle, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxTrait, 1, 0, 2, 1);


        horizontalLayout_2->addWidget(CryptSearchFrame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        CryptView = new PartialDeckView(frame_2);
        CryptView->setObjectName(QStringLiteral("CryptView"));
        CryptView->setMinimumSize(QSize(220, 0));
        CryptView->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_2->addWidget(CryptView);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(frame_2);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 10, 0);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pBCryptSearch = new QPushButton(frame_4);
        pBCryptSearch->setObjectName(QStringLiteral("pBCryptSearch"));
        sizePolicy3.setHeightForWidth(pBCryptSearch->sizePolicy().hasHeightForWidth());
        pBCryptSearch->setSizePolicy(sizePolicy3);
        pBCryptSearch->setMinimumSize(QSize(75, 45));
        pBCryptSearch->setMaximumSize(QSize(75, 45));

        horizontalLayout_3->addWidget(pBCryptSearch);

        pBCryptClearForm = new QPushButton(frame_4);
        pBCryptClearForm->setObjectName(QStringLiteral("pBCryptClearForm"));
        sizePolicy3.setHeightForWidth(pBCryptClearForm->sizePolicy().hasHeightForWidth());
        pBCryptClearForm->setSizePolicy(sizePolicy3);
        pBCryptClearForm->setMinimumSize(QSize(75, 45));
        pBCryptClearForm->setMaximumSize(QSize(75, 45));

        horizontalLayout_3->addWidget(pBCryptClearForm);

        pBAddtoDeck = new QPushButton(frame_4);
        pBAddtoDeck->setObjectName(QStringLiteral("pBAddtoDeck"));
        sizePolicy3.setHeightForWidth(pBAddtoDeck->sizePolicy().hasHeightForWidth());
        pBAddtoDeck->setSizePolicy(sizePolicy3);
        pBAddtoDeck->setMinimumSize(QSize(75, 45));
        pBAddtoDeck->setMaximumSize(QSize(75, 45));

        horizontalLayout_3->addWidget(pBAddtoDeck);


        verticalLayout->addWidget(frame_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        VisuelCrypt = new QLabel(frame_3);
        VisuelCrypt->setObjectName(QStringLiteral("VisuelCrypt"));
        sizePolicy3.setHeightForWidth(VisuelCrypt->sizePolicy().hasHeightForWidth());
        VisuelCrypt->setSizePolicy(sizePolicy3);
        VisuelCrypt->setMinimumSize(QSize(360, 500));
        VisuelCrypt->setMaximumSize(QSize(360, 500));
        VisuelCrypt->setFrameShape(QFrame::StyledPanel);
        VisuelCrypt->setFrameShadow(QFrame::Sunken);
        VisuelCrypt->setLineWidth(0);
        VisuelCrypt->setPixmap(QPixmap(QString::fromUtf8("../../jr/Desktop/Vtes_Grelarge.gif")));

        verticalLayout->addWidget(VisuelCrypt);

        verticalSpacer = new QSpacerItem(20, 246, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(frame_3);

        PTVCryptResults = new PItemView(frame);
        PTVCryptResults->setObjectName(QStringLiteral("PTVCryptResults"));
        sizePolicy1.setHeightForWidth(PTVCryptResults->sizePolicy().hasHeightForWidth());
        PTVCryptResults->setSizePolicy(sizePolicy1);
        PTVCryptResults->setMinimumSize(QSize(1130, 100));
        PTVCryptResults->setMaximumSize(QSize(1500, 16777215));
        PTVCryptResults->setFrameShape(QFrame::NoFrame);
        PTVCryptResults->setFrameShadow(QFrame::Plain);
        PTVCryptResults->setLineWidth(0);
        PTVCryptResults->setAlternatingRowColors(true);
        PTVCryptResults->setShowGrid(false);

        horizontalLayout_4->addWidget(PTVCryptResults);


        verticalLayout_2->addWidget(frame);

        tab_search_crypt->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_search_crypt);

        QMetaObject::connectSlotsByName(tab_search_crypt);
    } // setupUi

    void retranslateUi(QScrollArea *tab_search_crypt)
    {
        tab_search_crypt->setWindowTitle(QApplication::translate("tab_search_crypt", "ScrollArea", 0));
        groupBoxText->setTitle(QApplication::translate("tab_search_crypt", "General", 0));
        lName->setText(QApplication::translate("tab_search_crypt", "Name", 0));
        lENameCard->setText(QString());
        lArtist->setText(QApplication::translate("tab_search_crypt", "Artist :", 0));
        lCardText->setText(QApplication::translate("tab_search_crypt", "Text", 0));
        groupBox_3->setTitle(QApplication::translate("tab_search_crypt", "Edition", 0));
        label_48->setText(QApplication::translate("tab_search_crypt", "Set", 0));
        label_46->setText(QApplication::translate("tab_search_crypt", "Rarity", 0));
        groupBoxDiscipline->setTitle(QApplication::translate("tab_search_crypt", "Disciplines", 0));
        lAbombwe->setText(QString());
        lFortitude->setText(QString());
        lObeah->setText(QString());
        lPresence->setText(QString());
        lSerpentis->setText(QString());
        lThaumaturgy->setText(QString());
        lAnimalism->setText(QString());
        lDaimoinon->setText(QString());
        lMelpominee->setText(QString());
        lObfuscate->setText(QString());
        lProtean->setText(QString());
        lSpiritus->setText(QString());
        lValeren->setText(QString());
        lAuspex->setText(QString());
        lDementation->setText(QString());
        lMytherceria->setText(QString());
        lObtenebration->setText(QString());
        lQuietus->setText(QString());
        lTemporis->setText(QString());
        lVicissitude->setText(QString());
        lDominate->setText(QString());
        lNecromancy->setText(QString());
        lPotence->setText(QString());
        lSanguinus->setText(QString());
        lThanatosis->setText(QString());
        lVisceratika->setText(QString());
        groupBox->setTitle(QApplication::translate("tab_search_crypt", "Generation", 0));
        label_21->setText(QApplication::translate("tab_search_crypt", "Grouping", 0));
        label_29->setText(QApplication::translate("tab_search_crypt", "Capacity", 0));
        groupBoxVirtues->setTitle(QApplication::translate("tab_search_crypt", "Virtues", 0));
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
        groupBoxTrait->setTitle(QApplication::translate("tab_search_crypt", "Caracteristics", 0));
        lClan->setText(QApplication::translate("tab_search_crypt", "Clan", 0));
        ckBBlackHand->setText(QApplication::translate("tab_search_crypt", "Black hand", 0));
        ckBFlight->setText(QApplication::translate("tab_search_crypt", "Flight", 0));
        ckBScare->setText(QApplication::translate("tab_search_crypt", "Scarce", 0));
        ckBSeraph->setText(QApplication::translate("tab_search_crypt", "Seraph", 0));
        ckBInfernal->setText(QApplication::translate("tab_search_crypt", "Infernal", 0));
        ckBSlave->setText(QApplication::translate("tab_search_crypt", "Slave", 0));
        ckBSterile->setText(QApplication::translate("tab_search_crypt", "Sterile", 0));
        ckBBloodCurse->setText(QApplication::translate("tab_search_crypt", "Blood curse", 0));
        ckBRedList->setText(QApplication::translate("tab_search_crypt", "Red List", 0));
        lSect->setText(QApplication::translate("tab_search_crypt", "Sect", 0));
        lTitle->setText(QApplication::translate("tab_search_crypt", "Title", 0));
        pBCryptSearch->setText(QApplication::translate("tab_search_crypt", "Search", 0));
        pBCryptSearch->setShortcut(QApplication::translate("tab_search_crypt", "F1", 0));
        pBCryptClearForm->setText(QApplication::translate("tab_search_crypt", "Clear Form", 0));
        pBAddtoDeck->setText(QApplication::translate("tab_search_crypt", "Add to Deck", 0));
        VisuelCrypt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tab_search_crypt: public Ui_tab_search_crypt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_SEARCH_CRYPT_H

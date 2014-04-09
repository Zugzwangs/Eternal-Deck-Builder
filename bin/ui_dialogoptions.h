/********************************************************************************
** Form generated from reading UI file 'dialogoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPTIONS_H
#define UI_DIALOGOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogOptions
{
public:
    QTabWidget *tabWidget;
    QWidget *General;
    QWidget *Impression;
    QGroupBox *gBFormatImpression;
    QRadioButton *rBA4;
    QRadioButton *rBA3;
    QWidget *Multijoueur;
    QPushButton *pBOk;
    QPushButton *pBCancel;
    QPushButton *pBApply;

    void setupUi(QDialog *DialogOptions)
    {
        if (DialogOptions->objectName().isEmpty())
            DialogOptions->setObjectName(QStringLiteral("DialogOptions"));
        DialogOptions->resize(650, 420);
        tabWidget = new QTabWidget(DialogOptions);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 650, 361));
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        tabWidget->addTab(General, QString());
        Impression = new QWidget();
        Impression->setObjectName(QStringLiteral("Impression"));
        gBFormatImpression = new QGroupBox(Impression);
        gBFormatImpression->setObjectName(QStringLiteral("gBFormatImpression"));
        gBFormatImpression->setGeometry(QRect(20, 20, 220, 91));
        rBA4 = new QRadioButton(gBFormatImpression);
        rBA4->setObjectName(QStringLiteral("rBA4"));
        rBA4->setGeometry(QRect(50, 40, 41, 20));
        rBA3 = new QRadioButton(gBFormatImpression);
        rBA3->setObjectName(QStringLiteral("rBA3"));
        rBA3->setGeometry(QRect(130, 40, 41, 20));
        tabWidget->addTab(Impression, QString());
        Multijoueur = new QWidget();
        Multijoueur->setObjectName(QStringLiteral("Multijoueur"));
        tabWidget->addTab(Multijoueur, QString());
        pBOk = new QPushButton(DialogOptions);
        pBOk->setObjectName(QStringLiteral("pBOk"));
        pBOk->setGeometry(QRect(300, 370, 93, 28));
        pBCancel = new QPushButton(DialogOptions);
        pBCancel->setObjectName(QStringLiteral("pBCancel"));
        pBCancel->setGeometry(QRect(410, 370, 93, 28));
        pBApply = new QPushButton(DialogOptions);
        pBApply->setObjectName(QStringLiteral("pBApply"));
        pBApply->setGeometry(QRect(520, 370, 93, 28));

        retranslateUi(DialogOptions);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DialogOptions);
    } // setupUi

    void retranslateUi(QDialog *DialogOptions)
    {
        DialogOptions->setWindowTitle(QApplication::translate("DialogOptions", "Dialog", 0));
        tabWidget->setTabText(tabWidget->indexOf(General), QApplication::translate("DialogOptions", "General", 0));
        gBFormatImpression->setTitle(QApplication::translate("DialogOptions", "           Format d'impression", 0));
        rBA4->setText(QApplication::translate("DialogOptions", "A4", 0));
        rBA3->setText(QApplication::translate("DialogOptions", "A3", 0));
        tabWidget->setTabText(tabWidget->indexOf(Impression), QApplication::translate("DialogOptions", "Impression", 0));
        tabWidget->setTabText(tabWidget->indexOf(Multijoueur), QApplication::translate("DialogOptions", "Multijoueur", 0));
        pBOk->setText(QApplication::translate("DialogOptions", "OK", 0));
        pBCancel->setText(QApplication::translate("DialogOptions", "Cancel", 0));
        pBApply->setText(QApplication::translate("DialogOptions", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogOptions: public Ui_DialogOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPTIONS_H

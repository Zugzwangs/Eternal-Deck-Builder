/********************************************************************************
** Form generated from reading UI file 'tab_gold_fich.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_GOLD_FICH_H
#define UI_TAB_GOLD_FICH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab_gold_fich
{
public:
    QWidget *scrollAreaWidgetContents;

    void setupUi(QScrollArea *tab_gold_fich)
    {
        if (tab_gold_fich->objectName().isEmpty())
            tab_gold_fich->setObjectName(QStringLiteral("tab_gold_fich"));
        tab_gold_fich->resize(1027, 698);
        tab_gold_fich->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1025, 696));
        tab_gold_fich->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab_gold_fich);

        QMetaObject::connectSlotsByName(tab_gold_fich);
    } // setupUi

    void retranslateUi(QScrollArea *tab_gold_fich)
    {
        tab_gold_fich->setWindowTitle(QApplication::translate("tab_gold_fich", "ScrollArea", 0));
    } // retranslateUi

};

namespace Ui {
    class tab_gold_fich: public Ui_tab_gold_fich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_GOLD_FICH_H

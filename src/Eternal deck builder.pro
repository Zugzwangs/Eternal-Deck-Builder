#-------------------------------------------------
#
# Project created by QtCreator 2012-05-28T15:35:21
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += widgets
QT       += printsupport
QT       += sql
QT       += network

TARGET = Eternal deck builder
TEMPLATE = app

SOURCES +=  main.cpp\
            mainwindow.cpp \
            Global.cpp \
            Sauvegarde.cpp \
            dialogoptions.cpp \
            tab_search_library.cpp \
            tab_search_crypt.cpp \
            game_element.cpp \
            update_manager.cpp \
            tab_deck_tuning.cpp \
            tab_gold_fich.cpp \
            marbitemdelegate.cpp \
            marbabstractitemview.cpp \
            Charts/radialchart.cpp \
            Charts/piechart3D.cpp \
            Charts/piechart.cpp \
            Charts/linearchart.cpp \
            Charts/delegates.cpp \
            Charts/chartstyle.cpp \
            Charts/chart.cpp \
            Statistic.cpp \
            playground.cpp \
            mvddeck.cpp \
            mvdbdd.cpp \
            Widgets/bloodbank.cpp \
            Widgets/disciplinebutton.cpp \
            Widgets/vipedviewer.cpp \
            hud.cpp \
            Widgets/library.cpp \
    Widgets/crypt.cpp \
    Widgets/ashheap.cpp

HEADERS  += mainwindow.h \
            Global.h \
            Sauvegarde.h \
            dialogoptions.h \
            tab_search_library.h \
            tab_search_crypt.h \
            game_element.h \
            update_manager.h \
            tab_deck_tuning.h \
            tab_gold_fich.h \
            marbitemdelegate.h \
            marbabstractitemview.h \
            Marb.h \
            Charts/radialchart.h \
            Charts/piechart3D.h \
            Charts/piechart.h \
            Charts/linearchart.h \
            Charts/delegates.h \
            Charts/chartstyle.h \
            Charts/chart.h \
            Statistic.h \
            playground.h \
            mvddeck.h \
            mvdbdd.h \
            Widgets/bloodbank.h \
            Widgets/disciplinebutton.h \
            Widgets/vipedviewer.h \
            hud.h \
            Widgets/library.h \
    Widgets/crypt.h \
    Widgets/ashheap.h

FORMS    += mainwindow.ui \
            dialogoptions.ui \
            tab_search_library.ui \
            tab_search_crypt.ui \
            tab_deck_tuning.ui \
            tab_gold_fich.ui \
            hud.ui \
            Widgets/library.ui \
    Widgets/crypt.ui \
    Widgets/ashheap.ui

RESOURCES += res.qrc

RC_FILE = logo_link.rc

OTHER_FILES += \
    todo_list.txt


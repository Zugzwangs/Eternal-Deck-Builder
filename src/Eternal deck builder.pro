#-------------------------------------------------
#
# Fichier projet.
#
#-------------------------------------------------

QT += core gui widgets printsupport sql network

TEMPLATE = app

#Shadow build
CONFIG(debug, debug|release) {
    TARGET = EternalDeckBuilder_d
    DESTDIR = $${_PRO_FILE_PWD_}/../bin_d
    MODE_PWD = $${_PRO_FILE_PWD_}/../build/debug
} else {
    TARGET = EternalDeckBuilder
    DESTDIR = $${_PRO_FILE_PWD_}/../bin
    MODE_PWD = $${_PRO_FILE_PWD_}/../build/release
}

# Define custom output directories
OBJECTS_DIR = $${MODE_PWD}/obj
MOC_DIR = $${MODE_PWD}/moc
UI_DIR = $${MODE_PWD}/ui
RCC_DIR = $${MODE_PWD}/rcc

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

OTHER_FILES += todo_list.txt


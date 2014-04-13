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
            Statzor.cpp \
            Global.cpp \
            Sauvegarde.cpp \
            pitemview.cpp \
            PGraphics.cpp \
            PWidget.cpp \
            dialogoptions.cpp \
            tab_search_library.cpp \
            tab_search_crypt.cpp \
            game_element.cpp \
            update_manager.cpp

HEADERS  += mainwindow.h \
            pitemview.h \
            Global.h \
            Sauvegarde.h \
            Statzor.h \
            PGraphics.h \
            PWidget.h \
            dialogoptions.h \
            tab_search_library.h \
            tab_search_crypt.h \
            game_element.h \
            update_manager.h

FORMS    += mainwindow.ui \
            dialogoptions.ui \
            tab_search_library.ui \
            tab_search_crypt.ui

RESOURCES += res.qrc

RC_FILE = logo_link.rc


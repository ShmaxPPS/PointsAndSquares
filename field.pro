#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T20:56:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = field
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    gamefield.cpp \
    sideview.cpp \
    cellview.cpp \
    gamemanager.cpp

HEADERS  += mainwindow.h \
    gamefield.h \
    sideview.h \
    cellview.h \
    gamemanager.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc

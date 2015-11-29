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
    gamefield.cpp \
    sideview.cpp \
    cellview.cpp \
    gamemanager.cpp \
    computerai.cpp \
    game.cpp \
    button.cpp

HEADERS  += \
    gamefield.h \
    sideview.h \
    cellview.h \
    gamemanager.h \
    computerai.h \
    game.h \
    button.h

FORMS    +=

OTHER_FILES +=

RESOURCES += \
    images.qrc

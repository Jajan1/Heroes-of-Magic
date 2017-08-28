#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T12:08:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HoM
TEMPLATE = app


SOURCES += main.cpp\
    hero.cpp \
    attribute.cpp \
    spell.cpp \
    effect.cpp \
    logic.cpp \
    ghero.cpp \
    graphics.cpp \
    gspell.cpp

HEADERS  += \
    hero.h \
    attribute.h \
    spell.h \
    effect.h \
    logic.h \
    ghero.h \
    graphics.h \
    gspell.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    images.qrc

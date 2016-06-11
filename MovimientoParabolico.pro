#-------------------------------------------------
#
# Project created by QtCreator 2016-06-10T18:45:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MovimientoParabolico
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DuScene.cpp \
    DuThread.cpp \
    DuBall.cpp

HEADERS  += Widget.h \
    DuScene.h \
    DuThread.h \
    DuBall.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14

DEFINES -= MY_DEBUG

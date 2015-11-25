#-------------------------------------------------
#
# Project created by QtCreator 2015-11-25T13:01:37
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapwidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsonripper.cpp

HEADERS  += mainwindow.h \
    jsonripper.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T14:26:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = radis-label
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    radislabel.cpp \
    radispaintinterface.cpp \
    radistestpaint.cpp

HEADERS  += mainwindow.h \
    radislabel.h \
    radispaintinterface.h \
    radistestpaint.h

FORMS    += mainwindow.ui

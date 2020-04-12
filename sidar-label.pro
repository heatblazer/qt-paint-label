#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T14:26:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sidar-label
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sidarlabel.cpp \
    SidarPaintInterface.cpp \
    sidartestpaint.cpp

HEADERS  += mainwindow.h \
    quadtree.h \
    sidarlabel.h \
    SidarPaintInterface.h \
    sidartestpaint.h

FORMS    += mainwindow.ui

RESOURCES += assets/globe_64.jpg

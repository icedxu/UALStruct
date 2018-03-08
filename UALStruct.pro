#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T13:32:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UALStruct
TEMPLATE = app


SOURCES += main.cpp\
        mytitlebar.cpp \
    basewindow.cpp \
    succ.cpp

HEADERS  += mytitlebar.h \
    basewindow.h \
    succ.h

FORMS    += mytitlebar.ui \
    succ.ui

RESOURCES += \
    UALStruct.qrc
RC_FILE = proj.rc

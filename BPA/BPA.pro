#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T20:36:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BPA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Parser.cpp

HEADERS  += mainwindow.h \
    Parser.h

FORMS    += mainwindow.ui

RC_FILE = AppIconRes.rc

OTHER_FILES +=

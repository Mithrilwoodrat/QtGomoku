#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T15:05:12
#
#-------------------------------------------------

QT       += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
TARGET = Gomoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gomoku.cpp \
    serverdialog.cpp

HEADERS  += mainwindow.h \
    gomoku.h \
    serverdialog.h

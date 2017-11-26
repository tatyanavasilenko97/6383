#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T11:20:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = treeviz
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp       \
           mainwindow.cpp \
           treeview.cpp   \
           treewidget.cpp \
           codetree.cpp

HEADERS  += mainwindow.h  \
            treeview.h    \
            treewidget.h  \
            codetree.h

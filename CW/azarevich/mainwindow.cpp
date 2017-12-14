// Курсовая работа
// mainwindow.cpp
// Азаревич Артём, гр. 6383
// 11.12.17
//
// Бинарные алгоритмы поиска. БДП случайного типа

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent)
{
    setWindowTitle("Визуализация бинарного дерева поиска");
    setMinimumSize(640, 480);
    widget_ = new TreeWidget(this);
    setCentralWidget(widget_);
}



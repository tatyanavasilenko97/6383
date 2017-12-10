// Курсовая работа
// mainwindow.cpp
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    setWindowTitle("Визуализация бинарного дерева");
    setMinimumSize(640, 480);
    widget_ = new TreeWidget(this);
    setCentralWidget(widget_);
}

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    setWindowTitle("Визуализация бинарного дерева");
    setMinimumSize(640, 480);
    widget_ = new TreeWidget(this);
    setCentralWidget(widget_);
}

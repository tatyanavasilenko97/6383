#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    setWindowTitle("Coding by Shannon-Fano and Huffman methods by Bykov I.V. 6383 group");
    setMinimumSize(1000, 600);
    widget_ = new TreeWidget(this);
    setCentralWidget(widget_);
}

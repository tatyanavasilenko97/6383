#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //QLocale::setDefault(QLocale("ru_RU"));
    MainWindow w;
    w.show();
    return a.exec();
}

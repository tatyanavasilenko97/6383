#pragma once

/*  Курсовая работа по дисциплине Программирование.
    Выполнил Быков И. В. 6383
    Вариант 1. Кодирование и декодирование методами Фано-Шеннона и Хаффмана
    Визуалицация метода.
*/

#include "treewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    TreeWidget *widget_;
};


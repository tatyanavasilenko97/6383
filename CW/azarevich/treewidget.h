// Курсовая работа
// treewidget.h
// Азаревич Артём, гр. 6383
// 11.12.17
//
// Бинарные алгоритмы поиска. БДП случайного типа

#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include "treeview.h"

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);

private:
    TreeView *view_;
    QLineEdit *lineEdit_;
    QPushButton *button_;
    QLabel *code;
    QLabel *step;

    unsigned int stateIndex=0;


public slots:
    void insert();
    void next();
    void back();
};

#endif // TREEWIDGET_H

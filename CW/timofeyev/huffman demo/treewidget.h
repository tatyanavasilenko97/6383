// Курсовая работа
// treewidget.h
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include<QLabel>

#include "treeview.h"
#include "codetree.h"

class TreeWidget : public QWidget{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = 0);

public slots:
    void insert();
    void next();
    void back();

private:
    TreeView *view_;
    QLineEdit *lineEdit_;
    QPushButton *button_;
    QLabel *code ;
    QLabel *step;

    std::vector<demo_haffman::State*> states;
    unsigned int stateIndex=0;
};

#endif // TREEWIDGET_H

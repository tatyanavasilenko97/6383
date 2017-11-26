#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include<QLabel>
#include "codetree.h"
#include "treeview.h"
#include "codetree1.h"
#include <vector>
class TreeWidget : public QWidget{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = 0);
    int solve(int s);
    void fill_beginers();
    bool dynamic;

public slots:
    void insert();
    void insert_dynamic();
    void next();
    void back();
    void next_step();
    void back_step();
private:
    TreeView *view_;
    QLineEdit *lineEdit_;
    QPushButton *button_static;
    QPushButton *button_dynamic;
    QLabel *code ;
    QLabel *step;
    QPushButton *next_tree;
    QPushButton *back_tree;
    std::vector<Trees*> trees;
    std::vector<State*> states;
    int stateIndex=0;
    int treeIndex = 0;
    int *beginers;
    int levels;
};

#endif // TREEWIDGET_H

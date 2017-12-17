#pragma once

// Создание окна и обработка функций в визуальном режиме

#include "treeview.h"

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = 0);
    int solve(int s);
    void fill_beginers();
    bool dynamic;
    void buttonEnabledShennon_Fano();
    void buttonEnabledHuff();
public slots:
    void insert_huff();
    void insert_shf();
    void next();
    void back();
private:
    TreeView *view_;
    QLineEdit *lineEdit_;
    QPushButton *button_huffman;
    QPushButton *button_shennon_fano;
    QLabel *code ;
    QLabel *message;
    QLabel *step;
    QPushButton *next_tree;
    QPushButton *back_tree;
    std::vector<Trees*> trees;
    int stateIndex = 0;
    int treeIndex = 0;
    int *beginers;
    int levels;
};


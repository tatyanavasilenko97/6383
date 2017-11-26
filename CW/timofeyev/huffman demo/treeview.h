// Курсовая работа
// treeview.h
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>

#include "codetree.h"

class TreeView : public QWidget{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);
    void setTree(const demo_haffman::BT* data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawNode(QPainter *painter, const demo_haffman::BT* root, int x, int y);
    const demo_haffman::BT* tree;
    const int nodeWidth{ 80 };
    const int nodeHeight{ 80 };
};

#endif // TREEVIEW_H

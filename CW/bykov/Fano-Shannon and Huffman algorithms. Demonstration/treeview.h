#pragma once

// Прорисовка дерева

#include "codetree.h"

class TreeView : public QWidget
{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);
    void setTree(BinaryTree* data);
    void setTree(CodeTree* data);

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    void drawNode(QPainter *painter,  BinaryTree* root, int x, int y);
    BinaryTree* tree;
    const int nodeWidth{ 80 };
    const int nodeHeight{ 80 };
    int dynamic = -1;
};

#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>

#include "codetree1.h"
#include "codetree.h"
class TreeView : public QWidget{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);
    void setTree(BT* data);
    void setTree(CodeTree* data);

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    void drawNode(QPainter *painter,  BT* root, int x, int y);
    BT* tree;
    const int nodeWidth{ 80 };
    const int nodeHeight{ 80 };
    int dynamic = -1;
};

#endif // TREEVIEW_H


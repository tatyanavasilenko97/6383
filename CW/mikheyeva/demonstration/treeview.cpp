#include "treeview.h"
#include "treewidget.h"
#include <QPainter>
#include <QFontMetrics>
#include <sstream>
#include <cmath>
#include <QTextStream>
#include <mainwindow.h>
TreeView::TreeView(QWidget *parent): QWidget(parent), tree(NULL){}


void TreeView::setTree(BT* tree){
    this->tree = tree;
    update();
}

void TreeView::paintEvent(QPaintEvent *){
    QPainter painter(this);
    drawNode(&painter, tree, 0, 0);
}


void TreeView::drawNode(QPainter *painter, BT* root, int x, int y){

    if(root==NULL)return;
    painter->save();
    QPoint p(width() / pow(2, y) * x + width() / pow(2, y+1), nodeHeight * y);

    // square
    QRect rec(p.x() - nodeWidth/4, p.y(), nodeWidth/2, nodeHeight/2);
    painter->setPen(Qt::blue);
    painter->drawRect(rec);
    painter->setPen(Qt::red);

    QFont font = painter->font() ;
    font.setPointSize(10);
    painter->setFont(font);

    std::stringstream str,strw;
    str<<root->symbol<<std::endl;
    str<<root->weight;

    QString text = fontMetrics().elidedText(
        QString::fromLatin1(str.str().c_str()),
        Qt::ElideLeft, rec.width());
    painter->drawText(rec, Qt::AlignCenter, text);

    // lines
    painter->setPen(Qt::blue);
    if(root->left != NULL) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() - width()/pow(2, y+2), p.y() + nodeHeight);
     }

     if(root->right != NULL) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() + width()/pow(2, y+2), p.y() + nodeHeight);
     }
     painter->restore();

     // childs
     if(root->left != NULL)drawNode(painter, root->left, 2*x, y+1);
     if(root->right != NULL)drawNode(painter, root->right, 2*x + 1, y+1);
}

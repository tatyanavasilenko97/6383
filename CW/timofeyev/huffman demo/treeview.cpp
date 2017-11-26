// Курсовая работа
// treeview.cpp
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#include "treeview.h"

#include <QPainter>
#include <QFontMetrics>
#include <sstream>

TreeView::TreeView(QWidget *parent): QWidget(parent), tree(nullptr){}

void TreeView::setTree(const demo_haffman::BT* tree){
    this->tree = tree;
    update();
}

void TreeView::paintEvent(QPaintEvent *){
    QPainter painter(this);
    drawNode(&painter, tree, 0, 0);
}

void TreeView::drawNode(QPainter *painter, const demo_haffman::BT* root, int x, int y){
    if(root==nullptr)return;

    painter->save();
    QPoint p(width() / pow(2, y) * x + width() / pow(2, y+1), nodeHeight * y);

    // circle
    QRect rec(p.x() - nodeWidth/4, p.y(), nodeWidth/2, nodeHeight/2);
    if(root->updated){
        painter->setPen(Qt::red);
    }
    else{
        painter->setPen(Qt::blue);
    }
    painter->drawRect(rec);
    painter->setPen(Qt::black);

    QFont font = painter->font() ;
    font.setPointSize(10);
    painter->setFont(font);

    std::stringstream str;
    str<<root->symbol<<std::endl<<root->weight;

    QString text = fontMetrics().elidedText(
                QString::fromLatin1(str.str().c_str()),
                Qt::ElideLeft, rec.width());
    painter->drawText(rec, Qt::AlignCenter, text);

    // lines
    painter->setPen(Qt::blue);
    if(root->left != nullptr) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() - width()/pow(2, y+2), p.y() + nodeHeight);
    }

    if(root->right != nullptr) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() + width()/pow(2, y+2), p.y() + nodeHeight);
    }
    painter->restore();

    // childs
    if(root->left != nullptr)drawNode(painter, root->left, 2*x, y+1);
    if(root->right != nullptr)drawNode(painter, root->right, 2*x + 1, y+1);
}

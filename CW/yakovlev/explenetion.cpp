#include <QPainter>
#include <QFontMetrics>
#include "explenetion.h"
#include "ui_explenetion.h"

Explenetion::Explenetion(QWidget *parent) :
  QDialog(parent),ui(new Ui::Explenetion) ,
  tree_(nullptr)
{
  ui->setupUi(this);
  update();
}

Explenetion::~Explenetion()
{
  delete ui;
}

void Explenetion::setTree(const treap<int> *tree)
{
    tree_ = tree;
    update();
}

void Explenetion::paintEvent(QPaintEvent *)
{
    if(tree_ == nullptr)
        return;

    QPainter painter(this);
    drawNode(&painter, *tree_, 0, 0);
}

void Explenetion::drawNode(QPainter *painter, const treap<int> &it,
                        int x, int y)
{
    if(&it == NULL)
       return;
    painter->save();

    QPoint p(width() / pow(2, y) * x + width() / pow(2, y+1), nodeHeight * y);

    // circle
    QRect rec(p.x() - nodeWidth/4, p.y(), nodeWidth/2, nodeHeight/2);
    painter->setPen(Qt::blue);
    painter->drawEllipse(rec);
    painter->setPen(Qt::red);
    QString text = fontMetrics().elidedText(QString::number(it.key), Qt::ElideLeft, rec.width()) +
            " , " + fontMetrics().elidedText(QString::number(it.priority), Qt::ElideLeft, rec.width());
    painter->drawText(rec, Qt::AlignCenter, text);
    // lines
    painter->setPen(Qt::blue);
    if(it.left != nullptr) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2,
                          p.x() - width()/pow(2, y+2), p.y() + nodeHeight);
    }

    if(it.right != nullptr) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2,
                          p.x() + width()/pow(2, y+2), p.y() + nodeHeight);
    }

    painter->restore();

    // childs
    if(it.left != nullptr)
        drawNode(painter, *it.left, 2*x, y+1);

    if(it.right != NULL)
        drawNode(painter, *it.right, 2*x + 1, y+1);
}

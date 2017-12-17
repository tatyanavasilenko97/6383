#ifndef EXPLENETION_H
#define EXPLENETION_H

#include <QDialog>
#include "treap.h"

namespace Ui {
  class Explenetion;
}

class Explenetion : public QDialog
{
  Q_OBJECT

public:
  explicit Explenetion(QWidget *parent = 0);
  void setTree(const treap<int> *data);
  ~Explenetion();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
  Ui::Explenetion *ui;
  void drawNode(QPainter *painter, const treap<int> &it,
                int x, int y);

  const treap<int> *tree_;

  const int nodeWidth{ 50 };
  const int nodeHeight{ 50 };
};

#endif // EXPLENETION_H

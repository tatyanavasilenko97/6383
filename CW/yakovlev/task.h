#ifndef TASK_H
#define TASK_H
#include <QString>
#include "treap.h"
#include "task.cpp"
#include "explenetion.h"
#include <QVector>
#include <QFile>
#include <algorithm>

template <class T>
bool addFirstElement(treap<T>*&,QString,QString);

template <class T>
QString addOrDelIntTreapElLine(treap<T>*&,QString,bool);

int HeigthOfTree(const treap<int> &p);

QString DelRandEl(const treap<int> &p, int & level);
#endif // TASK_H

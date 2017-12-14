// Курсовая работа
// treeview.h
// Азаревич Артём, гр. 6383
// 11.12.17
//
// Бинарные алгоритмы поиска. БДП случайного типа

#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>
#include "bts.h"

class TreeView : public QWidget
{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = nullptr);
    void Push_key(Elem a);
    void Push_flag(bool a);
    BTS* tree;


protected:
    void paintEvent(QPaintEvent *event) override;

    Elem Pop_key();
    bool Pop_flag();



private:
    void drawNode(QPainter *painter,  BTS *root, int x, int y);

    // Ширина/Высота элемента
    int nodeWidth{ 120 };
    int nodeHeight{ 25 };

    Elem key;     // Имя искомого/добавляемого элемента
    bool flag; // true - элемент был, false - элемент добавили

};

#endif // TREEVIEW_H

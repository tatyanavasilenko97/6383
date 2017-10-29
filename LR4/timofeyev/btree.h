//
// Лабораторная работа №4
// btree.h
// Тимофеев Дмитрий, группа 6383
// 19.10.17
//
// Программирование алгоритмов с бинарными деревьями

#ifndef BTREE
#define BTREE
#include<stdlib.h>

namespace binTree_modul
{
    typedef char base;

    struct node {
        base info;
        node *lt;
        node *rt;
            // constructor
            node () {lt = NULL; rt = NULL;}
    };

    typedef node *binTree; // "представитель" бинарного дерева

    binTree Create(void);
    bool isNull(binTree);
    base RootBT (binTree); // для непустого бин.дерева
    binTree Left (binTree);// для непустого бин.дерева
    binTree Right (binTree);// для непустого бин.дерева
    binTree ConsBT(const base &x, const binTree &lst,  const binTree &rst);
    void destroy (binTree&);

} // end of namespace binTree_modul


#endif // BTREE


//
// Лабораторная работа №4
// bt_implementanion.cpp
// Тимофеев Дмитрий, группа 6383
// 19.10.17
//
// Программирование алгоритмов с бинарными деревьями

#include <iostream>
#include <cstdlib>
#include "btree.h"
using namespace std ;

namespace binTree_modul
{

//-------------------------------------
    binTree Create()
    {	return NULL;
    }
//-------------------------------------
    bool isNull(binTree b)
    {	return (b == NULL);
    }
//-------------------------------------
    base RootBT (binTree b)			// для непустого бин.дерева
    {	if (b == NULL) { cerr << "Error: RootBT(null) \n"; exit(1); }
        else return b->info;
    }
//-------------------------------------
    binTree Left (binTree b)		// для непустого бин.дерева
    {	if (b == NULL) { cerr << "Error: Left(null) \n"; exit(1); }
        else return b ->lt;
    }
//-------------------------------------
    binTree Right (binTree b)		// для непустого бин.дерева
    {	if (b == NULL) { cerr << "Error: Right(null) \n"; exit(1); }
        else return b->rt;
    }
//-------------------------------------
    binTree ConsBT(const base &x, const binTree &lst, const binTree &rst)
    {	binTree p;
        p = new node;
        if ( p != NULL)	{
            p ->info = x;
            p ->lt = lst;
            p ->rt = rst;
            return p;
        }
        else {cerr << "Memory not enough\n"; exit(1);}
    }
//-------------------------------------
    void destroy (binTree &b)
    {	if (b != NULL)	{
            destroy (b->lt);
            destroy (b->rt);
            delete b;
            b = NULL;
        }
    }

} // end of namespace h_list

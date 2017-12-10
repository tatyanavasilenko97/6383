// Курсовая работа
// bts.cpp
// Азаревич Артём, гр. 6383
// 11.12.17
//
// Бинарные алгоритмы поиска. БДП случайного типа

#include "bts.h"



BTS::BTS( Elem x )
{
    key = x;
    left = right = NULL;
}


BTS::~BTS()
{
    if (left != NULL)
        delete left;

    if (right != NULL)
        delete right;
}


bool BTS::Find_Add (Elem &x)
{
    if ( key > x)
    {
        if ( left == NULL )
        {
            left = new BTS(x);
            return false;
        }
        return left->Find_Add(x);
    }

    if ( key < x)
    {
        if ( right == NULL )
        {
            right = new BTS(x);
            return false;
        }
        return right->Find_Add(x);
    }

    if ( key == x )
        return true;
}


Elem BTS::Ret_key()
{
    return key;
}

BTS * BTS::Left_Child()
{
    return left;
}


BTS * BTS::Right_Child()
{
    return right;
}

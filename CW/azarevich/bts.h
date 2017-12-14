// Курсовая работа
// bts.h
// Азаревич Артём, гр. 6383
// 11.12.17
//
// Бинарные алгоритмы поиска. БДП случайного типа

#ifndef BTS_H
#define BTS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

typedef int Elem;

class BTS
{
public:
    BTS( Elem x);
    ~BTS();

    bool Find_Add (Elem &x);
    BTS *Left_Child();
    BTS *Right_Child();
    Elem Ret_key();


private:
    Elem key;
    BTS *left;
    BTS *right;
};

#endif // BTS_H

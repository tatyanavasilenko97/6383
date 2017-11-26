// Курсовая работа
// codetree.h
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#ifndef CODETREE
#define CODETREE

#include<iostream>
#include"bitstream.h"

namespace code_tree {
    void encode(std::istream &in, std::ostream &code);
    void decode(std::istream &in, std::ostream &code);
}

#endif // CODETREE


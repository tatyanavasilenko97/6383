// Лабораторная работа №5
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#include <iostream>
#include<fstream>
#include"codetree.h"

using namespace std;
using namespace code_tree;

// a0b00r0100k01100d011011001000!
void test(){
    ifstream input("msg");
    ofstream output("code");
    encode(input, output);
    output.close();
    input.close();
    ifstream coded("code");
    ofstream decoded("encoded");
    decode(coded, decoded);
}

int main(){
    test();
    return 0;
}


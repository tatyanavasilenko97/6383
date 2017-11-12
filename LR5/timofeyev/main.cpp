// Лабораторная работа №5
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#include <iostream>
#include"codetree.h"

using namespace std;
using namespace code_tree;


int main(){
    cout<<"Введите закодированную строку"<<endl;
    char code[1000];
    scanf("%s",code);
    cout<<decode(code)<<endl;
    return 0;
}


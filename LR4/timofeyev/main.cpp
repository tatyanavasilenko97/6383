//
// Лабораторная работа №4
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 19.10.17
//
// Программирование алгоритмов с бинарными деревьями

#include"form.h"
using namespace std ;
using namespace form_modul;

int main (){
    Form f;
    Form fPrime;
    try{
        cout<<"Исходная формула: "; writeForm(cout, (f=readForm(cin)));cout<<endl;
        cout<<"Производная по х: "; writeForm(cout, (fPrime=deriviate(f,'x')));cout<<endl;
    }
    catch(const char* t){
        cout<<t;
    }
    destroy(f);
    destroy(fPrime);
    return 0;
}

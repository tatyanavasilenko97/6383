// Лабораторная работа 4
// Вариант 3б
// Проверить, равны ли два бинарных дерева
// Михеева Екатерина группа 6383
// 22.10.17
// Пример ввода дерева (a(b//)(c//))
//
#include <iostream>
#include "bintree.h"

using namespace std;

void outBT(binTree b);
bool check(binTree b1, binTree b2);
binTree enterBracket();

int main(){
    binTree b1,b2;
    cout<<"Введите дерево 1"<<endl;
    try {
        b1 = enterBracket();
    }
    catch (char *error){
        cout << error;
        return 0;
    }
    cout<<"Введите дерево 2"<<endl;
    try {
        b2 = enterBracket();
    }
    catch (char *error){
        cout << error;
        return 0;
    }
    cout<<endl;
    if (check(b1,b2) == true)
        cout << "Equal"<<endl;
    else
        cout <<"Not equal"<<endl;
    destroy(b1);
    destroy(b2);
    return 0;
}

bool check(binTree b1, binTree b2){
    if ((b1 == NULL) && (b2 == NULL))
        return true;
    if (((b1 == NULL) ^ (b2 == NULL)) == true)
        return false;
    if (RootBT(b1) != RootBT(b2))
        return false;
    return (check (Left(b1), Left(b2)) && check (Right(b1), Right(b2)));
}

void outBT(binTree b) {
    if (b!=NULL) {
        cout << RootBT(b);
        outBT(Left(b));
        outBT(Right(b));
    }
    else cout << '/';
}

binTree enterBracket(){
    binTree p,q;
    char elem;
    cin >> elem;
    if (elem == '/')
        return NULL;
    if (elem == '('){
        cin >> elem;
        p = enterBracket();
        q = enterBracket();
        char ch;
        cin >> ch;
        if (ch != ')')
            throw "incorrect input\n";
        return ConsBT(elem,p,q);
    }
    throw "incorrect input\n";
}

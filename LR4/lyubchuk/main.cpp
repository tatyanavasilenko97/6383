#include <iostream>

#include <fstream>

#include <fstream>

#include <cstdlib>

#include "Btree.h"

//#include <windows.h>

//#include <conio.h>

#include <algorithm>

using namespace std;

using namespace binTree_modul;

typedef unsigned int unInt;

binTree enterBT();

void displayBT(binTree b, int n);

int getMaxDepth(binTree b, int depth);
ifstream infile("input.txt");




int main()

{
    
    binTree b;
    
  //  SetConsoleCP(1251); // для вывода кирилицы
    
  //  SetConsoleOutputCP(1251); // для вывода кирилицы
    
    b = enterBT();
    
    
    if (isNull(b)) cout << "Пустое БД" << endl;
    
    else
    
    {
        
        cout << "Бинарное дерево (повернутое): " << endl;
        
        displayBT(b, 1);
        
        cout << "\nВычисление высоты дерева: " << endl;
        
        int a = getMaxDepth(b,1) - 1;
        
        cout << "Высота дерева = " << a << "\n\n";
        
        destroy(b);
        
    }
    
    _getch();
    
}

//---------------------------------------

binTree enterBT()

{
    
    char ch;
    
    binTree p, q;
    
    infile >> ch;//считывание из файла
    
    while (ch == '(' || ch == ')') infile >> ch;//проверка на скобки
    
    if (ch == '/') { return NULL; }//проверка на пустой элемент
    
    else { //иначе рекурсивная запись элементов
        
        p = enterBT();
        
        q = enterBT();
        
        return ConsBT(ch, p, q);
    }
    
}

int getMaxDepth(binTree q, int depth)//находит глубину дерева

{
    
    if (q != NULL)//если узел не пуст
    
    cout << "Узел " << q->info << " Текущая глубина=" << depth << endl; //Печать узла и текущей глубины
    
    if (q == NULL) { return depth; }//Если элемент пуст, возвращается значение глубины
    
    else return max(getMaxDepth(q->rt, depth + 1), getMaxDepth(q->lt, depth + 1));//В противном случае, рекурсивно продолжается процесс
    
}


//---------------------------------------

void displayBT(binTree b, int n) //Для печати повернутого дерева

{ // n - уровень узла
    
    if (b != NULL)
    
    {
        
        cout << ' ' << RootBT(b); //Проверка элемента
        
        if (!isNull(Right(b)))
        
        displayBT(Right(b), n + 1); //Если правая ветка не пустая, то печатаем элементы
        
        else cout << endl; // спускаемся вниз
        
        if (!isNull(Left(b))) //Если левая ветка не пустая, то печатаем элементы
        
        {
            
            for (int i = 1; i <= n; i++)
            
            cout << " "; // вправо
            
            displayBT(Left(b), n + 1);
            
        }
        
    }
    
}

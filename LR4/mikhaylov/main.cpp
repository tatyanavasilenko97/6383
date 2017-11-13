#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BTree.h"
#include <windows.h>
#include <conio.h>
#include <algorithm>

using namespace std;
using namespace binTree_modul;

typedef unsigned int unInt;

binTree enterBT();
void displayBT(binTree b, int n);
unInt NumOfLvl(binTree b, int a, int c = 1);
ifstream infile("KLP.txt");

int main()
{
	binTree b;
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	b = enterBT();
	if (isNull(b)) cout << "Пустое БД" << endl;
	else
	{
		cout << "Бинарное дерево (повернутое): " << endl;
		displayBT(b, 1);
		cout << "\nНахождение количества узлов на N-ом уровне. Введите N:" << endl;
		int num;
		cin >> num;
		cout << "Количество узлов на заданном уровне = " << NumOfLvl(b, num);

		destroy(b);

	}
	_getch();
}

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

void displayBT(binTree b, int n)  //Для печати повернутого дерева
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
	else {};
}

unInt NumOfLvl(binTree b, int lvl, int lvl_now)
{
	if (b != NULL && lvl >= lvl_now) //Если элемент не равен нулю и уровень больше текущего
		cout << lvl << " vs " << lvl_now << "; Узел -" << b->info << ";"; //то этот элемент - узел
	{
		if (lvl == lvl_now) cout << " Узел на заданном уровне существует!\n"; //есл уровень равен текущему уровню
		else cout <<" Узла на заданном уровне нет!"<< endl;
	}
	if (lvl == lvl_now) return 1;
	else if (lvl >= lvl_now)
		return(((b->lt) ? NumOfLvl(b->lt, lvl, lvl_now + 1) : 0) + ((b->rt) ? NumOfLvl(b->rt, lvl, lvl_now + 1) : 0)); //Подсчет кол-ва узлов
}

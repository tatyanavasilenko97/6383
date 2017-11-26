#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include "Btree.h"
#include <windows.h>
#include <conio.h>
#include <algorithm>

using namespace std;
using namespace binTree_modul;

typedef unsigned int unInt;

binTree enterBT();
void displayBT(binTree b, int n);
unInt sizeBT(binTree b);
unInt lenBT(binTree b);
unInt NumOfLvl(binTree b, int a, int c = 1);
int getMaxDepth(binTree b, int depth = 1);
void levelBT(binTree b);
ifstream infile("KLP.txt");

int main()
{
	binTree b;
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	b = enterBT();
	int depth = 1;
	if (isNull(b)) cout << "Пустое БД" << endl;
	else
	{
		cout << "Бинарное дерево (повернутое): " << endl;
		displayBT(b, 1);
		cout << "\nВычисление высоты дерева: " << endl;
		int a = getMaxDepth(b) - 1;
		cout << "Высота дерева = " << a << "\n\n";
		cout << "Длина внутреннего пути дерева = " << lenBT(b) << endl;
		cout << "\nПоиск листьев дерева:" << endl; levelBT(b);
		cout << "\nНахождение количества узлов на N-ом уровне. Введите N:" << endl;
		int num;
		cin >> num;
		cout << "Количество узлов на заданном уровне = " << NumOfLvl(b, num);

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

void levelBT(binTree b) //Поиск листьев дерева
{
	if (!isNull(b)) //Если дерево не пусто
	{
		if (!(isNull(b->lt) && isNull(b->rt))) //Если не правый и не левый
			cout << "Узел:" << b->info << endl;//то это узел, петатаем его
		levelBT(b->lt); //Рекурчивно проверяем следующий элемент
		if (isNull(b->lt) && isNull(b->rt)) //если правый и левый
			cout << "Лист:" << b->info << endl; //то это лист , печать
		levelBT(b->rt);
	}
}

unInt NumOfLvl(binTree b, int lvl, int lvl_now)
{
	if (b != NULL && lvl >= lvl_now) //Если элемент не равен нулю и уровень больше текущего
		cout << lvl << " vs " << lvl_now << "       Узел " << b->info; //то этот элемент - узел
	{
		if (lvl == lvl_now) cout << " Узел на заданном уровне существует!\n"; //есл уровень равен текущему уровню
		else cout << endl;
	}
	if (lvl == lvl_now) return 1;
	else if (lvl >= lvl_now)
		return(((b->lt) ? NumOfLvl(b->lt, lvl, lvl_now + 1) : 0) + ((b->rt) ? NumOfLvl(b->rt, lvl, lvl_now + 1) : 0)); //Подсчет кол-ва узлов
}

//int len = 0;

unInt lenBT(binTree b) //Для внутреннего пути
{
	if (!isNull(b)) //Если дерево не пусто
		cout << "Узел " << b->info << " " << /*Печать узла*/
		" Левый " << lenBT(Left(b)) <<  /*Печать левого*/
		" Правый " << lenBT(Right(b)) <<    /*Печать правого*/
		" Количество узлов " << sizeBT(b) - 1 << endl; /*Печать количества узлов*/
	if (isNull(b)) { return 0; } //Если пустое дерево, возврат 0
	else return lenBT(Left(b)) + lenBT(Right(b)) + sizeBT(b) - 1; //В противном случае, возрат внутреннего пути дерева
}

unInt sizeBT(binTree b) //Для подсчета количества узлов
{
	if (isNull(b)) return 0; //Проверка на пустое дерево
	else return sizeBT(Left(b)) + sizeBT(Right(b)) + 1; //Если нет , то рекурсивный подсчет кол-ва узлов
}

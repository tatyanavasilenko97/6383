#include <iostream>
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
void Findleaf(binTree b);
ifstream infile("DEREVO.txt");

int main()
{
	binTree b;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	b = enterBT();
	int depth = 1;
	if (isNull(b)) cout << "Пустое БД" << endl;
	else
	{
		cout << "Поиск листьев дерева:" << endl; Findleaf(b);
		destroy(b);
	}
	_getch();
}

binTree enterBT()
{
	char ch;
	binTree p, q;
	infile >> ch;
	while (ch == '(' || ch == ')') infile >> ch;
	if (ch == '/') { return NULL; }
	else {
		p = enterBT();
		q = enterBT();
		return ConsBT(ch, p, q);
}
}

void Findleaf(binTree b)
{
	if (!isNull(b))
	{
		if (!(isNull(b->lt) && isNull(b->rt)))
			cout << "Узел:" << b->info << endl;
		Findleaf(b->lt);
		if (isNull(b->lt) && isNull(b->rt))
			cout << "Лист:" << b->info << endl;
		Findleaf(b->rt);
	}
}
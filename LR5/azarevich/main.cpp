//
// Лабораторная работа №5
// main.cpp
// Азаревич артём, группа 6383
// 13.11.2017
//
// Программа для создания бинарного дерева 
// поиска t и последующего поиска элемента х

#include <windows.h>
#include "BTS.h"

void Read_F (BTS &t, istream &in);
bool Continous();

void main()
{
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	ifstream fin("F.txt");
	if (!fin)
	{
		cerr << "Файл не найден";
		exit;
	}

	Elem x;
	fin >> x;
	BTS t(x);
	Read_F(t, fin);

	do
	{
		system("cls");
		cout << "Дерево: \n";
		t.Display();

		cout << "\n\nПоиск элемента: ";
		cin >> x;

		if ( t.Find_Add(x) )
			cout << "Элемент в дереве уже есть\n\n";
		else
		{
			cout << "Элемент вставлен в дерево. Новое дерево:\n";
			t.Display();
		}
	}
	while ( Continous() );
}


bool Continous()
{
	begin:
	cout << "Завершить? (Y/N)\n";
	char c;

	cin >> c;

	switch(c)
	{
		case 'Y': return false;
		case 'N': return true;
		default: goto begin;
	}
}


void Read_F (BTS &t, istream &in)
{
	while( !in.eof() )
	{
		Elem x;
		in >> x;

		t.Find_Add(x);
	}
}
//
// Лабораторная работа №4
// main.cpp
// Азаревич артём, группа 6383
// 30.10.2017
//
// Программа для поиска элемента х в бинарном дереве b

#include <windows.h>
#include "BT.h"
using namespace std;


int main () 
{
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	std::ifstream fin("test.txt");
	if(!fin)
		GLOBAL_ERRORS(2);	//cerr: тестовый файл не найден

	BT b(fin);

	std::cout <<"Задано бинарное дерево:\n";
	b.Display(1);
	
	Elem x;
	while( true )
	{
		std::cout << "Элемент ";
		std::cin >> x;

		cout <<"в заданном бинарном дереве\n";

		if ( b.Found(x) )
			std::cout << "присутствует\n\n";
		else
			std::cout << "отсутствует\n\n";
	}
}


void GLOBAL_ERRORS(int n)
{
	switch(n)
	{
	case 0: cerr << "Ошибка: Бин. дерево не закончно\n"; break;
	case 1: cerr << "Ошибка: Дерево пусто\n";			 break;
	case 2: cerr << "Ошибка: Тестовый файл не найден\n"; break;
	default: return;
	}

	exit(1);
}



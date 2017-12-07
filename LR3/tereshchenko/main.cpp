#include <iostream>
#include <fstream>
#include <locale.h>
#include "stack.h"
#include "queue.h"
#include "methods.h"
#include <Windows.h>

using namespace std;

 //проверка, является ли формулой 
void mainformula(ifstream &fin, Stack &Q2)
{
	Queue Q3;
	int n = 1;
	char symb;
	fin >> symb;
	while (!(fin.eof()))
	{
		Q2.push(symb);
		Q3.push(symb);
		fin >> symb;
	}
	Stack Q1;
	while (Q2.can_pop())
	{
		char a = Q2.pop();
		cout << "Заносим в стек элемент [" << a << "]\n";
		Q1.push(a);
	}
	cout << "\nСчитанная строка: ";
	print_formula(Q3);
	cout << endl << endl;
	bool f = is_it_formula(Q1, Q3);
	cout << "\nЭто формула!\n\n";
	int what_is_open_bracket(char symb, int s);
}

 //вывод формулы
void print_formula(Queue &Q3)
{
	while (Q3.can_pop())
	cout << Q3.pop();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "Rus");
	ifstream fin("input.txt");
	
	if (!fin.is_open())
	{
		cout << "Файл не может быть открыт или не создан\n";
		system("pause");
		return 1;
	}
	if (fin.eof()) cout << "Файл пуст\n";
	else
	{
		Stack Q2;
		mainformula(fin, Q2);
	}
	fin.close();
	system("pause");
}
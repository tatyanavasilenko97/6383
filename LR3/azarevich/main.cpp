//
// Лабораторная работа №3
// main.cpp
// Азаревич артём, группа 6383
// 16.09.2017
//
// Программа для вывода содержимого файла F в определённом порядке
#include <fstream>
#include "Queue.h"
using namespace std ;

void GLOBAL_ERRORS(int num);
bool F_read(istream &in, Queue &lessA, Queue &greaterB, Queue &A_B, type a, type b);
void F_write(Queue &lessA, Queue &greaterB, Queue &A_B);

void main()
{
	setlocale(0, "");
	Queue lessA;
	Queue greaterB;
	Queue A_B;

	ifstream fin("F.txt");
	if (!fin)
		GLOBAL_ERRORS(0);

	type a, b;

	cout <<"Введите а: ";
	cin >> a;

	cout <<"Введите b: ";
	cin >> b;

	if (a >= b)
		GLOBAL_ERRORS(2);

	if ( !F_read(fin, lessA, greaterB, A_B, a, b) ) 
		cerr << "Предупреждение: одна из очередей переполнилась\n";

	F_write(lessA, greaterB, A_B);


	
	char c;
	cin >> c;
}



void GLOBAL_ERRORS(int num)
{
	switch(num)
	{
		case 0: cerr << "Ошибка: файл с исходными данными не найден\n";	break;
		case 1: cerr << "Ошибка: Память не выделена\n";					break;
		case 2: cerr << "Ошибка: а должно быть меньше b\n";				break;
		case 3: cerr << "Ошибка: в файле должны быть ТОЛЬКО числа\n";	break;
		default: return;
	}
	exit(1);
}


bool F_read(istream &in, Queue &lessA, Queue &greaterB, Queue &A_B, type a, type b)
{
	type item;
	cout << "Содержимое файла:\n";

	while(!in.eof())
	{
		in >> item;
		if (!in.good() && !in.eof())
			GLOBAL_ERRORS(3);

		cout << item <<ends;
		

		if ( item < a )
		{
			if( !lessA.push(item) ) return false;
		}
		else
			if ( item > b )
			{
				if( !greaterB.push(item) ) return false;
			}
			else 
				if ( !A_B.push(item) ) return false;
 	}

	return true;
}


void F_write(Queue &lessA, Queue &greaterB, Queue &A_B)
{
	type item;
	cout <<"\nПосле преобразования:\n";

	while( lessA.pop(item) )
		cout << item << ends;

	while( A_B.pop(item) )
		cout << item << ends;

	while( greaterB.pop(item) )
		cout << item << ends;
}
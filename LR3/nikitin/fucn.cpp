#include "Header.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace vect
{
	// Функция, проверяющая корректность введенных данных при работе в меню 
	//и выводящая на экран запрос о повторном введении данных, если они введены некорректно.
	void fail_menu(int& q)
	{
		//введенное с клавиатуры значение
		while ((cin.fail()) || ((q != 1) && (q != 2)))
		{
			cout << "Error. Enter another value\n";
			cin.clear();
			cin.sync();
			cin >> q;
		}
	}

	// Функция, выводящая на экран и в файл сообщение об ошибке входных данных и производящая выход из программы.
	void ErrorMessege()
	{
		cout << "Error! Wrong value. Programm will end\n";
		system("pause");
		exit(1);
	}

	// Функция, добавляющая элемент в стек.
	void Stack::push(int& i)
	{
		//значение текущего элемента
		l++;
		st[l] = i;
		topOfStack = st[l];
	}

	// Функция, извлекающая элемент из стека.
	void Stack::pop()
	{
		l--;
		topOfStack = st[l];
	}
}

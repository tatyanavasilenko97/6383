#include <iostream>
#include <fstream>

#include "interf.h"

using namespace std;
using namespace stack;

int main()
{
	setlocale(LC_ALL, "");
	if (!fout.is_open()) //проверка на корректность открытия
	{
		cout << "! - Error: file was not opened\n"; //ошибка
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (!fin.is_open()) //проверка корректности открытия
	{
		cout << "! - Error: file is not opened." << endl; //ошибка
		system("pause");
		exit(EXIT_FAILURE);
	}
	int cmd;
	Stack operation; //стек для операций M(max) или m(min) из формулы
	Stack digit; //стек для цифр из формулы
	bool tag;
	cout << "Загрузка данных из файла" << endl;
	tag = read_expr(fin, &operation, &digit); //начинаем считывание из файла
		if (tag && !fout.eof())
		{//формула корректна
			cout << "\nformula is correct\n";
			fout << "\nformula is correct\n";
		}
		else
		{ //ошибка: слишком много символов
			cout << "\n! - Error: invalid expression- too much symbols!\n";
			fout << "\n! - Error: invalid expression- too much symbols!\n";
			exit(EXIT_FAILURE);
		}
	base result = digit.top(); // получение результата из стека.
	cout << "Result of calculating: " << result << endl;
	fout << "Result of calculating: " << result << endl;
	cout << "End!\n";
	fout << "End!\n";
	system("pause");
	fin.close();
	fout.close();
	operation.destroy();
	digit.destroy();
	return 0;
}
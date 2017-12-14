#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "lisp.h"
#include "list.h"

using namespace std;

int main() {
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	ifstream infile("input.txt");
	ofstream outfile("output.txt");

	lisp s;
	elem b;
	int n = 0;

	// Считывание иерархического списка из файла
	read_lisp(s, infile);
	cout << "Введен иерархический список: " << endl;
	// Вывод списка на экран
	write_lisp(s);
	// Анализ иерархического списка;
	// s - иерархический список, b - линейный список, n - количество атомов
	analysis(s, b, n);
	cout << endl << "Результаты анализа: " << endl << "Количество атомов = " << n << endl << "Линейный список: " << endl;
	outfile << "Результаты анализа: " << endl << "Количество атомов = " << n << endl << "Линейный список: " << endl;
	// Вывод результатов анализа;
	output(b, outfile);
	cout << endl;
	outfile << endl;
	cout << "Анализ успешно завершен..." << endl;
	destroy(s);
	destroy_lin(b);
	system("pause");
	return 0;
}
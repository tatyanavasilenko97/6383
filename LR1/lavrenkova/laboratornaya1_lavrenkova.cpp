//
// Лабораторная работа №1
// lab1.cpp
// Лавренкова Екатерина, группа 6383
// 18.09.17
//
// Программа для вывода всех перестановок символов

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// фукнция меняет x и y местами
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// рекурсивная функция переборов всех возможный перестановок строки
void next(int k, char *A, const int n, bool toFile) {
	if (k == n)
	{
		for (int i = 0; i < n; i++)
			cout << A[i];

		if (!toFile)
			cout << endl;
		else
			cout << endl;
		return;
	}

	for (int i = k; i < n; i++)
	{
		swap(A[k], A[i]);
		next(k + 1, A, n, toFile);
		swap(A[k], A[i]);
	}
}

// функция меню
void Menu() {
	cout << "Если вы хотите ввести символы из консоли - нажмите 1." << endl;
	cout << "Если вы хотите вывести символы из файла - нажмите 2." << endl;
	cout << "Если вы хотите выйти - нажмите 3." << endl;
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int m;
	Menu();
	cout << "\nВведите номер операции: ";
	cin >> m;
	while (true) {
		switch (m) {
		case 1: {
			system("cls");
			char A[1000] = {};
			int n;
			cout << "Введите количество вводимых символов: ";
			cin >> n;
			while (n <= 0) {
				cout << "Количество символов должно быть положительным. Попробуйте ещё раз." << endl;
				cin >> n;
			}
			cout << "\nВведите символы: ";
			cin >> A;
			while (n != strlen(A)) {
				cout << "Неверное количество символов. Попробуйте ещё раз: " << endl;
				cout << "\nВведите символы: ";
				cin >> A;
			}
			next(0, A, n, false);
			Menu();
			cout << "\nВведите номер операции: ";
			cin >> m;
			break;
		}
		case 2: {
			system("cls");
			ifstream in;
			in.open("in.txt");
			if (!in) {
				cout << "Файла с данными не существует. Введите символы с консоли." << endl << "\n";
				cout << "\nНажмите 1: ";
				cin >> m;
				break;
			}
			char A[1000];
			int n;
			in >> n;
			for (int i = 0; i < n; i++)
				in >> A[i];
			next(0, A, n, true);
			Menu();
			cout << "\nВведите номер операции: ";
			cin >> m;
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		default:
			cout << "\nНеверный ввод. Попробуйте ещё раз." << endl;
			Menu();
			cout << "\nВведите номер операции: ";
			cin >> m;
			break;
		}
	}
}

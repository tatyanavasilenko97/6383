#include <iostream>
#include <fstream>
#include <cstdlib>
#include "head.h"
#include <windows.h>

using namespace std;

void main() {
	int w = 1;
	char x;
	Formula* head = new Formula;
		cout << "Please, select:\n1. Enter the three\n2. Enter the formula\n";
		cin >> w;
		Error(w);
		cin.get(x);
		if (w == 1) read_three(head, x); // вызов функции считывани€ дерева-формулы с клавиатуры
		if (w == 2) read_form(head, x); // вызов функции считывани€ формулы с клавиатуры
		cin.get(x);
		if (x != '\n') ErrorMessege(); // если не все данные были считаны, то вывод об ошибке и прерывание программы
		system("cls");
		while (w != 4) {// выбор пользователем последующей работы программы
		system("cls");
		cout << "Please, select:\n1. Print the three\n2. Print the formula\n3. Calculate the value\n4. Exit\n";
		cin >> w;
		switch (w) {
			case 1: // печать дерева-формулы
				int depth; // переменна€ дл€ определени€ текущей глубины формулы
				depth = 0;
				bool close[50]; // массив переменных дл€ определени€ "закрытости" дерева с соответствующей глубиной, то есть пограмма работает со вторым его плечом.
				for (int k = 1; k <= 49; k++) close[k] = 0;
				print(head); // вызов функции печати формулы
				cout << endl;
				build(head, depth, close); // вызов функции печати дерева-формулы
				break;

			case 2: // печать формулы
				print(head); // вызов функции печати формулы
				cout << endl;
				break;

			case 3: // расчет результата формулы
				bool k;
				k = 1; // переменна€, определ€юща€ наличие терминалов-букв
				int res; // переменна€ дл€ записи в нее результата
				calculate(head, res, k); // вызов функции расчета результата
				print(head); // вызов функции печати формулы
				if (!k) { // печать о невозможности расчета результата из-за наличи€ в формуле не только цифр
					cout << "\nCalcutation can not be performed.\n";
				}
				else {// печать результата
					cout << " = " << res << endl;
				}
				break;

			case 4:
				w = 4;
				break;

			default: // некорректный ввод
				cout << "Uncorrect input. Try again.\n";
				break;
			}
			system("pause");
		}
}

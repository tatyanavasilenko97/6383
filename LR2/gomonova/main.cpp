#include <iostream>
#include "list.h"
using namespace std;


void printAndReverseLists()
{
	lisp s1 = NULL;

	system("cls");
	cout << boolalpha;
	cout << "Ваша последовательность " << endl;
	read_lisp(s1);
	freopen("CON", "rt", stdin);

	cout << "====================================" << endl;
	write_lisp(s1);

	cout << endl << " Начальный набор скобок и символов " << endl;
	write_lisp(s1);	cout << endl;

	lisp s2 = rev(s1, NULL);

	cout << " Обращенный набор скобок и символов " << endl;
	write_lisp(s2);	cout << endl;
	cout << "====================================" << endl;
	system("pause");
}


int main()
{
	setlocale(0, "RUS");

	char action;
	bool exit = false;
	char string[256];

	while (!exit)
	{
		system("cls");
		cout << "Выберите нужное действие." << endl;
		cout << "====================================" << endl;
		cout << " 1. Считать из файла " << endl;
		cout << " 2. Ввод с консоли " << endl;
		cout << " 3. Завершить программу " << endl;
		cout << "====================================" << endl;
		cout << "Ваш ответ: ";
		(cin >> action).get();
		cout << "====================================" << endl;
		switch (action)
		{
		case '1':
			system("cls");
			cout << "Введите путь до файла: (Пример описания директории для Windows: C:\\folder\\file.txt)" << endl;
			cin.getline(string, 256);
			freopen(string, "rt", stdin);
			printAndReverseLists();
			break;
		case '2':
			printAndReverseLists();
			break;
		case '3':
			return 0;
			break;
		default:
			system("cls");
			cout << "Введена некорретная команда\n";
			system("pause");
		}
	}
	return 0;
}



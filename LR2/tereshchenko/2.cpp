#include <iostream>
#include <climits>
#include <iomanip>
#include <windows.h>
#include "methods.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "Rus");
	Unit* list = nullptr;
	unsigned a;
	do
	{
		cout << "1. Ввести список\n" << "2. Вывести список на экран\n" << "3. Копировать список\n" << "4. Удалить все вхождения элемента x\n" 
			"5. Проверить, пустой ли список\n" << "6. Очистить список\n" << "7. Выход\n\n" << "   Выберите команду: ";
		cin >> a;
		system("cls");
		switch (a)
		{
			case 1:
			{
				destroy(list);
				cout << "Введите список: ";
				list = readUnit(list);
				break;
			}
			case 2:
			{
				if (isEmpty(list)) cout << "Текущий список пуст\n";
				else
				{
					cout << "Текущий список: ";
					write(list);
				}
				break;
			}
			case 3:
			{
				cout << "Исходный список: ";
				write(list);
				Unit* list_copy = copy(list);
				cout << "Скопированный список: ";
				write(list_copy);
				destroy(list_copy);
				break;
			}
			case 4:
			{
				cout << "Введите элемент, который хотите удалить (x): ";
				base x;
				cin >> x;
				cout << "Исходный список (x = " << x << "):";
				write(list);
				list = delete_x(list, x);
				cout << "Обработанный список: ";
				write(list);
				break;
			}
			case 5:
			{
				if (isEmpty(list)) cout << "Список пуст\n";
				else cout << "Список не пуст\n";
				break;
			}
			case 6:
			{
				destroy(list);
				list = nullptr;
				cout << "Список очищен\n";
				break;
			}
			case 7:
			{
				cout << "Спасибо за работу\n";
				break;
			}
			default:
				cout << "Пожалуйста, введите цифру из предложенных\n";
		}
		system("pause");
		system("cls");
	}
	while (a != 7);
	return 0;
}
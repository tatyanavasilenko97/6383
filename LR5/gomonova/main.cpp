#include "bintree.h"

#include <stdlib.h>
#include <locale.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <time.h>

using namespace std;
using namespace binTree_modul;

binTree b;
vector<int> numbers;

void readFromFileBinTree()
{
	char path[256];

	cout << "Введите пункт к файлу: ";
	cin >> path;

	ifstream file(path);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!\n";
		return;
	}
	else
	{
		cout << "\nВведенные значения:\n";
		numbers.clear();
		while (!file.eof())
		{
			char value[80];
			file >> value;
			cout << value << " ";

			numbers.push_back(atoi(value));
		}
		cout << endl;

	}


}

void readFromKeyboardBinTree()
{
	int size;
	cout << "Введите количество чисел: ";
	cin >> size;

	numbers.clear();
	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << i + 1 << " число: ";
		int value;
		cin >> value;
		numbers.push_back(value);
	}

	cout << "\nВведенные значения:\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;


}

void generateRandomNumbers()
{
	int size;
	cout << "Введите количество чисел: ";
	cin >> size;

	numbers.clear();

	cout << "\nВведенные значения:\n";
	for (int i = 0; i < size; i++)
	{
		numbers.push_back(rand() % 100 + 1);
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;
}

void generateBinTree()
{
	b = NULL;
	int t = 0;
	for (int i = 0; i<numbers.size(); i++)
	{
		b = insertrandom(b, numbers[i], t);
	}
}

void generateDataBinTree()
{

	int decision1 = 1;
	while (decision1 != 4)
	{
		system("cls");

		cout << " #################################################" << endl;
		cout << " #                                               #" << endl;
		cout << " #                     Меню                      #" << endl;
		cout << " #                                               #" << endl;
		cout << " #    1.  Ввести данные из файла                 #" << endl;
		cout << " #    2.  Ввести данные с клавиатуры             #" << endl;
		cout << " #    3.  Создать произвольное дерево            #" << endl;
		cout << " #    4.  Вернуться к предыдущему пункту         #" << endl;
		cout << " #                                               #" << endl;
		cout << " #################################################" << endl << endl;
		cout << " Выберите: ";

		cin >> decision1;
		switch (decision1)
		{
		case 1:
			system("cls");
			cout << "1. Ввести данные из файла\n";
			readFromFileBinTree();
			generateBinTree();
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "2. Ввести данные с клавиатуры\n";
			readFromKeyboardBinTree();
			generateBinTree();
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "3. Ввести данные с клавиатуры \n";
			generateRandomNumbers();
			generateBinTree();
			system("pause");
			break;

		case 4:
			break;

		default:
			system("cls");
			cout << "Нет такого варианта! Повторите попытку.\n";
			system("pause");
			break;
		}



	}

}

void find_add()
{
	while (true)
	{
		int x = 0;
		cout << "Поиск элемента: ";
		cin >> x;
		if (searchAndElement(b, x))
			cout << "Элемент в дереве уже есть\n\n";
		else
		{
			cout << "Элемент вставлен в дерево. Новое дерево:\n\n";
			numbers.push_back(x);
			displayBT(b, 1);
			cout << endl << endl;
		}


		int decision = 0;
		while (decision == 0)
		{
			cout << "Завершить? [Y/N]: ";
			char c;
			cin >> c;

			if (c == 'Y' || c == 'y')
			{
				return;
			}
			else
				if (c == 'N' || c == 'n')
				{
					break;
				}
				else
				{
					decision = 0;
				}
		}
		
	}
	

}

void printBinTree()
{
	if (numbers.size() == 0)
	{
		cout << "Данные отсутствуют! Необходимо добавить данные прежде чем выводить дерево.\n";
		system("pause");
		return;
	}
	
	cout << endl << endl;
	displayBT(b, 1);
	cout << endl << endl;
	
	find_add();
	system("pause");

}

void deleteElemntInBinTree()
{
	if (numbers.size() == 0)
	{
		cout << "Данные отсутствуют! Необходимо добавить данные прежде чем выводить дерево.\n";
		system("pause");
		return;
	}
	cout << "Ваше дерево:\n\n";
	displayBT(b, 1);
	cout << endl << endl;

	cout << "Введите удаляемый элемент в дереве: ";
	int x;
	cin >> x;

	bool flag = false;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == x)
		{
			numbers[i] = numbers[numbers.size() - 1];
			numbers.erase(numbers.begin() + numbers.size() - 1);
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "Отсутствует данный элемент!";
		system("pause");
		return;
	}

	b = NULL;
	int t = 0;
	for (int i = 0; i<numbers.size(); i++)
	{
		b = insertrandom(b, numbers[i], t);
	}

	cout << "Ваше дерево:\n\n";
	displayBT(b, 1);
	cout << endl << endl;

	system("pause");

}


int main()
{
	srand(time(NULL));
	setlocale(0,"Russian");
	int decision = 1;

	while (decision != 5)
	{
		system("cls");
		
		cout << " #################################################" << endl;
		cout << " #                                               #" << endl;
		cout << " #                     Меню                      #" << endl;
		cout << " #                                               #" << endl;
		cout << " #    1.  Создать СБД поиска                     #" << endl;
		cout << " #    2.  Поиск элемента в дереве                #" << endl;
		cout << " #    3.  Удалить элемент дерева                 #" << endl;
		cout << " #    4.  Очистка СБД поиска                     #" << endl;
		cout << " #    5.  Выход                                  #" << endl;
		cout << " #                                               #" << endl;
		cout << " #################################################" << endl << endl;
		cout << " Выберите: ";

		cin >> decision;
		switch (decision)
		{
			case 1:
				system("cls");
				cout << "1. Создание случайного бинарного дерева поиска\n\n";
				generateDataBinTree();
				break;

			case 2:
				system("cls");
				cout << "2. Поиск элемента в дереве \n";
				printBinTree();
				break;

			case 3:
				system("cls");
				cout << "3.  Удалить элемент дерева\n";
				deleteElemntInBinTree();
				break;

			case 4:
				system("cls");
				cout << "4. Очистка СБД поиска \n";
				numbers.clear();
				b = NULL;
				cout << "Выполнено успешно!\n";
				system("pause");
				break;


			case 5:
				break;

			default:
				system("cls");
				cout << "Нет такого варианта! Повторите попытку.\n";
				system("pause");
				break;
		}

	}

    return 0;
}


#include <iostream>
#include <fstream>
#include <map>
#include <conio.h>
#include <string>
#include <windows.h>
#include "process.h"

using namespace std;
using namespace proc;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //Консольный хук
COORD CursorPosition;

void gotoXY(int, int); //Перемещения по консоли

void main() {
	setlocale(LC_ALL, "Russian");//Русские символы в консоле

	string str;
	My lets;
	ifstream in("input.txt");
	if (!in.is_open()) {
		cout << "Файл input.txt не найден!" << endl;
		system("pause");
		return;
	}

	char buff[1024] = { 0 };

	//Считывание файла в одну строку (переносы строк заменяются символом "_")
	while (!in.eof()) {
		in.getline(buff, 1024);
		buff[(sizeof(buff) / sizeof(buff[0])) - 1] = NULL;
		str += buff;
		str += '_';
	}
	str.pop_back();//Удаление последнего символа
	in.close();

	if (str.length() == 0) {
		cout << "Исходный файл пуст!" << endl;
		getchar();
		return;
	}

start:
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;

	gotoXY(30, 5); cout << "    Main Menu";
	gotoXY(10, 7); cout << "->";

	while (running)
	{
		gotoXY(12, 7);  cout << "• Метод Хаффмана (вывод алгоритма кодирования/декодирования)";
		gotoXY(12, 8);  cout << "  [Исходный файл - input.txt, результирующий - hman.txt]";
		gotoXY(12, 9);  cout << "• Метод Шеннона-фано (вывод алгоритма кодирования/декодирования)";
		gotoXY(12, 10);  cout << "  [Исходный файл - input.txt, результирующий - fano.txt]";
		gotoXY(12, 11);  cout << "• Выход";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x < 11) //нажата кнопка "Верх"
		{
			gotoXY(10, x); cout << "  ";
			x += 2;
			gotoXY(10, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x > 7) //нажата кнопка "Вниз"
		{
			gotoXY(10, x); cout << "  ";
			x -= 2;
			gotoXY(10, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { //нажата кнопка "Enter"
			system("cls");
			switch (menu_item) {
			case 0: {
				lets.hman(str);
				running = false;
				break;
			}

			case 1: {
				lets.fano(str);
				running = false;
				break;
			}

			case 2: {
				cout << "Вы завершили работу программы." << endl;
				running = false;
				getchar();
				return;
			}
			}

		}

	}

	getchar();
	goto start;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
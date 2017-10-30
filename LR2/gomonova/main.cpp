#include <iostream>
#include "list.h"
using namespace std;


void printAndReverseLists()
{
	lisp s1 = NULL;

	system("cls");
	cout << boolalpha;
	cout << "���� ������������������ " << endl;
	read_lisp(s1);
	freopen("CON", "rt", stdin);

	cout << "====================================" << endl;

	write_lisp(s1);

	cout << endl << " ��������� ����� ������ � �������� " << endl;
	write_lisp(s1);	cout << endl;

	lisp s2 = rev(s1, NULL);

	cout << " ���������� ����� ������ � �������� " << endl;
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
		cout << "�������� ������ ��������." << endl;
		cout << "====================================" << endl;
		cout << " 1. ������� �� ����� " << endl;
		cout << " 2. ���� � ������� " << endl;
		cout << " 3. ��������� ��������� " << endl;
		cout << "====================================" << endl;
		cout << "��� �����: ";
		(cin >> action).get();
		cout << "====================================" << endl;
		switch (action)
		{
		case '1':
			system("cls");
			cout << "������� ���� �� �����: (������ �������� ���������� ��� Windows: C:\\folder\\file.txt)" << endl;
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
			cout << "������� ������������ �������\n";
			system("pause");
		}
	}
	return 0;
}







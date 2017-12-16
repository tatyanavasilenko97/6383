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
		if (w == 1) read_three(head, x); // ����� ������� ���������� ������-������� � ����������
		if (w == 2) read_form(head, x); // ����� ������� ���������� ������� � ����������
		cin.get(x);
		if (x != '\n') ErrorMessege(); // ���� �� ��� ������ ���� �������, �� ����� �� ������ � ���������� ���������
		system("cls");
		while (w != 4) {// ����� ������������� ����������� ������ ���������
		system("cls");
		cout << "Please, select:\n1. Print the three\n2. Print the formula\n3. Calculate the value\n4. Exit\n";
		cin >> w;
		switch (w) {
			case 1: // ������ ������-�������
				int depth; // ���������� ��� ����������� ������� ������� �������
				depth = 0;
				bool close[50]; // ������ ���������� ��� ����������� "����������" ������ � ��������������� ��������, �� ���� �������� �������� �� ������ ��� ������.
				for (int k = 1; k <= 49; k++) close[k] = 0;
				print(head); // ����� ������� ������ �������
				cout << endl;
				build(head, depth, close); // ����� ������� ������ ������-�������
				break;

			case 2: // ������ �������
				print(head); // ����� ������� ������ �������
				cout << endl;
				break;

			case 3: // ������ ���������� �������
				bool k;
				k = 1; // ����������, ������������ ������� ����������-����
				int res; // ���������� ��� ������ � ��� ����������
				calculate(head, res, k); // ����� ������� ������� ����������
				print(head); // ����� ������� ������ �������
				if (!k) { // ������ � ������������� ������� ���������� ��-�� ������� � ������� �� ������ ����
					cout << "\nCalcutation can not be performed.\n";
				}
				else {// ������ ����������
					cout << " = " << res << endl;
				}
				break;

			case 4:
				w = 4;
				break;

			default: // ������������ ����
				cout << "Uncorrect input. Try again.\n";
				break;
			}
			system("pause");
		}
}

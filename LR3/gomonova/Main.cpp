//#include <stdafx.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include "Stack.h"
#include "Queue.h"
using namespace std;

void call_error(Queue & Q3, char symb, int numb) // ������� ������������ ����� ������
{
	cout << ",������� �� ������������� �������� �������." << endl;
	cout << "��� �� �������!" << endl;
	switch (numb)
	{
	case 1:
	{
		cout << "��������� ���, ���� [x],[y],[z], ��� ����������� ������ - [(]." << endl;
		break;
	}
	case 2:
	{
		cout << "�������� ����, ���� [+],[-], ��� ����������� ������ - [)]." << endl;
		break;
	}
	default: break;
	}
	cout << "����� ������, ������� �������� �������� � ����� ���� ���������." << endl;
	while (Q3.can_pop())
		cout << Q3.pop() << " ";
	cout << "\n��������� ����� ���������." << endl;
	system("pause");
	exit(1);
}
bool bracket_c_f(char symb)  // �������� ����������� ������
{
	if (symb == ')')
		return true;
	else
		return false;
}
bool bracket_o_f(char symb) // �������� ����������� ������
{
	if (symb == '(')
		return true;
	else
		return false;
}
bool sign_f(char symb)    // ������� �������� �������� ������
{
	if (symb == '+' || symb == '-')
		return true;
	else
		return false;
}
bool name_f(char symb)      // �������� �������� �� �������� ������
{
	if (symb == 'x' || symb == 'y' || symb == 'z')
		return true;
	else
		return false;
}
bool is_it_f(Stack Q1, Queue & Q3)   // �������� �� ������ ��������
{
	char symb;
	bool name = true;
	bool sign = false;
	bool bracket_c = false;
	bool bracket_o = true;
	bool is_el = false;
	int open = 0;
	int close = 0;
	while (Q1.can_pop())
	{
		symb = Q1.pop();
		cout << "�� ����� �������� ������� [" << symb << "] ";
		is_el = false;
		if (!is_el && name && name_f(symb))
		{
			cout << ",������� �������� ������. " << endl;
			is_el = true;
			name = false;
			sign = true;
			bracket_c = true;
			bracket_o = false;
			Q3.push(symb);
		}
		if (!is_el && sign && sign_f(symb))
		{
			cout << ",������� �������� ������." << endl;
			is_el = true;
			name = true;
			sign = false;
			bracket_c = false;
			bracket_o = true;
			Q3.push(symb);
		}
		if (!is_el && bracket_o && bracket_o_f(symb))
		{
			cout << ",������� �������� ����������� �������. " << endl;
			is_el = true;
			bracket_o = true;
			bracket_c = false;
			name = true;
			sign = false;
			open++;
			Q3.push(symb);
		}
		if (!is_el && bracket_c && bracket_c_f(symb))
		{
			close++;
			cout << ",������� �������� ����������� �������." << endl;
			if (close <= open)
			{
				close--;
				open--;
				is_el = true;
				bracket_o = false;
				bracket_c = true;
				name = false;
				sign = true;
				Q3.push(symb);
			}
			else
				call_error(Q3, symb, 2);
		}
		if (!is_el && (name && bracket_o))
			call_error(Q3, symb, 1);
		else
			if (!is_el && (sign && bracket_c))
				call_error(Q3, symb, 2);
	}
	if (open != close)
		call_error(Q3, symb, 2);
	return true;
}
void print_f(Queue & Q3)      // ������� �������
{
	while (Q3.can_pop())
	{
		cout << Q3.pop() << " ";
	}
}
void mainf(ifstream & fin, Stack & Q2)   // ������� � ������� ���������� ������� �������� �� ��������
{
	Queue Q3;
	int n = 1;
	char symb;
	fin >> symb;
	while (!(fin.eof()))
	{
		Q2.push(symb);
		Q3.push(symb);
		fin >> symb;
	}
	Stack Q1;
	cout << "������� �������� ������ � ����:" << endl;
	while (Q2.can_pop())
	{
		char a = Q2.pop();
		cout << "� ���� ������� ������� [" << a << "]." << endl;
		Q1.push(a);
	}
	cout << "��������� �� ����� ������.";
	print_f(Q3);
	cout << endl;
	bool f = is_it_f(Q1, Q3);
	cout << "��� �������." << endl;
	cout << "�� ���: " << endl;
	print_f(Q3);
}
int main()
{
	setlocale(LC_ALL, "rus");
	int answer;
	cout << "�������� ������ ��������." << endl;
	cout << "============================================" << endl;
	cout << "1.������� ������� �� �����." << endl;
	cout << "2.��������� ���������." << endl;
	cout << "============================================" << endl;
	cout << "��� �����: ";
	cin >> answer;
	cout << "============================================" << endl;
	while (answer != 1 && answer != 2 || cin.fail())
	{
		system("cls");
		cout << "�� ����� �������� ��������. ����������� �����." << endl;
		cin.clear();
		cin.sync();
		cout << "============================================" << endl;
		cout << "1.������� ������� �� �����." << endl;
		cout << "2.��������� ���������." << endl;
		cout << "============================================" << endl;
		cout << "��� �����: ";
		cin >> answer;
		cout << "============================================" << endl;
	}
	if (answer == 1)
	{
		ifstream fin("queue.txt");
		Stack Q2;
		mainf(fin, Q2);
		fin.close();
	}
	else
		cout << "������ ����� ���������." << endl;
	cout << endl;
	system("pause");
}

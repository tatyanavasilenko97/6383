#include "Header.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace vect
{
	// �������, ����������� ������������ ��������� ������ ��� ������ � ���� 
	//� ��������� �� ����� ������ � ��������� �������� ������, ���� ��� ������� �����������.
	void fail_menu(int& q)
	{
		//��������� � ���������� ��������
		while ((cin.fail()) || ((q != 1) && (q != 2)))
		{
			cout << "Error. Enter another value\n";
			cin.clear();
			cin.sync();
			cin >> q;
		}
	}

	// �������, ��������� �� ����� � � ���� ��������� �� ������ ������� ������ � ������������ ����� �� ���������.
	void ErrorMessege()
	{
		cout << "Error! Wrong value. Programm will end\n";
		system("pause");
		exit(1);
	}

	// �������, ����������� ������� � ����.
	void Stack::push(int& i)
	{
		//�������� �������� ��������
		l++;
		st[l] = i;
		topOfStack = st[l];
	}

	// �������, ����������� ������� �� �����.
	void Stack::pop()
	{
		l--;
		topOfStack = st[l];
	}
}

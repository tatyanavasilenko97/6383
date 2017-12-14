#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "St_class.h"
using namespace std;

void result(ifstream& fin) {
	Stack<int> s;
	char a[100];
	int n1 = 100;
	int n = 0;
	while (n < n1 && fin >> a[n]) n++;
	cout << "����� ������: " << n << endl;
	for (int i = 0; i < n; i++) cout << a[i];
	cout << endl;
	cout << "��������� ���������..." << endl;

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == ' ')
			continue;
		cout << "���: " << i << " ������ = " << a[i] << endl;
		if (a[i] == '+')
			s.push(s.pop2() + s.pop2());
		if (a[i] == '-')
			s.push(s.pop2() - s.pop2());
		if (a[i] == '/')
			s.push(s.pop2() / s.pop2());
		if (a[i] == '*')
			s.push(s.pop2() * s.pop2());
		if (isdigit(a[i])) {
			s.push(a[i] - '0');
			while (isdigit(a[--i]))
			{
				cout << "���_: " << i << " ������ = " << a[i] << endl;
				s.push(10 * (a[i] - '0') + s.pop2());
			}
		}
	}
	cout << "��������� =" << s.pop2() << endl;
}

int main() {	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "���� ������ � ���������� ������� ��������� � �����." << endl;
	ifstream fin("prefix.txt");
	fin >> noskipws;	
	if (!fin) { cout << "File not open for reading!\n"; return 1; }
	result(fin);
		
	system("pause");
	return (0);
}

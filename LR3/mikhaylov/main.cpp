#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "St_class.h"
using namespace std;

void result(ifstream& fin,Stack<int> s) {
	char a[100];
	int n1 = 100;
	int n = 0;
	while (n<n1 && fin >> a[n]) n++;
	cout << "����� ������: " << n << endl;
	for (int i = 0; i<n; i++) cout << a[i];
	cout << endl;
	cout << "��������� ���������..." << endl;
	
	for (int i = n; i >= 0; i--)
	{
		cout << "���: " << i << " ������ = " << a[i] << endl;
		if (a[i] == '+')
			s.push(s.pop2() + s.pop2());
		if (a[i] == '-')
			s.push(s.pop2() - s.pop2());
		if (a[i] == '/')
			s.push(s.pop2() / s.pop2());
		if (a[i] == '*')
			s.push(s.pop2() * s.pop2());
		if ((a[i] >= '0') && (a[i] <= '9'))
			s.push(0);
		while ((a[i] >= '0') && (a[i] <= '9'))
		{
			s.push(10 * s.pop2() + (a[i--] - '0'));
			cout << "���_: " << i << " ������ = " << a[i] << endl;
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
	Stack<int> s;
	result(fin, s);

	s.destroy();
	system("pause");
	return (0);
}

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
	cout << "Длина строки: " << n << endl;
	for (int i = 0; i < n; i++) cout << a[i];
	cout << endl;
	cout << "Вычисляем выражение..." << endl;

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == ' ')
			continue;
		cout << "шаг: " << i << " символ = " << a[i] << endl;
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
				cout << "шаг_: " << i << " символ = " << a[i] << endl;
				s.push(10 * (a[i] - '0') + s.pop2());
			}
		}
	}
	cout << "Результат =" << s.pop2() << endl;
}

int main() {	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Ввод строки с префиксной записью выражения с файла." << endl;
	ifstream fin("prefix.txt");
	fin >> noskipws;	
	if (!fin) { cout << "File not open for reading!\n"; return 1; }
	result(fin);
		
	system("pause");
	return (0);
}

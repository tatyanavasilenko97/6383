#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "St_class.h"
using namespace std;


int main() {
	char a[100];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Ввод строки с постфиксной записью выражения с файла." << endl;
	ifstream fin("postfix.txt");
	fin >> noskipws;
	if (!fin) { cout << "File not open for reading!\n"; return 1; }
	int n1 = 100;
	int n = 0;
	while (n<n1 && fin >> a[n]) n++;
	cout << "Длина строки: " << n << endl;
	for (int i = 0; i<n; i++) cout << a[i];
	cout << endl;
	cout << "Вычисляем выражение..." << endl;

	Stack<int> s;
	for (int i = 0; i < n; i++)
	{
		cout << "шаг: " << i << " символ = " << a[i] << endl;
		if (a[i] == '+')
			s.push(s.pop2() + s.pop2());
		if (a[i] == '-')
			s.push(s.pop2() - s.pop2());
		if (a[i] == '*')
			s.push(s.pop2() * s.pop2());
		if (a[i] == '/')
			s.push(s.pop2() / s.pop2());
		if ((a[i] >= '0') && (a[i] <= '9'))
			s.push(0);
		while ((a[i] >= '0') && (a[i] <= '9'))
		{
			s.push(10 * s.pop2() + (a[i++] - '0'));
			cout << "шаг_: " << i << " символ = " << a[i] << endl;
		}
	}
	cout << "Результат =" << s.pop2() << endl;

	system("pause");
	return (0);
}

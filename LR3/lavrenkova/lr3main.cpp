#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "lr3head.h"

using namespace std;
using namespace st_modul1;

int main() {
	char a[100];
	setlocale(0, "Rus");
	cout << "Ввод строки с постфиксной записью выражения." << endl;
	ifstream fin("postfix.txt");
	fin >> noskipws; // включить манипулятор

	if (!fin)
	{
		cout << "Файл отсутствует!\n";
		system("Pause");
		return 1;
	}

	int n1 = 100;
	int n = 0;
	while (n < n1 && fin >> a[n]) n++;
	cout << "Длина строки = " << n << endl;
	for (int i = 0; i < n; i++) cout << a[i];
	cout << endl;
	cout << "Вычислить!" << endl;

	Stack s;
	for (int i = 0; i < n; i++)
	{
		cout << "Шаг_: " << i + 1 << " символ = " << a[i] << endl; // dem
		if (a[i] == '+')
			s.push(s.pop2() + s.pop2());
		if (a[i] == '-')
		{
			base tmp = s.pop2();
			s.push(s.pop2() - tmp);
		}
		if (a[i] == '*')
			s.push(s.pop2() * s.pop2());
		if (a[i] == '/')
		{
			base tmp = s.pop2();
			s.push(s.pop2() / tmp);
		}
		if (a[i] == '^')
		{
			base tmp = s.pop2();
			s.push((base)pow(s.pop2(), tmp));
		}
		if ((a[i] >= '0') && (a[i] <= '9'))
			s.push(0);
		while ((a[i] >= '0') && (a[i] <= '9'))
		{
			s.push(10 * s.pop2() + (a[i++] - '0'));
			cout << "Шаг_: " << i + 1 << " символ = " << a[i] << endl;// dem
		}
	}
	cout << "Результат = " << s.pop2() << endl;

	s.destroy();

	system("Pause");
	return 0;
}
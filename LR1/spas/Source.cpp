#include <iostream>
#include <Windows.h>

using namespace std;

/**
*     ������ ����������:       ��������| ��������, ������ ����������
*     �������� :             ��� = ����� �����    | ���=(������ ����������)
*     ��� : ����� ����� �����
*/
bool spisok(std::istream& in);

bool imya(std::istream& in) {
	for (int i = 0; i < 3; ++i) {
		if (isalpha(in.peek())) in.get();
		else return false;
	}
	return true;
}


bool parametr(std::istream& in) {
	if (!imya(in))return false;
	if (in.peek() != '=') {
		return false;
	}
	in.get();
	if (in.peek() == '(') {
		in.get();
		spisok(in);
		if (in.peek() != ')')return false;
		in.get();
		return true;
	}
	else {
		for (int i = 0; i < 2; ++i) {
			if ('0' <= in.peek() <= '9') in.get();
			else return false;
		}
	}
	return true;
}

bool spisok(std::istream& in) {
	if (!parametr(in)) return false;
	if (in.peek() == '\n') return true;
	if (in.peek() != ',')return false;
	else {
		in.get();
		spisok(in);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� ����������: ";
	if (spisok(cin)) cout << "�������� ������� ����������\n";
	else cout << "�� �������� ������� ����������\n";
	system("pause >nul");
	return 0;
}
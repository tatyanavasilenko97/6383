#include <iostream>
#include <Windows.h>
using namespace std;
/*
������::=� | ������ ������
������::= (B ������)
*/

bool bracket(std::istream& in);

bool brackets(std::istream& in) {
	while (true) {
		switch (in.peek()) {
		case'A':
			in.get();
			if (in.peek() == 10)
				return true;
			if (in.peek() == ')')
				return true;
			if (!bracket(in)) return false;
			return false;
		case '(':
			in.get();
			if (in.peek() == ')')
				return false;
			if (!bracket(in)) return false;
			return true;
		default:
			return false;
			break;
		}
	}
}

bool bracket(std::istream& in) {
	while (true) {
		switch (in.peek()) {
		case 'B':
			in.get();
			if (!brackets(in)) return false;
			return true;
		case ')':
			in.get();
			if (!brackets(in)) return false;
			return true;
		default:
			return false;
			break;
		}
	}
}

int main() {
	SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "������� ���������� ��������:" << endl;
		if (brackets(cin)) {
			cout << "���� ���������� �������� �������" << endl;
		}
		else cout << "���� ���������� �� �������� �������   " << endl;

		system("pause");
		return 0;
}

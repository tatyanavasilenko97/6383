#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

/**
*     скобки: A | (B скобки скобки)
*/
bool _bracketsBegin(std::istream& in);
bool _bracketsCont(std::istream& in);

int check = 0;

bool _bracketsEnd(std::istream& in) {

	while (true) {
		switch (in.peek()) {
		case '(':
			in.get();
			if (!_bracketsCont(in)) return false;
			return true;
			break;
		case 'A':
			check = -1;
			in.get();
			if (!_bracketsBegin(in)) return false;
			return true;
			break;
		default:
			return false;
			break;
		}
	}
}

bool _bracketsCont(std::istream& in) {

	while (true) {
		switch (in.peek()) {
		case 'B':
			check = -1;
			in.get();
			if (!_bracketsEnd(in)) return false;
			return true;
			break;
		default:
			return false;
			break;
		}
	}
}

bool _bracketsBegin(std::istream& in) {
	
	while (true) {
		switch (in.peek()) {
		case '(':
			in.get();
			if (!_bracketsCont(in)) return false;
			return true;
			break;
		case ')':
			in.get();
			if (in.peek() == ')') return false;
			if (!_bracketsBegin(in)) return true;
			break;
		case 'A':
			in.get();
			
			if (in.peek() != 'A'&& check == 0) return false;
			if (!_bracketsBegin(in)) return true;
			return true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите комбинацию символов:" << endl;
	if (_bracketsBegin(cin)) {
		cout << "Это скобка!" << endl;
	}
	else cout << "Это не скобка!" << endl;
	system("pause");
	return 0;
}

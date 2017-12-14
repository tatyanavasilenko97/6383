#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

/**
*     скобки: A | (B скобки скобки)
*/
//------------------------------
bool braket_(std::istream& in){

	switch (in.peek()) {
		case 'A':
			in.get();
			return true;
			break;
		case '(':
			in.get();
			if (in.peek() == 'B') 
			in.get();
			if (!(braket_(in) && braket_(in))) 
				return false;
			if (in.peek() == ')') 
				return true;			
			return false;
			break;
		default:
			return false;
	}
	return false;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите комбинацию символов:" << endl;
	if (braket_(cin)) {
		cout << "Это скобка!" << endl;
	}
	else cout << "Это не скобка!" << endl;
	system("pause");
	return 0;
}

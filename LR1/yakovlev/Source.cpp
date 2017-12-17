#include <iostream>
#include <string>
#include <clocale>
using namespace std;

string lgcFrml; int  it = -1;
bool ERR = false;

bool logic();
bool NOT();
bool AND_OR();
void ERROR(int a);
void ERROR(int a) {
	ERR = true;
	switch (a)
	{
	case 1: cout << endl << "Лишние символы" << endl;		break;
	case 3: cout << endl << "Не закрыта скобка для NOT" << endl;		break;
	case 4: cout << endl << "Не закрыта скобка для AND" << endl;		break;
	case 5: cout << endl << "Не закрыта скобка для OR" << endl;		break;
	default: break;
	}

}
bool logic() {
	it++;
	if (lgcFrml[it] == 'T' || lgcFrml[it] == 'F'){
		if (lgcFrml[it] == 'T' && lgcFrml[it + 1] == 'R' && lgcFrml[it + 2] == 'U' && lgcFrml[it + 3] == 'E') {  it += 4;return true; }
		if (lgcFrml[it] == 'F' && lgcFrml[it + 1] == 'A' && lgcFrml [it + 2] == 'L'  && lgcFrml[it + 3] == 'S'&& lgcFrml[it + 4] == 'E') { it += 5; return false; }
																											else ERROR(1);
	}
	else {
		if (lgcFrml[it] == 'N') return NOT();
		if (lgcFrml[it] == 'A' || lgcFrml[it] == 'O') return AND_OR();
	}
	ERROR(1);
}

bool NOT() {
	if (lgcFrml[it] == 'N' && lgcFrml[it+1] == 'O' && lgcFrml[it + 2] == 'T' && lgcFrml[it + 3] == '(')
	{
		it += 3;
		bool O;
		O = logic();
		if (lgcFrml[it] == ')') { it++; return !O; }
		else ERROR(3);
		return 0;

	}
	else ERROR(1);
}


bool AND_OR() {
	bool val;
	if (lgcFrml[it] == 'A' && lgcFrml[it + 1] == 'N' && lgcFrml[it + 2] == 'D' && lgcFrml[it + 3] == '(')
	{
		val = 1;
		it += 3;
		do {
			val &= logic();
		} while (it < lgcFrml.length() && lgcFrml[it] != ')');

		if (lgcFrml[it] == ')') { it++; return val; }	else ERROR(4);
	}

	if (lgcFrml[it] == 'O' && lgcFrml[it + 1] == 'R'  && lgcFrml[it + 2] == '(')
	{
		val = 0;
		it += 2;
		do {
			val |= logic();
		} while (it < lgcFrml.length() && lgcFrml[it] != ')');

		if (lgcFrml[it] == ')') { it++; return val; }else ERROR(5);
	}
	ERROR(1);
}


int main() {
	setlocale(LC_ALL, "ru_RU.CP1251");
	setlocale(LC_ALL, "Russian");
	cout << "        (     TRUE     FALSE     NOT()     OR()      AND()     )" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Введите логическкое выражение: ";

	cin >> lgcFrml;
	cout << "Ваше выражение: " << lgcFrml;
	
	if (logic()) { if (!ERR) cout << "  ===  TRUE"; }
	else if (!ERR) cout << "  ===  FALSE";
	cout << endl;
	system("pause");
	return 0;
}
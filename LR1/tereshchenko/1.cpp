// Lr ¹1
// 1.cpp
// Tereshchenko Viktoria, group 6383
// 18.09.17
// Var 21

#include <iostream>
#include <fstream>

using namespace std ;
bool Brackets(ifstream &f);
bool Round (ifstream &f, char c);
bool Square (ifstream &f, char c);
void Error (short n);

int main ( )
{
	setlocale (LC_ALL,""); 
	ifstream f ("input.txt");
	if (!f.is_open()) { 
    	cout << "File can not be opened or created"; 
		return 1; 
	}
	bool a = Brackets (f);
	if (a) cout << "Yes, it's'" << endl;
	else cout << "No, it isn't'" << endl;
	system("pause");
	return 0;
}	

bool Round (ifstream &f, char c)
{ 
	if (c == 'A')
		return true;
	else 
		if (c == '(')	{ 
		f >> c;
		if (Round (f, c)) 
			f >> c;
		else return false; 
		if (Square (f, c)) {
			f >> c;
			return (c == ')');
		}
		else return false;
	}
	else return false;
}

bool Square (ifstream &f, char c) 
{ 
	if (c == 'B') 
		return true;
	else 
		if (c == '[') { 
			f >> c;
		if (Square (f, c))
			f >> c;
		else return false; 
		if (Round (f, c)) { 
			f >> c;
			return (c == ']');
		}
		else return false;
	}
	else return false;
}

bool Brackets(ifstream &f)
{ 
	char c;
	bool a;
	a = false;
	if (f >> c) {
		if ((c == 'B') || (c == '[')) a = Square (f, c);
		else if ((c == 'A') || (c == '(')) a = Round (f, c);
		else Error(1); 
	}
	else Error (0); 
	return a;
}

void Error (short n)
{
	cout << "err ¹" << n << endl;
	switch (n) {
		case 0: cout << "Empty line" << endl; 
		break; 
		case 1: cout << "Invalid start character" << endl; 
		break; 
		default: 
		break; 
	};
}

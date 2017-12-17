#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include "stek_inter.h"
using namespace std;
using namespace st_modul;
string norm(const string str) {
	string str1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') str1 += '(';
		else if (str[i] == '>') str1 += ')';
		else if (str[i] == 'f') {
			str1 += '0';
			i += 4;
		}
		else if (str[i] == 't') {
			str1 += '1';
			i += 3;
		}
		else str1 += str[i];
	}
	return str1;
}
int oper(char a) {
	if (a == '(') return 0;
	if (a == '+') return 1;
	if (a == '*') return 2;
	if (a == '!') return 3;
	return 4;
}
string postfix(string &str) {
	Stack s;
	string str1;
	str = norm(str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0' || str[i] == '1') str1 += str[i];
		else if (str[i] == '(') 
			s.push(str[i]);
		else if (str[i] == ')') {
			while (s.top() != '(')
				str1 += s.pop2();
			s.pop();
		} 
		else {
			while ((oper(str[i]) <= oper(s.top())) && !s.isNull()) str1 += s.pop2();
			s.push(str[i]);
		}
	}
	while(!s.isNull()) { str1 += s.pop2(); };
	s.destroy();
	return str1;
}
bool solut(const string str) {
	Stack s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0' || str[i] == '1')
			s.push(str[i] - 48);
		if (str[i] == '!')
			s.push(!s.pop2());
		if (str[i] == '*')
			s.push(s.pop2() & s.pop2());
		if (str[i] == '+')
			s.push(s.pop2() | s.pop2());
	}
	if (s.pop2() == 0) {
		s.destroy();
		return false;
	}
	else {
		s.destroy();
		return true;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	ifstream fin("postfix.txt");
	if (!fin) { cout << "File not open for reading!\n"; return 1; }
	getline(fin, str, '\n');
	cout <<"Заданное выражение: "<< str<< endl;
	str = postfix(str);
	if (solut(str)) cout << "Ответ: true";
	else cout << "Ответ: false";
	system("pause > nul");
	return 0;
}
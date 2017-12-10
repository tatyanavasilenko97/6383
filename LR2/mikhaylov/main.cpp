#include <iostream>
#include <cstdlib>
#include "Extrar.h"
#include <windows.h>
#include <string>
using namespace std;
lisp concat(const lisp y, const lisp z);
void enter_lisp(const lisp x);
void enter_seq(const lisp x);
void res_lisp(const lisp x,string& dec);
void res_seq(const lisp x,string& dec);
lisp flatten(const lisp s);
void rezult(string& dec);
bool xnak = false;

void start_menu() {
	string dec;
	lisp s1;
	int c = 0;
	cout << boolalpha;
	cout << "������� ������:" << endl;
	read_lisp(s1);
	cout << "������ ������: ";
	write_lisp(s1);
	cout << endl;
	cout << "������� �������� ����������:" << endl;
	enter_lisp(s1);
	cout << "����������� ������: ";
	write_lisp(s1);
	res_lisp(s1, dec);
	cout << endl;
	cout << "�������� ���������: ";
	rezult(dec);
	cout << dec << endl;
	destroy(s1);
	cout << "��������� ���������!���������?[1-��/0-���]" << endl;	
}

int main()
{
	int c = 0;
	SetConsoleCP(1251);			
	SetConsoleOutputCP(1251);	
	cout << "����� ���������� � ���������!" << endl;
	cout << "� ������ ��������� ������������ ����������� �����(1,2,3...). ��� ��������� ������ ���������� ������ �����������, ����� ���� ���������� char." << endl;
	cout << "����� ��������� ����� �������� �����������" << endl;
	start_menu();
	cin >> c;
	while (c == 1) {
		system("cls");
		start_menu();
		cin >> c;
	}
	system("pause");
	return 0;
}
void rezult(string& dec) {//���������� ��������� � ���������� ����� ����������� �������
	for (int i = 0; i < dec.length() - 2; i++) {
		if (dec[i] == '+' || dec[i] == '*' || dec[i] == '-' || dec[i] == '/') {
			xnak = true;
			if (dec[i + 1] != '+' && dec[i+1] != '*' && dec[i+1] != '-' && dec[i+1] != '/') {
				char c = dec[i];
				dec[i] = dec[i + 1];
				dec[i + 1] = c;
				int a, b;
				a = dec[i] - '0';
				b = dec[i + 2] - '0';
				switch (dec[i + 1])
				{
				case '+':a = a + b;
					dec[i] = a + '0';									
					break;
				case '-':a = a - b;
					dec[i] = a + '0';									
					break;
				case '*':a = a * b;
					dec[i] = a + '0';									
					break;
				case '/':a = a / b;
					dec[i] = a + '0';										
					break;
				default:
					break;
				}
				dec[i + 1] = dec[i + 2];
				for (int j = i + 1; j < dec.length() - 1; j++) {
					dec[j] = dec[j + 1];
				}
				for (int j = i + 1; j < dec.length() - 1; j++) {
					dec[j] = dec[j + 1];
				}
				dec.resize(dec.length() - 2);
			}			
		}
		else break;
	}	
	if (!xnak) {
		cout << "������!����������� ������� ���������!��� ��������!(+ - * /)" << endl; system("pause");  exit(0);
	}
	if (dec.length() > 1) rezult(dec);	
}
lisp flatten(const lisp s)
{//������������ ������
	if (isNull(s)) return NULL;
	else if (isAtom(s)) return cons(make_atom(getAtom(s)), NULL);
	else //s  ? �������� ������ 
		if (isAtom(head(s))) return cons(make_atom(getAtom(head(s))), flatten(tail(s)));
		else //Not Atom(Head(s))
			return concat(flatten(head(s)), flatten(tail(s)));
} // end flat
void res_lisp(const lisp x, string& dec)
{//��� �������� ���������� ��������� � ���������� �����, ������� ��� � ���������� ���� string
	char a;
	if (isNull(x)) cout << " ()";
	else if (isAtom(x)) {
		dec = dec + x->node.atom;
	} 
	else { //�������� ������} 
		res_seq(x, dec);
	}
} // end write_lisp
void res_seq(const lisp x,string& dec)
{//
	if (!isNull(x)) {
		res_lisp(head(x),dec);
		res_seq(tail(x),dec);
	}
}
void enter_lisp(lisp x)
{//���������� ������ ������������ ����������
	int s;
	char y;
	if (isNull(x)) cout << "������ ������!";
	else if (isAtom(x)) {
		if (x->node.atom != '+' && x->node.atom != '-' && x->node.atom != '*' && x->node.atom != '/') {
			cout << x->node.atom << ":";
			cin >> y;
			x->node.atom = y;
		}
	}
	else {
		enter_seq(x);
	}
} // end write_lisp

void enter_seq(lisp x)
{//
	if (!isNull(x)) {
		enter_lisp(head(x));
		enter_seq(tail(x));
	}
}
lisp concat(const lisp y, const lisp z)
{
	if (isNull(y)) return copy_lisp(z);
	else return cons(copy_lisp(head(y)), concat(tail(y), z));
} // end concat  

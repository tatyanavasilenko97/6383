#include "head.h"
#include <iostream>
#include <fstream>

using namespace std;

void Error(int& w) {
	while ((cin.fail()) || ((w != 1) && (w != 2))) {
		cout << "Error. Enter another value.\n";
		cin.clear();
		cin.sync();
		cin >> w;
	}
}


void ErrorMessege() {
	cout << "Error! Uncorrect input. The programm will be interrupted.\n";
	system("pause");
	exit(1);
}

void read_form(Formula*& s, char& x) { // рекурсивная функция считывания формулы с клавиатуры
	cin.get(x);
	if ((x >= '0') && (x <= '9')) {
		s->tag = 1;
		s->form.term.num = int(x) - 48;
	}
	else {
		if ((x >= 'a') && (x <= 'z')) {
			s->tag = 2;
			s->form.term.let = x;
		}
		else {
			if (x != '(') ErrorMessege();
			else {
				s->tag = 0;
				s->form.form1.f1 = new Formula;
				read_form(s->form.form1.f1, x);
				cin.get(x);
				if ((x != '*') && (x != '+') && (x != '-')) ErrorMessege();
				else {
					s->form.form1.znak = x;
				}
				s->form.form1.f2 = new Formula;
				read_form(s->form.form1.f2, x);
				cin.get(x);
				if (x != ')') ErrorMessege();
			}
		}
	}
}

void read_three(Formula*& s, char& x) { // рекурсивная функция считывания дерева-формулы с клавиатуры
	cin.get(x);
	if (x != '(') ErrorMessege();
	else {
		cin.get(x);
		if ((x == '*') || (x == '+') || (x == '-')) {
			s->tag = 0;
			s->form.form1.znak = x;
			s->form.form1.f1 = new Formula;
			s->form.form1.f2 = new Formula;
			read_three(s->form.form1.f1, x);
			read_three(s->form.form1.f2, x);
		}
		else {
			if ((x >= '0') && (x <= '9')) {
				s->tag = 1;
				s->form.term.num = int(x) - 48;
			}
			else {
				if ((x >= 'a') && (x <= 'z')) {
					s->tag = 2;
					s->form.term.let = x;
				}
				else ErrorMessege();
			}
		}
		cin.get(x);
		if (x != ')') ErrorMessege();
	}
}

void print(Formula*& s) {
	if (s->tag == 1) {
		cout << s->form.term.num;
	}
	if (s->tag == 2) {
		cout << s->form.term.let;
	}
	if (!s->tag) {
		cout << "(";
		print(s->form.form1.f1);
		cout << s->form.form1.znak;
		print(s->form.form1.f2);
		cout << ")";
	}
}

void calculate(Formula*& s, int& res, bool& k) {
	if (k) {
		if (s->tag == 2) k = 0;
		else {
			if (s->tag == 1) {
				res = s->form.term.num;
			}
			else {
				int res1, res2;
				calculate(s->form.form1.f1, res1, k);
				calculate(s->form.form1.f2, res2, k);
				if (s->form.form1.znak == '+') res = res1 + res2;
				if (s->form.form1.znak == '-') res = res1 - res2;
				if (s->form.form1.znak == '*') res = res1 * res2;
				if (k) {
					cout << "The value of  ";
					print(s);
					cout << " is " << res << endl;
				}
			}
		}
	}
}

void build(Formula*& s, int& depth, bool close[]) {
	depth++;
	if (s->tag == 1) {
		cout << s->form.term.num << endl;
	}
	if (s->tag == 2) {
		cout << s->form.term.let << endl;
	}
	if (!s->tag) {
		cout << s->form.form1.znak << endl;
		for (int j = 1; j <= depth; j++) {
			if (!close[j]) {
				cout << "|  ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
		for (int j = 1; j <= depth - 1; j++) {
			if (!close[j]) {
				cout << "|  ";
			}
			else {
				cout << "   ";
			}
		}
		cout << "|--";
		build(s->form.form1.f1, depth, close);
		depth--;
		for (int j = 1; j <= depth; j++) {
			if (!close[j]) {
				cout << "|  ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
		for (int j = 1; j <= depth - 1; j++) {
			if (!close[j]) {
				cout << "|  ";
			}
			else {
				cout << "   ";
			}
		}
		cout << "|--";
		close[depth] = 1;
		build(s->form.form1.f2, depth, close);
		depth--;
		close[depth] = 0;
	}
}

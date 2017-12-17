
/* Lr3
-main.cpp
-Gomonova Anastasia, group 6383
-Var6в
-Проверить, является ли содержимое заданного текстового файла F правильной записью формулы следующего вида:
-< формула > ::= < терм > | < терм > + < формула > | < терм > - < формула >
-< терм > ::= < имя > | ( < формула > ) 
-< имя > ::= x | y | z
-Если не является, то указать место ошибочной позиции.
-*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include "Stack.h"
#include "Queue.h"
using namespace std;

void call_error(Queue & Q3, char symb, int numb) // ôóíêöèÿ ïîêàçûâàþùàÿ ìåñòî îøèáêè
{
	cout << ",êîòîðûé íå óäîâëåòâîðÿåò óñëîâèÿì ôîðìóëû." << endl;
	cout << "Ýòî íå ôîðìóëà!" << endl;
	switch (numb)
	{
	case 1:
	{
		cout << "Îæèäàëîñü èìÿ, òèïà [x],[y],[z], èëè îòêðûâàþùàÿ ñêîáêà - [(]." << endl;
		break;
	}
	case 2:
	{
		cout << "Îæèäàëñÿ çíàê, òèïà [+],[-], èëè çàêðûâàþùàÿ ñêîáêà - [)]." << endl;
		break;
	}
	default: break;
	}
	cout << "×àñòü ñòðîêè, êîòîðàÿ ÿâëÿåòñÿ ôîðìóëîé è ìîæåò áûòü çàâåðøåíà." << endl;
	while (Q3.can_pop())
		cout << Q3.pop() << " ";
	cout << "\nÏðîãðàììà áóäåò çàâåðøåíà." << endl;
	system("pause");
	exit(1);
}
bool bracket_c_f(char symb)  // ïðîâåðêà çàêðûâàþùåé ñêîáêè
{
	if (symb == ')')
		return true;
	else
		return false;
}
bool bracket_o_f(char symb) // ïðîâåðêà îòêðûâàþùåé ñêîáêè
{
	if (symb == '(')
		return true;
	else
		return false;
}
bool sign_f(char symb)    // ïðîåðêà ÿâëÿåòñÿ ýëëåìåíò çíàêîì
{
	if (symb == '+' || symb == '-')
		return true;
	else
		return false;
}
bool name_f(char symb)      // ïðîâåðêà ÿâëÿåòñÿ ëè ýëåììåíò èìåíåì
{
	if (symb == 'x' || symb == 'y' || symb == 'z')
		return true;
	else
		return false;
}
bool is_it_f(Stack Q1, Queue & Q3)   // ÿâëÿåòñÿ ëè ñòðîêà ôîðìóëîé
{
	char symb;
	bool name = true;
	bool sign = false;
	bool bracket_c = false;
	bool bracket_o = true;
	bool is_el = false;
	int open = 0;
	int close = 0;
	while (Q1.can_pop())
	{
		symb = Q1.pop();
		cout << "Èç ñòåêà èçâëå÷åí ýëåìåíò [" << symb << "] ";
		is_el = false;
		if (!is_el && name && name_f(symb))
		{
			cout << ",êîòîðûé ÿâëÿåòñÿ èìåíåì. " << endl;
			is_el = true;
			name = false;
			sign = true;
			bracket_c = true;
			bracket_o = false;
			Q3.push(symb);
		}
		if (!is_el && sign && sign_f(symb))
		{
			cout << ",êîòîðûé ÿâëÿåòñÿ çíàêîì." << endl;
			is_el = true;
			name = true;
			sign = false;
			bracket_c = false;
			bracket_o = true;
			Q3.push(symb);
		}
		if (!is_el && bracket_o && bracket_o_f(symb))
		{
			cout << ",êîòîðûé ÿâëÿåòñÿ îòêðûâàþùåé ñêîáêîé. " << endl;
			is_el = true;
			bracket_o = true;
			bracket_c = false;
			name = true;
			sign = false;
			open++;
			Q3.push(symb);
		}
		if (!is_el && bracket_c && bracket_c_f(symb))
		{
			close++;
			cout << ",êîòîðûé ÿâëÿåòñÿ çàêðûâàþùåé ñêîáêîé." << endl;
			if (close <= open)
			{
				close--;
				open--;
				is_el = true;
				bracket_o = false;
				bracket_c = true;
				name = false;
				sign = true;
				Q3.push(symb);
			}
			else
				call_error(Q3, symb, 2);
		}
		if (!is_el && (name && bracket_o))
			call_error(Q3, symb, 1);
		else
			if (!is_el && (sign && bracket_c))
				call_error(Q3, symb, 2);
	}
	if (open != close)
		call_error(Q3, symb, 2);
	return true;
}
void print_f(Queue & Q3)      // âûâåñòè ôîðìóëó
{
	while (Q3.can_pop())
	{
		cout << Q3.pop() << " ";
	}
}
void mainf(ifstream & fin, Stack & Q2)   // ôóíêöèÿ â êîòîðîé ïðîâåðÿòñÿ óñëîâèå ÿâëÿåòñÿ ëè ôîðìóëîé
{
	Queue Q3;
	int n = 1;
	char symb;
	fin >> symb;
	while (!(fin.eof()))
	{
		Q2.push(symb);
		Q3.push(symb);
		fin >> symb;
	}
	Stack Q1;
	cout << "Çàíîñèì ýëåìåíòû ñòðîêè â ñòåê:" << endl;
	while (Q2.can_pop())
	{
		char a = Q2.pop();
		cout << "Â ñòåê ïîìåùåí ýëåìåíò [" << a << "]." << endl;
		Q1.push(a);
	}
	cout << "Ñ÷èòàííàÿ èç ôàéëà ñòðîêà.";
	print_f(Q3);
	cout << endl;
	bool f = is_it_f(Q1, Q3);
	cout << "Ýòî ôîðìóëà." << endl;
	cout << "Åå âèä: " << endl;
	print_f(Q3);
}
int main()
{
	setlocale(LC_ALL, "rus");
	int answer;
	cout << "Âûáåðèòå íóæíîå äåéñòâèå." << endl;
	cout << "============================================" << endl;
	cout << "1.Ñ÷èòàòü ôîðìóëó èç ôàéëà." << endl;
	cout << "2.Çàâåðøèòü ïðîãðàììó." << endl;
	cout << "============================================" << endl;
	cout << "Âàø îòâåò: ";
	cin >> answer;
	cout << "============================================" << endl;
	while (answer != 1 && answer != 2 || cin.fail())
	{
		system("cls");
		cout << "Âû ââåëè íåâåðíîå çíà÷åíèå. Ïîïûòàéòåñü ñíîâà." << endl;
		cin.clear();
		cin.sync();
		cout << "============================================" << endl;
		cout << "1.Ñ÷èòàòü ôîðìóëó èç ôàéëà." << endl;
		cout << "2.Çàâåðøèòü ïðîãðàììó." << endl;
		cout << "============================================" << endl;
		cout << "Âàø îòâåò: ";
		cin >> answer;
		cout << "============================================" << endl;
	}
	if (answer == 1)
	{
		ifstream fin("queue.txt");
		Stack Q2;
		mainf(fin, Q2);
		fin.close();
	}
	else
		cout << "Ðàáîòà áóäåò çàâåðøåíà." << endl;
	cout << endl;
	system("pause");
}

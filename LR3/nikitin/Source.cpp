#include <cstdlib>
#include "Header.h"
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace vect;

Stack s;

int main()
{
	int w;
	setlocale(LC_ALL, "RUS");
	Node vector[MAX];
	ifstream f("input.txt");
	ofstream f1("output.txt");
	list l;
	l.head = 0;
	l.cur = 0;
	char x;
	bool g = false;
	for (int m = 0; m <= MAX; m++) vector[m].cl = 0;
	cout << "Choose input:\n1. from console\n2. from file\n";
	cin >> w;
	cout << endl;
	fail_menu(w);
	bool k = true;
	if (w == 1) cin >> x;
	if (w == 2)
	{
		f >> x;
		if (f.fail()) ErrorMessege();
	}
	int j = 0, i = 0;
	while (k)
	{
		j++;
		if ((x == ')') && (s.topOfStack == 0)) ErrorMessege();
		if (x == '(')
		{
			g = true;
			i++;
			s.push(i);
			vector[s.topOfStack].op = j;
		}
		if (x == ')')
		{
			if (!s.topOfStack) ErrorMessege();
			vector[s.topOfStack].cl = j;
			if (!l.head)
			{
				l.head = s.topOfStack;
				l.cur = l.head;
			}
			else
			{
				vector[l.cur].next = s.topOfStack;
				l.cur = s.topOfStack;
			}
			s.pop();
		}
		if (w == 1)
		{
			cin.get(x);
			if ((x == '\n') || (x == ' ')) k = false;
		}
		if (w == 2)
		{
			f >> x;
			if (f.fail()) k = false;
		}
	}
	vector[l.cur].next = 0;
	if (s.topOfStack) ErrorMessege();
	cout << "Choose task:\n1. a)\n2. á)\n";
	cin >> w;
	cout << endl;
	fail_menu(w);
	cout << endl;
	if (w == 1) j = l.head;
	if (w == 2) j = 1;
	while (vector[j].cl != 0)
	{
		cout << vector[j].op << " " << vector[j].cl << endl;
		f1 << vector[j].op << " " << vector[j].cl << "; ";
		if (w == 1) j = vector[j].next;
		if (w == 2) j++;
	}
	if (!g)
	{
		cout << "There is no brackets.\n";
		f1 << "There is no brackets.\n";
	}
	system("pause");
}

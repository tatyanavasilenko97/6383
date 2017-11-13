#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BTree.h"
#include <windows.h>
#include <conio.h>
#include <algorithm>

using namespace std;
using namespace binTree_modul;

typedef unsigned int unInt;

binTree enterBT();
void displayBT(binTree b, int n);
unInt NumOfLvl(binTree b, int a, int c = 1);
ifstream infile("KLP.txt");

int main()
{
	binTree b;
	SetConsoleCP(1251);			// ��� ������ ��������
	SetConsoleOutputCP(1251);	// ��� ������ ��������

	b = enterBT();
	if (isNull(b)) cout << "������ ��" << endl;
	else
	{
		cout << "�������� ������ (����������): " << endl;
		displayBT(b, 1);
		cout << "\n���������� ���������� ����� �� N-�� ������. ������� N:" << endl;
		int num;
		cin >> num;
		cout << "���������� ����� �� �������� ������ = " << NumOfLvl(b, num);

		destroy(b);

	}
	_getch();
}

binTree enterBT()
{
	char ch;
	binTree p, q;
	infile >> ch;//���������� �� �����
	while (ch == '(' || ch == ')') infile >> ch;//�������� �� ������
	if (ch == '/') { return NULL; }//�������� �� ������ �������
	else { //����� ����������� ������ ���������
		p = enterBT();
		q = enterBT();
		return ConsBT(ch, p, q);
	}
}

void displayBT(binTree b, int n)  //��� ������ ����������� ������
{ // n - ������� ����
	if (b != NULL)
	{
		cout << ' ' << RootBT(b); //�������� ��������
		if (!isNull(Right(b)))
			displayBT(Right(b), n + 1); //���� ������ ����� �� ������, �� �������� ��������
		else cout << endl; // ���������� ����
		if (!isNull(Left(b))) //���� ����� ����� �� ������, �� �������� ��������
		{
			for (int i = 1; i <= n; i++)
				cout << " "; // ������
			displayBT(Left(b), n + 1);
		}
	}
	else {};
}

unInt NumOfLvl(binTree b, int lvl, int lvl_now)
{
	if (b != NULL && lvl >= lvl_now) //���� ������� �� ����� ���� � ������� ������ ��������
		cout << lvl << " vs " << lvl_now << "; ���� -" << b->info << ";"; //�� ���� ������� - ����
	{
		if (lvl == lvl_now) cout << " ���� �� �������� ������ ����������!\n"; //��� ������� ����� �������� ������
		else cout <<" ���� �� �������� ������ ���!"<< endl;
	}
	if (lvl == lvl_now) return 1;
	else if (lvl >= lvl_now)
		return(((b->lt) ? NumOfLvl(b->lt, lvl, lvl_now + 1) : 0) + ((b->rt) ? NumOfLvl(b->rt, lvl, lvl_now + 1) : 0)); //������� ���-�� �����
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <Btree.h>
#include <Queue.h>
using namespace std;

void goriz(int index, binTree b, ofstream &);// �������� �������

int main() {
	setlocale(LC_ALL, "russian");
	binTree b;
	int input;
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	cout << "------------------------------\n";
	cout << "������� ������ \n";
	cout << "1: �� ����� \n2: � ���������� \n";
	cin >> input;
	switch (input)
	{
	case 1:
		enterBT(0, b, fin);
		goriz(0, b, fout);
		cout << endl << "����� ������ � �����";
		break;

	case 2:
		enterBT(0, b, cin);
		goriz(0, b, fout);
		cout << endl << "����� ������ � �����";
		break;

	default:
		cout << "Incorrect command ";
		break;
	}
	fin.close(); fout.close();
	cout << endl;
	system("pause > nul");
	return 0;

}


void goriz(int index, binTree b, ofstream &fout)
{
	Queue<int> q; // ������� ������� � ���������� ���� int
	q.Put(index);//������ � ������� ������ ��������� ��������  ������
	while (!q.Empty())// ���� ������� �� �����
	{
		index = q.Get();//�������� �� ������� ������ �������� ������
		fout << RootBT(index, b) << " ";
		if (!isNull(b, Left(index, b))) //���� ����� ���� ������� �� ������� ��� ������ � �������
		{
			q.Put(Left(index, b));
		}
		if (!isNull(b, Right(index, b)))//���� ������ ���� ������� �� ������� ��� ������ � �������
		{
			q.Put(Right(index, b));
		}
	}
}
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "lisp_list.h"

using namespace std;

int main() {
	SetConsoleCP(1251);			// ��� ������ ��������
	SetConsoleOutputCP(1251);	// ��� ������ ��������

	ifstream infile("input.txt");
	ofstream outfile("output.txt");

	lisp s;
	elem b;
	int n = 0;

	// ���������� �������������� ������ �� �����
	read_lisp(s, infile);
	cout << "������ ������������� ������: " << endl;
	// ����� ������ �� �����
	write_lisp(s);
	// ������ �������������� ������;
	// s - ������������� ������, b - �������� ������, n - ���������� ������
	analysis(s, b, n);
	cout << endl << "���������� �������: " << endl << "���������� ������ = " << n << endl << "�������� ������: " << endl;
	outfile << "���������� �������: " << endl << "���������� ������ = " << n << endl << "�������� ������: " << endl;
	// ����� ����������� �������;
	output(b, outfile);
	cout << endl;
	outfile << endl;
	cout << "������ ������� ��������..." << endl;
	destroy(s);
	destroy_lin(b);
	system("pause");
	return 0;
}
#include <iostream>
#include <fstream>

#include "interf.h"

using namespace std;
using namespace stack;

int main()
{
	setlocale(LC_ALL, "");
	if (!fout.is_open()) //�������� �� ������������ ��������
	{
		cout << "! - Error: file was not opened\n"; //������
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (!fin.is_open()) //�������� ������������ ��������
	{
		cout << "! - Error: file is not opened." << endl; //������
		system("pause");
		exit(EXIT_FAILURE);
	}
	int cmd;
	Stack operation; //���� ��� �������� M(max) ��� m(min) �� �������
	Stack digit; //���� ��� ���� �� �������
	bool tag;
	cout << "�������� ������ �� �����" << endl;
	tag = read_expr(fin, &operation, &digit); //�������� ���������� �� �����
		if (tag && !fout.eof())
		{//������� ���������
			cout << "\nformula is correct\n";
			fout << "\nformula is correct\n";
		}
		else
		{ //������: ������� ����� ��������
			cout << "\n! - Error: invalid expression- too much symbols!\n";
			fout << "\n! - Error: invalid expression- too much symbols!\n";
			exit(EXIT_FAILURE);
		}
	base result = digit.top(); // ��������� ���������� �� �����.
	cout << "Result of calculating: " << result << endl;
	fout << "Result of calculating: " << result << endl;
	cout << "End!\n";
	fout << "End!\n";
	system("pause");
	fin.close();
	fout.close();
	operation.destroy();
	digit.destroy();
	return 0;
}
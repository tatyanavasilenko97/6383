#include <iostream>
#include <fstream>

#include "interface.h"

using namespace std;
using namespace stack;

//���������� �������
bool read_expr(istream& input, Stack *op, Stack *dig);
//���������� �� �������
void calc(Stack* op, Stack* dig);


ifstream fin("input.txt", ios_base::in);
ofstream fout("output.txt", ios_base::out);




//������ ��������� � ����������
bool read_expr(istream& input, Stack *op, Stack *dig)
{
	bool flag = false;
	char ch;
	do input >> ch; while (ch == ' ');
	if ((ch >= '0') && (ch <= '9')) //�������� �� ������?
	{ //�������� ������
		dig->push(ch - '0'); //���������� � ���� digit
		flag = true;
	}
	else if ((ch == 'M') || (ch == 'm')) //�������� �� ������������ �������� min ��� Max?
	{ //�������� ������������ ��������
		if (ch == 'M') //�������� MAX
		{
			op->push(1); // 1 ������������ M, ���������� � ���� operation
		}
		else if (ch == 'm') //�������� min
		{
			op->push(2); //2 ������������ m, ���������� � ���� operation
		}
		do input >> ch; while (ch == ' ');
		if (ch == '(')
		{//��������� ������ - ���������� ������
			flag = read_expr(input, op, dig); //����������� �����
			if (flag)
			{//���������� ��������� - �������
				do input >> ch; while (ch == ' ');

				if (ch == ',')
				{//��������� ������ - �������
					flag = read_expr(input, op, dig);//����������� �����
					if (flag)
					{//���������� ��������� - �������
						do input >> ch; while (ch == ' ');

						if (ch == ')')
						{//��������� ������ - ����������� ������
							flag = true;
							calc(op, dig); //���������� �� ������� ��������� �������
						}
						else
						{
							cout << "! - Error\n";
							fout << "! - Error\n";
							exit(EXIT_FAILURE);
						}
					}
					else
					{
						cout << "\n! - Error\n";
						fout << "\n! - Error\n";
						system("pause");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					cout << "\n! - Error\n";
					fout << "\n! - Error\n";
					system("pause");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				cout << "\n! - Error\n";
				fout << "\n! - Error\n";
				system("pause");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			cout << "\n! - Error\n";
			fout << "\n! - Error\n";
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cout << "\n! - Error\n";
		fout << "\n! - Error\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	return flag; //��� �������������, �������� �� ����������� ��������� ��������
}

void calc(Stack* op, Stack* dig)
{//���������� ��������� ��������� �������
	int fun = op->pop2(); //����� �� ����� operation ��������� 
	base a = dig->pop2(); //����� �� ����� ������ � ������ ��������� �������� �����
	base b = dig->pop2();  //����� �� ����� ������ � ������ ��������� �������� �����
	base res;//��� �������� ���������� ����������
	if (a == b) //��������� �����
	{
		cout << "the arguments are equal\n";
		fout << "the arguments are equal\n";
		res = a; //��������� - ����� �� ����������
	}
	else
	{
		if (fun == 1)//���������� ��������
		{
			(a > b) ? res = a : res = b; //���� a>b, �� �������� - a, ����� - b
			cout << "M( " << a << " , " << b << " ) = " << res << endl;
			fout << "M( " << a << " , " << b << " ) = " << res << endl;
		}
		else if (fun == 2)//���������� �������
		{
			(a < b) ? res = a : res = b; //���� a<b, �� ��������� - a, ����� - b
			cout << "m( " << a << " , " << b << " ) = " << res << endl;
			fout << "m( " << a << " , " << b << " ) = " << res << endl;
		}
	}
	dig->push(res); //���������� � ���� ��������� ����������
	cout << "------------------------------------\n\n";
	fout << "------------------------------------\n\n";
}
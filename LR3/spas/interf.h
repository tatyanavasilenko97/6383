#include <iostream>
#include <fstream>

#include "interface.h"

using namespace std;
using namespace stack;

//считывание формулы
bool read_expr(istream& input, Stack *op, Stack *dig);
//вычисление по формуле
void calc(Stack* op, Stack* dig);


ifstream fin("input.txt", ios_base::in);
ofstream fout("output.txt", ios_base::out);




//чтение выражения с клавиатуры
bool read_expr(istream& input, Stack *op, Stack *dig)
{
	bool flag = false;
	char ch;
	do input >> ch; while (ch == ' ');
	if ((ch >= '0') && (ch <= '9')) //является ли цифрой?
	{ //является цифрой
		dig->push(ch - '0'); //записываем в стек digit
		flag = true;
	}
	else if ((ch == 'M') || (ch == 'm')) //является ли обозначением операции min или Max?
	{ //является обозначением операции
		if (ch == 'M') //является MAX
		{
			op->push(1); // 1 эквивалентно M, записываем в стек operation
		}
		else if (ch == 'm') //является min
		{
			op->push(2); //2 эквивалентно m, записываем в стек operation
		}
		do input >> ch; while (ch == ' ');
		if (ch == '(')
		{//очередной символ - окрывающая скобка
			flag = read_expr(input, op, dig); //рекурсивный вызов
			if (flag)
			{//предыдущее выражение - формула
				do input >> ch; while (ch == ' ');

				if (ch == ',')
				{//очередной символ - запятая
					flag = read_expr(input, op, dig);//рекурсивный вызов
					if (flag)
					{//предыдущее выражение - формула
						do input >> ch; while (ch == ' ');

						if (ch == ')')
						{//очередной символ - закрывающая скобка
							flag = true;
							calc(op, dig); //вычисление по крайней считанной формуле
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
	return flag; //для идентификации, является ли считываемое выражение формулой
}

void calc(Stack* op, Stack* dig)
{//вычисление последней считанной формулы
	int fun = op->pop2(); //берем из стека operation последнюю 
	base a = dig->pop2(); //берем из стека символ и меняем указатель верхушки стека
	base b = dig->pop2();  //берем из стека символ и меняем указатель верхушки стека
	base res;//для хранения результата вычисления
	if (a == b) //аргументы равны
	{
		cout << "the arguments are equal\n";
		fout << "the arguments are equal\n";
		res = a; //результат - любой из аргументов
	}
	else
	{
		if (fun == 1)//определяем максимум
		{
			(a > b) ? res = a : res = b; //если a>b, то резуьтат - a, иначе - b
			cout << "M( " << a << " , " << b << " ) = " << res << endl;
			fout << "M( " << a << " , " << b << " ) = " << res << endl;
		}
		else if (fun == 2)//определяем минимум
		{
			(a < b) ? res = a : res = b; //если a<b, то результат - a, иначе - b
			cout << "m( " << a << " , " << b << " ) = " << res << endl;
			fout << "m( " << a << " , " << b << " ) = " << res << endl;
		}
	}
	dig->push(res); //записываем в стек результат вычисления
	cout << "------------------------------------\n\n";
	fout << "------------------------------------\n\n";
}
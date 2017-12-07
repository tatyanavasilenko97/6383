#include "methods.h"
#include <iostream>
#include <fstream>
#include "stack.h"
#include "queue.h"
using namespace std;

//����� ������
void place_of_error(Queue &Q3, char symb, int b)
{
	cout << "- �� ������������� �������� �������\n";
	cout << "\n������ �� �������� �������� - ";
	switch (b)
	{
	case 1:
	{
		cout << "����� �������� ������� ���� [x],[y],[z]\n��� �������� � ������\n\n";
		break;
	}
	case 2:
	{
		cout << "����� �������� ������� ���� [+],[-]\n��� �������� � ������\n\n";
		break;
	}
	default:
		break;
	}
	system("pause");
	exit(1);
}

 //�������� �� ����������� ������� ������
bool bracket_open_circle_formula(char symb)
{
	if (symb == '(')
		return true;
	else return false;
}

 //�������� �� ����������� ���������� ������
bool bracket_open_square_formula(char symb)
{
	if (symb == '[')
		return true;
	else return false;
}

 //�������� �� ����������� �������� ������
bool bracket_open_figure_formula(char symb)
{
	if (symb == '{')
		return true;
	else return false;
}

 //�������� �� ����������� ������� ������
bool bracket_close_circle_formula(char symb)
{
	if (symb == ')') return true;
	else return false;
}

 //�������� �� ����������� ���������� ������
bool bracket_close_square_formula(char symb)
{
	if (symb == ']') return true;
	else return false;
}

 //�������� �� ����������� �������� ������
bool bracket_close_figure_formula(char symb)
{
	if (symb == '}') return true;
	else return false;
}

 //�������, �������� �� ������� ������
bool sign_formula(char symb)
{
	if (symb == '+' || symb == '-') return true;
	else return false;
}

 //��������, �������� �� ������� ������ 
bool name_formula(char symb)
{
	if (symb == 'x' || symb == 'y' || symb == 'z') return true;
	else return false;
}

 //��������, �������� �� ������ �������� 
bool is_it_formula(Stack Q1, Queue &Q3)
{
	char symb;
	bool name = true;
	bool sign = false;
	bool bracket_circle_close = false;
	bool bracket_square_close = false;
	bool bracket_figure_close = false;
	bool bracket_circle_open = true;
	bool bracket_square_open = true;
	bool bracket_figure_open = true;
	bool is_elem = false;
	int open_cir = 0, open_squ = 0, open_fig = 0;
	int close_cir = 0, close_squ = 0, close_fig = 0;
	while (Q1.can_pop())
	{
		symb = Q1.pop();
		cout << "����������� ������� [" << symb << "] ";
		is_elem = false;
		if (!is_elem && name && name_formula(symb))
		{
			cout << "- ���\n";
			is_elem = true;
			name = false;
			sign = true;
			bracket_circle_close = true;
			bracket_square_close = true;
			bracket_figure_close = true;
			bracket_circle_open = false;
			bracket_square_open = false;
			bracket_figure_open = false;
			Q3.push(symb);
		}
		if (!is_elem && sign && sign_formula(symb))
		{ 
			cout << "- ����\n";
			is_elem = true;
			name = true;
			sign = false;
			bracket_circle_close = false;
			bracket_square_close = false;
			bracket_figure_close = false;
			bracket_circle_open = true;
			bracket_square_open = true;
			bracket_figure_open = true;
			Q3.push(symb);
		}
		if(!is_elem && bracket_circle_open && bracket_open_circle_formula(symb))
		{	
			cout << "- ����������� ������� ������\n";
			is_elem = true;
			bracket_circle_open = true;
			bracket_circle_close = false;
			name = true;
			sign = false;
			open_cir++;
			Q3.push(symb);
		}
		if (!is_elem && bracket_square_open && bracket_open_square_formula(symb))
		{
			cout << "- ����������� ���������� ������\n";
			is_elem = true;
			bracket_square_open = true;
			bracket_square_close = false;
			name = true;
			sign = false;
			open_squ++;
			Q3.push(symb);
		}
		if (!is_elem && bracket_figure_open && bracket_open_figure_formula(symb))
		{
			cout << "- ����������� �������� ������\n";
			is_elem = true;
			bracket_figure_open = true;
			bracket_figure_close = false;
			name = true;
			sign = false;
			open_fig++;
			Q3.push(symb);
		}
		if (!is_elem && bracket_circle_close && bracket_close_circle_formula(symb))
		{
			close_cir++;
			cout << "- ����������� ������� ������\n";
			if (close_cir <= open_cir)
			{
				close_cir--;
				open_cir--;
				is_elem = true;
				bracket_circle_open = false;
				bracket_circle_close = true;
				name = false;
				sign = true;
				Q3.push(symb);
			}
			else place_of_error(Q3, symb, 2);
		}
		if (!is_elem && bracket_square_close && bracket_close_square_formula(symb))
		{
			close_squ++;
			cout << "- ����������� ���������� ������\n";
			if (close_squ <= open_squ)
			{
				close_squ--;
				open_squ--;
				is_elem = true;
				bracket_square_open = false;
				bracket_square_close = true;
				name = false;
				sign = true;
				Q3.push(symb);
			}
			else place_of_error(Q3, symb, 2);
		}
		if (!is_elem && bracket_figure_close && bracket_close_figure_formula(symb))
		{
			close_fig++;
			cout << "- ����������� �������� ������\n";
			if (close_fig <= open_fig)
			{
				close_fig--;
				open_fig--;
				is_elem = true;
				bracket_figure_open = false;
				bracket_figure_close = true;
				name = false;
				sign = true;
				Q3.push(symb);
			}
			else place_of_error(Q3, symb, 2);
		}
		if (!is_elem && (name && (bracket_circle_open || bracket_square_open || bracket_figure_open)))
			place_of_error(Q3, symb, 1);
		else
			if (!is_elem && (sign && (bracket_circle_close || bracket_square_close || bracket_figure_close)))
				place_of_error(Q3, symb, 2);
	}
	if ((open_cir != close_cir) || (open_squ != close_squ) || (open_fig != close_fig))
		place_of_error(Q3, symb, 2);
	return true;
}
#include "queue.h"
#include "stack.h"

void place_of_error(Queue &Q3, char symb, int b); //����� ������
bool bracket_close_circle_formula(char symb); //�������� �� ����������� ������� ������
bool bracket_close_square_formula(char symb); //�������� �� ����������� ���������� ������
bool bracket_close_figure_formula(char symb); //�������� �� ����������� �������� ������
bool bracket_open_circle_formula(char symb); //�������� �� ����������� ������� ������
bool bracket_open_square_formula(char symb); //�������� �� ����������� ���������� ������
bool bracket_open_figure_formula(char symb); //�������� �� ����������� �������� ������
bool sign_formula(char symb); //��������, �������� �� ������� ������
bool name_formula(char symb); //��������, �������� �� ������� ������ 
bool is_it_formula(Stack Q1, Queue &Q3); //��������, �������� �� ������ �������� 
void print_formula(Queue &Q3); //����� �������
void mainformula(ifstream &fin, Stack &Q2); //��������, �������� �� �������� 
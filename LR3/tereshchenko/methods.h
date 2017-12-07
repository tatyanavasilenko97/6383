#include "queue.h"
#include "stack.h"

void place_of_error(Queue &Q3, char symb, int b); //место ошибки
bool bracket_close_circle_formula(char symb); //проверка на закрывающую круглую скобку
bool bracket_close_square_formula(char symb); //проверка на закрывающую квадратную скобку
bool bracket_close_figure_formula(char symb); //проверка на закрывающую фигурную скобку
bool bracket_open_circle_formula(char symb); //проверка на открывающую круглую скобку
bool bracket_open_square_formula(char symb); //проверка на открывающую квадратную скобку
bool bracket_open_figure_formula(char symb); //проверка на открывающую фигурную скобку
bool sign_formula(char symb); //проверка, является ли элемент знаком
bool name_formula(char symb); //проверка, является ли элемент именем 
bool is_it_formula(Stack Q1, Queue &Q3); //проверка, является ли строка формулой 
void print_formula(Queue &Q3); //вывод формулы
void mainformula(ifstream &fin, Stack &Q2); //проверка, является ли формулой 
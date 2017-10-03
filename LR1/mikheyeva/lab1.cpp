//
// Лабораторная работа №1
// lab1.cpp
// Михеева Екатерина, группа 6383
// 16.09.17
// Программа для определения, является ли введенная строка вещественным //числом



// вещественное_число::=	целое_число . целое_без_знака |
//целое_число . целое_без_знакаЕцелое число |
//целое_числоЕцелое_число
//целое_без_знака::=цифра | цифра  целое_без_знака
//целое_число::=целое_без_знака | + целое_без_знака | целое_без_знака



//#include "stdafx.h"
#include "iostream"
using namespace std;


enum returns
{
    fig,
    end_of_line,
    Exp,
    point,
    fail

};


bool sign(char c)
{
    if (c == '-' || c == '+') return true;
    return false;

}

void what_fail(int points, int expon, bool INCORRECT_SYMBOL)
{
    if (points == 0 && expon == 1)
    {
        cout << "Число иррациональное" << endl;
        return;
    }
    if (points == 0 && expon == 0 && INCORRECT_SYMBOL == 0) {
        cout << "Число целое" << endl;
        return;
    }
    cout << "Некорректный символ" << endl;
    return;
}

bool real(std::istream &in, int &points, int &expon, bool &INCORRECT_SYMBOL);
int figure(char c)

{
    if (c <= '9' && c >= '0')
        return fig;
    if (c == '\n')
        return end_of_line;

    if (c == 'e')
        return Exp;
    if (c == '.')

        return point;
    return fail;
}

bool u_integer(std::istream &in, int &points, int &expon, bool &INCORRECT_SYMBOL);

bool integer(std::istream &in, int &points, int &expon, bool &INCORRECT_SYMBOL)
{

    switch (in.peek())
    {
    case '+':
        in.get();

        if (u_integer(in, points, expon, INCORRECT_SYMBOL) == false) return false; return true;
        break;

    case '-':

        in.get();

        if (u_integer(in, points, expon, INCORRECT_SYMBOL) == false) return false; return true;
        break;

    case '\n': {
        if (points == 1 || expon == 1)return true;
        return false;
    }
    default:
        if (u_integer(in, points, expon, INCORRECT_SYMBOL) == false) return false; else return true;
    }
}
bool u_integer(std::istream &in, int &points, int &expon, bool &INCORRECT_SYMBOL)
{
    char c = cin.peek();
    switch (figure(c))
    {
        //цифра
    case fig:
        in.get();

        u_integer(in, points, expon, INCORRECT_SYMBOL);
        break;

        //точка
    case point:
        if (expon == 1 || points == 1) return false;
        points++;
        in.get();
        if (figure(in.peek()) != fig)
        {
            INCORRECT_SYMBOL = 1;
            return false;
        }
        u_integer(in, points, expon, INCORRECT_SYMBOL);
        break;

        //конец строки
    case end_of_line:
        if (points == 1 || expon == 1)
            return true;
        else
            return false;

        //экспонента
    case Exp:
        if (expon == 1)
        {
            expon++;
            return false;
        }
        expon++;
        in.get();
        if (figure(in.peek()) != fig && sign(in.peek() == false))
        {
            INCORRECT_SYMBOL = 1;
            return false;
        }
        integer(in, points, expon, INCORRECT_SYMBOL);
        break;

    case fail:
        INCORRECT_SYMBOL = 1;
        return false;
    }
}
bool real(std::istream &in, int &points, int &expon, bool &INCORRECT_SYMBOL)
{
    char c = in.peek();
    if (c == '.' || c == 'e') {
        INCORRECT_SYMBOL = 1;
        return false;
    }
    if (integer(in, points, expon, INCORRECT_SYMBOL) == false) return false;
    return true;
}
int main()
{
    bool INCORRECT_SYMBOL = 0;
    int points = 0, expon = 0;
    setlocale(0, "rus");
    cout << "Введите строку" << endl;
    cin;
    if (cin.peek() == '\n') {
        cout << "Пустая строка" << endl;
        return 0;
    }

    if (real(cin, points, expon, INCORRECT_SYMBOL) == true)
        cout << "Число вещественное\n";
    else what_fail(points, expon, INCORRECT_SYMBOL);
    //system("pause");
    return 0;
}


/*Быков И. В. 6383 лабораторная работа #2. вариант 3.

Заменить в иерархическом списке все вхождения заданного элемента (атома) x на заданный элемент (атом) y;

использование модуля с АТД "Иерархический Список" .
Интерфейс модуля в заголовочном файле "list.h"
и его реализация (в отдельном файле list.cpp) образуют
пространство имен namespace h_list
*/

#include <iostream>
#include <cstdlib>
#include "list.h"
#include <clocale>

using namespace std;
using namespace h_list;

/*
Рекурсивная функция замены всех вхождений заданного атома на заданный
предусловие: список, элемент, который меняем, элемент на который меняем
*/
void myReplace(lisp list, const base &a, const base &b);
int readAction();

int main ( )
{
    //setlocale(LC_ALL, "Russian");
	ifstream in( "input.txt");
    ofstream out("output.txt");
    char a, b; // a - что меняем, b - на что меняем
	lisp s;
	int flag, format;
	cout << "Выберите формат работы:\n1 - чтение из файла.\n2 - работа в консоли\nother - выход.\n" << endl;
	cin >> format;
	switch (format)
	{
    case 1:
        if (!in) cerr << "Не найден файл input.txt\n";
        cout << "Чтение из input.txt..." << endl;
        in >> a;
        in >> b;
        cout << "Замена " << a << " на " << b <<".Результат: " << endl;
        while (!in.eof())//(in.get() != EOF)
        {
            read_lisp (s, in);
			write_lisp(s, cout);
			cout << "   ";
            myReplace(s, a, b);
            write_lisp (s, out);
            write_lisp (s, cout);
            out << endl;
            cout << endl;
            //cout << "destroy list: " << endl;
            destroy (s);
            //cout << "end! " << endl;
        }
        break;
    case 2:
        while (true)
        {
		switch (readAction())
		{
            case 1:
                cout << "Введите список: ";
                read_lisp (s, cin);
                break;
            case 2:
                destroy(s);
				s = NULL;
                cout << "Cписок удален!" << endl;
                break;
            case 3:
                cout << "Введите элемент, который требуется заменить: ";
                cin >> a;
                cout << "Введите элемент, накоторый будем менять: ";
                cin >> b;
                myReplace(s, a, b);
                break;
            case 4:
				if (isNull(s))
						cout << "Список пуст." << endl;
				else
                {
						cout << "Cписок: ";
                		write_lisp (s, cout);
            			cout << endl;
				}
				break;
            case 5:
                return 0;
            }
            cout << "Продолжить? 1 - да; 0 - нет. ";
            cin >> flag;
            cout << endl;
            if (flag == 0)
                return 0;
        }
        break;
	}

}

void myReplace(lisp list, const base &a, const base &b)
{
    if (isNull(list))
        return;
    else if (isAtom(list))
    {
        if (list->node.atom == a)
            list->node.atom = b;
    }
    else
    {
        myReplace(head(list), a, b);
        myReplace(tail(list), a, b);
    }
    return;
}

int readAction()
{
	while (true)
	{
		cout <<"Выберите действие:\n1 - ввод списка;\n2 - удаление списка;\n3 - замена элемента;\n4 - вывод списка на экран\n5 -выход.\n";
		int action;
		cin >> action;
		if (action > 5 || action < 1)
		{
			printf("Ошибка!\n");
			continue;
		}
		return action;
	}
}


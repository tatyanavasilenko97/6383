#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <Btree.h>
#include <Queue.h>
using namespace std;

void goriz(int index, binTree b, ofstream &);// основная функция

int main() {
	setlocale(LC_ALL, "russian");
	binTree b;
	int input;
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	cout << "------------------------------\n";
	cout << "Входные данные \n";
	cout << "1: из файла \n2: с клавиатуры \n";
	cin >> input;
	switch (input)
	{
	case 1:
		enterBT(0, b, fin);
		goriz(0, b, fout);
		cout << endl << "вывод ответа в файле";
		break;

	case 2:
		enterBT(0, b, cin);
		goriz(0, b, fout);
		cout << endl << "вывод ответа в файле";
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
	Queue<int> q; // Создаем очередь с элементами типа int
	q.Put(index);//заношу в очередь индекс корневого элемента  дерева
	while (!q.Empty())// пока очередь не пуста
	{
		index = q.Get();//Выдераем из очереди индекс элемента дерева
		fout << RootBT(index, b) << " ";
		if (!isNull(b, Left(index, b))) //если слева есть элемент то заносим его индекс в очередь
		{
			q.Put(Left(index, b));
		}
		if (!isNull(b, Right(index, b)))//если справа есть элемент то заносим его индекс в очередь
		{
			q.Put(Right(index, b));
		}
	}
}
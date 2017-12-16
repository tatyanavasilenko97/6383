#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
struct Nod 		//—труктура дл€ очереди
{
	T znach;
	Nod *Next;
};

template <typename T>
class Queue		//ќчередь
{
	Nod<T> *First, *Last;
	int kol;
public:
	Queue() :First(NULL), Last(NULL) { kol = 0; }; //конструкор
	~Queue(); //деструктор
	void Put(T x);//добавление нового элемента в конец очереди	
	T Get();//возвращение значени€ первого элемента и его удаление
	int Kol();//возвращает количество элементов в очереди 
	bool Empty();//возвращает True если очередь пуста
};
template <typename T>
void Queue<T>::Put(T x) //добавление нового элемента в конец очереди	
{
	Nod<T> *temp = new Nod<T>;//создание указател€ на структуру Nod и выделение под него пам€ти
	temp->znach = x;
	temp->Next = NULL;
	if (First == NULL)
	{
		First = temp;
		Last = temp;
		kol++;
	}
	else
	{
		Last->Next = temp;
		Last = temp;
		kol++;
	}
};

template <typename T>
Queue<T>::~Queue() //удаление всех эелементов
{
	Nod<T> *temp;
	kol = 0;
	while (First != NULL)
	{
		Nod<T> *temp;
		temp = First;
		First = First->Next; //переходим на следующий элемент
		delete temp;
	}
};

template <typename T>
T Queue<T>::Get() //возвращение значени€ первого элемента и его удаление
{
	if (First == NULL) { printf("ќчередь пуста \n"); exit(1); }
	Nod<T> *temp;
	T x;
	x = First->znach;
	temp = First;
	First = First->Next;
	delete temp;
	kol--;
	return x;
};

template <typename T>
int Queue<T>::Kol() //возвращает количество элементов в очереди  
{
	return kol;
};

template <typename T>
bool Queue<T>::Empty() //возвращает True если очередь пуста
{
	return First == NULL;
};
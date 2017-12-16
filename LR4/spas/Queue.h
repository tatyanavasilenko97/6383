#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
struct Nod 		//��������� ��� �������
{
	T znach;
	Nod *Next;
};

template <typename T>
class Queue		//�������
{
	Nod<T> *First, *Last;
	int kol;
public:
	Queue() :First(NULL), Last(NULL) { kol = 0; }; //����������
	~Queue(); //����������
	void Put(T x);//���������� ������ �������� � ����� �������	
	T Get();//����������� �������� ������� �������� � ��� ��������
	int Kol();//���������� ���������� ��������� � ������� 
	bool Empty();//���������� True ���� ������� �����
};
template <typename T>
void Queue<T>::Put(T x) //���������� ������ �������� � ����� �������	
{
	Nod<T> *temp = new Nod<T>;//�������� ��������� �� ��������� Nod � ��������� ��� ���� ������
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
Queue<T>::~Queue() //�������� ���� ����������
{
	Nod<T> *temp;
	kol = 0;
	while (First != NULL)
	{
		Nod<T> *temp;
		temp = First;
		First = First->Next; //��������� �� ��������� �������
		delete temp;
	}
};

template <typename T>
T Queue<T>::Get() //����������� �������� ������� �������� � ��� ��������
{
	if (First == NULL) { printf("������� ����� \n"); exit(1); }
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
int Queue<T>::Kol() //���������� ���������� ��������� � �������  
{
	return kol;
};

template <typename T>
bool Queue<T>::Empty() //���������� True ���� ������� �����
{
	return First == NULL;
};
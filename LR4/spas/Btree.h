#include <iostream>
#include <fstream>
using namespace std;


template <typename T>
struct Node 	//��������� ������
{
	T info = NULL;
	int lt; //������ ������ ����
	int rt; //������ ������� ����
};
typedef Node<char> binTree[100];


bool isNull(binTree, int); //�������� �� ������� ����
char RootBT(int, binTree); //������ ����� ���������
int Left(int, binTree); //������ ������� ������ ����
int Right(int, binTree); //������ ������� ������� ����
int ConsBT(char x, int lst, int rst, binTree, int); //���������� ���� � ������ �� ���� �������
void destroy(int, binTree); // �������� ������
int enterBT(int, binTree, istream &input); // ���������� ������ �� �����
int lastIndex = 0; //��������� ������ �������
bool isNull(binTree b, int index) //�������� �� ������� ����
{
	return b[index].info == NULL;
}

char RootBT(int index, binTree b) //������ ����� ���������
{
	if (b == NULL)
	{
		cerr << "Error: RootBT(null) \n";
		exit(1);
	}
	else
		return b[index].info;
}

int Left(int index, binTree b) //������ ������� ������ ����
{
	if (b == NULL)
	{
		cerr << "Error: Left(null) \n";
		exit(1);
	}
	else
		return b[index].lt;
}

int Right(int index, binTree b) //������ ������� ������� ����
{
	if (b == NULL)
	{
		cerr << "Error: Right(null) \n";
		exit(1);
	}
	else
		return b[index].rt;
}
int ConsBT(char x, int lst, int rst, binTree b, int index) //���������� ���� � ������ �� ���� �������
{
	if (b != NULL)
	{
		b[index].info = x;
		b[index].lt = lst;
		b[index].rt = rst;
		if (lastIndex < rst)
			lastIndex = rst;
		return index;
	}
	else
	{
		cerr << "Memory not enough\n";
		exit(1);
	}
}

void destroy(int index, binTree b) // �������� ������
{
	if (b != NULL)
	{
		destroy(b[index].lt, b);
		destroy(b[index].rt, b);
		delete b;
		b = NULL;
	}
}


int enterBT(int index, binTree b, istream &input) // ���������� ������ �� �����
{
	char ch;
	int p, q;
	input >> ch;
	lastIndex = index;
	if (ch == '/')
	{
		b[index].info = NULL;
		return index;
	}
	else
	{
		p = enterBT(++index, b, input);
		index = lastIndex;
		q = enterBT(++index, b, input);
		index = q;
		return ConsBT(ch, p, q, b, index - (q - p + 1));
	}
}
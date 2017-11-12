#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <locale.h>

using namespace std;
typedef unsigned int unInt;

typedef char base;
struct node {
	base info;
	node *lt;
	node *rt;
	// constructor
	node() { lt = NULL; rt = NULL; }
};
typedef node *binTree; // "представитель" бинарного дерева
binTree enterBT();
void displayBT(binTree b, int n);
unInt NumOfLvl(binTree b, int a, int c = 1);
int getMaxDepth(binTree b, int depth = 1);
void levelBT(binTree b);
typedef node *binTree; // "представитель" бинарного дерева
binTree Create(void);
bool isNull(binTree), RooBT(binTree);
base RootBT(binTree); // для непустого бин.дерева
binTree Left(binTree), Right(binTree);// для непустого бин.дерева
binTree ConsBT(const base &x, binTree &lst, binTree &rst);
void destroy(binTree&);
ifstream infile("input.txt");

int main()
{
	binTree b;
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	b = enterBT();
	int depth = 1;
	if (isNull(b)) cout << "Пустое БД" << endl;
	else
	{
		cout << "Бинарное дерево (повернутое): " << endl;
		displayBT(b, 1);
		int a = getMaxDepth(b) - 1; // высота дерева 
		cout << "\nПоиск листьев дерева:" << endl; levelBT(b);
		cout << "\nНахождение количества узлов на N-ом уровне. Введите N:" << endl;
		int num;
		cin >> num;
	while ((num < 1) || (num > a))
		{
			cout << "Такого уровня не существует\n";
			cout << "Введите N: \n";
			cin >> num;
		}
		cout << "Количество узлов на заданном уровне = " << NumOfLvl(b, num);
		destroy(b);

	}
	_getch();
}
binTree enterBT() //функция ввода бинарного дерева
{
	char ch;
	binTree p, q;
	infile >> ch;
	while (ch == '(' || ch == ')') infile >> ch;
	if (ch == '/') { return NULL; }
	else {
		p = enterBT(); q = enterBT();
		return ConsBT(ch, p, q);
	}
}

int getMaxDepth(binTree q, int depth) //висчитываем глубину дерева
{
	if (q == NULL) { return depth; }
	else return max(getMaxDepth(q->rt, depth + 1), getMaxDepth(q->lt, depth + 1));
}
void displayBT(binTree b, int n) // функция для вывода бд на консоль
{
	if (b != NULL) {
		displayBT(Right(b), n + 1);//Прохождение по правым
		for (int i = n + 1; i > 0; i--)
			cout << "   ";
		cout << b->info << endl;//Вывод текущего
		displayBT(Left(b), n + 1);//Прохождение по левым
	}
}

void levelBT(binTree b) // определение является ли листом
{
	if (!isNull(b))
	{
		if (!(isNull(b->lt) && isNull(b->rt)))
			cout << "Узел:" << b->info << endl;
			levelBT(b->lt);
		if (isNull(b->lt) && isNull(b->rt))
			cout << "Лист:" << b->info << endl;
		levelBT(b->rt);
	}
}

unInt NumOfLvl(binTree b, int lvl, int lvl_now) //функция, определяющая наличие узлов на заданном уровне
{
	if (b != NULL&&lvl >= lvl_now)cout << lvl << " vs " << lvl_now << "  Узел - " << b->info << "\n";
	{
		if (lvl == lvl_now)
		{
			cout << " Узел на заданном уровне существует!\n";
		}
		else cout << " Это узел не того уровня\n";
	}
	if (lvl == lvl_now) return 1;
	else if (lvl >= lvl_now)return(((b->lt) ? NumOfLvl(b->lt, lvl, lvl_now + 1) : 0) + ((b->rt) ? NumOfLvl(b->rt, lvl, lvl_now + 1) : 0));

}

int len = 0;

binTree Create()
{
	return NULL;
}

bool isNull(binTree b)
{
	return (b == NULL);
}

base RootBT(binTree b)			// для непустого бин.дерева
{
	if (b == NULL) { cerr << "Error: RootBT(null) \n"; exit(1); }
	else return b->info;
}

bool RooBT(binTree b)
{
	if (b == NULL) return false;
	else return true;
}

binTree Left(binTree b)		// для непустого бин.дерева
{
	if (b == NULL) { cerr << "Error: Left(null) \n"; exit(1); }
	else return b->lt;
}

binTree Right(binTree b)		// для непустого бин.дерева
{
	if (b == NULL) { cerr << "Error: Right(null) \n"; exit(1); }
	else return b->rt;
}

binTree ConsBT(const base &x, binTree &lst, binTree &rst)
{
	binTree p;
	p = new node;
	if (p != NULL) {
		p->info = x;
		p->lt = lst;
		p->rt = rst;
		return p;
	}
	else { cerr << "Memory not enough\n"; exit(1); }
}
void destroy(binTree &b)
{
	if (b != NULL) {
		destroy(b->lt);
		destroy(b->rt);
		delete b;
		b = NULL;
	}
}

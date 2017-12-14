#include "methods.h"
#include <iostream>
using namespace std;

//получаем указатель на голову
Unit* getHead(Unit* list) 
{
	if (isEmpty(list) || list->type == Atomic) return nullptr; 
	return list->val.pair.head;
}

//получаем указатель на хвост
Unit* getTail(Unit* list) 
{
	if (isEmpty(list) || list->type == Atomic) return nullptr; 
	return list->val.pair.tail;
}

//создаем новый элемент
Unit* create(Unit* head, Unit* tail)  
{
	if (isAtom(tail)) return nullptr; 
	Unit* unit = new Unit;
	unit->type = Pair;
	unit->val.pair.head = head; //head - первый список
	unit->val.pair.tail = tail; //tail - второй список
	return unit;
}

//получаем значения атома
base getAtom(Unit* list) 
{
	if (!isAtom(list)) return 0; 
	return list->val.element;
}

//создаем новый список
Unit* makeAtom(base elem) 
{
	Unit* element = new Unit;
	element->type = Atomic;
	element->val.element = elem;
	return element;
}

//выводим список на экран
void write(Unit* list) 
{
	if (!list) write_deep(list);
	else
	{
		cout << "(";
		write_deep(list);
		cout << ")";
	}
	cout << endl;
}

void write_deep(Unit* list) 
{
	if (isEmpty(list))
	{
		cout << "() ";
		return;
	}
	if (isAtom(list))
	{
		cout << list->val.element;
		return;
	}
	if (!isAtom(list->val.pair.head))
	{
		cout << "(";
		write_deep(list->val.pair.head);
		cout << ")";
	}
	else write_deep(list->val.pair.head);
	if (list->val.pair.tail) write_deep(list->val.pair.tail);
}

//проверяем, не пустой ли список
bool isEmpty(Unit* list)  
{
	return list == nullptr;
}

//копируем список
Unit* copy(Unit* list) 
{
	if (isEmpty(list)) return nullptr;
	else if (isAtom(list)) return makeAtom(list->val.element);
	else return create(copy(getHead(list)), copy(getTail(list)));
}

//вводим список с консоли
Unit* readUnit(Unit* list) 
{
	base x;
	do cin >> x;
	while (x == ' ');
	if (x != '(')
	{
		cout << "Некорректный ввод списка\n";
		return nullptr;
	}
	else
	{
		cout << "Список введен успешно\n";
		list = read_s_expr(x, list);
	}
	return list;
}

Unit* read_s_expr(base prev, Unit* list)
{
	if (prev == ')') exit(1);
	else 
		if (prev != '(')
		{
			list = makeAtom(prev);
			return list;
		}
		else list = read_seq(list);
	return list;
}

Unit* read_seq(Unit* list)
{
	base x;
	Unit* p1 = nullptr;
	Unit* p2 = nullptr;

	if (!(cin >> x)) exit(1);
	else
	{
		while (x == ' ') cin >> x;
		if (x == ')')
		{
			list = NULL;
			return list;
		}
		else
		{
			p1 = read_s_expr(x, p1);
			p2 = read_seq(p2);
			list = create(p1, p2);
			return list;
		}
	}
}

//проверяем, является ли элемент атомом
bool isAtom(Unit* list) 
{
	if (list == nullptr) return false;
	return (list->type == Atomic);
}

//удаляем заданный элемент (x)
Unit* delete_x(Unit* list, base x) 
{
	if (isEmpty(list)) return nullptr;
	if (isAtom(list))
	{ 
		if (getAtom(list) != x) return list;
		else
		{
			delete list;
			return nullptr;
		}
	}

	list->val.pair.head = delete_x(getHead(list), x);
	list->val.pair.tail = delete_x(getTail(list), x);

	return ((getHead(list) == nullptr) ? getTail(list) : list);
}

//разрушаем список
void destroy(Unit* list)  
{
	if (!isEmpty(list))
	{
		if (!isAtom(list))
		{
			destroy(getHead(list));
			destroy(getTail(list));
		}
		delete list;
	}
}
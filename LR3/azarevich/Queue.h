#include <iostream>
typedef double type;

class Queue
{
public:
	Queue(int n = 100);
	~Queue();

	bool push(type item);//поместить в очередь
	bool pop(type &item);//изъять из очереди

private:
	type *store;//очередь
	int begin;//метка начала очереди
	int end;//метка конца очереди
	int size;//размер очереди
	bool full;//флаг "отсутствие свободных мест"
};
#include "Queue.h"
using namespace std ;

extern void GLOBAL_ERRORS(int num);


Queue::Queue(int n)
{
	store = (type *)malloc(n*sizeof(type) );
	if ( !store )
		GLOBAL_ERRORS(1);

	begin = end = 0;
	size = n;
	full = false;
}


Queue::~Queue()
{
	free(store);
}



bool Queue::push(type item)
{
	if ( full )
	{
		//cerr << "Предупреждение: очередь заполнена\n";
		return false;
	}

	store[end] = item;
	end = (end +1)%size;
	
	if (begin == end) full = true;
	return true;
}


bool Queue::pop(type &item)
{
	if ( (begin == end) && !full)
	{
		//cerr << "Предупреждение: очередь пуста\n";
		return false;
	}

	item = store[begin];
	begin = (begin +1)%size;

	full = false;
	return true;
}



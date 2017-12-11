#ifndef ST_CLASS_H_INCLUDED
#define ST_CLASS_H_INCLUDED

//-------------------------------------
template <class Elem>
class Stack
{
private:
	struct node
	{ //
		Elem *hd;
		node *tl;
		// constructor
		node()
		{
			hd = NULL; tl = NULL;
		};
	};// end node

	node *topOfStack;

public:
	Stack()
	{
		topOfStack = NULL;
	}//;

	 //-------------------------------------
	Elem Stack::top(void) //
	{// PreCondition: not null	
		if (topOfStack == NULL) { cerr << "Error: top(null) \n"; system("pause"); exit(1); }
		else return *topOfStack->hd;
	}
	//-------------------------------------
	void Stack::pop(void)//
	{// PreCondition: not null
		if (topOfStack == NULL) { cerr << "Error: pop(null) \n"; system("pause"); exit(1); }
		else
		{
			node *oldTop = topOfStack;
			topOfStack = topOfStack->tl;
			delete oldTop->hd;
			delete oldTop;
		}
	}
	//-------------------------------------
	Elem Stack::pop2(void)//
	{// PreCondition: not null
		if (topOfStack == NULL) { cerr << "Error: pop(null) \n"; system("pause"); exit(1); }
		else
		{
			node *oldTop = topOfStack;
			Elem r = *topOfStack->hd;
			topOfStack = topOfStack->tl;
			delete oldTop->hd;
			delete oldTop;
			return r;
		}
	}
	//-------------------------------------
	void Stack::push(const Elem &x)//
	{
		node *p;
		p = topOfStack;
		topOfStack = new node;
		if (topOfStack != NULL) {
			topOfStack->hd = new Elem;
			*topOfStack->hd = x;
			cout << "push -> " << x << endl; // Demo
			topOfStack->tl = p;
		}
		else { cerr << "Memory not enough\n"; system("pause"); exit(1); }
	}
	//-------------------------------------
	bool Stack::isNull(void)//
	{
		return (topOfStack == NULL);
	}
	//-------------------------------------
	Stack::~Stack(void)//
	{
		while (topOfStack != NULL) {
			pop();
		}
	}
};



#endif // ST_CLASS_H_INCLUDED

﻿#include <iostream>
#include <cstdlib>
#include "lr3head.h"
using namespace std;

namespace st_modul1
{
	struct Stack::node
	{
		base *hd;
		node *tl;

		node()
		{
			hd = NULL; tl = NULL;
		}
	};

	base Stack::top(void)
	{
		if (topOfStack == NULL) { cerr << "Error: top(null) \n"; exit(1); }
		else return *topOfStack->hd;
	}

	void Stack::pop(void)
	{
		if (topOfStack == NULL) { cerr << "Error: pop(null) \n"; exit(1); }
		else
		{
			node *oldTop = topOfStack;
			topOfStack = topOfStack->tl;
			delete oldTop->hd;
			delete oldTop;
		}
	}

	base Stack::pop2(void)
	{
		if (topOfStack == NULL)
		{
			cerr << "Error: pop(null) \n";
			exit(1);
		}
		else
		{
			node *oldTop = topOfStack;
			base r = *topOfStack->hd;
			topOfStack = topOfStack->tl;
			delete oldTop->hd;
			delete oldTop;
			return r;
		}
	}

	void Stack::push(const base &x)
	{
		node *p;
		p = topOfStack;
		topOfStack = new node;
		if (topOfStack != NULL) {
			topOfStack->hd = new base;
			*topOfStack->hd = x;
			//cout << "push -> " << x << endl;		
			topOfStack->tl = p;
		}
		else { cerr << "Memory not enough\n"; exit(1); }
	}

	bool Stack::isNull(void)
	{
		return (topOfStack == NULL);
	}

	Stack::~Stack(void)
	{
		while (topOfStack != NULL) {
			pop();
		}
	}
}
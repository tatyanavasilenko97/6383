﻿#pragma once
#include <iostream>
using namespace std;

class Stack
{
public:
	void init()
	{
		for (int i = 0; i < size_1; i++) arr[i] = 0;
		work[0] = -1;
		work[1] = -1;
	}

	void push(char a)
	{
		if (work[1] != size_1 - 1)
		{
			if (work[0] == -1)
			{
				arr[0] = a;
				work[1] = 0;
				work[0] = 0;
			}
			else
			{
				arr[work[0] + 1] = a;
				work[0]++;
			}
		}
		else cout << "Стек переполнен." << endl;
	}

	bool can_pop()
	{
		if (work[0] != -1) return 1;
		else return 0;
	}

	char pop()
	{
		if (work[0] != -1)
		{
			if (work[0] != work[1])
			{
				char tmp = arr[work[0]];
				arr[work[0]] = 0;
				work[0]--;
				return tmp;
			}
			else
			{
				char tmp = arr[work[0]];
				arr[work[0]] = 0;
				work[0] = -1;
				work[1] = -1;
				return tmp;
			}
		}
		else return 0; //т.к. стек пуст
	}
	
	Stack()
	{
		init();
	}

private:
	const static size_t size_1 = 100;
	char arr[size_1];
	int work[2];
};
#include <iostream>
using namespace std;
const size_t size_1 = 100;
class Stack
{
public:
	char arr[size_1];
	int start, top;
	void init()
	{
		for (int i = 0; i < size_1; i++)
			arr[i] = 0;
		top = -1;
		start = -1;
	}
	void push(char a)
	{
		if (start != size_1 - 1)
		{
			if (top == -1)
			{
				arr[0] = a;
				start = 0;
				top = 0;
			}
			else
			{
				arr[top + 1] = a;
				top++;
			}
		}
		else
			cout << "Стек переполнен." << endl;
	}
	bool can_pop()
	{
		if (top != -1)
			return 1;
		else
			return 0;
	}
	char pop()
	{
		if (top != -1)
		{
			if (top != start)
			{
				char tmp = arr[top];
				arr[top] = 0;
				top--;
				return tmp;
			}
			else
			{
				char tmp = arr[top];
				arr[top] = 0;
				top = -1;
				start = -1;
				return tmp;
			}
		}
		else
		{
			cout << "Не удалось извлечь элемент, стек пуст." << endl;
			return 0;
		}
	}
	Stack()
	{
		init();
	}
};

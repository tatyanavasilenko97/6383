#pragma once
#define ADD_MEM 256
template <class T> class priority_queue
{
public:
	struct queue_cell
	{
		T data;
		__int64 priority;
	};
	queue_cell * head;
	long size, top;
	void alloc_mem(long count, bool is_realloc)
	{
		if (!is_realloc)
		{
			head = (queue_cell *)malloc(sizeof(queue_cell)* count);
			size = count;
		}
		else
		{
			size = size + count;
			head = (queue_cell *)realloc(head, sizeof(queue_cell)* size);
		}
	}
	void swap(long i1, long i2)
	{
		queue_cell tmp = head[i1];
		head[i1] = head[i2];
		head[i2] = tmp;
	}
public:
	priority_queue()
	{
		alloc_mem(ADD_MEM, false);
		top = -1;
	}
	template<class T> void push(T data0, __int64 cur_priority)
	{
		if (top + 1 >= size)
			alloc_mem(ADD_MEM, true);

		queue_cell cur_cell;

		cur_cell.data = data0;
		cur_cell.priority = cur_priority;

		head[++top] = cur_cell;

		for (long i = top - 1; i >= 0; i--)
		{
			if (head[i].priority <= cur_priority)
				swap(i, i + 1);
			else
				break;
		}
	}
	template<class T> T pop(__int64 & pr)
	{
		pr = head[top].priority;
		return head[top--].data;
	}
	long get_top()
	{
		return top;
	}
	~priority_queue()
	{
		free(head);
	}
};
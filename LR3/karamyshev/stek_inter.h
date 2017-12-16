#pragma once
namespace st_modul
{
	typedef int base;
	class Stack {
	private:
		struct node;
		node *top_stak;
	public:
		Stack(node *inptop = nullptr) : top_stak(inptop) {};
		char top(void);
		void pop(void);
		char pop2(void);
		void push(const char &x);
		bool isNull(void);
		void destroy(void);
	};
}

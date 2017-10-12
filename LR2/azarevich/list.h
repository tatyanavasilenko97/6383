#include <iostream>
#include <fstream>

using namespace std;

namespace h_list
{
	typedef char base;	// базовый тип элементов (атомов)
	struct s_expr;

	struct  two_ptr
	{
		s_expr *head; //указатель на голову
		s_expr *tail; //указатель на хвост
	};

	struct s_expr 
	{
		bool tag; // true: atom, false: pair
		union  
		{
			base atom;	 //элемент
			two_ptr pair;//указатели на голову и хвост
		} 
		node;	
	};			

	typedef s_expr *list;

	// базовые функции:
	list head (const list s);
	list tail (const list s);
	list cons (const list h, const list t);
	list make_atom (const base x);
	bool isAtom (const list s);
	bool isNull (const list s);

	void destroy (list s);//удаление списка

	// функции ввода(создание списка):
	void read_list ( list& y, istream &in);			// основная
	void read_s_expr (base prev, list &y, istream &in); 
	void read_seq ( list& y, istream &in); 

	// функции вывода:
	void write_list (const list x);		// основная
	void write_seq (const list x);  

	list copy_list (const list x);
}
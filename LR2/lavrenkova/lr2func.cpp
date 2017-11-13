#include "lisp_list.h"
#include "list.cpp"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

lisp head(const lisp s) {
	if (s != NULL)
		if (!isAtom(s))
			return s->node.pair.head;
		else {
			cerr << "Error: Head(atom) \n";
			exit(1);
		}
	else {
		cerr << "Error: Head(nil) \n";
		exit(1);
	}
}

bool isAtom(const lisp s) {
	if (s == NULL)
		return false;
	else
		return (s->tag);
}

bool isNull(const lisp s) {
	return s == NULL;
}

lisp tail(const lisp s)
{
	if (s != NULL)
		if (!isAtom(s))
			return s->node.pair.tail;
		else
		{
			cerr << "Error: Tail(atom) \n";
			exit(1);
		}
	else
	{
		cerr << "Error: Tail(nil) \n";
		exit(1);
	}
}

lisp cons(const lisp h, const lisp t)
{
	lisp p;
	if (isAtom(t))
	{
		cerr << "Error: Cons(*, atom)\n";
		exit(1);
	}
	else
	{
		p = new s_expr;
		if (p == NULL)
		{
			cerr << "Memory not enough\n";
			exit(1);
		}
		else
		{
			p->tag = false;
			p->node.pair.head = h;
			p->node.pair.tail = t;
			return p;
		}
	}
}

lisp make_atom(const base x)
{
	lisp s;
	s = new s_expr;
	s->tag = true;
	s->node.atom = x;
	return s;
}

void destroy(lisp s)
{
	if (s != NULL)
	{
		if (!isAtom(s))
		{
			destroy(head(s));
			destroy(tail(s));
		}
		delete s;
	};
}

base getAtom(const lisp s)
{
	if (!isAtom(s))
	{
		cerr << "Error: getAtom(s) for !isAtom(s) \n";
		exit(1);
	}
	else
		return (s->node.atom);
}

void read_lisp(lisp& y, ifstream &infile)
{
	base x;
	do
		infile >> x;
	while (x == ' ');
	read_s_expr(x, y, infile);
}

lisp copy_lisp(const lisp x)
{
	if (isNull(x))
		return NULL;
	else
		if (isAtom(x))
			return make_atom(x->node.atom);
		else
			return cons(copy_lisp(head(x)), copy_lisp(tail(x)));
}

void analysis(const lisp x, elem& h, int & n)
{
	elem ah;

	if (isNull(x))
		h = NULL;
	else
	{
		work_lisp(x, n, h, ah);
		ah->next = NULL;
	}
}

void write_lisp(const lisp x)
{
	if (isNull(x))
		cout << " ()";
	else
		if (isAtom(x))
			cout << ' ' << x->node.atom;
		else
		{
			cout << " (";
			write_seq(x);
			cout << " )";
		}
}

void write_seq(const lisp x)
{
	if (!isNull(x))
	{
		write_lisp(head(x));
		write_seq(tail(x));
	}
}

void read_s_expr(base prev, lisp& y, ifstream &infile)
{
	if (prev == ')')
	{
		cerr << " ! List.Error 1 " << endl;
		exit(1);
	}
	else
		if (prev != '(')
			y = make_atom(prev);
		else
			read_seq(y, infile);
}

void read_seq(lisp& y, ifstream &infile)
{
	base x;
	lisp p1, p2;

	if (!(infile >> x))
	{
		cerr << " ! List.Error 2 " << endl;
		exit(1);
	}
	else
	{
		while (x == ' ')
			infile >> x;
		if (x == ')')
			y = NULL;
		else
		{
			read_s_expr(x, p1, infile);
			read_seq(p2, infile);
			y = cons(p1, p2);
		}
	}
}

void work_seq(const lisp x, int & n, elem& h, elem& ah)
{
	if (!isNull(x))
	{
		work_lisp(head(x), n, h, ah);
		work_seq(tail(x), n, h, ah);
	}
}

void work_lisp(const lisp x, int & n, elem& h, elem& ah)
{
	if (isAtom(x))
	{
		// Подсчет атомов;
		n++;
		// Создание линейного списка;
		/*if (n == 1)
		{
			ah = new List;
			ah->atom = x->node.atom;
			h = ah;
		}
		else
		{
			ah->next = new List;
			if (n == 2)
				h = ah;
			ah = ah->next;
			ah->atom = x->node.atom;
		}
	}*/
		create_list(x, n, h, ah);
	}
	else
		work_seq(x, n, h, ah);
}
#pragma once
#include <fstream>

using namespace std;
typedef char base;

struct s_expr;
struct  two_ptr {
	s_expr *head;
	s_expr *tail;
};

struct s_expr {
	bool tag; // true: atom, false: pair
	union {
		base atom;
		two_ptr pair;
	} node;
};

struct List {
	base atom;
	List *next;
};

typedef s_expr *lisp;
typedef List *elem;


// ѕроцедура вывода списка с обрамл¤ющими его скобками - write_lisp,
//  а без обрамл¤ющих скобок - write_seq
lisp head(const lisp s);
bool isAtom(const lisp s);
bool isNull(const lisp s);
lisp tail(const lisp s);
lisp cons(const lisp h, const lisp t);
lisp make_atom(const base x);
void destroy(lisp s);
base getAtom(const lisp s);
void read_lisp(lisp& y, ifstream &infile);
void read_s_expr(base prev, lisp& y, ifstream &infile);
void read_seq(lisp& y, ifstream &infile);
void write_lisp(const lisp x);
void write_seq(const lisp x);
lisp copy_lisp(const lisp x);
void analysis(const lisp x, elem& b, int & n);
void work_lisp(const lisp x, int & n, elem& h, elem& ah);
void work_seq(const lisp x, int & n, elem& h, elem& ah);
void output(elem& b, ofstream &outfile);
void destroy_lin(elem b);
void create_list(const lisp x, int & n, elem& h, elem& ah);
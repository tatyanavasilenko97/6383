#ifndef LIST_H
#define LIST_H

#endif // LIST_H

#include<iostream>

typedef char base;	// базовый тип элементов (атомов)

enum TAG{
    TAG_ATOM, TAG_PAIR
};

struct  s_expr;

struct  two_ptr  {
    s_expr  *hd;
    s_expr  *tl;
} ;	//end two_ptr;

struct  s_expr {
    TAG tag;
    union  {
        base  atom;
        two_ptr pair;
    } node;		//end union node
};			    //end s_expr

typedef  s_expr* lisp;


lisp head (const lisp s);
lisp tail (const lisp s);
lisp cons (const lisp h, const lisp t);
lisp make_atom (const base x);
bool isAtom (const lisp s);
bool isNull (const lisp s);
void destroy (lisp s);
void write_lisp (const lisp x, std::ostream &cout);
void read_lisp ( lisp& y, std::istream &cin);

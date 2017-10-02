#include"list.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

lisp head (const lisp s)
{// PreCondition: not null (s)
    if (s != NULL)
        if (!isAtom(s))	return s->node.pair.hd;
        else { cerr << "Error: Head(atom) \n"; 	exit(1); }
    else { cerr << "Error: Head(nil) \n";
        exit(1);
    }
}

lisp tail (const lisp s)
{// PreCondition: not null (s)
    if (s != NULL)
        if (!isAtom(s))	return s->node.pair.tl;
        else { cerr << "Error: Tail(atom) \n"; exit(1); }
    else { cerr << "Error: Tail(nil) \n";
        exit(1);
    }
}

bool isAtom (const lisp s)
{	if(s == NULL) return false;
    else return (s -> tag==TAG_ATOM);
}


bool isNull (const lisp s)
{
    return s==NULL;
}

lisp cons (const lisp h, const lisp t)
// PreCondition: not isAtom (t)
{lisp p;
    if (isAtom(t)) { cerr << "Error: cons(*, atom) \n"; exit(1);}
    else { p = new s_expr;
        if ( p == NULL)	{
            cerr << "Memory ...\n"; exit(1);
        }
        else {
            p->tag = TAG_PAIR;
            p->node.pair.hd = h;
            p->node.pair.tl = t;
            return p;
        }
    }
}

lisp make_atom (const base x)
{	lisp s;
    s = new s_expr;
    s -> tag = TAG_ATOM;
    s->node.atom = x;
    return s;
}

void destroy (lisp s)
{
    if ( s != NULL) {
        if (!isAtom(s)) {
            destroy ( head (s));
            destroy ( tail(s));
        }
        delete s;
    };
}

// функции ввода:
void read_lisp ( lisp& y,istream &cin);		// основная
void read_s_expr (base prev, lisp& y,istream &cin);
void read_seq ( lisp& y,istream &cin);

// ввод списка с консоли
void read_lisp ( lisp& y,istream &cin)
{	base x;
    do cin >> x; while (x==' ');
    read_s_expr ( x, y,cin);
} //end read_lisp

void read_s_expr (base prev, lisp& y,istream &cin)
{ //prev   － ранее прочитанный символ
    if ( prev == ')' ) {cerr << " ! List.Error 1 " << endl; exit(1); }
    else if ( prev != '(' ) y = make_atom (prev);
    else read_seq (y,cin);
} //end read_s_expr

void read_seq ( lisp& y,istream &cin)
{	base x;
    lisp p1, p2;
    if (!(cin >> x)) {cerr << " ! List.Error 2 " << endl; exit(1);}
    else {
        while  ( x==' ' ) cin >> x;
        if ( x == ')' ) y = NULL;
        else {	read_s_expr ( x, p1,cin);
            read_seq ( p2,cin);
            y = cons (p1, p2);
        }
    }
} //end read_seq

// функции вывода:
void write_lisp (const lisp x,ostream &cout);	// основная
void write_seq (const lisp x,ostream &cout);

void write_lisp (const lisp x,ostream &cout)
{//пустой список выводится как ()
    if (isNull(x)) cout << " ()";
    else if (isAtom(x)) cout << ' ' << x->node.atom;
    else  { //непустой список
        cout << " (" ;
        write_seq(x,cout);
        cout << " )";
    }
} // end write_lisp
void write_seq (const lisp x,ostream &cout)
{/*выводит последовательность элементов списка без обрамляющих его скобок */
    if (!isNull(x)) {
        write_lisp(head (x),cout);
        write_seq(tail (x),cout);
    }
}

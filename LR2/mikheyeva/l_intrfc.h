#ifndef L_INTRFC_H
#define L_INTRFC_H



namespace h_list
{
    typedef char base;	// базовый тип элементов (атомов)

    struct s_expr;
    struct  two_ptr
        {
        s_expr *hd;
        s_expr *tl;
    } ;	//end two_ptr;

    struct s_expr {
        bool tag; // true: atom, false: pair
        union
            {
            base atom;
            two_ptr pair;
        } node;		//end union node
    };			//end s_expr

    typedef s_expr *lisp;

// функции
    void print_s_expr( lisp s );
    // базовые функции:
    lisp head (const lisp s);
    lisp tail (const lisp s);
    lisp cons (const lisp h, const lisp t);
    lisp make_atom (const base x);
    bool isAtom (const lisp s);
    bool isNull (const lisp s);
   



    // функции ввода:
    void read_lisp ( lisp& y);			// основная
    void read_s_expr (base prev, lisp& y);
    void read_seq ( lisp& y);

    // функции вывода:
    void write_lisp (const lisp x);		// основная
    void write_seq (const lisp x);

    lisp copy_lisp (const lisp x);

} // end of namespace h_list


// continue of namespace h_list
#include "l_intrfc.h"
#include <iostream>
#include <cstdlib>

using namespace std;
namespace h_list
{

//....................................
    lisp head (const lisp s)
    {// PreCondition: not null (s)
        if (s != NULL) if (!isAtom(s))	return s->node.pair.hd;
            else { cerr << "Error: Head(atom) \n"; exit(1); }
        else { cerr << "Error: Head(nil) \n";
            exit(1);
        }
    }
//.......................................
    bool isAtom (const lisp s)
    {	if(s == nullptr) return false;
    else return (s -> tag);
    }
//.......................................
    bool isNull (const lisp s)
    { return s==NULL;
    }
//.......................................
    lisp tail (const lisp s)
{// PreCondition: not null (s)
        if (s != NULL) if (!isAtom(s))	return s->node.pair.tl;
            else { cerr << "Error: Tail(atom) \n"; exit(1); }
        else { cerr << "Error: Tail(nil) \n";
            exit(1);
        }
    }
//.......................................
    lisp cons (const lisp h, const lisp t)
    // PreCondition: not isAtom (t)
    {lisp p;
    if (isAtom(t)) { cerr << "Error: Cons(*, atom)\n"; exit(1);}
    else {
        p = new s_expr;
        if ( p == NULL)	{cerr << "Memory not enough\n"; exit(1); }
        else {
            p->tag = false;
            p->node.pair.hd = h;
            p->node.pair.tl = t;
            return p;
        }
    }
    }
//...........................
    lisp make_atom (const base x)
    {	lisp s;
        s = new s_expr;
        s -> tag = true;
        s->node.atom = x;
        return s;
    }

//...........................
   
//...........................


//...........................
// ввод списка с консоли
    void read_lisp ( lisp& y)
    {	base x;
        do cin >> x; while (x==' ');
        read_s_expr ( x, y);
    } //end read_lisp
//...........................
    void read_s_expr (base prev, lisp& y)
    { //prev   － ранее прочитанный символ}
        if ( prev == ')' ) {cerr << " ! List.Error 1 " << endl; exit(1); }
        else if ( prev != '(' ) y = make_atom (prev);
             else read_seq (y);
    } //end read_s_expr
//...........................
    void read_seq ( lisp& y)
    {	base x;
        lisp p1, p2;

        if (!(cin >> x)) {cerr << " ! List.Error 2 " << endl; exit(1);}
        else {
            while  ( x==' ' ) cin >> x;
            if ( x == ')' ) y = NULL;
            else {
                read_s_expr ( x, p1);
                read_seq ( p2);
                y = cons (p1, p2);
            }
        }
    } //end read_seq
//...........................
// Процедура вывода списка с обрамляющими его скобками  － write_lisp,
//  а без обрамляющих скобок   － write_seq
    void write_lisp (const lisp x)
    {//пустой список выводится как ()
		
    if (isNull(x)) cout << " ()";
	else if (isAtom(x)) {
	//	cout << x << endl;
		cout << ' ' << x->node.atom;

	}
        else  { //непустой список}
            cout << " (" ;
            write_seq(x);
            cout << " )";
        }
    } // end write_lisp
//...........................
void write_seq (const lisp x)
{//выводит последовательность элементов списка без обрамляющих его скобок
    if (!isNull(x)) {
        write_lisp(head (x));
        write_seq(tail (x));
    }
}
//...........................

 // end of namespace h_list




#endif // L_INTRFC_H

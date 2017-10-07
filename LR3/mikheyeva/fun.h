#ifndef FUN_H
#define FUN_H


namespace st_modul1
{

//-------------------------------------
    typedef int base;

    class Stack {
    private:
        struct node;
/*	определение структуры будет дано в другом файле (продолжении namespace st_modul)  － в файле Implementation,
    а здесь достаточно объявления "struct node;"
*/
    node *topOfStack;

    public:
        Stack ()
            { topOfStack = NULL;
            };
       base top (void);

        base pop2(void);
        void push (const base &x);
        bool isNull(void);

    };
}

// Implementation  － Реализация АТД "Стек"(ссылочная реализация в динамической памяти)
#include <iostream>
#include <cstdlib>
#include "fun.h"
using namespace std ;

namespace st_modul1
{
    struct Stack::node {//
    base *hd;
    node *tl;
        // constructor
        node ()
            {hd = NULL; tl = NULL;
        }
    };// end node

//-------------------------------------
    base Stack::top (void)
    {// PreCondition: not null
        if (topOfStack == NULL) { cerr << "Error: top(null) \n"; exit(1); }
        else return *topOfStack->hd;
    }
//-------------------------------------

//-------------------------------------
    base Stack::pop2(void)
    {// PreCondition: not null
        if (topOfStack == NULL) { cerr << "Error: pop(null) \n"; exit(1); }
        else
        {	node *oldTop = topOfStack;
            base r = *topOfStack->hd;
            topOfStack = topOfStack->tl;
            delete oldTop->hd;
            delete oldTop;
            return r;
        }
    }
//-------------------------------------
    void Stack::push (const base &x)
    {	node *p;
        p = topOfStack;
        topOfStack = new node;
        if ( topOfStack != NULL)	{
            topOfStack->hd = new base;
            *topOfStack->hd = x;

            topOfStack->tl = p;
        }
        else {cerr << "Memory not enough\n"; exit(1);}
    }
//-------------------------------------
    bool Stack::isNull(void)
    {	return (topOfStack == NULL) ;
    }
//-------------------------------------

}

#endif // FUN_H

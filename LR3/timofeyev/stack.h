// 
// Лабораторная работа №3
// stack.h
// Тимофеев Дмитрий, группа 6383
// 06.10.17
//
// Линейные структуры данных: стек, очередь, дек. 

#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<stdlib.h>

template <class Elem>
class Stack{
    private:
        struct node{ //
            Elem hd;
            node *tl;
            node (){
                tl = NULL;
            }
        };// end node

    node *topOfStack;

    public:
        Stack (){
            topOfStack = NULL;
        }//;

//-------------------------------------
    Elem top (void) {// PreCondition: not null
        if (topOfStack == NULL) {
            std::cerr << "Error: top(null) \n";
            exit(1);
        }
        else return topOfStack->hd;
    }

    Elem pop(void){// PreCondition: not null
        if (topOfStack == NULL) {
            std::cerr << "Error: pop(null) \n";
            exit(1);
        }
        else{
            node *oldTop = topOfStack;
            Elem r = topOfStack->hd;
            topOfStack = topOfStack->tl;
            delete oldTop;
            return r;
        }
    }

    void push (const Elem &x){
        node *p;
        p = topOfStack;
        topOfStack = new node;
        if ( topOfStack != NULL)	{
            topOfStack->hd = x;
            topOfStack->tl = p;
        }
        else {
            std::cerr << "Memory not enough\n";
            exit(1);
        }
    }

    bool isNull(void){
        return (topOfStack == NULL) ;
    }

    ~Stack (){
        while ( topOfStack != NULL) {
            pop();
        }
    }
};

#endif // STACK_H

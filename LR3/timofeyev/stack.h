#ifndef STACK_H
#define STACK_H

#endif // STACK_H
#include<iostream>
#include<stdlib.h>

namespace stack{
    template <class Elem>
    class Stack{
        private:
            struct node{ //
                Elem *hd;
                node *tl;
                node (){
                    hd = NULL;
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
            else return *topOfStack->hd;
        }

        Elem pop(void){// PreCondition: not null
            if (topOfStack == NULL) {
                std::cerr << "Error: pop(null) \n";
                exit(1);
            }
            else{
                node *oldTop = topOfStack;
                Elem r = *topOfStack->hd;
                topOfStack = topOfStack->tl;
                delete oldTop->hd;
                delete oldTop;
                return r;
            }
        }

        void push (const Elem &x){
            node *p;
            p = topOfStack;
            topOfStack = new node;
            if ( topOfStack != NULL)	{
                topOfStack->hd = new Elem;
                *topOfStack->hd = x;
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

        void destroy (void){
            while ( topOfStack != NULL) {
                pop();
            }
        }
    };
}

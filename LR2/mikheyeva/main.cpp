// Михеева Екатеринв
// группа 6383
//вариант 4
//09.10.17
//
#include <iostream>
#include <cstdlib>
#include "l_intrfc.h"
#include "list.h"
using namespace std;
using namespace h_list;

/*
struct list {

    base ch;
    list *tail;
    list *head;
};
typedef list *list_pointer;
void add(list_pointer &x, char elem)
{
    x->ch = elem;
               x->tail = new list;
                x->tail->head = x->head;
               x = x->tail;
}

*/
bool find(list_pointer head, base c);


/*
list_pointer tail_l(list_pointer head)
{
    return head->tail;
}
void write_l(list_pointer head)
{
    if (head->tail != NULL)
    {
        cout << head->ch << " ";
        write_l(tail_l(head));
}

    else
         return ;

}
*/
void count(list_pointer head, int &k)
{

    if (head->tail != NULL)
    {

       count(tail_l(head),k);
       k++;
}

    else
         return ;

}

bool find(list_pointer head, base c) // found true - íàéäåí
{

    if (head != nullptr) {
        if (head->ch == c) {

            return true;
        }
        else find(tail_l(head), c);
    }
    else return false;
}

void make_list( lisp  s1, list_pointer &x);
void make_list_seq(  lisp   s1, list_pointer &x);

int main()
{

   lisp  s1;

    int k = 0;
    cout << "Введите list1:" << endl;
    read_lisp(s1);
//write_lisp(s1);
    cout << endl;

    list_pointer x = new list;
    list_pointer head = x;
    x->head = head;
   // list_pointer head = new list;
      make_list(s1,x);
       cout << "flatten  =  ";
       cout<<"( ";
     write_l((head));
     cout<<")"<<endl;
   count(head, k);
   cout<<"Количество = ";
 cout << k << endl;

    return 0;
}

void make_list ( lisp s1, list_pointer &x)
{
if (isNull(s1)) return;
else if (isAtom(s1)) {

    bool found = false;

    found = find(x->head, s1->node.atom);

        if (found == false)

            add(x,s1->node.atom);

}
    else  {
        make_list_seq(s1,x);

    }
}
//...........................
void make_list_seq ( lisp s1,list_pointer &x)
{
if (!isNull(s1)) {
    make_list(head (s1),x);
    make_list_seq(tail (s1),x);
}
}

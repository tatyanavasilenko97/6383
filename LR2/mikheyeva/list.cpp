#include "list.h";
#include <iostream>
using namespace std;
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
void add(list_pointer &x, char elem)
{
    x->ch = elem;
               x->tail = new list;
                x->tail->head = x->head;
               x = x->tail;
}

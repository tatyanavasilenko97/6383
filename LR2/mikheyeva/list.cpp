#include "list.h"
#include <iostream>
using namespace std;
list tail_l(list head){
    return head->next;
}

void write_l(list head){
    if (head != NULL){
        cout << head->value << " ";
        write_l(tail_l(head));
    }
    else return ;
}

void add(list &x, char elem){
    list node = new Node;
    node->value = elem;
    node ->next  = x;
    x = node;
}

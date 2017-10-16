// Михеева Екатеринв
// группа 6383
//вариант 4
//09.10.17
//
#include <iostream>
#include <cstdlib>
#include "lisp.h"
#include "list.h"
using namespace std;

void count(list head, int &k) {
    if (head != NULL) {
        count(tail_l(head),k);
        k++;
    }
    else return;
}

bool find(list head, base c){
    if (head != nullptr) {
        if (head->value == c)
            return true;
        else return find(tail_l(head), c);
    }
    else return false;
}

list make_list(lisp s1);
void make_list_private( lisp  s1, list &x);
void make_list_private_seq(  lisp   s1, list &x);

int main(){
    lisp  s1;
    int k = 0;
    cout << "Введите list1:" << endl;
    read_lisp(s1);
    cout << endl;
    list head;
    head = make_list(s1);
    cout << "flatten  =  ";
    cout<<"( ";
    write_l((head));
    cout<<")"<<endl;
    count(head, k);
    cout<<"Количество = ";
     cout << k << endl;
    return 0;
}

void make_list_private ( lisp s1, list &x){
    if (is_null(s1)) return ;
    if (is_atom(s1)) {
        if (!find(x, s1->node.atom))
        add(x,s1->node.atom);
    }
    else make_list_private_seq(s1,x);
}
//...........................
void make_list_private_seq ( lisp s1,list &x){
    if (!is_null(s1)) {
        make_list_private(head (s1),x);
        make_list_private_seq(tail (s1),x);
    }
}

list make_list(lisp s1){
    list x = nullptr;
    make_list_private(s1,x);
    return x;
}



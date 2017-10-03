//
//Михеева Екатерина группа 6363
// 03.10.17
//Программа предназначена для подсчета количества уникальных элементов
// и формирования из них линейного списка
//


#include <iostream>
#include <cstdlib>
#include "l_intrfc.h"

using namespace std;
using namespace h_list;


//......................
//вспомогтельная структура для поиска уникаланых элеметов
struct n {

    base ch;
    n *tail;

};
typedef n *p;


p find(p head, base c, bool &found);

p tail_l(p head)
{
    return head->tail;
}

p find(p head, base c, bool &found) // found true - найден
{

    if (head != nullptr) {
        if (head->ch == c) {
            found = true;
            return NULL;
        }
        else find(tail_l(head), c, found);
    }
    else return NULL;
}

p change( lisp s,lisp s1, lisp &y,p &t, p &head,int &k);
void change_seq( lisp s,lisp s1,lisp &y,p &t,p &head,int &k);

int main()
{
 //   setlocale(0, "rus");
    lisp  s1,s2, s3;
    p s4;

    p head;
    int k = 0;
    cout << "введите list1:" << endl;
    read_lisp(s1);
    cout << "введен list1: " << endl;
    write_lisp(s1);
    cout << endl;
    cout << "uniq: ";
    s3 = nullptr;
 change(s1,s1,s3, s4, head,k);

 cout << k << endl;
 if (k == 0) {
     cout << "()"; return 0;
 };
 s4->tail = nullptr;
 cout << "flatten списка = " << endl;

    write_lisp(s3);
    cout << endl;

//	system("pause");
    return 0;
}
//
p change( lisp x, lisp s1, lisp &y,p &t, p &head,int &k)
{
    p u;

    if (isNull(x)) return nullptr;
    else if (isAtom(x)) {

            bool found = false;

            if (k>=1) find(head, x->node.atom, found);

                if (found == false) {
                    y = cons(make_atom(x->node.atom), y);
                    k++;
                    u = new (n);
                    if (k == 1) head = u;
                    if (k > 1) t->tail = u;
                    t = u;
                    t->tail = nullptr;
                    t->ch = x->node.atom;
                }


         return nullptr;
    }
    else {
        change_seq(x,s1,y,t,head,k);
        return t;
    }
}
//.........................
void change_seq( lisp x, lisp s1,lisp &y,p &t, p &head1,int &k)
{
    if (!isNull(x)) {

    }
}
        change(head(x),s1,y,t,head1,k);
        change_seq(tail(x),s1,y,t,head1,k);

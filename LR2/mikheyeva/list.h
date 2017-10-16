#ifndef LIST
#define LIST

typedef char base;
struct Node {
    base value;
    Node *next;
};
typedef Node *list;
list tail_l(list head);
void write_l(list head);
void add(list &x, char elem);
void destroy_list(list x);

#endif
// LIST

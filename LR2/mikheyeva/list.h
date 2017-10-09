#ifndef LIST
#define LIST

typedef char base;
struct list {

    base ch;
    list *tail;
    list *head;
};
typedef list *list_pointer;
list_pointer tail_l(list_pointer head);
void write_l(list_pointer head);
void add(list_pointer &x, char elem);
#endif // LIST


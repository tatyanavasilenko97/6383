#ifndef STACK
#define STACK

typedef char base;
class Stack {
public:
    Stack (){
        topOfStack = NULL;
    };
    ~Stack();
    base top (void);
    base pop(void);
    void push (const base &x);
    bool isNull(void);
private:
    struct node;
    node *topOfStack;
};

#endif // STACK


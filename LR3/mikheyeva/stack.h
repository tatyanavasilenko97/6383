#ifndef STACK
#define STACK

//namespace st_modul1
//{

//-------------------------------------
    typedef char base;

    class Stack {
    private:
        struct node;

    node *topOfStack;

    public:
        Stack ()
            { topOfStack = NULL;
            };
      ~Stack();
       base top (void);

        base pop(void);
        void push (const base &x);
        bool isNull(void);

    };




//}

#endif // STACK


#ifndef BINTREE
#define BINTREE

typedef char base;

struct node {
    base info;
    node *lt;
    node *rt;
    node () {
        lt = NULL;
        rt = NULL;
    }
};

typedef node *binTree;

    binTree Create(void);
    bool isNull(binTree);
    base RootBT (binTree);
    binTree Left (binTree);
    binTree Right (binTree);
    binTree ConsBT(const base &x, binTree &lst,  binTree &rst);
    void destroy (binTree&);

#endif // BINTREE


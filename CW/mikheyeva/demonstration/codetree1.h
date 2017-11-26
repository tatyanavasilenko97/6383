#ifndef CODETREE1
#define CODETREE1
#include "codetree.h"
#define MAX_CODE_LEN 1000000
struct Symbol {
    char c;
    //char *str ;
    int weight;
};
bool symbol_less(const Symbol& l, const Symbol& r);
bool symbol_greater(const Symbol& l, const Symbol& r);
struct CodeTree {
    char *str;
    Symbol s;
    CodeTree* parent;
    CodeTree* left;
    CodeTree* right;
};
CodeTree* make_leaf(const Symbol& s);
CodeTree* make_node(int weight, CodeTree* left, CodeTree* right);
bool is_leaf(const CodeTree* node);
bool is_root(const CodeTree* node);
char* encode(/*const*/ CodeTree* tree, /*const*/ char* message);
char* decode(const CodeTree* tree, /*const*/ char* code);
void destroy(CodeTree* tree);


struct Trees{

    BT* root=NULL;
    CodeTree *tree;
    int weight;
    char symbol;
    Trees(CodeTree *tree,int weight, char symbol){
        this->tree = tree;
        this->weight = weight;
        this->symbol = symbol;
        this->root=makeBT(tree);
    }

    ~Trees(){
        if(root!=NULL)delete root;
    }
    static BT* makeBT(CodeTree* root){
        if(root==NULL)return NULL;
        return new BT(root->s.c,
                      root->s.weight,
                      makeBT(root->left),
                      makeBT(root->right));
    }
};


#endif // CODETREE1



#ifndef CODETREE
#define CODETREE

#include<iostream>
#include<string.h>
#include<vector>
//using nullptr = NULL;
//typedef  NULL nullptr;
//namespace code_tree {
    struct Node{
        char symbol;
        long weight;
        Node* parent;
        Node* left;
        Node* right;
        Node* next=NULL;
        Node* back=NULL;
        Node(char symbol, long weight, Node* parent, Node* left, Node* right){
            this->symbol=symbol;
            this->weight=weight;
            this->parent=parent;
            this->left=left;
            this->right=right;
        }
    };

    class DemoTree{
    public:
        DemoTree();
        ~DemoTree();
        Node* updateTree(unsigned char symbol);

    private:
        Node* symbols[256]={NULL};
        Node* esc;
        Node* root=NULL;
    };

    struct BT{
        char symbol;
        long weight;
        BT* left=NULL;
        BT* right=NULL;
        ~BT(){
            if(left!=NULL)delete left;
            if(right!=NULL)delete right;
        }
        BT(char symbol, long weight, BT* left,BT* right){
            this->symbol=symbol;
            this->weight=weight;
            this->left=left;
            this->right=right;
        }
    };

    struct State{
        int currentSymbol;
        char* msg=NULL;
        BT* root=NULL;

        State(int currentSymbol, char* msg, Node* root){
            this->currentSymbol=currentSymbol;
            this->msg=new char[strlen(msg)+1];
            (*(this->msg))='\0';
            stpcpy(this->msg,msg);
            this->root=captureTree(root);
        }

        ~State(){
            if(root!=NULL)delete root;
            if(msg!=NULL)delete[] msg;
        }
        static BT* captureTree(Node* root){
            if(root==NULL)return NULL;
            return new BT(root->symbol,
                          root->weight,
                          captureTree(root->left),
                          captureTree(root->right));
        }
    };

    void encode(std::istream &in, std::ostream &code);
    void decode(std::istream &in, std::ostream &code);
    void demoEncode(std::vector<State*> &states, char* msg);

//}

#endif // CODETREE

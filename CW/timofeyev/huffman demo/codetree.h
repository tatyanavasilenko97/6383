// Курсовая работа
// codetree.h
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#ifndef CODETREE
#define CODETREE

#include<iostream>
#include<string.h>
#include<vector>

namespace code_tree {
    struct Node{
        char symbol;
        long weight;
        Node* parent;
        Node* left;
        Node* right;
        Node* next=nullptr;
        Node* back=nullptr;
        Node(char symbol, long weight, Node* parent, Node* left, Node* right){
            this->symbol=symbol;
            this->weight=weight;
            this->parent=parent;
            this->left=left;
            this->right=right;
        }
    };

    void encode(std::istream &in, std::ostream &code);
    void decode(std::istream &in, std::ostream &code);
}

namespace demo_haffman{
    struct BT{
        char symbol;
        long weight;
        bool updated;
        BT* left=nullptr;
        BT* right=nullptr;
        ~BT(){
            if(left!=nullptr)delete left;
            if(right!=nullptr)delete right;
        }
        BT(char symbol, long weight, BT* left,BT* right,bool updated){
            this->symbol=symbol;
            this->weight=weight;
            this->left=left;
            this->right=right;
            this->updated=updated;
        }
    };

    struct State{
        int updatedSymbol;
        char* msg=nullptr;
        BT* root=nullptr;

        State(int updatedSymbol,const char* msg, code_tree::Node* root){
            this->updatedSymbol=updatedSymbol;
            this->msg=new char[strlen(msg)+1];
            (*(this->msg))='\0';
            stpcpy(this->msg,msg);
            this->root=captureTree(root);
        }

        ~State(){
            if(root!=nullptr)delete root;
            if(msg!=nullptr)delete[] msg;
        }

        static BT* captureTree(code_tree::Node* updated);
        static BT* captureTreeRec(code_tree::Node* root, code_tree::Node* updated);
    };


    void demoEncode(std::vector<State*> &states, char* msg);
}
#endif // CODETREE


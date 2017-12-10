// Лабораторная работа №5
// codetree.cpp
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#include"codetree.h"
#include<iostream>
using namespace std;

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

    bool isLeft(Node* node){
        return node==node->parent->left;
    }

    Node* rootOfTree(Node* n){
        while (n->parent!=nullptr)n=n->parent;
        return n;
    }

    void destroyRec(Node* n){
        if(n==nullptr)return;
        destroyRec(n->left);
        destroyRec(n->right);
        delete n;
    }

    void destroy(Node* n){
        destroyRec(rootOfTree(n));
    }

    void resolve(Node* problem){
        Node* next=problem->next;
        Node* target=next;
        while((next=next->next)->weight<problem->weight)
            if(next!=problem->parent)target=next;

        Node* parentTarget=target->parent;
        Node* parentProblem=problem->parent;
        if(isLeft(target)) parentTarget->left=problem;
            else parentTarget->right=problem;
        if(isLeft(problem))parentProblem->left=target;
            else parentProblem->right=target;
        problem->parent=parentTarget;
        target->parent=parentProblem;

        Node* tn=target->next;
        target->next=problem->next;
        target->next->back=target;
        problem->next=tn;
        problem->next->back=problem;

        Node* tb=target->back;
        target->back=problem->back;
        target->back->next=target;
        problem->back=tb;
        problem->back->next=problem;
    }

    void incrementWeight(Node* n){
        n->weight++;
        if(n->parent==nullptr)return;
        Node* next=n->next;
        if(next==n->parent)next=next->next;
        if(next!=nullptr&&next->weight<n->weight)resolve(n);
        incrementWeight(n->parent);
    }

    Node* splitESCSymbol(Node* esc, char symbol){
        Node* root=new Node(0,
                            esc->weight,
                            esc->parent,
                            esc,
                            new Node(symbol,1,nullptr,nullptr,nullptr)
                            );
        if(esc->parent!=nullptr){
            if(isLeft(esc))root->parent->left=root;
                else root->parent->right=root;
        }
        esc->parent=root;
        root->right->parent=root;

        root->next=esc->next;
        if(root->next!=nullptr)root->next->back=root;
        root->back=root->right;
        root->back->next=root;
        esc->next=root->back;
        esc->next->back=esc;

        incrementWeight(root);
        return root->right;
    }

    int lenCode(Node* n){
        if(n->parent==nullptr)return 0;
        else return 1+lenCode(n->parent);
    }

    int bitCode(char* code, int offset, Node* symbol){
        int len=lenCode(symbol);
        for(int i=0;i<len;i++){
            code[offset+len-1-i]=(isLeft(symbol)?'0':'1');
            symbol=symbol->parent;
        }
        return len;
    }

    Node* initESC(){
        return new Node(0,0,nullptr,nullptr,nullptr);
    }

    void encode(istream &in, ostream &code){
        if(in.peek()==EOF)return;
        Node* symbols[256]={nullptr};
        Node* esc=initESC();
        unsigned char current;

        unsigned char firstChar=in.get();
        code<<firstChar;
        symbols[firstChar]=splitESCSymbol(esc,firstChar);

        while(in.peek()!=EOF){
            current=in.get();
            if(symbols[current]==nullptr){
                char bits[256];
                int len=bitCode(bits,0,esc);
                for(int i=0;i<len;i++)code<<bits[i];
                symbols[current]=splitESCSymbol(esc,current);
                code<<current;
            }
            else{
                char bits[256];
                int len=bitCode(bits,0,symbols[current]);
                for(int i=0;i<len;i++)code<<bits[i];
                incrementWeight(symbols[current]);
            }
        }
        destroy(esc);
    }

    Node* symbolByCodeStream(Node* root, istream &code){
        while(true){
            if(root->left==nullptr)return root;
            char c=code.get();
            if(c=='0'){
                root=root->left;
                continue;
            }
            if(c=='1'){
                root=root->right;
                continue;
            }
            throw "error code";
        }
    }

    void decode(istream &in, ostream &code){
        if(in.peek()==EOF)return;
        Node* esc=initESC();

        unsigned char firstSymbol=in.get();
        splitESCSymbol(esc,firstSymbol);
        Node* root=esc->parent;
        code<<firstSymbol;

        while(in.peek()!=EOF){
            Node* symbol=symbolByCodeStream(root, in);
            if(symbol!=esc){
                code<<symbol->symbol;
                incrementWeight(symbol);
            }
            else{
                char newSymbol=in.get();
                code<<newSymbol;
                splitESCSymbol(esc,newSymbol);
            }
        }

        destroy(esc);
    }
}

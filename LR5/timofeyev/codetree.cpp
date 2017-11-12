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

    // сверху - влево
    // слева - вправо
    // справа- вверх
    Node* iterateNextOnThisLevel(Node* current){
        if(current==nullptr)return nullptr;
        int level=0;
        Node* prev=current;

        current=current->parent;
        if(current==nullptr)return nullptr;
        level--;

        while(level!=0){
            if(prev==current->parent){ // сверху
                if(current->left!=nullptr){
                    prev=current;
                    current=current->left;
                    level++;
                }
                else{
                    if(current->parent==nullptr)return nullptr;
                    prev=current;
                    current=current->parent;
                    level--;
                }
                continue;
            }

            if(current->left==prev){ // слева
                level++;
                prev=current;
                current=current->right;
                continue;
            }

            if(current->right==prev){ // справа
                if(current->parent==nullptr)return nullptr;
                level--;
                prev=current;
                current=current->parent;
                continue;
            }
        }
        return current;
    }

    Node* findFirstOnLevel(Node* root, int level){
        if(root==nullptr)return nullptr;
        if(level==1)return root;
        Node* f=findFirstOnLevel(root->left,level-1);
        if(f!=nullptr)return f;
        f=findFirstOnLevel(root->right,level-1);
        return f;
    }

    Node* firstOnPrevLevel(Node* current){
        int level=0;
        while(current->parent!=nullptr){
            current=current->parent;
            level++;
        } // нашли корень у требуемый уровень
        return findFirstOnLevel(current,level);
    }

    Node* iterate(Node* current){
        if(current==nullptr)return nullptr;
        Node* n=iterateNextOnThisLevel(current);
        if(n!=nullptr)return n;
        return firstOnPrevLevel(current);
    }

    void resolve(Node* problem){
        Node* next=iterate(problem);
        Node* target=next;
        while((next=iterate(next))->weight<problem->weight)
            if(next!=problem->parent)target=next;

        Node* parentTarget=target->parent;
        Node* parentProblem=problem->parent;
        if(isLeft(target)) parentTarget->left=problem;
            else parentTarget->right=problem;
        if(isLeft(problem))parentProblem->left=target;
            else parentProblem->right=target;
        problem->parent=parentTarget;
        target->parent=parentProblem;
    }

    void incrementWeight(Node* n){
        n->weight++;
        if(n->parent==nullptr)return;
        Node* next=iterate(n);
        if(next->weight<n->weight&&next!=n->parent)resolve(n);
        incrementWeight(n->parent);
    }

    Node* splitESCSymbol(Node* esc, char symbol){
        Node* root=new Node(0,
                            0,
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

    char* emptyString(){
        char* s=new char[1];
        s[0]='\0';
        return s;
    }

    const int MSG_LEN=1000000;

    char* encode(char* in){
        if((*in)=='\0')return emptyString();
        char* code=new char[MSG_LEN];
        Node* symbols[256]={nullptr};
        Node* esc=new Node(0,0,nullptr,nullptr,nullptr);
        unsigned char current;
        int indexCode=0;

        unsigned char firstChar=*(in++);
        code[indexCode++]=firstChar;
        symbols[firstChar]=splitESCSymbol(esc,firstChar);

        while((current=*in)!='\0'){
            if(symbols[current]==nullptr){
                indexCode+=(bitCode(code,indexCode,esc));
                symbols[current]=splitESCSymbol(esc,current);
                code[indexCode++]=current;
            }
            else{
                indexCode+=(bitCode(code,indexCode,symbols[current]));
                incrementWeight(symbols[current]);
            }
            in++;
        }
        code[indexCode]='\0';
        destroy(esc);
        return code;
    }

    Node* symbolByCode(Node* root, char* &code){
        while(true){
            if(root->left==nullptr)return root;
            char c=*(code++);
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

    char* decode(char* in){
        if((*in)=='\0')return emptyString();
        char* code=new char[MSG_LEN];
        Node* esc=new Node(0,0,nullptr,nullptr,nullptr);
        int indexCode=0;

        int firstSymbol=*(in++);
        splitESCSymbol(esc,firstSymbol);
        Node* root=esc->parent;
        code[indexCode++]=firstSymbol;

        while(true){
            if((*in)=='\0')break;
            Node* symbol=symbolByCode(root,in);
            if(symbol!=esc){
                code[indexCode++]=symbol->symbol;
                incrementWeight(symbol);
            }
            else{
                char newSymbol=*(in++);
                code[indexCode++]=newSymbol;
                splitESCSymbol(esc,newSymbol);
            }
        }
        code[indexCode]='\0';
        destroy(esc);
        return code;
    }
}

// Курсовая работа
// codetree.h
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#include"codetree.h"
#include<iostream>
#include<QTextStream>
using namespace std;

namespace code_tree {
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
        Node* root=new Node('*',
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
        return new Node('%',0,nullptr,nullptr,nullptr);
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

namespace demo_haffman{
    using namespace code_tree;

    BT* State::captureTreeRec(code_tree::Node* root, code_tree::Node* updated){
        if(root==nullptr)return nullptr;
        return new BT(root->symbol,
                      root->weight,
                      captureTreeRec(root->left,updated),
                      captureTreeRec(root->right,updated),
                      root==updated);
    }

    BT* State::captureTree(code_tree::Node* updated){
        if(updated==nullptr)return nullptr;
        return captureTreeRec(rootOfTree(updated),updated);
    }

    void incrementWeightDemo(Node* n, std::vector<State*> &states, char current, char* code){
        n->weight++;
                            states.push_back(new State(current,code,n));
        if(n->parent==nullptr)return;
        Node* next=n->next;
        if(next==n->parent)next=next->next;
        if(next!=nullptr&&next->weight<n->weight){
            resolve(n);
                            states.push_back(new State(current,code,n));
        }
        incrementWeightDemo(n->parent, states, current, code);
    }

    Node* splitESCSymbolDemo(Node* esc, char symbol, std::vector<State*> &states,  char* code){
        Node* root=new Node('*',
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
        incrementWeightDemo(root, states, symbol, code);
        return root->right;
    }

    void demoEncode(std::vector<State*> &states, char *msg){
        states.clear();
                            states.push_back(new State(0,"",nullptr));
        if(*msg=='\0')return;
        Node* symbols[256]={nullptr};
        Node* esc=initESC();
        unsigned char current;

        int inInd=0;
        int outInd=0;
        unsigned char firstChar=msg[inInd++];
        char code[1000]={0};
        code[outInd++]=firstChar;
        symbols[firstChar]=splitESCSymbolDemo(esc,firstChar,states, code);

        while(msg[inInd]!='\0'){
            current=msg[inInd++];
            if(symbols[current]==nullptr){
                outInd+=bitCode(code,outInd,esc);
                symbols[current]=splitESCSymbolDemo(esc,current,states, code);
                code[outInd++]=current;
            }
            else{
                outInd+=bitCode(code,outInd,symbols[current]);
                incrementWeightDemo(symbols[current], states, current, code);
            }
        }
        destroy(esc);
    }
}

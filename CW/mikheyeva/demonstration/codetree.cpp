
#include"codetree.h"
#include<iostream>
#include<QTextStream>
using namespace std;

    bool isLeft(Node* node){
        return node==node->parent->left;
    }

    bool isRight(Node* node){
        return node==node->parent->right;
    }

    Node* RootOfTree(Node* n){
        while (n->parent!=NULL)n=n->parent;
        return n;
    }

    void destroyRec(Node* n){
        if(n==NULL)return;
        destroyRec(n->left);
        destroyRec(n->right);
        delete n;
    }

    void destroy(Node* n){
        destroyRec(RootOfTree(n));
    }

    void ChangeTree(Node* problem){
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

    void IncrementWeight(Node* n){
        n->weight++;
        if(n->parent==NULL)return;
        Node* next=n->next;
        if(next==n->parent)next=next->next;
        if(next!=NULL&&next->weight<n->weight)ChangeTree(n);
        IncrementWeight(n->parent);
    }

    Node* MakeNewNode(Node* esc, char symbol){
        Node* root=new Node('*',
                            esc->weight,
                            esc->parent,
                            esc,
                            new Node(symbol,1,NULL,NULL,NULL)
                            );
        if(esc->parent!=NULL){
            if(isLeft(esc))root->parent->left=root;
                else root->parent->right=root;
        }
        esc->parent=root;
        root->right->parent=root;

        root->next=esc->next;
        if(root->next!=NULL)root->next->back=root;
        root->back=root->right;
        root->back->next=root;
        esc->next=root->back;
        esc->next->back=esc;

        IncrementWeight(root);
        return root->right;
    }

    int CodeLength(Node* n){
        if(n->parent==NULL)return 0;
        else return 1+CodeLength(n->parent);
    }

    int bitCode(char* code, int offset, Node* symbol){
        int len=CodeLength(symbol);
        for(int i=0;i<len;i++){
            code[offset+len-1-i]=(isLeft(symbol)?'0':'1');
            symbol=symbol->parent;
        }
        return len;
    }

    Node* initESC(){
        return new Node('%',0,NULL,NULL,NULL);
    }

    void encode(istream &in, ostream &code){
        if(in.peek()==EOF)return;
        Node* symbols[256]={NULL};
        Node* esc=initESC();
        unsigned char current;

        unsigned char firstChar=in.get();
        code<<firstChar;
        symbols[firstChar]=MakeNewNode(esc,firstChar);

        while(in.peek()!=EOF){
            current=in.get();
            if(symbols[current]==NULL){
                char bits[256];
                int len=bitCode(bits,0,esc);
                for(int i=0;i<len;i++)code<<bits[i];
                symbols[current]=MakeNewNode(esc,current);
                code<<current;
            }
            else{
                char bits[256];
                int len=bitCode(bits,0,symbols[current]);
                for(int i=0;i<len;i++)code<<bits[i];
                IncrementWeight(symbols[current]);
            }
        }
        destroy(esc);
    }

    Node* SymbolFromCodeStream(Node* root, istream &code){
        while(true){
            if(root->left==NULL)return root;
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
        MakeNewNode(esc,firstSymbol);
        Node* root=esc->parent;
        code<<firstSymbol;

        while(in.peek()!=EOF){
            Node* symbol=SymbolFromCodeStream(root, in);
            if(symbol!=esc){
                code<<symbol->symbol;
                IncrementWeight(symbol);
            }
            else{
                char newSymbol=in.get();
                code<<newSymbol;
                MakeNewNode(esc,newSymbol);
            }
        }

        destroy(esc);
    }


    DemoTree::DemoTree(){esc=initESC();}
    DemoTree::~DemoTree(){destroy(esc);}
    Node* DemoTree::updateTree(unsigned char symbol){
        if(symbols[symbol]==NULL)symbols[symbol]=MakeNewNode(esc,symbol);
        else IncrementWeight(symbols[symbol]);
        return root!=NULL? root:(root=esc->parent);
    }


    void demoEncode(std::vector<State*> &states, char *msg){
        states.clear();
        states.push_back(new State(0,"",NULL));
        if(*msg=='\0')return;
        Node* symbols[256]={NULL};
        Node* esc=initESC();
        unsigned char current;

        int inInd=0;
        int outInd=0;
        unsigned char firstChar=msg[inInd++];
        char code[1000]={0};
        code[outInd++]=firstChar;
        symbols[firstChar]=MakeNewNode(esc,firstChar);
        states.push_back(new State(inInd,code,RootOfTree(esc)));

        while(msg[inInd]!='\0'){
            current=msg[inInd++];
            QTextStream out(stdout);
            out<<(char)current<<endl;
            if(symbols[current]==NULL){
                outInd+=bitCode(code,outInd,esc);
                symbols[current]=MakeNewNode(esc,current);
                code[outInd++]=current;
            }
            else{
                outInd+=bitCode(code,outInd,symbols[current]);
                IncrementWeight(symbols[current]);
            }
            states.push_back(new State(inInd,code,RootOfTree(esc)));
        }
        destroy(esc);
    }


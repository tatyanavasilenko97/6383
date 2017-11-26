
#include"codetree.h"
#include<iostream>
namespace code_tree {
    bool isLeft(Node* node){
        return node==node->parent->left;
    }

    bool isRight(Node* node){
        return node==node->parent->right;
    }

    Node* RootOfTree(Node* n){
        while (n->parent!=nullptr)n=n->parent;
        return n;
    }

    void DestroyRec(Node* n){
        if(n==nullptr)return;
        DestroyRec(n->left);
        DestroyRec(n->right);
        delete n;
    }

    void destroy(Node* n){
        DestroyRec(RootOfTree(n));
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
        if(n->parent==nullptr)return;
        Node* next=n->next;
        if(next==n->parent)next=next->next;
        if(next!=nullptr&&next->weight<n->weight)ChangeTree(n);
        IncrementWeight(n->parent);
    }

    Node* MakeNewNode(Node* esc, char symbol){
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

        IncrementWeight(root);
        return root->right;
    }

    int CodeLength(Node* n){
        if(n->parent==nullptr)return 0;
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
        return new Node('%',0,nullptr,nullptr,nullptr);
    }

    void encode(char *a, std::ostream &code){
        if(a[0]=='\0')return;
        Node* symbols[256]={nullptr};
        Node* esc=initESC();
        unsigned char current;
        unsigned char firstChar=a[0];
        code<<firstChar;
        symbols[firstChar]=MakeNewNode(esc,firstChar);
        int i = 0;
        while(a[i]!='\0'){
            current = a[i];
            if(symbols[current]==nullptr){
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
            i++;
        }
        destroy(esc);
    }

    Node* SymbolFromStream(Node* root,std:: istream &code){
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

    void decode(std::istream &in,std:: ostream &code){
        if(in.peek()==EOF)return;
        Node* esc=initESC();
        unsigned char firstSymbol=in.get();
        MakeNewNode(esc,firstSymbol);
        Node* root=esc->parent;
        code<<firstSymbol;
        while(in.peek()!=EOF){
            Node* symbol=SymbolFromStream(root, in);
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

}

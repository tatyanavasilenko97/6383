#ifndef CODETREE1_CPP
#define CODETREE1_CPP
#include<iostream>
#include "codetree1.h"
#include <climits>
#include <cstring>
bool symbol_less(const Symbol& l, const Symbol& r){
    return l.weight < r.weight;
}
bool symbol_greater(const Symbol& l, const Symbol& r){
    return l.weight > r.weight;
}
CodeTree* make_leaf(const Symbol& s)
{
    return new CodeTree{ "*",s, NULL, NULL, NULL };
}
CodeTree* make_node(int weight, CodeTree* left, CodeTree* right){
    Symbol s{ '*', weight };
    return new CodeTree{ "*", s,NULL, left, right };
}
bool is_leaf(const CodeTree* node){
    return node->left == NULL && node->right == NULL;
}
bool is_root(const CodeTree* node){
    return node->parent == NULL;
}
static void fill_symbols_map(const CodeTree* node, const CodeTree** symbols_map);

char* encode( CodeTree* tree,  char* message)
{

    char* code = new char[MAX_CODE_LEN];
    const CodeTree** symbols_map = new const CodeTree*[UCHAR_MAX];
    for(int i = 0; i < UCHAR_MAX; ++i) {
        symbols_map[i] = NULL;
    }
    fill_symbols_map(tree, symbols_map);
    int len = strlen(message);
    int index = 0;
    char path[MAX_CODE_LEN];
    for(int i = 0; i < len; ++i) {
        const CodeTree* node = symbols_map[message[i] - CHAR_MIN];
        int j = 0;
        while(!is_root(node)) {
            if(node->parent->left == node)
                path[j++] = '0';
            else
                path[j++] = '1';
            node = node->parent;
        }
       //path[j++] = message[i];
        while(j > 0)
            code[index++] = path[--j];
    }
    code[index] = 0;
    delete [] symbols_map;
    return code;
}
char* decode(const CodeTree* tree, const char* code){
    char* message = new char[MAX_CODE_LEN];
    int index = 0;
    int len = strlen(code);
    const CodeTree* v = tree;
    for(int i = 0; i < len; ++i) {
        if(code[i] == '0')
            v = v->left;
        else
            v = v->right;
        if(is_leaf(v)) {
            message[index++] = v->s.c;
            v = tree;
        }
    }
    return message;
}
void destroy(CodeTree* tree){
    if(tree == NULL) return;
    destroy(tree->left);
    destroy(tree->right);
    delete tree;
    tree = NULL;
}
void fill_symbols_map(const CodeTree* node, const CodeTree** symbols_map){
    if(is_leaf(node))
        symbols_map[node->s.c - CHAR_MIN] = node;
    else {
        fill_symbols_map(node->left, symbols_map);
        fill_symbols_map(node->right, symbols_map);
    }
}



#endif // CODETREE_CPP


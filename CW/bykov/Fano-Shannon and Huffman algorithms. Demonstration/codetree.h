#pragma once

// Структуры: символ, Кодовое дерево, Trees - для создания бинарного дерева

#include "binarytree.h"
#define MAX_CODE_LEN 1000000

struct Symbol
{
    char c;
    int weight;
};

bool symbol_less(const Symbol& l, const Symbol& r);
bool symbol_greater(const Symbol& l, const Symbol& r);

struct CodeTree
{
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
char* encode(CodeTree* tree, char* message);
char* decode(const CodeTree* tree, char* code);
void destroy(CodeTree* tree);

struct Trees
{
    BinaryTree* root = NULL;
    CodeTree *tree;
    int weight;
    char symbol;
    Trees(CodeTree *tree, int weight, char symbol);
    ~Trees();
    BinaryTree* makeBinaryTree(CodeTree* root);
};

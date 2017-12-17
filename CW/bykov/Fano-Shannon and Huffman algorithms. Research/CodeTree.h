#pragma once

#include <iostream>

#define MAX_INPUT_LEN 10000000
#define MAX_CODE_LEN  1000000000

struct Symbol
{
	char c;
    long long int weight;
};
bool symbol_less(const Symbol& l, const Symbol& r);
bool symbol_greater(const Symbol& l, const Symbol& r);
struct CodeTree
{
	Symbol s;
	CodeTree* parent;
	CodeTree* left;
	CodeTree* right;
};
CodeTree* make_leaf(const Symbol& s);
CodeTree* make_node(long long int weight, CodeTree* left, CodeTree* right);
bool is_null(const CodeTree* node);
bool is_leaf(const CodeTree* node);
bool is_root(const CodeTree* node);
char* encode(const CodeTree* tree, const char* message);
char* decode(const CodeTree* tree, const char* code);
void destroy(CodeTree* tree);
void print_tree(CodeTree* tree, long long int level, std::ostream& out);

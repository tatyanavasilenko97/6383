#include "binarytree.h"

BinaryTree::BinaryTree(char symbol, long long int weight, BinaryTree* left, BinaryTree* right)
{
    this->symbol = symbol;
    this->weight = weight;
    this->left = left;
    this->right = right;
}

BinaryTree::~BinaryTree()
{
    if(left != NULL)
        delete left;
    if(right != NULL)
        delete right;
}


#pragma once

// Описание структуры Бинарное дерево

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cmath>

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextStream>

struct BinaryTree
{
    char symbol;
    long long int weight;
    BinaryTree* left = NULL;
    BinaryTree* right = NULL;
    BinaryTree(char symbol, long long int weight, BinaryTree* left, BinaryTree* right);
    ~BinaryTree();
};


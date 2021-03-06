#include "haffman.h"
#include "priority_queue.h"
#include <functional>
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <QTextStream>
#include <cstring>
#include <stdlib.h>
#include <codetree.h>
#include "codetree1.h"
CodeTree* haffman(const Symbol* symbols, int len){

    PriorityQueue<CodeTree*>* queue = create_pq<CodeTree*>(len);
    for(int i = 0; i < len; ++i)
        push(queue, symbols[i].weight, make_leaf(symbols[i]));
    while(size(queue) > 1) {

        CodeTree* ltree = pop(queue);
        CodeTree* rtree = pop(queue);
        int weight = ltree->s.weight + rtree->s.weight;
        CodeTree* node = make_node(weight, ltree, rtree);
        ltree->parent = node;
        rtree->parent = node;
        push(queue, weight, node);
    }
    CodeTree* result = pop(queue);
    destroy_pq(queue);
   return result;
}

CodeTree* haffman(char* message) {
    if (*message == '\0') return 0;
    Symbol symbols[UCHAR_MAX];
    for(int i = 0; i < UCHAR_MAX; ++i) {
        symbols[i].c = i + CHAR_MIN;

        symbols[i].weight = 0;
    }
    int size = strlen(message);
    for(int i = 0; i < size; ++i)
        symbols[message[i] - CHAR_MIN].weight++;
    std::sort(symbols, symbols + UCHAR_MAX, symbol_greater);
    int len = 0;
    while(symbols[len].weight > 0 && len < UCHAR_MAX) len++;
    return haffman(symbols, len);
}

CodeTree* haffman1( char* message) {
    QTextStream out(stdout);
    out << "1";
}
typedef CodeTree * Codeptr;
CodeTree *haffman_demo(std::vector<Trees*> &trees, const Symbol* symbols, int len){

    PriorityQueue<CodeTree*>* queue = create_pq<CodeTree*>(len);
    for(int i = 0; i < len; ++i)
        push(queue, symbols[i].weight, make_leaf(symbols[i]));
    while(size(queue) > 1) {
        Codeptr tmp[size(queue)];
        CodeTree *tree;
        int k = size(queue);
        while (size(queue) > 0){
            tree = pop(queue);
            trees.push_back(new Trees(tree,tree->s.weight,tree->s.c));
            tmp[size(queue)] = tree;
        }
        for (int i = 0;i<k;i++){
            push(queue, tmp[i]->s.weight, tmp[i]);
        }
        CodeTree* ltree = pop(queue);
        CodeTree* rtree = pop(queue);
        int weight = ltree->s.weight + rtree->s.weight;
        CodeTree* node = make_node(weight, ltree, rtree);
        ltree->parent = node;
        rtree->parent = node;
        push(queue, weight, node);
}

    CodeTree* result = pop(queue);
    trees.push_back(new Trees(result,result->s.weight,result->s.c));
    destroy_pq(queue);
   return result;

}
CodeTree* haffman_demo(std::vector<Trees*> &trees, char* message) {
    if (*message == '\0') return 0;
    trees.clear();
    trees.push_back(new Trees(NULL,0,'*'));
    if (*message == '\0') return 0;
    Symbol symbols[UCHAR_MAX];
    for(int i = 0; i < UCHAR_MAX; ++i) {
        symbols[i].c = i + CHAR_MIN;

        symbols[i].weight = 0;
    }
    int size = strlen(message);
    for(int i = 0; i < size; ++i)
        symbols[message[i] - CHAR_MIN].weight++;
    std::sort(symbols, symbols + UCHAR_MAX, symbol_greater);
    int len = 0;
    while(symbols[len].weight > 0 && len < UCHAR_MAX) len++;
    return haffman_demo(trees,symbols, len);
}



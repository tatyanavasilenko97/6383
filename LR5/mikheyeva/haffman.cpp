#include "haffman.h"
#include "priority_queue.h"
#include <functional>
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
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

CodeTree* haffman(const char* message) {
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

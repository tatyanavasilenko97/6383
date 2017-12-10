#ifndef HAFFMAN_H
#define HAFFMAN_H

#include "codetree1.h"
#include <QChar>
#include <vector>
CodeTree* haffman(/*const*/ char* message);
CodeTree* haffman(/*const*/ char* keys, const int* w, int len);
CodeTree* haffman1(/*const*/ char* message);
CodeTree* haffman_demo(std::vector<Trees*> &trees, char* message);
CodeTree *haffman_demo(std::vector<Trees*> &trees, const Symbol* symbols, int len);
#endif // HAFFMAN_H

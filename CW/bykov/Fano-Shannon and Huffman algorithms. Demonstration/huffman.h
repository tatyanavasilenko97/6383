#pragma once

// Запись в дерево строки по алгоритму Хаффмана

#include "codetree.h"

CodeTree* huffman(std::vector<Trees*> &trees, char* message);
CodeTree* huffman(std::vector<Trees*> &trees, const Symbol* symbols, int len);

#pragma once

// Запись в дерево строки по алгоритму Фано - Шеннона

#include "codetree.h"

CodeTree* fanno_shannon(std::vector<Trees*> &trees, char* message);
CodeTree* fanno_shannon(std::vector<Trees*> &trees, const Symbol* symbols, long long int len);

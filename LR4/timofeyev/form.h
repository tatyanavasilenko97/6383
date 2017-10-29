//
// Лабораторная работа №4
// form.h
// Тимофеев Дмитрий, группа 6383
// 19.10.17
//
// Программирование алгоритмов с бинарными деревьями

#ifndef FORM_H
#define FORM_H

#include "btree.h"
#include <iostream>
using namespace binTree_modul;

namespace form_modul{
    typedef binTree Form;
    Form readForm(std::istream &in);
    void writeForm(std::ostream &out, const Form f);
    Form deriviate(const Form f, char var);
}

#endif // FORM_H

#ifndef TREAP_H
#define TREAP_H

#include "treap.cpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"

template <class T>
struct treap;

template <class T>
  void split(treap<T>*,T ,treap<T>*&,treap<T>*&);

template <class T>
void insertElInTreap(treap<T>*&,treap<T>*);


template <class T>
void QPrintTreap(treap<T>*,int,bool,QString&);

template <class T>
bool isExistInTreap(treap<T>*,treap<T>*);

template <class T>
void isExistInTreapXorY(treap<T>*,treap<T>*,bool&);

template <class T>
void merge(treap<T>*&,treap<T>*,treap<T>*);

template <class T>
void deleteTreapEl(treap<T>*& , T);

#endif // TREAP_H

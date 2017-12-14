#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <fstream>

typedef unsigned int unInt;
using namespace std ;

namespace binTree_modul
{

//-------------------------------------
	typedef char base;

	struct node {
		base info;
		node *lt;
		node *rt;
			// constructor
			node () {lt = NULL; rt = NULL;}
	};

	typedef node *binTree;

	binTree Create(void);
	bool isNull(binTree);
	base RootBT (binTree);
	binTree Left (binTree);
	binTree Right (binTree);
	binTree ConsBT(const base &x, binTree &lst,  binTree &rst);
	void destroy (binTree&);
    binTree enterBT (std::istream &infile);
    void outBT(binTree b);
    void displayBT (binTree b, int n);
    unInt hBT (binTree b);
    unInt sizeBT (binTree b);
    void printKLP (binTree b);
    int count(binTree b, base x);
} // end of namespace binTree_modul

#endif // BTREE_H_INCLUDED

#include "lisp_list.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void create_list(const lisp x, int & n, elem& h, elem& ah) {
	if (n == 1) {
		ah = new List;
		ah->atom = x->node.atom;
		h = ah;
	}
	else {
		ah->next = new List;
		if (n == 2)
			h = ah;
		ah = ah->next;
		ah->atom = x->node.atom;
	}
}

void destroy_lin(elem b)
{
	elem help;

	while (b != NULL)
	{
		help = b->next;
		delete b;
		b = help;
	}
	delete b;
}
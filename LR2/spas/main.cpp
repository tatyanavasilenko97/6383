#include <iostream>
#include <fstream>
#include "l_intrfc.h"


using namespace h_list;
using namespace std;
lisp delet(lisp l, base x);

int main()
{
	lisp l = nullptr;
	base x;
	cout << "Enter an element you want to delete" << endl;
	cin >> x;
	cout << "Enter a list" << endl;
	read_lisp(l);
	cout << "Input list:" << endl;
	write_lisp(l);
	cout << endl;
	cout << "Output list:" << endl; 
	l = delet(l, x);
	write_lisp(l);
	cout << endl;
	destroy(l);
	system("pause");
}

lisp delet(lisp l, base x)
{
	if (isNull(l)) return nullptr;
	if (isAtom(l))
	{
		if (getAtom(l) != x) return l;
		else
		{
			delete l;
			return nullptr;
		}
	}

	l->node.pair.hd = delet(head(l), x);
	l->node.pair.tl = delet(tail(l), x);

	return ((head(l) == nullptr) ? tail(l) : l);
}
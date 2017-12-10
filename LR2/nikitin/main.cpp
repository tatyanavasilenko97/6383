#include <iostream>
#include <fstream>
#include "l_intrfc.h"


using namespace h_list;
using namespace std;

bool found(const base &x, const lisp l);


int main()
{
	lisp l;
	base x;
    cout << "Ener an element you want to search" << endl;
	cin >> x;
    cout << "Enter a list" << endl;
	read_lisp (l);
	cout << "Input list:" << endl;
	write_lisp(l);
	cout << endl;
	if (found(x, l) )
		cout << x  <<" is existing\n";
	else
		cout << x << " is not existing \n";
    destroy(l);
}



bool found(const base &x, const lisp l)
{
    if (isNull(l)) return false;
	if( isAtom(l) )
		if (l->node.atom == x) return true;
		else return false;

	if( found(x, l->node.pair.hd) ) return true;

	if( found(x, l->node.pair.tl) ) return true;


	return false;
}

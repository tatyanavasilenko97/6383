#include <iostream>
#include <fstream>
using namespace std;


typedef double Elem;

class BTS
{
public:
	BTS( Elem x);
	~BTS();

	void Display(int n = 1);
	bool Find_Add (Elem &x);

private:
	Elem key;
	BTS *left;
	BTS *right;
};
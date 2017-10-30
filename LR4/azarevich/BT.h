#include <iostream>
#include <fstream>

typedef char Elem;

void GLOBAL_ERRORS(int n = -1);


class BT
{
public:
	BT(std::ifstream &in);
	~BT();

	void Display(int n);
	bool Found(Elem const &x);

private:
	BT *left;
	BT *right;
	Elem cell;
	
	bool isNull(BT *t);
	void Enter(std::ifstream &in);
};
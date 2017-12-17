#include "BT.h"

BT::BT(std::ifstream &in)
{
	Enter(in);
}

void BT::Enter(std::ifstream &in)
{
	Elem x;
	if(in.eof())
		GLOBAL_ERRORS(0);

	in >> x;
	cell = x;
	
	if (in.peek() != '/' )
		left = new BT(in);
	else
	{
		left = NULL;
		in.get();
	}

	if (in.peek() != '/' )
		right= new BT(in);
	else
	{
		right = NULL;
		in.get();
	}
}


BT::~BT()
{
	if( !isNull(left) )
		delete left;

	if( !isNull(right) )
		delete right;
}

bool BT::isNull(BT *t)
{
	return (t == NULL);
}


void BT::Display(int n)
{
	std::cout << ' ' << cell;
	if( !(right == NULL ) ) 
		right->Display(n+1);
	else 
		std::cout << std::endl; // вниз

	if( !(left == NULL) ) 
	{
		for (int i=1;i<=n;i++) 
			std::cout << "  "; // вправо

		left->Display(n+1); 
	}
}


bool BT::Found(Elem const &x)
{
	if( cell == x ) return true;

	if( !isNull(left) ) 
		if( left->Found(x) ) return true;

	if( !isNull(right) )
		if( right->Found(x) ) return true;

	return false;
}
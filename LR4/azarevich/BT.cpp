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
		left->~BT();

	if( !isNull(right) )
		right->~BT();
}

bool BT::isNull(BT *t)
{
	return (t == NULL);
}


void BT::Display(int n)
{
	for(int i=1; i<=n; i++)
		std::cout <<" ";

	std::cout << "-" << cell << std::endl;
	
	if( !isNull(left) )
		left->Display(n+1);
	
	if( !isNull(right) )
		right->Display(n+1);
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
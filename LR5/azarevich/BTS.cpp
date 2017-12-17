#include "BTS.h"


BTS::BTS( Elem x )
{
	key = x;
	left = right = NULL;
}


BTS::~BTS()
{
	if (left != NULL)
		delete left;
	
	if (right != NULL)
		delete right;
}


void BTS::Display(int n)
{
	cout << ' ' << key;
	if( !(right == NULL ) ) 
		right->Display(n+1);
	else 
		cout << endl; // вниз

	if( !(left == NULL) ) 
	{
		for (int i=1;i<=n;i++) 
			cout << "  "; // вправо

		left->Display(n+1); 
	}
}


bool BTS::Find_Add (Elem &x)
{
	if ( key > x)
	{
		if ( left == NULL )
		{
			left = new BTS(x);
			return false;
		}
		return left->Find_Add(x);
	}

	if ( key < x)
	{
		if ( right == NULL )
		{
			right = new BTS(x);
			return false;
		}
		return right->Find_Add(x);
	}

	if ( key == x )
		return true;
}
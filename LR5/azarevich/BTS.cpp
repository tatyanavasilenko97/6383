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


void Q(int n)
{
	for(int i=1; i<=n; i++)
		cout <<"   ";
	cout << "_";
}


void BTS::Display(int n)
{
	Q(n);

	cout << key << endl;
	
	if( left != NULL )
		left->Display(n+1);
	else 
		if ( right != NULL )
		{
			Q(n+1);
			cout << endl;
		}
	
	if( right != NULL  )
		right->Display(n+1);
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
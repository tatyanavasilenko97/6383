// Implementation  － Реализация АТД "Бинарное дерево" (в процедурно-модульной парадигме)
#include "BTree.h"

namespace binTree_modul
{

//-------------------------------------
	binTree Create()
	{	return NULL;
	}
//-------------------------------------
	bool isNull(binTree b)
	{	return (b == NULL);
	}
//-------------------------------------
	base RootBT (binTree b)			// для непустого бин.дерева
	{	if (b == NULL) { cerr << "Error: RootBT(null) \n"; exit(1); }
		else return b->info;
	}
//-------------------------------------
	binTree Left (binTree b)		// для непустого бин.дерева
	{	if (b == NULL) { cerr << "Error: Left(null) \n"; exit(1); }
		else return b ->lt;
	}
//-------------------------------------
	binTree Right (binTree b)		// для непустого бин.дерева
	{	if (b == NULL) { cerr << "Error: Right(null) \n"; exit(1); }
		else return b->rt;
	}
//-------------------------------------
	binTree ConsBT(const base &x, binTree &lst,  binTree &rst)
	{	binTree p;
		p = new node;
		if ( p != NULL)	{
			p ->info = x;
			p ->lt = lst;
			p ->rt = rst;
			return p;
		}
		else {cerr << "Memory not enough\n"; exit(1);}
	}
//-------------------------------------
	void destroy (binTree &b)
	{	if (b != NULL)	{
			destroy (b->lt);
			destroy (b->rt);
			delete b;
			b = NULL;
		}
	}

//---------------------------------------
	binTree enterBT (istream &infile)
	{
		if (infile.eof())
		{
			cerr << "Error!\n";
			exit(1);
		}
		char ch;
		binTree p, q;
		infile.get(ch);
			if (ch=='/') return NULL;
			else 
			{
				p = enterBT(infile); 
				q = enterBT(infile); 
				return ConsBT(ch, p, q);
			}
	}
//---------------------------------------
	void outBT(binTree b)
	{
		if (b!=NULL) {
			cout << RootBT(b);
			outBT(Left(b));
			outBT(Right(b));
		}
		else cout << '/';
	}
//---------------------------------------
	void displayBT (binTree b, int n)
	{
		for (int i = 1; i <=  n; i++)
				cout << "    ";
		cout << "-" << RootBT(b) << endl;
		if (!isNull(Left(b)))
				displayBT(Left(b), n + 1);
		if (!isNull(Right(b)))
				displayBT(Right(b), n + 1);
	/*	if (b!=NULL) {
			cout << ' ' << RootBT(b);
			if(!isNull(Right(b))) {displayBT (Right(b),n+1);}
			else cout << endl; // вниз
			if(!isNull(Left(b))) {
				for (int i=1;i<=n;i++) cout << "  "; // вправо
				displayBT (Left(b),n+1);}
		}*/
	//	else {};
	}
    //---------------------------------------
	unInt hBT (binTree b)
	{
		if (isNull(b)) return 0;
		else return max (hBT (Left(b)), hBT(Right(b))) + 1;
	}
    //---------------------------------------
	unInt sizeBT (binTree b)
	{
		if (isNull(b)) return 0;
		else return sizeBT (Left(b))+ sizeBT(Right(b)) + 1;
	}
    //---------------------------------------
	void printKLP (binTree b)
	{
	    	if (!isNull(b)) {
			cout << RootBT(b);
			printKLP (Left(b));
			printKLP (Right(b));
		}
	}
    //---------------------------------------
	int count(binTree b, base x)
	{
		int cnt = 0;
        if(!isNull(b))
        {
            if (RootBT(b) == x)
                cnt++;
            cnt = cnt + count(Left(b), x) + count(Right(b), x);
        }
		return cnt;
	}
    //---------------------------------------
	/*int path_length(binTree b, base x)
	{
	   int cnt = 0;
	   binTree p = b;
	   while(p)
       {
           cnt++;
           if (RootBT(p) > x)
                p = Right(p);
           else if (RootBT(p) < x) p = Left(p);
           else return cnt;
       }
       return cnt;
	}*/

} // end of namespace h_list

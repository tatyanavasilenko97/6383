#include "b_k.h"


b_k::b_k()
{
	save = (ull **)malloc(sizeof(ull *) );
	Nmax = 2;

	save[0] = (ull *)malloc(sizeof(ull) );
	save[0][0] = 2;
}

b_k::~b_k()
{
	for (ui i=0; i < Nmax-1; i++)
		free(save[i]);

	free(save);
}


void b_k::more(ui n)
{
	//n++;

	save = (ull **)realloc(save, (n-1)*sizeof(ull *) );

	for (ui i=Nmax-1; i<(n-1); i++)
	{
		save[i] = (ull *)calloc(n-1, sizeof(ull) );

		//save[i][0] = save[i][i] = 1;
	}
	Nmax = n;

//	std::cout << save<<std::endl;
}


ull b_k::binom(ui m, ui n)
{
	isOverFlow = true;

	if ( (!m) || (m==n) ) return 1;



	if ( !save[n-2][m-1] )
	{
		save[n-2][m-1]= binom(m-1, n-1);
		if(!isOverFlow)
			return 1;
		ull c = binom(m, n-1);

		if ( (ULLONG_MAX - c < save[n-2][m-1]) || (!isOverFlow) )
		{
			isOverFlow = false;
			save[n-2][m-1] = 1;
			return 1;
		}
		save[n-2][m-1]+= c;
		return save[n-2][m-1];
	}
	
	if ( save[n-2][m-1]==1 )
		isOverFlow = false;

	return save[n-2][m-1];
}
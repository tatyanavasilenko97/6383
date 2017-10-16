#include "b_k.h"


Binomial::Binomial()
{
	save = (ull **)malloc(sizeof(ull *) );
	Nmax = 2;

	save[0] = (ull *)malloc(sizeof(ull) );
	save[0][0] = 2;
}


Binomial::~Binomial()
{
	for (ui i=0; i < Nmax-1; i++)
		free(save[i]);

	free(save);
}


void Binomial::more(ui n)
{
	save = (ull **)realloc(save, (n-1)*sizeof(ull *) );
	if (!save)
	{
		std::cerr << "Ошибка: память не была выделена\n";
		system ("pause");
		exit(1);
	}

	for (ui i=Nmax-1; i<(n-1); i++)
	{
		save[i] = (ull *)calloc(i+1, sizeof(ull) );

		if (!save[i])
		{
			std::cerr << "Ошибка: память не была выделена\n";
			system ("pause");
			exit(1);
		}
	}
	Nmax = n;
}


ull Binomial::binom(ui m, ui n)
{
	if ( (!m) || (m==n) ) return 1;
	if ( !save[n-2][m-1] )
	{
		save[n-2][m-1]= binom(m-1, n-1);
		if(!NotOverFlow)
			return 1;
		ull c = binom(m, n-1);

		if ( (ULLONG_MAX - c < save[n-2][m-1]) || (!NotOverFlow) )
		{
			NotOverFlow = false;
			save[n-2][m-1] = 1;
			return 1;
		}
		save[n-2][m-1] += c;
		return save[n-2][m-1];
	}
	
	if ( save[n-2][m-1]==1 )
		NotOverFlow = false;

	return save[n-2][m-1];
}


bool Binomial::colculate(ui &m, ui &n, ull &res)
{
	NotOverFlow = true;

	if ( m > n ) 
	{
		res = 0;
		return NotOverFlow;
	}

	if (n >= Nmax) more(n);

	res = binom(m, n);

	return NotOverFlow;
}
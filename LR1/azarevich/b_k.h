#include <iostream>
#include <fstream>
//#include <stdin.h>
//данного файла нет в VS2008

typedef unsigned long long ull;
typedef unsigned int ui;

class Binomial
{
public:
	Binomial();
	~Binomial();
	bool colculate(ui &m, ui &n, ull &res);

private:
	ull **save;		 //хранение выч-ных бин. коэф.
	bool NotOverFlow;//флаг переполнения
	ui Nmax;		 //макc. встретившееся n	

	void more(ui n);
	ull binom(ui m, ui n);
};
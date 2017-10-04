#include <iostream>
#include <fstream>

typedef unsigned long long ull;
typedef unsigned int ui;

class b_k
{
private:
	ull **save;		//хранение выч-ных бин. коэф.

public:
	bool isOverFlow;//флаг переполнения
	ui Nmax;		//макc. встретившееся n

	b_k();
	~b_k();

	void more(ui n);
	ull binom(ui m, ui n);
};
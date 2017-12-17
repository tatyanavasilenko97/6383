
#pragma once
#include <iomanip>

using namespace std;

struct Formula;
struct Formula1 {
	Formula* f1;
	Formula* f2;
	char znak;
};
struct  Formula {
	int tag;
	union {
		union {
			int num;
			char let;
		}term;
		Formula1 form1;
	}form;
};

void read_three(Formula*& s, char& x);
void read_form(Formula*& s, char& x);
void build(Formula*& s, int& depth, bool close[]);
void print(Formula*& s);
void calculate(Formula*& s, int& res, bool& k);
void ErrorMessege();
void Error(int& w);
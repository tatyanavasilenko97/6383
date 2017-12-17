#include <iostream>
#include <cstdlib>
#include "stek_inter.h"
using namespace std;

namespace st_modul
{
	struct Stack::node {
		char *hd;
		node *tl;
		node(char *inphd = nullptr, node* inptl = nullptr) :hd(inphd), tl(inptl) {};
	};
	char Stack::top(void){
		if (top_stak == nullptr) { return 0; }
		else return *top_stak->hd;
	}
	void Stack::pop(void){
		if (top_stak == nullptr) { cerr << "Error: pop(null) \n"; exit(1); }
		else{
			node *oldTop = top_stak;
			top_stak = top_stak->tl;
			delete oldTop->hd;
			delete oldTop;
		}
	}
	char Stack::pop2(void){
		if (top_stak == nullptr) { cerr << "Error: pop(null) \n"; exit(1); }
		else{
			node *oldTop = top_stak;
			char r = *top_stak->hd;
			top_stak = top_stak->tl;
			delete oldTop->hd;
			delete oldTop;
			return r;
		}
	}
	void Stack::push(const char &x)
	{
		node *p;
		p = top_stak;
		top_stak = new node;
		if (top_stak != nullptr) {
			top_stak->hd = new char;
			*top_stak->hd = x;		
			top_stak->tl = p;
		}
		else { cerr << "Memory not enough\n"; exit(1); }
	}
	bool Stack::isNull(void){
		return (top_stak == nullptr);
	}
	void Stack::destroy(void){
		while (top_stak != nullptr) {
			pop();
		}
	}
}

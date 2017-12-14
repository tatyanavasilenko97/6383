

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
int N;

typedef string base; // базовый тип элементов (атомов)

struct s_expr;
struct two_ptr{
	s_expr *hd;
	s_expr *tl;
} ;

struct s_expr{

	bool tag; // true: atom, false: pair

	base atom;

	two_ptr pair;

};

typedef s_expr *list;

int i=0;
string line;
list concat (const list y, const list z);
list rev(const list s,const list z);
list flatten(const list s);
list copy_lisp (const list x);
base getAtom (const list s);
void read_lisp ( list& y);
void read1 (base prev, list& y);
void read2 ( list& y);
void write_list (const list x);
void write1 (const list x);

void errors (int num);
bool isAtom (const list s){
	if(s == NULL) return false;
	else return (s -> tag);
}

bool isNull (const list s)

	{ return s==NULL;}

list head (const list s)

{

	if (s != NULL)

	if (!isAtom(s)) return s->pair.hd;

	else { errors(1); exit(1);}

	else { errors(2); exit(1);}

}

list tail (const list s){

	if (s != NULL)

	if (!isAtom(s)) return s->pair.tl;

	else { errors(3); exit(1); }

	else { errors(4);exit(1);}

}

list cons (const list h, const list t){

	list p;

	if (isAtom(t)) {errors(6); exit(1);}

	else { p = new s_expr;

	if ( p == NULL) {errors(5); exit(1); }

	else {

	p->tag = false;

	p->pair.hd = h;

	p->pair.tl = t;

	return p;}

}

}

list make_atom (const base x){

	list s;

	s = new s_expr;

	s -> tag = true;

	s->atom = x;

return s;

}

void destroy (list s){

	if ( s != NULL){

		if (!isAtom(s)){

			destroy ( head (s));

			destroy ( tail(s));

		}

	delete s;

	};

}

void read_list ( list& y)
{

base x;

do {

	if(line[i]==' '||line[i]=='('||line[i]==')'||line[i]=='\0')x+=line[i++];

	else

		while(isalpha(line[i]))x+=line[i++];

}

while (x==" ");

i--;

read1( x, y);

}

void read1 (base prev, list& y){

	if ( prev == ")" ) {errors(7); exit(1); }

	else if ( prev != "(" ) y = make_atom (prev);

	else read2 (y);

}

void read2 ( list& y){

	base x;

	list p1, p2;

	i++;

	if(line[i]==' '||line[i]=='('||line[i]==')'||line[i]=='\0')

		x+=line[i++];

	else

		while(isalpha(line[i]))x+=line[i++];

	i--;

	if (x=="\0") {errors(8); exit(1);}

	else {

		while ( x==" "){

			i++;

	if(line[i]==' '||line[i]=='('||line[i]==')'||line[i]=='\0')

		x+=line[i++];

	else

		while(isalpha(line[i]))x+=line[i++];

	i--;

};

if ( x == ")" ) y = NULL;

else {

	read1 ( x, p1);

read2 ( p2);

y = cons (p1, p2);

}

}

}

void write_list (const list x)

{

if (isNull(x)) cout << " ()"; //пустой список

else if (isAtom(x)) cout << ' ' << x->atom; //атом

else { //непустой список

cout << " (" ;

write1(x);

cout << " )";

}

}

void write1 (const list x)

{/*выводит последовательность элементов списка без обрамляющих его скобок */

	if (!isNull(x)) {

	write_list(head (x));

	write1(tail (x));

}

}

int count (const list x);

void count2 (const list x);

int count (const list x){

	if (isAtom(x)) N++;

	else if (!isNull(x)) {count2(x);}

	return N;

}

void count2 (const list x){

if (!isNull(x)){

	count(head (x));

	count2(tail (x));

}

}

int main(){

	list hlist;

	getline(cin, line);

	N=0;

	read_list(hlist);

	if(line[i+2]!='\0'){

		cout << "error";

	return 0;
}

	cerr << "\n Hierarchical List";

	write_list(hlist);

	cerr << "\n atoms: ";

	cout << ' ' << count(hlist);

	list newhlist;

	newhlist = flatten(hlist);

	cerr << "\n Line list: ";

	write_list(newhlist);

	destroy(hlist);

	destroy(newhlist);

	return 0;

}

list concat (const list y, const list z){

	if (isNull(y)) return copy_lisp(z);

	else return cons (copy_lisp(head (y)), concat (tail (y), z));

}

list flatten(const list s){

	if (isNull(s)) return NULL;

	else if(isAtom(s)) return cons(make_atom(getAtom(s)),NULL);

	else //s － непустой список

	if (isAtom(head(s))) return cons( make_atom(getAtom(head(s))),flatten(tail(s)));

	else

	return concat(flatten(head(s)),flatten(tail(s)));

}

list copy_lisp (const list x){
	 if (isNull(x)) return NULL;

	else if (isAtom(x)) return make_atom (x->atom);

	else return cons (copy_lisp (head (x)), copy_lisp (tail(x)));

}

base getAtom (const list s){

	return (s->atom);

}

void errors (int num)

{

switch (num) {

case 1:

	cerr << "Error: Head is atom \n";

break;

case 2:

	cerr << "Error: Head is NILL \n";

break;

case 3:

	cerr << "Error: Tail is atom \n";

break;

case 4:

	cerr << "Error: Tail(nil) \n";

		break;

case 5:

		cerr << "Error: Problems with memory\n";

break;

case 6:

	cerr << "Error: in function cons:element is atom) \n";

	break;

case 7:

	cerr << "Error: The list can't begin with ')' " << endl;

break;

case 8:

		cerr << "Error: missing simbol ')' " << endl;

break;

}

}
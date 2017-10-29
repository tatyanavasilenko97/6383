#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <fstream>

using namespace std;

namespace h_list
{
	typedef char base;	// ������� ��� ��������� (������)

	struct s_expr;
	struct  two_ptr
		{
		s_expr *hd;
		s_expr *tl;
	} ;	//end two_ptr;

	struct s_expr {
		bool tag; // true: atom, false: pair
		union
			{
			base atom;
			two_ptr pair;
		} node;		//end union node
	};			//end s_expr

	typedef s_expr *lisp;

// �������
	void print_s_expr( lisp s );
	// ������� �������:
	lisp head (const lisp s);
	lisp tail (const lisp s);
	lisp cons (const lisp h, const lisp t);
	lisp make_atom (const base x);
	bool isAtom (const lisp s);
	bool isNull (const lisp s);
	void destroy (lisp s);

	base getAtom (const lisp s);

	// ������� �����:
	void read_lisp ( lisp& y, istream& in);			// ��������
	void read_s_expr (base prev, lisp& y, istream& in);
	void read_seq ( lisp& y, istream& in);

	// ������� ������:
	void write_lisp (const lisp x, ostream& out);		// ��������
	void write_seq (const lisp x, ostream& out);

	lisp copy_lisp (const lisp x);

} // end of namespace h_list



#endif // LIST_H_INCLUDED

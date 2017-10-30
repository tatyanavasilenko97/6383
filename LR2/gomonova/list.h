typedef char base;	// ������� ��� ��������� (������)

struct s_expr;
struct  two_ptr
{
	s_expr *hd;
	s_expr *tl;
};

struct s_expr {
	bool tag; // true: atom, false: pair
	union
	{
		base atom;
		two_ptr pair;
	} node;
};

typedef s_expr *lisp;

// ������� �������:
lisp head(const lisp s);
lisp tail(const lisp s);
lisp cons(const lisp h, const lisp t);
lisp make_atom(const base x);
bool isAtom(const lisp s);
bool isNull(const lisp s);
void destroy(lisp s);

base getAtom(const lisp s);

// ������� �����:
void read_lisp(lisp& y);			// ��������
void read_s_expr(base prev, lisp& y);
void read_seq(lisp& y);

// ������� ������:
void write_lisp(const lisp x);		// ��������
void write_seq(const lisp x);

lisp copy_lisp(const lisp x);
lisp concat(const lisp y, const lisp z);
void tab(int n);					// �������, ������� ��������� ���������� ������� ��������

lisp rev(const lisp s, const lisp z, int n = 0); // ����������� ������


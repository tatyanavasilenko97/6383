#ifndef LISP_H
#define LISP_H

enum TAG {
    ATOM,
    PAIR
};

typedef char base;
struct s_expr;
struct  two_ptr{
    s_expr *hd;
    s_expr *tl;
};

struct s_expr {
    TAG tag;
    union{
        base atom;
        two_ptr pair;
    } node;
};

typedef s_expr *lisp;

void print_s_expr( lisp s );
lisp head (const lisp s);
lisp tail (const lisp s);
lisp cons (const lisp h, const lisp t);
lisp make_atom (const base x);
bool is_atom (const lisp s);
bool is_null (const lisp s);
void destroy (lisp s);
base get_atom (const lisp s);
void read_lisp ( lisp& y);
void read_s_expr (base prev, lisp& y);
void read_seq ( lisp& y);
void write_lisp (const lisp x);
void write_seq (const lisp x);

#endif //

#include "list.h"

lisp reverse(const lisp s);
lisp rev(const lisp s, const lisp z);

int main()
{
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы


	lisp s1, s2;
	cout << boolalpha;
	cout << "введите list1:" << endl;
	read_lisp(s1);
	cout << "введен list1: " << endl;
	write_lisp(s1);
	cout << endl;

	s2 = reverse(s1);
	cout << "обращенный список есть:" << endl;
	write_lisp(s2);	cout << endl;


	cout << "end! " << endl;
	system("pause");
 	return 0;
}
//...........................

  // -----------------------
lisp reverse(const lisp s)
{
	return(rev(s, NULL));
}
//........................
lisp rev(const lisp s, const lisp z)
{
	if (isNull(s)) return(z);
	else if (isAtom(head(s))) return(rev(tail(s), cons(head(s), z)));
	else return(rev(tail(s), cons(rev(head(s), NULL), z)));
}
//........................

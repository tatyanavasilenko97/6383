#include "list.h"

namespace h_list
{
	list head (const list s)
	{
		// PreCondition: not null (s)
		if (s != NULL) 
			if (!isAtom(s))	return s->node.pair.head;
				else 
				{ 
					cerr << "Ошибка: голова списка - атом \n"; 
					system("pause");
					exit(1); 
				}
		else 
		{
			cerr << "Ошибка: список пуст \n";
			system("pause");
			exit(1);
		}
	}




	bool isAtom (const list s)
	{	
		if(s == NULL) return false;
			else return (s -> tag);
	}



	bool isNull (const list s)
	{ 
		return s==NULL;
	}



	list tail (const list s)
	{// PreCondition: not null (s)
		if (s != NULL) 
			if (!isAtom(s))	return s->node.pair.tail;
				else 
					{ 
						cerr << "Оибка: хвост списка - атом \n"; 
						system("pause");
						exit(1); 
					}
		else 
			{ 
				cerr << "Ошибка: хвост пуст \n";
				system("pause");
				exit(1);
			}
	}


	//новый список: h-голова,t-хвост
	//Предусловие: t - не явл. атомом
	list cons (const list h, const list t)

	{
		list p;
		if (isAtom(t)) 
			{ 
				cerr << "Ошибка: 2-й операнд - атом\n";
				system("pause");
				exit(1);
			}
		else 
			{	
				p = new s_expr; 
				if ( p == NULL)	
					{
						cerr << "Память не выделена\n";
						system("pause");
						exit(1); 
					} 	
				else 
					{
						p->tag = false;
						p->node.pair.head = h;
						p->node.pair.tail = t;
						return p;	
					}
			}
	}



	list make_atom (const base x)
	{	
		list s;
		s = new s_expr;
		s -> tag = true;
		s->node.atom = x;
		return s;
	}




	void destroy (list s) 
	{
		if ( s != NULL) 
			{
				if (!isAtom(s)) 
					{
						destroy ( head (s));
						destroy ( tail (s));
					}
				delete s;
		// s = NULL;
			};
	}

		

	// ввод списка с консоли
	void read_list ( list &y, istream &in)
	{	
		base x;
		do in >> x; while (x==' ');
		read_s_expr ( x, y, in);
	} 



	void read_s_expr (base prev, list& y, istream &in)
	{
		//prev   － ранее прочитанный символ}
		if ( prev == ')' ) 
			{
				cerr << " ! List.Error 1 " << endl; 
				system("pause");
				exit(1); 
			} 
		else 
			if ( prev != '(' ) y = make_atom (prev);
			 else read_seq (y, in);
	} 



	void read_seq ( list& y, istream &in) 
	{	
		base x; 
		list p1, p2;

		if (!(in >> x)) 
			{
				cerr << " ! List.Error 2 " << endl; 
				system("pause");
				exit(1);
			}
		else 
			{
				while  ( x==' ' ) in >> x;
				if ( x == ')' ) y = NULL;
				else 
					{
						read_s_expr ( x, p1, in);
						read_seq ( p2, in);
						y = cons (p1, p2);
					} 
			}
	} 



	// Процедура вывода списка с обрамляющими его скобками  － write_list,
	//  а без обрамляющих скобок   － write_seq
	void write_list (const list x)
	{
		//пустой список выводится как () 
		if (isNull(x)) cout << " ()";
			else 
				if (isAtom(x)) 
					cout << ' ' << x->node.atom;
				else  
				{
					//непустой список} 
					cout << " (" ;
					write_seq(x);
					cout << " )";
				}
	} 


	//выводит последовательность элементов списка без обрамляющих его скобок
	void write_seq (const list x)  
	{
		
		if (!isNull(x)) 
		{
			write_list(head (x)); 
			write_seq(tail (x));
		}
	}



	list copy_list (const list x)
	{	
		if  (isNull(x)) return NULL;
		else 
			if (isAtom(x)) return make_atom (x->node.atom);
				else return cons (copy_list (head (x)), copy_list (tail(x)));
	} 
}
struct Unit;
typedef char base;

struct List
{
	Unit* head;
	Unit* tail;
};

enum Type
{
	Atomic,
	Pair
};

union Value
{
	base element;
	List pair;
};

struct Unit
{
	Type type;
	Value val;
};

enum Head_Tail
{
	Head,
	Tail
};

Unit* getHead(Unit* list);					//получаем указатель на голову 
Unit* getTail(Unit* list);					//получаем указатель на хвост 
Unit* create(Unit* head, Unit* tail);		//создаем новый элемент
base getAtom(Unit* list);					//плучаем значение атома
Unit* makeAtom(base elem);					//создаем новый атом
void write(Unit* list);						//выводим список на экран
void write_deep(Unit* list);
bool isEmpty(Unit* list);					//проверяем, пустой ли список
Unit* copy(Unit* list);						//копируем список
Unit* readUnit(Unit* list);					//вводим список с консоли
Unit* read_s_expr(base prev, Unit* list);
Unit* read_seq(Unit* list);
bool isAtom(Unit* list);					//проверяем, является ли элемент атомом
Unit* delete_x(Unit* list, base x);			//удаляем заданный элемент (x)
void delete_x_deep(Unit** list, Unit** reserv_list, base x, Head_Tail y); 
void destroy(Unit* list);					//разрушаем список
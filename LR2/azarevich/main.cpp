#include <windows.h>
#include "list.h"


using namespace h_list;
bool found(const base &x, const list y);


void main()
{
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы
	
	list s1;
	base x;

	cout << boolalpha;

	ifstream fin("test.txt");

	if (fin)
	{
		cout<<"Найден тестовый файл. Производится загрузка списка\n\n";
		read_list (s1, fin);

		cout << "Введен список: " << endl;

		write_list (s1);
		cout << endl<< endl;

		while (!fin.eof())
		{

			fin >> x;
			cout <<"Ведётся поиск "<<x<<"...\n...\n";

			cout << "В списке \n";
			write_list (s1);
			cout << "\nэлемент \""<<x<<"\" ";
			if (found(x, s1) )
				cout << "присутствует\n\n";
			else
				cout << "отсутствует \n\n";
		}
		cout << "Тестовый файл закончился.\n\n";
	}

	cout << "Введите list1:" << endl;
	read_list (s1, cin);

	cout << "Введен список: " << endl;

	write_list (s1);
	cout << endl;


	while(true)
	{
		cout << "Введите искомое значение:"<<endl;
		cin >> x;
		cout <<"Ведётся поиск "<<x<<"...\n...\n";

		cout << "В списке \n";
		write_list (s1);
		cout << "элемент \""<<x<<"\" ";
		if (found(x, s1) )
			cout << "присутствует\n\n";
		else
			cout << "отсутствует \n\n";
	}

	cout << "Введен список: " << endl;

	write_list (s1);
	cout << endl;




	while(true)
	{
	cout << "Введите искомое значение:"<<endl;
	cin >> x;
	cout <<"Ведётся поиск "<<x<<"...\n...\n";

	cout << "В списке \n";
	write_list (s1);
	cout << "элемент \""<<x<<"\" ";
	if (found(x, s1) )
		cout << "присутствует\n\n";
	else
		cout << "отсутствует \n\n";
	}
	


	system("pause");
}



bool found(const base &x, const list y)
{
	if( isAtom(y) )
		if (y->node.atom == x) return true;
		else return false;

	if( found(x, y->node.pair.head) ) return true;

	if ( !y->node.pair.tail ) return false;

	if( found(x, y->node.pair.tail) ) return true;


	return false;
}






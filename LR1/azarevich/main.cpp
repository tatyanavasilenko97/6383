//
// Лабораторная работа №1
// main.cpp
// Азаревич артём, группа 6383
// 18.09.2017
//
// Программа для вычисления биномиальных коэффициентов


#include "b_k.h"
using namespace std;


void main()
{
	setlocale(0, "");
	unsigned int m, n;
	bool isOverflow = false;

	unsigned long long res = 0;

	ifstream fin ("test.txt");
	ofstream fout("out.txt");
	
	b_k koef;

	//Прогон по тестовым данным из файла test.txt
	if ( fin.is_open() )
	{
		cout << "Найден файл с тестами\n\n";
		fout << "Найден файл с тестами\n\n";
		while ( !fin.eof() )
		{
			fin >> m;
			fin >> n;

			cout << "m= " <<m<<";	n= "<<n<<";	";
			fout << "m= " <<m<<";	n= "<<n<<";	";

			if ( m>n )
			{
				cout << "Бин. коэф.= 0" << endl;
				fout << "Бин. коэф.= 0" << endl;
			}
			else 
			{
				if (n >= koef.Nmax) koef.more(n);

				res = koef.binom(m, n);
				if (koef.isOverFlow)
					{
					cout << "Бин. коэф.= "<<res << endl;
					fout << "Бин. коэф.= "<<res << endl;
				}
				else 
				{
					cout << "Произошло переполнение\n";
					fout << "Произошло переполнение\n";
				}

			}
		}
		fout <<"Прогон тестового файла завершён\n\n\n";
		cout <<"Прогон тестового файла завершён\n\n\n";

		fin.close();
	}

	while (true)
	{
		cout << "m= ";
		cin  >> m;
		cout << "n= ";
		cin	 >> n;

		fout << "m= " <<m<<";	n= "<<n<<";	";

		if ( m>n )
			{
				cout << "Бин. коэф.= 0" << endl;
				fout << "Бин. коэф.= 0" << endl;
			}
			else
			{
				if (n >= koef.Nmax) koef.more(n);

				res = koef.binom(m, n);
				if (koef.isOverFlow)
					{
					cout << "Бин. коэф.= "<<res << endl;
					fout << "Бин. коэф.= "<<res << endl;
				}
				else 
				{
					cout << "Произошло переполнение\n";
					fout << "Произошло переполнение\n";
				}
			}
		

	}
	
}
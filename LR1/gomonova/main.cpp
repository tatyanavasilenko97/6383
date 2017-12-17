#include <iostream>
#include <fstream>

using namespace std;
void ERROR(int k, ofstream &writeF);
bool brackets(ofstream &writeF, int &count, int &iterat, char *mas);
bool row_brackets(ofstream &writeF, int &count, int &iterat,  char *mas);


const int SIZE_OF_MAS = 100;


int main()
{
	char *mas = new char [SIZE_OF_MAS];

	int iterat = -1;
	int count = -1;

	ifstream readF;
	readF.open("input.txt");
	ofstream writeF;
	if (!readF.is_open())
	{
		ERROR(6, writeF);
		return 1;
	}
	writeF.open("output.txt", ios_base::app);
	writeF << "-----------------" << endl
		<< "Brackets Analyser" << endl;
	int i = -1;
	bool Err_LIsh = false;

	while (!readF.eof()) //Считывание условия с файла в массив
	{
		i++;
		if (i >= SIZE_OF_MAS)
		{
			cout << "ERROR: OVERFLOW" << endl;
			break;
		}
		readF >> mas[i];
	}
	if (i == 0)
	{
		Err_LIsh = true;
		ERROR(5, writeF);
	}
	mas[i] = '?';
	for (int l = 0; l < i; l++)  //Проверка на наличие лишних символов
		if (mas[l] != ';' && mas[l] != 'A' && mas[l] != '(' && mas[l] != ')')
		{
			ERROR(1, writeF);
			Err_LIsh = true;
			break;
		}

	cout << "Input:";
	for (int l = 0; l < i; l++) { writeF << mas[l]; cout << mas[l]; } //Вывод условия в файл и в консоль
	cout << endl << endl;

	bool b;
	if (!Err_LIsh)
	{
		b = brackets(writeF, count, iterat, mas);
		if (iterat + 1 != i) b = false;
		if (b) { writeF << endl << "This is brackets" << endl << endl; cout << endl << "This is brackets" << endl; }
		else { writeF << endl << "This is not brackets" << endl << endl; cout << endl << "This is not brackets" << endl; }
	}

	writeF.close();
	readF.close();
	system("pause");
	return 0;
}

void ERROR(int k, ofstream &writeF) //Функция ошибок
{
	writeF << endl;
	switch (k)
	{
	case 1:
		writeF << "ERROR: Extra symbols in the input line!" << endl;
		cout << endl << "ERROR: Extra symbols in the input line!" << endl;
		break;
	case 2:
		writeF << "ERROR: Missing ')' !";
		cout << endl << "ERROR: Missing ')' !";
		break;
	case 3:
		writeF << "ERROR: Missing '(' !";
		cout << endl << "ERROR: Missing '(' !";
		break;
	case 4:
		writeF << "ERROR: Missing ';' !";
		cout << endl << "ERROR: Missing ';' !";
		break;
	case 5:
		cout << "ERROR: File is empty";
		writeF << "ERROR: File is empty";
		break;
	case 6:
		cout << "ERROR: File not opend!";
		writeF << "ERROR: File not opend!";
		break;
	case 7:
		writeF << "ERROR: Missing 'A' !";
		cout << endl << "ERROR: Missing 'A' !";
		break;
	default:
		writeF << "ERROR: ...";
		cout << endl << "ERROR: ...";
		break;
	}
}

bool row_brackets(ofstream &writeF, int &iterat, int &count, char *mas) //ряд_скобок::= скобки | скобки;ряд_скобок
{
	bool k;
	cout << "  |";
	for (int z = 1; z < count; z++) cout << " ";
	cout << " Check Brackets" << endl;

	k = brackets(writeF, count, iterat, mas); //ряд_скобок::= скобки
	if (k)
	{
		if (mas[iterat + 1] == '?' || mas[iterat + 1] == ')')
		{
			count--;
			cout << "  |";
			for (int z = 1; z < count; z++) cout << " ";
			cout << "true1" << endl;

			return true;
		}
		else
		{
			iterat++;
			count++;
			cout << mas[iterat];
			if (mas[iterat] == ';')    //ряд_скобок::= скобки;ряд_скобок
			{
				cout << " |";
				for (int z = 1; z < count; z++) cout << " ";
				cout << "Check Row Brackets" << endl;

				k = row_brackets(writeF, count, iterat, mas);
				if (k)
				{
					count--;
					cout << "  |";
					for (int z = 1; z < count; z++) cout << " ";
					cout << "true2" << endl;

					return true;
				}
			}
			else
			{
				ERROR(4, writeF);
				return false;
			}
		}
	}
	return false;
}

bool brackets(ofstream &writeF, int &count, int &iterat, char *mas) //скобки::= А | А(ряд_скобок)
{

	bool k;
	iterat++;
	count++;
	cout << mas[iterat];
	if (mas[iterat] == 'A')  //скобки::= A
	{
		if (mas[iterat + 1] == '?' || mas[iterat + 1] == ';' || mas[iterat + 1] == ')')
		{
			count--;
			cout << " |";
			for (int z = 1; z < count; z++) cout << " ";
			cout << "true3" << endl;
			return true;
		}
		else
		{
			iterat++;
			count++;
			cout << mas[iterat];
			if (mas[iterat] == '(')  //скобки::= A(ряд_скобок)
			{
				cout << "|";
				for (int z = 1; z < count; z++) cout << " ";
				cout << "Check Row Brackets" << endl;

				k = row_brackets(writeF, count, iterat, mas);
				if (k)
				{
					iterat++;
					count++;
					cout << mas[iterat];
					if (mas[iterat] == '?')
					{
						ERROR(2, writeF);
						return false;
					}
					if (mas[iterat] = ')')
					{
						count--;
						cout << " |";
						for (int z = 1; z < count; z++) cout << " ";
						cout << "true4" << endl;

						return true;
					}
				}
			}
			else
			{
				ERROR(3, writeF);
				return false;
			}
		}
	}
	else { ERROR(7, writeF); return false; }
}

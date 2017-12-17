// Лабораторная работа №1
// main.cpp
// Василенко Таня, группа 6383

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <windows.h>

using namespace std;

bool IsSimpleLogic(ifstream&); // проверка на простое логическое
bool IsBinaryOperation(ifstream&); // проверка на бинарную операцию
bool IsIdentifierOrIsUnaryOperation(ifstream&); // проверка на унарные операции и идентификаторы
void Error(short);



int main()
{
	setlocale(0, "Rus"); // ставим кодировку чтобы писать по-русски

	ifstream inFile("infile.txt", ifstream::binary); // переменная для входного файла
	inFile >> noskipws; // чтобы не пропускать пробелы во входном файле
	if (!inFile) // если входного файла не существует, пишем об этом
			cout << "Входной файл не открыт!" << endl;
	else
	{
		cout << "Анализатор понятия 'простое_логическое':" << endl << endl;
		cout << "Это - " << (IsSimpleLogic(inFile) ? "" : "не ") << "простое логическое." << endl; // запуск анализатора
		system("pause");
	}
	return 0;
}


// лишние пробелы ставить нельзя
bool IsSimpleLogic(ifstream& inFile)
{
	char readCharacter;
	if (!(inFile >> readCharacter)) // если в файле пусто, все гуд
	{
		system("cls");
		cout<< "входной файл пустой\n";
		exit(-1);
	}
	if (readCharacter == '(') // встретив '(', должно быть (простое_логическое операция простое_логическое)
	{
		return IsBinaryOperation(inFile);
	}
	else if (isalpha(readCharacter)) // встретив букву, тут может быть идентификатор, TRUE, FALSE или операция NOT
	{
		inFile.seekg(-1, ios::cur); //  позволяет при следующей операции чтения считать тот же символ
		                            // сдвиг указателя назад в файле
		return IsIdentifierOrIsUnaryOperation(inFile);
	}
	else // другие символы не допускаются
	{
		return false;
	}
	return true;
}

bool IsIdentifierOrIsUnaryOperation(ifstream& inFile)
{
	char readCharacter;
	if (!(inFile >> readCharacter)) // ожидаем идентификатор, но его нет, поэтому ошибка
	{
		return false;
	}
	readCharacter = toupper(readCharacter); //просто поднимаем регистр символа
	if (readCharacter == 'N') // NOT или идентификатор N
	{
		if (!(inFile >> readCharacter))
		{
			return true;
		}
		readCharacter = toupper(readCharacter);
		if (readCharacter == ' ') // идентификатор N
		{
			return true;
		}
		else if (readCharacter == ')') // идентификатор N
		{
			inFile.seekg(-1, ios::cur);
			return true;
		}
		else if (readCharacter == 'O') // NO
		{
			if (!(inFile >> readCharacter))
			{
				return false;
			}
			readCharacter = toupper(readCharacter);
			if (readCharacter == 'T') // NOT, причём после него должен быть пробел и далее простое логическое
			{
				if (!(inFile >> readCharacter))
				{
					return false;
				}
				if (readCharacter == ' ')
				{
					return IsSimpleLogic(inFile);
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else if (readCharacter == 'T') // TRUE или идентификатор T
	{
		if (!(inFile >> readCharacter))
		{
			return true;
		}
		readCharacter = toupper(readCharacter);
		if (readCharacter == ' ') // идентификатор T
		{
			return true;
		}
		else if (readCharacter == ')') // идентификатор T
		{
			inFile.seekg(-1, ios::cur);
			return true;
		}
		else if (readCharacter == 'R') // TR
		{
			if (!(inFile >> readCharacter))
			{
				return false;
			}
			readCharacter = toupper(readCharacter);
			if (readCharacter == 'U') // TRU
			{
				if (!(inFile >> readCharacter))
				{
					return false;
				}
				readCharacter = toupper(readCharacter);
				if (readCharacter == 'E') // TRUE, после него может быть пробел или ')'
				{
					if (!(inFile >> readCharacter))
					{
						return true;
					}
					if (readCharacter == ' ')
					{
						return true;
					}
					else if (readCharacter == ')')
					{
						inFile.seekg(-1, ios::cur);
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else if (readCharacter == 'F') // FALSE или идентификатор F
	{
		if (!(inFile >> readCharacter))
		{
			return true;
		}
		readCharacter = toupper(readCharacter);
		if (readCharacter == ' ') // идентификатор F
		{
			return true;
		}
		else if (readCharacter == ')') // идентификатор F
		{
			inFile.seekg(-1, ios::cur);
			return true;
		}
		else if (readCharacter == 'A') // FA
		{
			if (!(inFile >> readCharacter))
			{
				return false;
			}
			readCharacter = toupper(readCharacter);
			if (readCharacter == 'L') // FAL
			{
				if (!(inFile >> readCharacter))
				{
					return false;
				}
				readCharacter = toupper(readCharacter);
				if (readCharacter == 'S') // FALS
				{
					if (!(inFile >> readCharacter))
					{
						return false;
					}
					readCharacter = toupper(readCharacter);
					if (readCharacter == 'E') // FALSE, после него может быть пробел или ')'
					{
						if (!(inFile >> readCharacter))
						{
							return true;
						}
						if (readCharacter == ' ')
						{
							return true;
						}
						else if (readCharacter == ')')
						{
							inFile.seekg(-1, ios::cur);
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else // другие идентификаторы
	{
		if (!(inFile >> readCharacter)) // если файл пуст, то всё плохо
		{
			return false;
		}
		// после него должен быть пробел или скобка
		if (readCharacter == ' ') // идентификатор
		{
			return true;
		}
		else if (readCharacter == ')') // идентификатор
		{
			inFile.seekg(-1, ios::cur);
			return true;
		}
	}
	return false;
}

bool IsBinaryOperation(ifstream& inFile)
{
	// в бинарной операции: открывающая скобка уже считана, поэтому проверяем:
	char readCharacter;
	if (!(inFile >> readCharacter))
	{
		return false;
	}
	inFile.seekg(-1, ios::cur);
	// сначала простое логическое:
	if (!IsSimpleLogic(inFile))
	{
		return false;
	}
	inFile.seekg(-1, ios::cur);
	// далее пробел либо скобка
	if (!(inFile >> readCharacter))
	{
		return false;
	}
	if (readCharacter != ' ' && readCharacter != ')')
	{
		return false;
	}
	if (!(inFile >> readCharacter))
	{
		return false;
	}
	if (readCharacter == ' ')
	{
		if (!(inFile >> readCharacter))
		{
			return false;
		}
	}
	/////// проверка на бинарную операцию
	if (readCharacter == 'A') // AND
	{
		if (!(inFile >> readCharacter))
		{
			return false;
		}
		readCharacter = toupper(readCharacter);
		if (readCharacter == 'N') // AN
		{
			if (!(inFile >> readCharacter))
			{
				return false;
			}
			readCharacter = toupper(readCharacter);
			if (readCharacter == 'D') // AND, после него пробел
			{
				if (!(inFile >> readCharacter))
				{
					return false;
				}
				if (readCharacter != ' ')
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (readCharacter == 'O') // OR
	{
		if (!(inFile >> readCharacter))
		{
			return false;
		}
		readCharacter = toupper(readCharacter);
		if (readCharacter == 'R') // OR, после него пробел
		{
			if (!(inFile >> readCharacter))
			{
				return false;
			}
			if (readCharacter != ' ')
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	// далее - второе простое логическое
	if (!IsSimpleLogic(inFile))
	{
		return false;
	}
	// и в конце должен быть символ ')'
	if (!(inFile >> readCharacter))
	{
		return false;
	}
	if (readCharacter != ')')
	{
		return false;
	}
	return true;
}

void Error(short errorId)
{
	cout << endl << "err#" << errorId << endl;
	switch (errorId)
	{
	case 0:
		cout << "! - Пустая входная строка" << endl;
		break;
	default:
		cout << "! - ...";
		break;
	}
}

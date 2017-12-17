/*
 Nikitn¿ Kirill, group 6383.
 Variance 16
 brackets: A | B | (brackets brackets)
*/

#include<fstream>
#include<iostream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
bool error = false;

bool checkBrackets(int &count) {
	int notBracketsCount = 0;
	while(!fin.eof()) {
		switch (fin.peek())
		{
		case 'A': {
			fin.get();
			count--;
			notBracketsCount++;
			break;
		}
		case 'B': {
			fin.get();
			count--;
			notBracketsCount++;
			break;
		}
		case '(': {
			fin.get();
			count += 2;
			checkBrackets(count);
			notBracketsCount++;
			break;
		}
		case ')': {
			fin.get();
			count--;
			if (notBracketsCount != 2) error = true;
			return error;
			break;
		}
		case EOF: {
			break;
		}
		default:
			fin.get();
			error = true;
			break;
		}
	}
	if (count != 0) error = true;
	return error;
}

int main()
{
	int count = 1;
	error = checkBrackets(count);
	if (fin.peek() != EOF) error = true;
	if (!error) fout << "It's a bracket!";
	else fout << "It's not a bracket!";
}

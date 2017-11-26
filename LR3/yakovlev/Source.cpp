#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Node {

	int atom; 
	Node* nextEl;
	Node() {
		this->atom = 0;
		this->nextEl = NULL;
	}
	
};



int strToInt(string);
string intToStr(int);
bool isNumber(string);
void readExp(vector<string>*);
int culcFunc(Node*, vector<string>, set<string>);
void writeCulcExp(int result);
void printMenu();
void push_Number(Node*& varList, string nowEl);
int pop_Ele(Node*& varList, Node* head);

int main()
{


	vector <string> exp;
	Node* head = new Node;
	Node* varList = new Node;
	set<string> oper;
	int result;
	oper.insert("+");
	oper.insert("-");
	oper.insert("*");
	oper.insert("/");
	oper.insert("^");
	varList = head;

	printMenu();

	readExp(&exp);


	varList = head;

	result = culcFunc(varList, exp, oper);

	cout << "______________" << endl;
	cout << "result = " << result;
	writeCulcExp(result);
	system("pause");
	return 0;


}

void push_Number(Node*& varList, string nowEl) {
	varList->nextEl = new Node;
	varList->nextEl->atom = strToInt(nowEl);
	varList = varList->nextEl;
	return;
}

int pop_Ele(Node*& varList, Node* head)
{
	int flag = varList->atom;
	varList = head;

	while (varList->nextEl->nextEl != NULL)
		varList = varList->nextEl;

	delete varList->nextEl;
	varList->nextEl = NULL;
	return flag;
}

void writeCulcExp(int result) {
	ofstream cout("output.txt");
	cout << "Result = " << result << " ;";
	cout.close();
}

void readExp(vector<string>*exp) {
	ifstream cin("postfix.txt");
	string simpExp;
	while (!cin.eof()) {
		cin >> simpExp;
		exp->push_back(simpExp);
	}
}



int culcFunc(Node*varList, vector<string>exp, set<string>oper) {
	Node* head = varList;
	int i = 1;
	int flag = 0;
	int result = 0;
	for (string nowEl : exp) {

		if (isNumber(nowEl)) {
			push_Number(varList, nowEl);
			cout << i << ") " << varList->atom << ";" << endl;
		}
		else
			if (oper.count(nowEl)) {
				switch (nowEl[0]) {

				case '+': {
					flag = pop_Ele(varList, head);
					varList->atom += flag;
				}
						  break;
				case '-': {
					flag = pop_Ele(varList, head);
					varList->atom -= flag;
				}
						  break;
				case '*': {
					flag = pop_Ele(varList, head);
					varList->atom *= flag;

				}
						  break;
				case '/': {

					if (varList->atom == 0) {
						cerr << "You use null at the division.";
						exit(2);
					}
					flag = pop_Ele(varList, head);
					varList->atom /= flag;
				}
						  break;
				case '^': {
					flag = pop_Ele(varList, head);
					varList->atom = pow(varList->atom, flag);
				}
						  break;
				default:
					break;
				}
				cout << i << ") " << varList->atom << ";" << endl;
			}
			else {
				cerr << "Incorrect data!";
				exit(1);
			}
			++i;
	}

	result = varList->atom;
	delete head;
	delete varList;

	return result;
}


bool isNumber(string atom) {
	for (char i : atom) {
		if (i>57 || i<48) return false;
	}
	return true;
}

int strToInt(string atom) {
	int result = 0;
	for (char i : atom) {
		result += i - 48;
	}
	return result;
}


string intToStr(int atom) {
	char result[33];
	_itoa(atom, result, 10);
	return result;
}

void printMenu() {
	cout << "Please enter aryphmetics expression in file:" << endl;
	cout << "Expression :: Oper Oper Operation" << endl;
	cout << "Oper :: Number || Word || Expression" << endl;
	cout << "Operation :: + || -  || * || / || ^" << endl;
	cout << "_____________________________________________" << endl;
	cout << "intermediate calculations:" << endl;
}


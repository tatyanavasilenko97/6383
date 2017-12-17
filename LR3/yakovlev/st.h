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
class  St
{
public:
	 St();
	Node* pointer;

	int pop_Ele(St varList, St head)
	{
		int flag = pointer->atom;
		varList = head;

		while (pointer->nextEl != nullptr)
			pointer = pointer->nextEl;

		delete pointer->nextEl;
		pointer->nextEl = NULL;
		return flag;
	}
	
	void push_Number(string nowEl) {

		pointer->nextEl = new Node;
		pointer->nextEl->atom = strToInt(nowEl);
		pointer = pointer->nextEl;
		return;
	}

private:




};

 St:: St()
{
	 pointer = new Node;
}




string intToStr(int);
bool isNumber(string);
void printMenu();
void readExp(vector<string>*);
int culcFunc(St, vector<string>, set<string>);
void writeCulcExp(int result);
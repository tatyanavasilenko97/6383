#include <iostream>
#include <string>
#include <ostream>
#include <conio.h>
#include <Windows.h> 

using namespace std;
class Node {
public:
	Node() {};
	friend class List;
	void destr(Node* node);
	void makeNodes(string& exp);
	friend bool equel(Node *a, Node *b);
private:
	Node *head = nullptr;
	Node *tail = nullptr;
	bool isAtom = false;
	char data;
	Node* makeAtom(char data);
};
void Node::makeNodes(string& exp) {
	if (exp[0] == ')') {
		exp.erase(0, 1);
		return;
	}
	else {
		if (exp[0] != '(') {
			head = makeAtom(exp[0]);
			exp.erase(0, 1);
			if (exp[0] == ')') {
				exp.erase(0, 1);
				return;
			}
			tail = new Node;
			tail->makeNodes(exp);
		}
		else {
			exp.erase(0, 1);
			head = new Node;
			head->makeNodes(exp);
			if (exp[0] == ')') {
				exp.erase(0, 1);
				return;
			}
			tail = new Node;
			tail->makeNodes(exp);
		}
	}
}
void Node::destr(Node* node) {
	if (node != nullptr)
	{
		if (!node->isAtom) {
			destr(node->head);
			destr(node->tail);
		}
		delete node;
	}
}
Node* Node::makeAtom(char data) {
	Node *node = new Node;
	node->data = data;
	node->isAtom = true;
	return node;
}
class List {
public:
	List(string list);
	void destrList();
	Node *HeadEl = nullptr;
};
void List::destrList() {
	HeadEl->destr(HeadEl);
};
List::List(string  list) {
	HeadEl = new Node;
	if (list[0] == '(') {
		list.erase(0, 1);
	}
	HeadEl->makeNodes(list);
}
bool equel(Node *a, Node *b) {
	if (a == b)return true;
	else if ((a != nullptr&& b == nullptr) || (a == nullptr && b != nullptr)) return false;
	else {
		if (!equel(a->head, b->head))return false;
		if(!equel(a->tail, b->tail))return false;
		return true;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬ведите ниже два списка, которые нужно проверить\n";
	string str, str1;
	getline(cin, str);
	List usual(str);
	getline(cin, str1);
	List usual1(str1);
	if (equel(usual.HeadEl,usual1.HeadEl)) cout << "Cool";
	else cout << "Bad!";
	usual.destrList();
	usual1.destrList();
	system("pause > nul");
	return 0;
}
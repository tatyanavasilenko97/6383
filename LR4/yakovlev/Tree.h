#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


template <class T>
struct binTree {
	int leftBr = 0;
	int rightBr = 0;
	T atom;
};

template <class T>
struct forest {
	vector<int> br;
	T atom;
};

template <class T>
class CBinTree {
private:
	vector<binTree<T>>* ourTree;
	vector<forest<T>>* ourForest;
	int numbOfEl;
	T emptySymbol;
public:

	CBinTree(int n = 100) {
		ourTree = new vector<binTree<T>>(n);
		ourForest = new vector<forest<T>>(n);
		numbOfEl = 0;
	}

	~CBinTree() {
		delete ourTree;
		delete ourForest;
	}

	void recReadTree(int nowEl, string brack, vector<T> el) {
		static int brackNumb = 0;
		if (brack.length() == brackNumb) return;
		if (brack[brackNumb] == '(')
			ourTree->at(nowEl).atom = el.at(numbOfEl);
		++brackNumb;
		if (brack[brackNumb] == '(') {

			if (ourTree->at(nowEl).leftBr == 0) {
				ourTree->at(nowEl).leftBr = numbOfEl + 1;
				++numbOfEl;
				recReadTree(numbOfEl, brack, el);
			}
			if (brack[brackNumb] == '(') {
				if (ourTree->at(nowEl).rightBr == 0) {
					ourTree->at(nowEl).rightBr = numbOfEl + 1;
					++numbOfEl;
					recReadTree(numbOfEl, brack, el);
				}
			}
			else {
				++brackNumb;
				return;
			}

		}
		else {
			++brackNumb;
			return;
		}
		++brackNumb;
	}

	void readTree() {
		int sch = 0;
		T readEl;
		char flag;
		vector<T> elements;
		string brackets;
		cout << "Do you want read tree from a console(y/n): ";
		flag = _getch();
		if (flag == 'y') {
			system("cls");
			cout << "Please complete symbol of your your typing is EOF:" << endl;
			cout << "Second typing elements of tree." << endl;
			cout << "First typing brakcets." << endl;
			cout << "For example:" << endl << "(())" << endl << "a b" << endl;
			cout << "-------------------------------" << endl;
			cin >> brackets;
			for (int i = 0; i<brackets.length(); ++i)
				if (brackets[i] == '(') ++sch;
			for (int i = 0; i<sch; ++i) {
				cin >> readEl;
				elements.push_back(readEl);

			}
		}
		else {
			ifstream readF("input.txt");
			readF >> brackets;
			for (int i = 0; i<brackets.length(); ++i)
				if (brackets[i] == '(') ++sch;
			for (int i = 0; i<sch; ++i) {
				readF >> readEl;
				elements.push_back(readEl);
			}
		}
		recReadTree(0, brackets, elements);
	}


	void printTree(int nowEl = 0, int level = 0, bool isLeft = true) {
		if (this->ourTree->at(nowEl).atom != emptySymbol) {
			for (int i = 0; i<level; ++i)
				cout << '-';
			if (isLeft)
				cout << '>';
			else cout << '<';
			cout << this->ourTree->at(nowEl).atom << endl;
		}
		if (this->ourTree->at(nowEl).leftBr != 0)
			printTree(this->ourTree->at(nowEl).leftBr, ++level, true);
		else { return; }
		if (this->ourTree->at(nowEl).rightBr != 0)
			printTree(this->ourTree->at(nowEl).rightBr, level, false);
		else { return; }
	}

	vector<binTree<T>> getTree() {
		return *ourTree;
	}

	void assignTree(vector<binTree<T>> newTree) {
		*ourTree = newTree;
	}

	void assignForest(vector<binTree<T>> newForest) {
		*ourTree = newForest;
	}


	void recForestTree(int nowEl = 0, int parEl = 0, int doubleParEl = 0, bool isRight = false) {


		if ((isRight) && (parEl != 0)) {
			if (this->ourForest->at(doubleParEl).br.at(1) == 0)
				this->ourForest->at(doubleParEl).br.at(1) = nowEl;
			else this->ourForest->at(doubleParEl).br.push_back(nowEl);
			this->ourTree->at(parEl).rightBr = 0;
			this->ourForest->at(parEl).br.at(1) = 0;
		}

		for (int i = 0; i<this->ourForest->at(nowEl).br.size(); ++i) {
			if (this->ourForest->at(nowEl).br.at(i) != 0)
				if (i == 0)
					recForestTree(this->ourForest->at(nowEl).br.at(i), nowEl, parEl, false);
				else recForestTree(this->ourForest->at(nowEl).br.at(i), nowEl, parEl, true);
		}
	}

	void printForest(int nowEl = 0, int level = 0, int order = 0) {
		if (this->ourTree->at(nowEl).atom != emptySymbol) {
			for (int i = 0; i<level; ++i)
				cout << '-';
			cout << order + 1 << '>';
			cout << this->ourForest->at(nowEl).atom << endl;
		}
		for (int i = 0; i<this->ourForest->at(nowEl).br.size(); ++i) {
			if (this->ourForest->at(nowEl).br.at(i) != 0)
				if (i == 0)
					printForest(this->ourForest->at(nowEl).br.at(i), ++level, i);
				else printForest(this->ourForest->at(nowEl).br.at(i), level, i);
		}
	}

	void recGetForest(int nowEl) {

		this->ourForest->at(nowEl).atom = this->ourTree->at(nowEl).atom;
		this->ourForest->at(nowEl).br.clear();
		this->ourForest->at(nowEl).br.push_back(this->ourTree->at(nowEl).leftBr);
		this->ourForest->at(nowEl).br.push_back(this->ourTree->at(nowEl).rightBr);

		if (this->ourTree->at(nowEl).leftBr != 0) {
			recGetForest(this->ourTree->at(nowEl).leftBr);
		}
		if (this->ourTree->at(nowEl).rightBr != 0) {
			recGetForest(this->ourTree->at(nowEl).rightBr);
		}
	}

	void leftForestTree() {
		this->ourTree->at(0).rightBr = 0;
		recGetForest(0);
		recForestTree(0);//this->ourTree->at(0).leftBr);
	}


	void assingEmptySymbol(T empty) {
		this->emptySymbol = empty;
	}

	void printWidthElements() {
		queue<int> mass;
		int flag;
		mass.push(0);
		while (!mass.empty()) {
			flag = mass.front();
			mass.pop();
			if (this->ourTree->at(flag).atom != emptySymbol) {
				cout << this->ourTree->at(flag).atom << " ";
			}
			if (this->ourTree->at(flag).leftBr != 0)
				mass.push(this->ourTree->at(flag).leftBr);
			if (this->ourTree->at(flag).rightBr != 0)
				mass.push(this->ourTree->at(flag).rightBr);
		}
		cout << endl;
	}

	void printWidthForestElements() {
		queue<int> mass;
		int flag;
		mass.push(0);
		while (!mass.empty()) {
			flag = mass.front();
			mass.pop();
			if (this->ourForest->at(flag).atom != emptySymbol)
				cout << this->ourForest->at(flag).atom << " ";
			for (int i = 0; i<this->ourForest->at(flag).br.size(); ++i) {
				if (this->ourForest->at(flag).br.at(i) != 0)
					mass.push(this->ourForest->at(flag).br.at(i));
			}
		}
		cout << endl;
	}

	int getRightElement() {
		return this->ourTree->at(0).rightBr;
	}

	void right() {
		this->ourTree->at(0) = this->ourTree->at(this->ourTree->at(0).rightBr);
	}
};

#endif
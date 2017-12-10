#include "Tree.h"


int main()
{
	int i;
	string empty;
	CBinTree<string> tree;
	CBinTree<string> forestTreeRight;
	cout << "Please, enter empty symbol: ";
	cin >> empty;
	tree.assingEmptySymbol(empty);
	system("cls");
	tree.readTree();
	cout << "---------------------------" << endl << "Tree:" << endl;
	tree.printTree();
	tree.printWidthElements();
	if (tree.getRightElement() == 0)i = 1;
	else i = 0;
	while (i != 2) {
		cout << "---------------------------" << endl << "Next Tree from forest:" << endl;
		forestTreeRight.assingEmptySymbol(empty);
		forestTreeRight.assignTree(tree.getTree());
		forestTreeRight.assignForest(tree.getTree());
		forestTreeRight.leftForestTree();
		forestTreeRight.printForest();
		forestTreeRight.printWidthForestElements();
		tree.right();
		if (tree.getRightElement() == 0)
			++i;
	}
	system("pause");
	return 0;
}

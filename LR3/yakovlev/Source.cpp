#include "st.h"



int main()
{


	vector <string> exp;
	St head;
	St varList;
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



int culcFunc(St varList, vector<string>exp, set<string>oper) {
	St head = varList;
	int i = 1;
	int flag = 0;
	int result = 0;
	for (string nowEl : exp) {

		if (isNumber(nowEl)){
			varList.push_Number(nowEl); 
			cout << i << ") " << varList.pointer->atom << ";" << endl;
		}
		else
			if (oper.count(nowEl)) {
				switch (nowEl[0]) {

				case '+': {
					flag = varList.pop_Ele(varList, head);
					varList.pointer->atom += flag;
				}
						  break;
				case '-': {
					flag = varList.pop_Ele(varList, head);
					varList.pointer->atom -= flag;
				}
						  break;
				case '*': {
					flag = varList.pop_Ele(varList, head);
					varList.pointer->atom *= flag;

				}
						  break;
				case '/': {

					if (varList.pointer->atom == 0) {
						cerr << "You use null at the division.";
						exit(2);
					}
					flag = varList.pop_Ele(varList, head);
					varList.pointer->atom /= flag;
				}
						  break;
				case '^': {
					flag = varList.pop_Ele(varList, head);
					varList.pointer->atom = pow(varList.pointer->atom, flag);
				}
						  break;
				default:
					break;
				}
				cout << i << ") " << varList.pointer->atom << ";" << endl;
			}
			else {
				cerr << "Incorrect data!";
				exit(1);
			}
			++i;
	}

	result = varList.pointer->atom;
	//delete head;
	//~varList;

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


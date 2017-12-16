#include <iostream>
#include <cmath>

using namespace std;
bool num(std::istream& in, int& res) {
	in >> res;
	if (!in.good()) cout << "Error\n";
	return in.good();
}
bool term(std::istream& in, int& res) {
	int val, vel;
	if (!num(in, val))return false;

	while (true) {
		if (in.peek() == '*') {
			in.get();
			if (!num(in, vel))return false;
			if ((vel != 0) && (val > (INT_MAX / vel))) {
				cout << "Переполнение при умножении";
				return false;
			val *= vel;
		}
		else {
			res = val;
			return true;
		}
	}

}

bool exp(std::istream& in, int& res) {
	int val;
	if(isdigit(in.peek())) if (!term(in, res))return false;
	
	if (in.peek() == '+') {
		in.get();
		if (!term(in, val))return false;
		if (res > (INT_MAX - val)){
			cout << "Переполнение при сложении";
			return false;
		}
		res += val;
	}
	else if (in.peek() == '-') {
		in.get();
		if (!term(in, val))return false;
		if (res < (INT_MIN + val)){
			cout << "Переполнение при вычитании";
			return false;
		}
		res -= val;
	}
	else return true;
	exp(in,res);
}

int main()
{
	int res = 0;
	exp(cin, res);
	cout << res << endl;

	system("pause > nul");
	return 0;
}

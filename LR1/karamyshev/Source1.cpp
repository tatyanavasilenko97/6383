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
			if ((vel != 0) && (val > (INT_MAX / vel))) return false;
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
		if (res > (INT_MAX - val))return false;
		res += val;
	}
	else if (in.peek() == '-') {
		in.get();
		if (!term(in, val))return false;
		if (res < (INT_MIN + val)) return false;
		res -= val;
	}
	else return true;
	exp(in,res);
}

int main()
{
	int res = 0;
	if (exp(cin, res))
		cout << res << endl;
	else cout << "Error!" << endl;

	system("pause > nul");
	return 0;
}

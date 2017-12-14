#include "fh.h"

int main()
{
	int flag = 0;
	while (true)
	{
		CodeTree* ct;// = nullptr;
		char *c;
		c = new char[MAX_CODE_LEN];
		char *_encode, *_decode;
		_encode = new char[MAX_CODE_LEN];
		std::cout << "Enter the string: ";
		std::cin >> c;
		ct = fanno_shannon(c);
		_encode = encode(ct, c);
		_decode = decode(ct, _encode);
		std::cout << "Tree:\n";
		print_tree(ct, 0, std::cout);
		std::cout << "Code: ";
		std::cout << _encode << std::endl;
		std::cout << "Decode: ";
		std::cout << _decode << std::endl;
		destroy(ct);
		delete[] c;
		std::cout << "Repeat? 1 - yes; 0 - no. ";
		std::cin >> flag;
		std::cout << std::endl;
		if (flag == 0)
			return 0;
	}
//	system("pause");
}

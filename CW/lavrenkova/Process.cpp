#include <iostream>
#include <fstream>
#include <map>
#include <conio.h>
#include "b_tree.h"
#include "queue.h"
#include "process.h"
#include <string>
#include <fstream>

using namespace std;

namespace proc {
	struct My::node {
		__int64 priority;
		string symbol;
	};

	struct My::f_node {
		int left;
		int right;
		int priority;
		string symbol;
		f_node(int a, int b)
		{
			left = a;
			right = b;
		}
		f_node()
		{
			left = 0;
			right = 0;
		}
	};

	void My::hman(string my_str) {
		bool open = false;
		ofstream fout("hman.txt", ios_base::app);
		if (fout.is_open())
			open = true;

		string result = "";

		cout << "                               [Метод Хаффмана]                               " << endl << endl;
		cout << "Введено сообщение: " << char(34) << my_str << char(34) << "\nРазмером: " << my_str.length() * 8 << " бит";
		fout << "Введено сообщение: " << char(34) << my_str << char(34) << "\nРазмером: " << my_str.length() * 8 << " бит";

		int* priority = new int[64];
		string* symbol = new string[64];
		for (int i = 0; i < 64; i++) {
			priority[i] = 0;
			symbol[i].clear();
		}

		map<string, string> table; // ассоциативный массив связывающий символ и его код
		map<char, int> dictionary; //ассоциативный массив связывающий символ и его количество вхождений

								   //b_node<node> * tree;
		priority_queue<b_node<node>*>* queue;
		queue = new priority_queue<b_node<node>*>;
		__int64 p1, p2;
		b_node<node> *bt1, *bt2, *ht;
		ht = new b_node<node>;

		for (unsigned int i = 0; i < my_str.length(); i++) {
			char tmp = my_str[i];
			dictionary[tmp]++;
		}

		if (dictionary.size() == 1) {//обрабатываем, если в файле используется одна буква
			fout << "\n\nТаблица кодов:" << endl;
			cout << "\n\nТаблица кодов:" << endl;
			result = One_Letter(my_str, dictionary, fout);
			fout << "\n\nЗакодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl;
			cout << "\n\nЗакодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl; //вывод закодированного сообщения
			for (unsigned i = 0; i < 80; i++)
				cout << "-";
			fout << "Декодированное сообщение: " << my_str << endl;
			cout << "Декодированное сообщение: " << my_str << endl;
		}
		else {
			fout << "\n\nСортируем символы по убыванию приоритета:" << endl;
			cout << "\n\nСортируем символы по убыванию приоритета:" << endl;
			for (map<char, int>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) { //пробегаемся по ассоц.массиву и добавляем элементы в приорит.очередь
				b_node<node>* tmp = new b_node<node>();
				tmp->data.symbol = it->first;
				tmp->data.priority = it->second;
				queue->push(tmp, it->second);
			}

			//выполняем пока не останется один элемент в очереди
			while ((queue->get_top()) != 0) { //создание дерева Хаффмана
				fout << "\n";
				cout << "\n";
				bt1 = queue->pop<b_node<node>*>(p1); //делаем pop последнего
				bt2 = queue->pop<b_node<node>*>(p2); //и предпоследнего элементов

				ht = cons_bt<node>(bt1, bt2, node()); //присоединяем два предыдущих элемента к пустому узлу
				ht->data.priority = ht->l_br->data.priority + ht->r_br->data.priority; //задаем общий приоритет отца
				ht->data.symbol = ht->l_br->data.symbol + ht->r_br->data.symbol; //общую строку для отца
				queue->push<b_node<node>*>(ht, p1 + p2); //добавляем полученное дерево в приор. очередь
				fout << "Текущие элементы: ";
				cout << "Текущие элементы: ";
				for (int i = 0; i <= queue->top; i++) {
					fout << "'" << queue->head[i].data->data.symbol << "'(" << queue->head[i].data->data.priority << ") ";
					cout << "'" << queue->head[i].data->data.symbol << "'(" << queue->head[i].data->data.priority << ") ";
				}
				cout << endl;
				fout << endl;
				print(ht, 0, fout); //вывод дерева Хаффмана
			}

			fout << "\n\nТаблица кодов:" << endl;
			cout << "\n\nТаблица кодов:" << endl;
			BuildTable(ht, table, fout); //построение и вывод кодов символов
			result = Final_Code(my_str, table);
			fout << "\nЗакодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl;
			cout << "\nЗакодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl; //вывод закодированного сообщения
			for (unsigned i = 0; i < 80; i++)
				cout << "-";
			string decoded = hman_decode(ht, result);
			cout << "Декодированное сообщение: " << decoded << endl; //Вывод декодированного сообщения
			for (unsigned i = 0; i < decoded.length(); i++) {
				if (decoded[i] == char(95))
					decoded[i] = char(13);
			}
			fout << endl << "Декодированное сообщение: " << decoded << endl;
		}

		fout << "==============================================================" << endl;
		delete[] priority;
		dictionary.clear();
		table.clear();
		delete[] symbol;
		fout.close();

		if (open)
			cout << "\nЛог действий успешно записан в файл hman.txt" << endl;
	}


	void My::fano(string my_str) {
		bool open = false;
		ofstream fout("fano.txt", ios_base::app);
		if (fout.is_open())
			open = true;

		string result = "";
		bool build = true;

		int * priority = new int[64];
		string * symbol = new string[64];
		for (int i = 0; i < 64; i++) {
			priority[i] = 0;
			symbol[i].clear();
		}

		map<string, string> table; // ассоциативный массив связывающий символ и его код 
		map<char, int> dictionary; //ассоциативный массив связывающий символ и его количество вхождений

		fout << "[Метод Шеннона-Фано]" << endl;
		cout << "                              [Метод Шеннона-Фано]                              " << endl;
		fout << "Введено сообщение: " << char(34) << my_str << char(34) << "\nРазмером: " << my_str.length() * 8 << " бит";
		cout << "Введено сообщение: " << char(34) << my_str << char(34) << "\nРазмером: " << my_str.length() * 8 << " бит";

		//Open_Map_Shen(file, priority, symbol, dictionary); //чтение из файла и запись в массивы
		for (unsigned int i = 0; i < my_str.length(); i++) {
			char tmp = my_str[i];
			dictionary[tmp]++;
		}
		int i1 = -1;
		for (map<char, int>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
			i1++;
			priority[i1] = it->second;
			symbol[i1] = it->first;
		}


		if (dictionary.size() == 1) {
			fout << "\n\nТаблица кодов:" << endl;
			cout << "\n\nТаблица кодов:" << endl;
			result = One_Letter(my_str, dictionary, fout);
			fout << "\n\nЗакодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl;
			cout << "\n\nЗакодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl;
			for (unsigned i = 0; i < 80; i++)
				cout << "-";
			fout << endl << "Декодированное сообщение: " << my_str << endl;
			cout << "Декодированное сообщение: " << my_str << endl;
		}
		else {
			Sort_Symb_Prior(symbol, priority, dictionary); //сортировка массивов: символы и приоритеты

			cout << "\n\nСортируем символы по убыванию приоритета:" << endl;
			fout << "\n\nСортируем символы по убыванию приоритета:" << endl;
			for (unsigned int i = 0; i < dictionary.size(); i++) {
				fout << "'" << symbol[i] << "'(" << priority[i] << ")";
				cout << "'" << symbol[i] << "'(" << priority[i] << ")";
				if ((dictionary.size() - i) != 1) {
					cout << "->";
					fout << "->";
				}
			}

			b_node < f_node > * root = make_root(f_node(0, dictionary.size()));

			Fano_Shennon(0, dictionary.size() - 1, root, priority, symbol, dictionary, true); //построение дерева
			f_node * mas;
			mas = new f_node[100];

			fout << "\n\nПостроение дерева Фано-Шеннона:" << endl;
			cout << "\n\nПостроение дерева Фано-Шеннона:" << endl;
			print2(root, mas, priority, symbol, 0, fout);

			fout << "\n\nТаблица кодов для каждого символа:" << endl;
			cout << "\n\nТаблица кодов для каждого символа:" << endl;
			BuildTable2(root, table, fout);
			result = Final_Code(my_str, table);
			fout << "Закодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl;
			cout << "Закодированное сообщение: " << result << "\nРазмером: " << result.length() << " бит" << endl;
			for (unsigned i = 0; i < 80; i++)
				cout << "-";
			string decoded = fano_decode(root, result);
			cout << "Декодированное сообщение: " << decoded << endl; //Вывод декодированного сообщения
			for (unsigned i = 0; i < decoded.length(); i++) {
				if (decoded[i] == char(95))
					decoded[i] = char(13);
			}
			fout << endl << "Декодированное сообщение: " << decoded << endl;
		}

		fout << "==============================================================" << endl;
		delete[] priority;
		dictionary.clear();
		table.clear();
		delete[] symbol;
		fout.close();

		if (open)
			cout << "\nЛог действий успешно записан в файл fano.txt" << endl;
	}

	void My::print(b_node<node> * root, unsigned k, ofstream &fout) {
		if (root != NULL)
		{
			print(root->r_br, k + 5, fout);

			for (unsigned int i = 0; i < k; i++) {
				cout << "  ";
				fout << "  ";
			}

			if (!root->data.symbol.empty()) {
				fout << "'" << root->data.symbol << "'(" << root->data.priority << ")" << endl;
				cout << "'" << root->data.symbol << "'(" << root->data.priority << ")" << endl;
			}
			else {
				fout << root->data.priority << endl;
				cout << root->data.priority << endl;
			}

			print(root->l_br, k + 5, fout);
		}
	}

	void My::print2(b_node<f_node> * root, f_node* mas, int *priority, string *symbol, int k, ofstream &fout) {
		if (root != NULL)
		{
			print2(root->r_br, mas, priority, symbol, k + 5, fout);
			for (int i = 0; i < k; i++) {
				cout << "  ";
				fout << "  ";
			}

			string s;
			int n = 0;
			for (int i = root->data.left; i <= root->data.right; i++)
			{
				s += symbol[i];
				n += priority[i];
			}

			if (!root->data.symbol.empty()) {
				fout << "'" << s << "'(" << n << ")" << endl;
				cout << "'" << s << "'(" << n << ")" << endl;
			}
			else {
				fout << "'" << s << "'(" << n << ")" << endl;
				cout << "'" << s << "'(" << n << ")" << endl;
			}

			print2(root->l_br, mas, priority, symbol, k + 5, fout);
		}
	}

	void My::BuildTable(b_node<node> *root, map<string, string> &table, ofstream &fout) {
		static std::string s = "";

		if (root->l_br != NULL&&root->r_br != NULL)
		{
			s += "1";

			BuildTable(root->r_br, table, fout);
			s.erase(s.size() - 1, 1);

			s += "0";

			BuildTable(root->l_br, table, fout);
			s.erase(s.size() - 1, 1);
		}
		else
		{
			fout << "'" << root->data.symbol << "'" << " = " << s << endl;
			cout << "'" << root->data.symbol << "'" << " = " << s << endl;
			table[root->data.symbol] = s;
		}
	}

	void My::BuildTable2(b_node<f_node> *root, map<string, string> &table, ofstream &fout) {
		static std::string s = "";

		if (root->l_br != NULL&&root->r_br != NULL)
		{
			s += "1";

			BuildTable2(root->r_br, table, fout);
			s.erase(s.size() - 1, 1);

			s += "0";

			BuildTable2(root->l_br, table, fout);
			s.erase(s.size() - 1, 1);
		}
		else
		{
			fout << "'" << root->data.symbol << "'" << " = " << s << endl;
			cout << "'" << root->data.symbol << "'" << " = " << s << endl;
			table[root->data.symbol] = s;
		}
	}

	int My::Share_to_Intervals(int L, int R, int p[], bool build) {
		if (R - L == 1)
			return L;
		else
		{
			int schet1 = 0;
			int schet2 = 0;
			for (int i = L; i <= R; i++)
			{
				schet1 = schet1 + p[i];
			}
			if (build)
				cout << "Cумма=" << schet1 << endl;

			int d = schet1 / 2;

			int i = L - 1;
			int pos = L;
			bool flag = false;
			while (true)
			{
				if ((schet2 + p[pos]) <= d)
				{
					flag = true;
					schet2 += p[pos];
					i++;
					pos++;
				}
				else
					break;
			}
			if (!flag)i++;

			return i;
		}
	}

	void My::Fano_Shennon(int left, int right, b_node<f_node> *root, int prior[], string *symbol, map<char, int> &dictionary, bool build) {
		if (right - left != 0)
		{
			if (build)
				cout << "\n\nLEFT = " << left << " RIGHT = " << right << endl;
			f_node ln;
			f_node rn;
			int n = Share_to_Intervals(left, right, prior, build);
			if (build)
				cout << "Точка разбиения: " << n << endl;

			int p = 0;
			int p1 = 0;

			for (int i = left; i <= n; i++)
				p += prior[i];

			for (int i = n + 1; i <= right; i++)
				p1 += prior[i];

			ln.left = left;
			ln.right = n;
			ln.symbol = symbol[n];
			ln.priority = p;

			rn.left = n + 1;
			rn.right = right;
			rn.symbol = symbol[n + 1];
			rn.priority = p1;

			if (build) {
				for (unsigned int i = 0; i<dictionary.size(); i++)
				{
					cout << "'" << symbol[i] << "'(" << prior[i] << ") ";
					if (i == n)
						cout << " | ";
				}
			}
			//_getch();

			root->l_br = make_root(ln);
			root->r_br = make_root(rn);

			if (ln.priority>rn.priority)
			{
				root->l_br = make_root(rn);
				root->r_br = make_root(ln);
			}

			Fano_Shennon(left, n, root->l_br, prior, symbol, dictionary, build);

			Fano_Shennon(n + 1, right, root->r_br, prior, symbol, dictionary, build);
		}
	}

	void My::Sort_Symb_Prior(string symbol[], int priority[], map<char, int> &dictionary) {
		for (unsigned int i = 0; i < dictionary.size(); i++)
		{
			for (unsigned int j = 0; j < dictionary.size() - i - 1; j++)
			{
				string temp2;
				int temp1 = 0;
				if (priority[j] < priority[j + 1])
				{
					temp1 = priority[j];
					temp2 = symbol[j];
					priority[j] = priority[j + 1];
					symbol[j] = symbol[j + 1];
					priority[j + 1] = temp1;
					symbol[j + 1] = temp2;
				}
			}
		}
	}

	string My::Final_Code(string str, map<string, string> &table) {
		string result;
		//cout << "Закодированное сообщение:" << endl;

		for (unsigned int i = 0; i < str.length(); i++) {
			string tmp;
			tmp.push_back(str[i]);
			//cout << table[tmp];
			result += table[tmp];
		}
		//cout << endl;
		return result;
	}

	string My::One_Letter(string str, map<char, int> &dictionary, ofstream &fout) {
		string result;
		//cout << dictionary.begin()->first << "(" << dictionary.begin()->second << ")\n" << endl;
		//cout << dictionary.begin()->first << "(" << dictionary.begin()->second << ")\n" << endl;
		fout << "'" << dictionary.begin()->first << "' = 1";
		cout << "'" << dictionary.begin()->first << "' = 1";
		char tmp = str[0];

		//cout << "\nЗакодированное сообщение:" << endl;
		for (int i = 0; i < dictionary[tmp]; i++)
			result += "1";
		//cout << "1";

		return result;
	}

	string My::hman_decode(b_node<node> * b, string encoded_str) {
		string curr, decoded;
		unsigned i = 0;
		while (i < encoded_str.length()) {
			b_node<node> * p = b;
			curr = "";
			while (p->l_br != NULL && p->r_br != NULL) {
				curr += encoded_str[i];
				i++;
				if (curr[curr.length() - 1] == '0') {
					p = p->l_br;
					if (encoded_str.length() < 160)
						cout << "Идём влево, текущий код: " << curr << endl;
				}
				else {
					p = p->r_br;
					if (encoded_str.length() < 160)
						cout << "Идём вправо, текущий код: " << curr << endl;
				}
			}

			if (encoded_str.length() < 160)
				cout << "-> Декодирован символ: '" << p->data.symbol << "'" << endl;
			decoded += p->data.symbol;
			//cout << p->data.symbol << endl;
		}
		return decoded;
	}

	string My::fano_decode(b_node<f_node> * b, string encoded_str) {
		string curr, decoded;
		unsigned i = 0;
		while (i < encoded_str.length()) {
			b_node<f_node> * p = b;
			curr = "";
			while (p->l_br != NULL && p->r_br != NULL) {
				curr += encoded_str[i];
				i++;
				if (curr[curr.length() - 1] == '0') {
					p = p->l_br;
					if (encoded_str.length() < 160)
						cout << "Идём влево, текущий код: " << curr << endl;
				}
				else {
					p = p->r_br;
					if (encoded_str.length() < 160)
						cout << "Идём вправо, текущий код: " << curr << endl;
				}
			}
			if (encoded_str.length() < 160)
				cout << "-> Декодирован символ: '" << p->data.symbol << "'" << endl;
			decoded += p->data.symbol;
			//cout << p->data.symbol << endl;
		}
		return decoded;
	}
}
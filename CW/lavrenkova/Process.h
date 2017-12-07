#pragma once
#include <string>
#include "B_tree.h"
#include "Queue.h"

using namespace bin_tree;
using namespace std;

namespace proc {
	class My {
	private:
		struct node; //Дерево для Хаффмана
		struct f_node; //Дерево для Шеннона-Фано
	public:
		void hman(string my_str); //Метод Хаффмана
		void fano(string my_str); //Метод Шеннона-Фано
		void print(b_node<node> * root, unsigned k, ofstream &fout); //Вывод дерева для метода Хаффмана
		void print2(b_node<f_node> * root, f_node* mas, int *priority, string *symbol, int k, ofstream &fout); //Вывод дерева для метода Шеннона-Фано
		void BuildTable(b_node<node> *root, map<string, string> &table, ofstream &fout); //Построение дерева для метода Хаффмана
		void BuildTable2(b_node<f_node> *root, map<string, string> &table, ofstream &fout); //Построение дерева для метода Шеннона-Фано
		int Share_to_Intervals(int L, int R, int p[], bool build); //Распределение по интервалам
		void Fano_Shennon(int left, int right, b_node<f_node> *root, int prior[], string *symbol, map<char, int> &dictionary, bool build); //Кодирование по дереву
		void Sort_Symb_Prior(string symbol[], int priority[], map<char, int> &dictionary); //Сортировка символов по частоте
		string Final_Code(string str, map<string, string> &table); //Создание закодированного собщения
		string One_Letter(string str, map<char, int> &dictionary, ofstream &fout); //Если в сообщении встречается всего один символ
		string hman_decode(b_node<node> * b, string encoded_str); //Декодирование по методу Хаффмана
		string fano_decode(b_node<f_node> * b, string encoded_str); //Декодирование по методу Шеннона-Фано
	};
}
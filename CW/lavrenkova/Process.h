#pragma once
#include <string>
#include "B_tree.h"
#include "Queue.h"

using namespace bin_tree;
using namespace std;

namespace proc {
	class My {
	private:
		struct node; //������ ��� ��������
		struct f_node; //������ ��� �������-����
	public:
		void hman(string my_str); //����� ��������
		void fano(string my_str); //����� �������-����
		void print(b_node<node> * root, unsigned k, ofstream &fout); //����� ������ ��� ������ ��������
		void print2(b_node<f_node> * root, f_node* mas, int *priority, string *symbol, int k, ofstream &fout); //����� ������ ��� ������ �������-����
		void BuildTable(b_node<node> *root, map<string, string> &table, ofstream &fout); //���������� ������ ��� ������ ��������
		void BuildTable2(b_node<f_node> *root, map<string, string> &table, ofstream &fout); //���������� ������ ��� ������ �������-����
		int Share_to_Intervals(int L, int R, int p[], bool build); //������������� �� ����������
		void Fano_Shennon(int left, int right, b_node<f_node> *root, int prior[], string *symbol, map<char, int> &dictionary, bool build); //����������� �� ������
		void Sort_Symb_Prior(string symbol[], int priority[], map<char, int> &dictionary); //���������� �������� �� �������
		string Final_Code(string str, map<string, string> &table); //�������� ��������������� ��������
		string One_Letter(string str, map<char, int> &dictionary, ofstream &fout); //���� � ��������� ����������� ����� ���� ������
		string hman_decode(b_node<node> * b, string encoded_str); //������������� �� ������ ��������
		string fano_decode(b_node<f_node> * b, string encoded_str); //������������� �� ������ �������-����
	};
}
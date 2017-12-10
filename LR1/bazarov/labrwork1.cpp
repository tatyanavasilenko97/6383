//Labwork1
//Bazarov Ilmurat, group 6383
//17var


#include <iostream>
#include <fstream>

using namespace std;


//function that swaps strings
void swap_str(string &str, string &result);

int main()

{	//reading string from text file
	ifstream fin("in.txt");
	string str, result;
	while(fin >> str){
		cout << "string before=" << str << endl;
		swap_str(str,result);
		cout << "string after=" << result << "\n\n";
		result.clear();
	} 

	return 0;
}

void swap_str(string &str, string &result){
	int pos = str.find('/',0);
	if (pos !=-1) //searching for '/' symbol 
	{
		result.insert(0,str,0,pos); //insert into string
		str.erase(0,pos+1); //erasing charachters from string
		swap_str(str,result);
	}
	else result = str+result;
}

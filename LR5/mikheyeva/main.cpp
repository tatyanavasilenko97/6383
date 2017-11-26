#include <iostream>
#include <cstdlib>
#include "haffman.h"
#include "codetree.h"
#include <climits>
#include <ctime>
using namespace std;

int GenerateRamdom(int min, int max){
    return  min + rand()%(max - min);
}

int main(){
    srand(time(0));
    char a[100];
    int minLength;
    int maxLength;
    cout << "Введите минимальную длину кодируемой строки"<<endl;
    cin >> minLength;
    cout << "Введите максимальную длину кодируемой строки"<<endl;
    cin >> maxLength;
    maxLength++;
    int textLength = GenerateRamdom(minLength,maxLength);
    for (int i = 0; i<textLength;i++)
        a[i] = GenerateRamdom(34,127);
    cout <<"text length = " <<textLength<<endl;
    cout<<"text = "<<a<<endl;
    char* c = encode(haffman(a),a);
    cout <<"haffman code ="<< c <<endl;
    cout<<"check = "<<decode(haffman(a),c);
    return 0;
}


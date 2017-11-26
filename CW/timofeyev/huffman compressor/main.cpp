// Курсовая работа
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману
#include<stdio.h>
#include<iostream>
#include<fstream>
#include"codetree.h"

#include<sstream>
#include<string.h>
#include<algorithm>
#include<iterator>
#include<chrono>

using namespace std;
using namespace std::chrono;
using namespace code_tree;

// a0b00r0100k01100d011011001000!
void test(){
    ifstream input("msg");
    ofstream output("code");
    cout<<"start"<<endl;
    encode(input, output);
    cout<<"coded"<<endl;
    output.close();
    input.close();
    ifstream coded("code");
    ofstream decoded("encoded");
    decode(coded, decoded);
    cout<<"decoded"<<endl;
}

const char* MSG_INFO="Неправильное команда. Пример команды:\n\thuffman -e input output\n\thuffman -d input output\n";

void speedTest(){
    ifstream fin("input");
    ofstream res("decoded");
    stringstream buffer;
    copy(istreambuf_iterator<char>(fin),istreambuf_iterator<char>(),ostreambuf_iterator<char>(buffer));
    fin.close();
    stringstream out;

    milliseconds start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    encode(buffer,out);
    milliseconds finish = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    cout<<"encoding time="<<finish.count()-start.count()<<"ms"<<endl;

    stringstream tmp;
    milliseconds startD = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    decode(out,tmp);
    milliseconds finishD = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    cout<<"decoding time="<<finishD.count()-startD.count()<<"ms"<<endl;

    copy(istreambuf_iterator<char>(tmp),istreambuf_iterator<char>(),ostreambuf_iterator<char>(res));
    res.close();
}

int main(int c, char* args[]){
    if(c==2&&strcmp(args[1],"-benchmark")==0){
        speedTest();
        return 0;
    }

    if(c!=4){
        cout<<MSG_INFO;
        return 0;
    }

    if(strcmp(args[2],args[3])==0){
        cout<<"Имя входного файла совпадает с именем выходного!"<<endl;
        return 0;
    }

    ifstream input(args[2]);
    if(!input){
        cout<<"входной файл не найден!"<<endl;
        return 0;
    }

    if(strcmp(args[1],"-e")==0){
        ofstream output(args[3]);
        encode(input, output);
        return 0;
    }

    if(strcmp(args[1],"-d")==0){
        ofstream output(args[3]);
        decode(input, output);
        return 0;
    }

    cout<<MSG_INFO;
    return 0;
}


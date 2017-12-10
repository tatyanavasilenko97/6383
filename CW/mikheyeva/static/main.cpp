
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "haffman.h"
#include "codetree.h"
#include <climits>
#include <ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;

int inline GenerateRamdom(int min, int max){
    return  min + rand()%(max - min);
}

int main(){
    char* a=(char*) malloc(MaxTextLength*sizeof(char));
    /*
    srand(time(0));
    for (long long i = 0; i<MaxTextLength;i++)
        a[i] = GenerateRamdom(50,127);
    */
    ofstream fout ("output");
    ifstream fin("input");  
    long long int i = 1;
    a[0] = fin.get();
    while(fin.peek()!=EOF)
       {a[i] = fin.get();
        i++;
    }
    milliseconds start_encoding = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    char *c =encode(haffman(a),a,fout);
    milliseconds finish_encoding = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    milliseconds start_decoding = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    decode(haffman(a),c);
    milliseconds finish_decoding = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    cout<<"encoding time="<<finish_encoding.count()-start_encoding.count()<<"s"<<endl;
    cout<<"decoding time="<<finish_decoding.count()-start_decoding.count()<<"s"<<endl;
    fout.close();
    return 0;
}


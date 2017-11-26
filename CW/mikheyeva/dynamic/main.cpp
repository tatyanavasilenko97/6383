#include <iostream>
#include <fstream>
#include "codetree.h"
#include "chrono"
#include <ctime>
const long long int MaxTextLength = 7000000;

using namespace std;
using namespace std::chrono;

int main(){
    ofstream fout("output");
    ofstream foutdec("outputdec");
    ifstream fin("input");
    ifstream findec("input1");
    char *a =(char*) malloc(MaxTextLength*10*sizeof(char));
    long long int i = 0;
    while(fin.peek()!=EOF){
        a[i] = fin.get();
        i++;
    }
    milliseconds start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    code_tree::encode(a,fout);
    milliseconds finish = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    cout << finish.count()-start.count()<<endl;
    code_tree::decode(findec,foutdec);
    fout.close();
    return 0;
}


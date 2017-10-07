#include "stdio.h"
#include <iostream>
#include <fstream>
#include "fun.h"

//
// Михеева Екатерина группа 6383
// 07.10.2017
// вариант 4
//
using namespace std;
using namespace st_modul1;

void read(Stack &s,std::ifstream &in, std::ofstream &out)

{
    char c;
    while ( (c = in.get()) != '\n')
     {
        if (!in){
            in.close();
            out.close()
             ;exit(0);};
        s.push(c);
    }
}


void write(Stack s, std::ofstream &out)
{

    while (!s.isNull())
 {
        out << s.pop2();

    }
    out<<endl;
}

int main(int argc, char *argv[])
{
    ofstream fout("output.txt");
    ifstream fin("input.txt") ;
   fin;

do {

Stack  s;
read(s,fin,fout);

write(s, fout);

   }
   while (true);

  return 0;
}

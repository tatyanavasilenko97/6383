#include <cstdio>
#include <iostream>
#include <fstream>
#include "stack.h"

//
// Михеева Екатерина группа 6383
// 07.10.2017
// вариант 4
//
using namespace std;
//using namespace st_modul1;
void write(Stack &s, std::ofstream &out);
void read(Stack &s,std::ifstream &in, std::ofstream &out)

{

    char c;
    while ((c = in.get()) != '\n' && c!=EOF )

        s.push(c);


}

void write(Stack &s, std::ofstream &out)
{

    while (!s.isNull())
        out << s.pop();

    out<<endl;
}

int main(int argc, char *argv[])
{
    ofstream fout("output.txt");
    ifstream fin("input.txt") ;
   fin;
   Stack  s;
while (!fin.eof())

{

read(s,fin,fout);

write(s, fout);

   }
fin.close();
fout.close();
  return 0;
}

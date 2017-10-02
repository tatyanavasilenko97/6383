#include"list.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

void replace(lisp list, char from, char to){
    if(isNull(list))return;
    if(isAtom(list)){
        if(list->node.atom==from)list->node.atom=to;
    }
    else{
        replace(head(list),from,to);
        replace(tail(list),from,to);
    }
}

const int STACK_SIZE=5;

void replaceIter(lisp list, char from, char to){
    lisp stack[STACK_SIZE];
    int stackPointer=0;
    stack[stackPointer++]=list;

    while(stackPointer!=0){
        if(isNull(list=stack[--stackPointer]))continue;
        if(isAtom(list)){
            if(list->node.atom==from)list->node.atom=to;
            continue;
        }
        if(stackPointer+2>=STACK_SIZE){std::cerr<<"stack overflow"<<std::endl; exit(-1);}
        stack[stackPointer++]=tail(list);
        stack[stackPointer++]=head(list);
    }
}

int main(){
    std::ifstream input ( "input.txt");
    std::ofstream output("output.txt");
    if(!input){std::cerr<<"Входной файл не открыт!"<<std::endl;return -1;}
    char from; input>>from;
    char to;   input>>to;
    lisp list;
    while(input.peek()!=EOF){
        read_lisp(list,input);
        replaceIter(list,from,to);
        write_lisp(list,output);
        output<<std::endl;
        write_lisp(list,std::cout);
        std::cout<<std::endl;
        destroy(list);
    }
    return 0;
}

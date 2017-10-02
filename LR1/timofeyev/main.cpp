//
// Лабораторная работа №1
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 14.09.17
//
// Синтаксический анализатор понятия простое_выражение

#include<iostream>
#include<fstream>

/*
 *
 *     простое_выражение      ::=  простой_идентификатор | (простое_выражение знак_операции простое_выражение)
 *     простой_идентификатор  ::=  буква
 *     знак_операции          ::=  – | + | *
 *
 *
 */

enum ANALISIS_RESULT{
    OK,
    INCORRECT_SIGN,
    CLOSE_BRACKET_ERROR,
    UNKNOWN_SYMBOL,
    DELIMETER_MISS
};

void printResult(std::ostream &out, ANALISIS_RESULT res){
    switch(res){
    case OK:                   out<<"  // ОК"<<std::endl; return;
    case INCORRECT_SIGN:       out<<"  // Некорректный знак, ожидался знак + - *"          <<std::endl; return;
    case CLOSE_BRACKET_ERROR:  out<<"  // Отсутствует закрывающая скобка"                  <<std::endl; return;
    case UNKNOWN_SYMBOL:       out<<"  // Неизвестный символ, ожидалось выражение"         <<std::endl; return;
    case DELIMETER_MISS:       out<<"  // Неизвестный символ, ожидался конец выражения"    <<std::endl; return;
    }
}

bool isSign(char c){
    return c=='-'||c=='+'||c=='*';
}

bool isLetter(char c){
    return ('a' <= c && 'z'>=c) || ('A' <= c && 'Z'>= c);
}


ANALISIS_RESULT analisis(std::istream &in,std::ostream &out){
    if(isLetter(in.peek())){
        out<<(char)in.get();
        return OK;
    }

    if('('==in.peek()){
        out<<(char)in.get();
        ANALISIS_RESULT res=analisis(in, out);
        if(OK!=res)return res;

        if(!isSign(in.peek())){
            out<<(char)in.peek();
            return INCORRECT_SIGN;
        }
        out<<(char)in.get();

        res=analisis(in,out);
        if(OK!=res)return res;

        if(in.peek()!=')'){
            out<<(char)in.peek();
            return CLOSE_BRACKET_ERROR;
        }
        out<<(char)in.get();

        return OK;
    }

    out<<(char)in.peek();
    return UNKNOWN_SYMBOL;
}

ANALISIS_RESULT analisisAndControlLastSymbol(std::istream &in,std::ostream &out){
    ANALISIS_RESULT res=analisis(in,out);
    if(OK!=res)return res;
    if(in.peek()!='\n'&&in.peek()!=' '&&in.peek()!='\0'&&in.peek()!=EOF){
        out<<(char)in.peek();
        return DELIMETER_MISS;
    }
    return OK;
}

void skipLine(std::istream &in){
    while(in.peek()!='\n'&&in.peek()!=EOF)in.get();
    if(in.peek()=='\n')in.get();
}

void test(){
    std::ifstream fin("../input.txt");
    if(!fin.is_open()){
        std::cout<<"Файл не открыт"<<std::endl;
        return;
    }

    while(true){
        ANALISIS_RESULT res=analisisAndControlLastSymbol(fin,std::cout);
        printResult(std::cout,res);
        skipLine(fin);
        if(fin.peek()==EOF)break;
    }
}

int main(){
    //test();
    std::cout<<"строка: ";
    ANALISIS_RESULT res=analisisAndControlLastSymbol(std::cin,std::cout);
    printResult(std::cout,res);
    return 0;
}

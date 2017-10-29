//
// Лабораторная работа №4
// form.cpp
// Тимофеев Дмитрий, группа 6383
// 19.10.17
//
// Программирование алгоритмов с бинарными деревьями

#include"form.h"
using namespace std;
namespace form_modul{

    //< формула > ::= < терминал > | ( < формула >  < знак >  < формула > )
    //< знак > ::= + | - | *
    //< терминал > ::=  0 | 1 | ... | 9 | a | b | ... | z

    bool isSign(char c){
        return c=='+'||c=='-'||c=='*';
    }

    bool isTerminal(char c){
        return isdigit(c)||(c>='a'&&c<='z');
    }

    Form readForm(istream &in){
        if(isTerminal(in.peek())){
            return ConsBT(in.get(),NULL,NULL);
        }
        if(in.peek()=='('){
            in.get();
            Form b=readForm(in);
            if(!isSign(in.peek()))throw "Ожидался знак\n";
            char s=in.get();
            b=ConsBT(s,b,readForm(in));
            if(in.peek()!=')')throw "Ожидался символ ')'";
            in.get();
            return b;
        }
        throw "Ожидался терминал или '('\n";
    }

    void writeForm(ostream &out, const Form f){
        if(isNull(f))throw "Ошибка формула не может быть пустой\n";
        if(isNull(Right(f))&&isNull(Left(f))){
            out<<RootBT(f);
            return;
        }
        if(isNull(Right(f))||isNull(Left(f)))
            throw "Узел в формуле должен содержать оба поддерева\n";
        out<<'(';
        writeForm(out,Left(f));
        out<<RootBT(f);
        writeForm(out,Right(f));
        out<<')';
    }

    Form deriviate(const Form f, char var){
        if(var==RootBT(f)||isdigit(RootBT(f))||isalpha(RootBT(f))){
            if(!isNull(Right(f))||!isNull(Left(f)))
                throw "Некорректная формула: переменная или константа не может быть в корне\n";
            if(var==RootBT(f))             // x'=1
                return ConsBT('1',NULL,NULL);
            return ConsBT('0',NULL,NULL);  // const'=0
        }

        if(RootBT(f)=='+'||RootBT(f)=='-') // (f(x) +/- g(x))' = f'(x) +/- g'(x)
            return ConsBT(
                          RootBT(f),
                          deriviate(Left(f),var),
                          deriviate(Right(f),var)
                   );
        if(RootBT(f)=='*')                 // (f(x)*g(x))'=f'(x)*g(x)+f(x)*g'(x)
            return ConsBT(
                          '+',
                          ConsBT(
                              '*',
                              deriviate(Left(f),var),
                              Right(f)
                          ),
                          ConsBT(
                              '*',
                              Left(f),
                              deriviate(Right(f),var)
                          )
                   );
        throw "Некорректная формула: неизвестный символ\n";
    }
}

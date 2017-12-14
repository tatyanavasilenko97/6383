#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int FindBracket(int len,char *str){ //функция для поиска позиции символа ")"
        if(len==1) return 0;
        int open=1;
        int close=0;
        char *symb=str+1;
        while(open != close){
                if(*symb=='(') open++;
                if(*symb==')') close++;
                if(*symb==0) return 0;
                if(symb==str+len) break;
                symb++;
                }
                return symb-str;
                }
int func(int len,char *str) //рекурсивная фунция для анализа строки на поняте "скобки"
        {if(len<1)
            return 0;
        if(*str=='A' && len==1)
        {
        return 1;
        }
        if(*str=='(' && *(str+1)=='B')
        {
            if(FindBracket(len,str)==0) return 0;
            int left=func(FindBracket(len,str)-3,str+2);
            int right=func(len-FindBracket(len,str),str+FindBracket(len,str));
        return left * right;
        }
        else
        {
            return 0;
        }
}
int main(int argc,char **argv)
{
setlocale(LC_ALL, "Rus");
    char *str=(char*)malloc(501);
               printf("Введите последовательность: ");
            scanf("%s",str);
    int len=strlen(str);
    if(len==0)
        {
            printf("Строка пуста!\n");
            return 0;
        }
    if(*str!='A' && (*str!='(' || FindBracket(len,str)==0))
        {
            printf("Ваша комбинация не является скобкой\n");
            return 0;
        }
    if(func(len,str)==1)
        {
            printf("Ваша комбинация является скобкой\n");
        }
    else
        {
            printf("Ваша комбинация не является скобкой\n");
        }
    free(str);
    return 0;
}

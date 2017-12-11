#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int FindBracket(int len,char *str){ //������� ��� ������ ������� ������� ")"
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
int func(int len,char *str) //����������� ������ ��� ������� ������ �� ������ "������"
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
               printf("������� ������������������: ");
            scanf("%s",str);
    int len=strlen(str);
    if(len==0)
        {
            printf("������ �����!\n");
            return 0;
        }
    if(*str!='A' && (*str!='(' || FindBracket(len,str)==0))
        {
            printf("���� ���������� �� �������� �������\n");
            return 0;
        }
    if(func(len,str)==1)
        {
            printf("���� ���������� �������� �������\n");
        }
    else
        {
            printf("���� ���������� �� �������� �������\n");
        }
    free(str);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "queue.hpp"
void f1(Queue in); // Функция для выполнения первой части задания
void f2(Queue in); // Второй
void f3(Queue in); // Третьей
double a,b;
int main(int argc, char const *argv[])
{
    FILE* f = fopen("/Users/denislubchyk/Documents/studies/lab3/lab_3.1/lab_3.1/input.txt", "r"); // Открытие файла
    if(!f)
    {
        printf("Can't open file \"input.txt\"\n");
        exit(1);
    }
    
    printf("Input a and b: \n");
    scanf("%lf %lf", &a, &b);
    if (a>=b)
    {
        printf("Wrong input.\n");
        exit(1);
    }
    double d;
    Queue q;
    
    while (!feof(f)) // Чтение из файла
    {
        if (fscanf(f, "%lf", &d)>0) // Если данные прочитались верно
        {
            q.put(d);
        }
    }
    f1(q);
    f2(q);
    f3(q);
    fclose(f);
    return 0;
}
void f1(Queue in)
{
    double d;
    while(!in.isEmpty())
    {
        d = in.take();
        if (d<a) printf("%lf ", d);
    }
}
void f2(Queue in)
{
    double d;
    while(!in.isEmpty())
    {
        d = in.take();
        if (d>=a && d<=b) printf("%lf ", d);
    }
}
void f3(Queue in)
{
    double d;
    while(!in.isEmpty())
    {
        d = in.take();
        if (d>b) printf("%lf ", d);
    }
}

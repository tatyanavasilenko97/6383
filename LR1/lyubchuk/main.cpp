#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int square(FILE *fp, FILE *f, char a, int i);// Функция для идентификации квадратных скобок
int round(FILE *fp, FILE *f, char a, int i);// -//- круглых скобок
int figure(FILE *fp, FILE *f, char a, int i);// -//- фигурных скобок
int znak(FILE *fp, FILE *f, char* a); //Функция для считывания и вывода данных посимвольно
int main() {
    char a; int b = 0; int answer; FILE *fp; FILE *f; int i = 0; char br[10000];
    printf("What do you want to do:\n1.enter data\n2.read data from a file\n");
    scanf("%d", &answer);
    while (answer != 1 && answer != 2)
    {
        printf("Wrong answer. Try again.\n");
        scanf("%d", &answer);
    }
    if (answer == 1) {  //Считываем данные с клавиатуры и записываем в файл input для дальнейшего использования
        fp = fopen("D:\\study\\input.txt", "w"); //открыли файл ввода, чтобы переписать туда данные с консоли
        printf("Enter data:\n");
        scanf("%s", br);
        fputs(br, fp);
        fclose(fp);
    }
    if (answer == 2) {
        fp = fopen("D:\\study\\input.txt", "r");//Если выбрали ввод из файла, надо вывести данные на консоль для наглядности
        printf("Data from the file: ");
        do
        {
            a = fgetc(fp);
            printf("%c", a);
        } while (a != EOF);
        printf("\n");
        fclose(fp);
    }
    fp = fopen("D:\\study\\input.txt", "r");//открыли файл ввода
    if (fp == NULL) {
        fprintf(stderr, "Error: file 'input.txt' is not opened!\n");
        exit(EXIT_FAILURE);
    }
    f = fopen("D:\\study\\output.txt", "w");//открыли файл вывода
    if (f == NULL) {
        fprintf(stderr, "Error: You can`t create 'output.txt' file!\n");
        exit(EXIT_FAILURE);
    }
    printf("Analysing...\n");
    znak(fp, f, &a);
    if (a == EOF) {//Проверка на наличие в файле данных
        printf("The file is empty");
        fprintf(f, "The file is empty");
        return 0;
    }                        //Проверка первого символа. Если он не соответствует возможному началу скобок, программа завершает работу, иначе - переходит в функцию для дальнейшей проверки на скобки
    if (a == '+' || a == '[')
        b = square(fp, f, a, i);
    if (a == '-' || a == '(')
        b = round(fp, f, a, i);
    if (a == '0' || a == '{')
        b = figure(fp, f, a, i);
    if (b == 1 && fscanf(fp, "%c", &a) == 1) {//Случай, если данные - скобки, но в конце присутствуют лишние символы
        printf("\nThere are extra characters. This is not brackets!");
        fprintf(f, "\nThere are extra characters. This is not brackets!");
        return 0;
    }
    if (b != 1) {
        printf("\nThis is not brackets!");
        fprintf(f, "\nThis is not brackets!");
    }
    if (b == 1) {
        printf("\nThis is brackets!");
        fprintf(f, "\nThis is brackets!");
    }
    fclose(fp);//закрытие файла ввода
    fclose(f);//и вывода
    return 0;
}
int square(FILE *fp, FILE *f, char a, int i) {
    for (int k = 0; k < i; k++) { //печать отступа, соответствующего глубине рекурсии. i - счётчик, который увеличивается при новом входе в функцию проверки скобок и уменьшается при выходе
        printf(" ");
        fprintf(f, " ");
    }
    i++;
    if (a != '+' && a != '[') { //проверка на то, является ли текущий символ допустимым для скобок
        printf("\n\"[\" or \"+\" must be there");
        fprintf(f, "\n\"[\" or \"+\" must be there");
        return 0;
    }
    if (a == '+') {//первый из допустимых вариантов символа для данных скобок, дальнейшая проверка для них не требуется
        i--;
        printf("This is square brackets\n");
        fprintf(f, "This is square brackets\n");
        return 1;
    }
    if (a == '[') {//второй из допустимых вариантов символа для данных скобок
        printf("Check for square brackets\n");
        fprintf(f, "Check for square brackets\n");
        znak(fp, f, &a);
        if (round(fp, f, a, i) == 1) {//проверка на то, находятся ли внутри круглые скобки. Если так, функция продолжает работу
            znak(fp, f, &a);
            if (figure(fp, f, a, i) == 1) {//проверка на то, находятся ли внутри фигурные скобки. Если так, то далее потребуется лишь закрывающий символ квадратных скобок
                znak(fp, f, &a);
                if (a == ']') {//проверка на завершающий символ данных скобок
                    i--;
                    for (int k = 0; k < i; k++) {
                        printf(" ");
                        fprintf(f, " ");
                    }
                    fprintf(f, "This is square brackets\n");
                    printf("This is square brackets\n");
                    return 1;
                    
                }
            }
        }
    }
    return 0;
}
int round(FILE *fp, FILE *f, char a, int i){//функция похожа на предыдущую, поэтому комментарии будут вставлены только там, где есть какие-либо различия
    for (int k = 0; k < i; k++) {
        printf(" ");
        fprintf(f, " ");
    }
    i++;
    if (a != '-' && a != '(') {
        printf("\n\"(\" or \"-\" must be there");
        fprintf(f, "\n\"(\" or \"-\" must be there");
        return 0;
    }
    if (a == '-') {
        i--;
        printf("This is round brackets\n");
        fprintf(f, "This is round brackets\n");
        return 1;
    }
    if (a == '(') {
        printf("Check for round brackets\n");
        fprintf(f, "Check for round brackets\n");
        znak(fp, f, &a);
        if (figure(fp, f, a, i) == 1) {	//проверка на то, находятся ли внутри фигурные скобки. Если так, функция продолжает работу
            znak(fp, f, &a);
            if (square(fp, f, a, i) == 1) {//проверка на то, находятся ли внутри квадратные скобки. Если так, то далее потребуется лишь закрывающий символ квадратных скобок
                znak(fp, f, &a);
                if (a == ')') {
                    i--;
                    for (int k = 0; k < i; k++) {
                        printf(" ");
                        fprintf(f, " ");
                    }
                    printf("This is round brackets\n");
                    fprintf(f, "This is round brackets\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}
int figure(FILE *fp, FILE *f, char a, int i){//функция похожа на предыдущую, поэтому комментарии будут вставлены только там, где есть какие-либо различия
    for (int k = 0; k < i; k++) {
        printf(" ");
        fprintf(f, " ");
    }
    i++;
    if (a != '0' && a != '{') {
        printf("\n\"{\" or \"0\" must be there");
        fprintf(f, "\n\"{\" or \"0\" must be there");
        return 0;
    }
    if (a == '0') {
        i--;
        printf("This is figure brackets\n");
        fprintf(f,"This is figure brackets\n");
        return 1;
    }
    if (a == '{') {
        printf("Check for figure brackets\n");
        fprintf(f, "Check for figure brackets\n");
        znak(fp, f, &a);
        if (square(fp, f, a, i) == 1) {//проверка на то, находятся ли внутри квадратные скобки. Если так, функция продолжает работу
            znak(fp, f, &a);
            if (round(fp, f, a, i) == 1) {//проверка на то, находятся ли внутри круглые скобки. Если так, то далее потребуется лишь закрывающий символ квадратных скобок
                znak(fp, f, &a);
                if (a == '}') {
                    i--;
                    for (int k = 0; k < i; k++) {
                        printf(" ");
                        fprintf(f, " ");
                    }
                    printf("This is figure brackets\n");
                    fprintf(f, "This is figure brackets\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}
int znak(FILE *fp, FILE *f, char* a) {
    *a = fgetc(fp);
    printf("%c", *a);
    fputc(*a, f);
    return 0;
}

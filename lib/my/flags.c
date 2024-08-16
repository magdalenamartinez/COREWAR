/*
** EPITECH PROJECT, 2022
** flags.c
** File description:
** flags.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int compare_flag(char const *format, int i);
int compare_sihay(char const *format, int i);
int compare_sihay_2(char const *format, int i);
int compare_flag_2(char const *format, int i);
char* flags_exist(char const *format,int  i)
{
    int k = 0; int num = -1; int fin = 0; i++;
    int j = -1; char *s = malloc(sizeof(char *));
    while (j == -1 && fin == 0) {
        j = compare_sihay(format, i);
        if (j == -1) {
            num = compare_flag(format,i);
        }
        if (num == -1) {
            fin = 1;
        }
        if (num >= 0 && j == -1) {
            s[k] = format[i]; k++;
        }
        i++;
    }
    if (j == 0) {
        s = NULL;
    }
    return s;
}

int compare_flag(char const *format, int i)
{
    int num = 0;
    switch (format[i]) {
        case '#':
        case '0':
        case '-':
        case '+':
        case ' ':
        case '*':
        case '1':
        case '2':
        case '3':
            num = i;
            break;
        default:
            num = compare_flag_2(format, i);
            break;
    }
    return num;
}

int compare_flag_2(char const *format, int i)
{
    int num = 0;
    switch (format[i]) {
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
        case '_':
        case ';':
        case ',':
        case ':':
            num = i; break;
        default:
            num = -1;
            break;
    }
    return num;
}

int compare_sihay(char const *format, int i)
{
    int pos = -1;
    switch (format[i]) {
        case 'd':
        case 'i':
        case 'u':
        case 'x':
        case 'X':
        case 'f':
        case 'F':
        case 'o':
        case 'e':
            pos = i;
            break;
        default:
            pos = compare_sihay_2(format,i);
            break;
    }
    return pos;
}

int compare_sihay_2(char const *format, int i)
{
    int pos = -1;
    switch (format[i]) {
        case 'E':
        case 'g':
        case 'G':
        case 'a':
        case 'A':
        case 'c':
        case 's':
        case 'p':
        case 'n':
        case 'S':
        case '%':
            pos = i;
            break;
    }
    return pos;
}

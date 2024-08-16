/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp2
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my_ls.h"
int my_subcmp(char **str, int j);
char ** my_subcmp2(int may, char **str, char *temp, int j);
int  my_strcmp2(char **str, char *temp)
{
    int c = 0;
    while (str[c] != NULL) {
        c++;
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c - 1; j++) {
            str = help(str, i, j);
        }
    }
    return 0;
}

char** help(char **str, int i, int j)
{
    char *temp;
    if (str[j][0] > str[j + 1][0]) {
        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
    }
    if (str[j][0] == str[j + 1][0]) {
        str = my_subcmp2(my_subcmp(str, j), str, temp, j);
    }
    return (str);
}

int my_subcmp(char **str, int j)
{
    int may = 0; int i = 0;
    while (str[j][i] == str[j + 1][i] && str[j][i] != '\0') {
        i++;
    }
    if (str[j][i] != '\0') {
        may = 1;
    }
    return may;
}

char** my_subcmp2(int may, char **str, char *temp, int j)
{
    if (may == 1) {
        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
    }
    return str;
}

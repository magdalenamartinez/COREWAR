/*
** EPITECH PROJECT, 2022
** pre.c
** File description:
** pre.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"
int pre_hag(char *str, char a)
{
    int change = 0;
    if (str[0] == '#') {
        if (a == 'o') {
            my_putchar('0');
        }
        if (a == 'x') {
            my_putstr("0x");
        }
        if (a == 'X') {
            my_putstr("0X");
        }
        if (a != 'o' && a != 'x' && a != 'X') {
            change = pre_hag2(a, 0);
        }
    }
    return change;
}

int pre_hag2(char a, int change)
{
    if (a == 'a' || a == 'A' || a == 'd' || a == 'e') {
        change = 1;
    }
    if (a == 'E' | a == 'f' || a == 'F' || a == 'g') {
            change = 1;
    }
    if (a == 'G' || a == 'i') {
        change = 1;
    }
    return change;
}

int pre_zero(char *s, char a)
{
    int fin = 0; int i = 0; int p = 0;
    char c = s[i]; char b = s[0];
    while ((s[i] > 58 || s[i] < 48) && s[i] != '\0') {
        i++;
    }
    b = s[i]; c = s[++i];
    while (c != '\0') {
        if (c < 58 && c > 48 && b == '0' && p == 0) {
            fin = 1;
        }
        if (c == '.' || c == '-') {
            p = 1;
        }
        i++; c = s[i];
    }
    if (p == 1) {
        fin = 0;
    }
    return fin;
}

int pre_num(char *str, char a)
{
    int i = 0; int j = 0; int n = 0;
    char *num = malloc(sizeof(str)); int pre = 0;
    while (str[i] != '\0' && pre == 0) {
        if (str[i] < 58 && str[i] > 47) {
            num[j] = str[i];
            j++;
        }
        if (str[i] == '.') {
            pre = 1;
        }
        i++;
    }
    n = my_getnbr(num);
    return n;
}

int pre_pre(char *str, char a)
{
    int i = 0; int j = 0; int n = 0; char c;
    char *num = malloc(sizeof(str)); int pre = 0;
    while (str[i] != '\0' && pre == 0) {
        if (str[i] == '.') {
            pre = 1;
        }
        i++;
    }
    if (pre == 1) {
        c = str[i];
        while (c != '\0' && c < 58 && c > 47) {
            num[j] = str[i]; j++; i++; c = str[i];
        }
        n = my_getnbr(num);
    } else {
        n = 6;
    }
    return n;
}

/*
** EPITECH PROJECT, 2022
** pre2.c
** File description:
** pre2.c
*/
#include <stdarg.h>
#include "../../include/my.h"
int pre_aux(int signo, int pos);
int pre_pos(char *str, char a)
{
    int dev = 0; int i = 0; int enc = 0;
    int pos = 0; int signo = 1; int fin = 0;
    while (str[i] != '\0' && fin == 0) {
        if (str[i] == '-') {
            signo = -1; enc = 1;
        }
        if (str[i] == '+') {
            pos = 1; enc = 1;
        }
        if (str[i] != '+' && str[i] != '-' && enc == 1) {
            fin = 1;
        }
        i++;
    }
    dev = pre_aux(signo, pos);
    return dev;
}

int pre_aux(int signo, int pos)
{
    int dev = 0;
    if (signo == -1) {
        dev = 1;
    }
    if (signo != -1 && pos == 1) {
        dev = 2;
    }
    return dev;

}

int pre_space(char *str, char a)
{
    int i = 0;
    if (str[i] == ' ') {
        if (a == 'a' || a == 'A' || a == 'd' || a == 'e') {
            my_putchar(' ');
        }
        if (a == 'E' || a == 'f' || a == 'F' || a == 'g') {
            my_putchar(' ');
        }
        if (a == 'G' || a == 'i') {
            my_putchar(' ');
        }
    }
    return 0;
}

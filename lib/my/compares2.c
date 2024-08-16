/*
** EPITECH PROJECT, 2022
** compares2.c
** File description:
** compares2.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int compare6(char a, va_list list, int n, char *s)
{
    int num = 0; pre_space(s, a);
    int z = pre_zero(s, a); int e = pre_num(s, a);
    int pos = pre_pos(s, a); int p = pre_pre(s, a);
    switch (a) {
        case 'x':
            num = va_arg(list, int);
            if (num < 0) {
                n += my_put_hexa(num * -1, e, z, pos);
            } else {
                n += my_put_hexa(num, e, z, pos);
            }
            break;
        default:
            n = compare7(a, list, n, s);
            break;
    }
    return n;
}

int compare7(char a, va_list list, int n, char *s)
{
    char *str; int num = 0; int p = pre_pre(s, a);
    pre_space(s, a); int z = pre_zero(s, a);
    int e = pre_num(s, a); int pos = pre_pos(s, a);
    switch (a) {
        case 'S':
            str = va_arg(list, char *);
            my_put_printables(str);
            break;
        case '%':
            my_putchar('%'); n++;
            break;
        default:
            n = compare8(a, list, n, s);
            break;
    }
    return n;
}

int compare8(char a, va_list l, int n, char *s)
{
    int num = 0; double numf = 0.0; pre_space(s, a);
    int z = pre_zero(s, a);int e = pre_num(s, a);
    int p = pre_pre(s, a); int pos = pre_pos(s, a);
    switch (a) {
        case 'f':
        case 'F':
            numf = va_arg(l, double);
            n += my_put_float(numf);
            break;
        default:
            n = compare9(a, l, n, s);
            break;
    }
    return n;
}

int compare9(char a, va_list l, int n, char *s)
{
    int num = 0; pre_space(s, a);
    int z = pre_zero(s, a);int e = pre_num(s, a);
    int p = pre_pre(s, a); int pos = pre_pos(s, a);
    switch (a) {
        case 'X':
            num = va_arg(l, int);
            if (num < 0) {
                n += my_put_hexa_may(num * -1, e, z, pos);
            } else {
                n += my_put_hexa_may(num, e, z, pos);
            }
            break;
        default:
            n = compare10(a, l, n ,s);;
            break;
    }
    return n;
}

int compare10(char a, va_list l, int n, char *s)
{
    int num = 0; double numf = 0.0; pre_space(s, a);
    int z = pre_zero(s, a);int e = pre_num(s, a);
    int p = pre_pre(s, a); int pos = pre_pos(s, a);
    switch (a) {
        case 'o':
            num = va_arg(l, int);
            if (num < 0) {
                n += my_put_octa(num * -1, e, z, pos);
            } else {
                n += my_put_octa(num, e, z, pos);
            }
            break;
        default:
            my_putchar('%'); my_putchar(a); n += 2;
            break;
    }
    return n;
}

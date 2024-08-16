/*
** EPITECH PROJECT, 2022
** compares.c
** File description:
** compares.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int compare1(char a, va_list l, int n, char *s)
{
    int m = 0; int z = 0; int c = pre_hag(s, a); pre_space(s, a);
    int p = 0; int e = 0; z = pre_zero(s, a); e = pre_num(s, a);
    int pos = 0; pos = pre_pos(s, a); p = pre_pre(s, a); int num = 0;
    switch (a) {
        case 'd': case 'i':
            m = va_arg(l, int); n += my_put_nbr(m, e, z, pos);
            break;
        case 'u':
            num = va_arg(l, int);
            if (num < 0) {
                n += my_putstr("4294962729");
            } else {
                n += my_put_nbr_u(num, e, z, pos);
            }
            break;
        default:
            n = compare2(a, l, n, s); break;
    }
    return n;
}

int compare2(char a, va_list list, int n, char *s)
{
    int p = 0; double numf = 0; int z = 0; int e = 0;
    int pos = 0; int sp = 0; z = pre_zero(s, a); e = pre_num(s, a);
    pos = pre_pos(s, a); p = pre_pre(s, a); sp = pre_space(s, a);
    switch (a) {
        case 'e':
            numf = va_arg(list, double);
            n += my_put_exp(numf);
            break;
        case 'E':
            numf = va_arg(list, double);
            n += my_put_exp_may(numf);
            break;
        default:
            n = compare3(a, list, n, s);
            break;
    }
    return n;
}

int compare3(char a, va_list list, int n, char *s)
{
    double numf = 0.0; int z = 0; z = pre_zero(s, a);
    int e = 0; e = pre_num(s, a); int pos = 0; pos = pre_pos(s, a);
    int p = 0; p = pre_pre(s, a); int sp = 0; sp = pre_space(s, a);
    switch (a) {
        case 'g':
            numf = va_arg(list, double);
            n += my_put_float_exp(numf, s, a);
            break;
        case 'G':
            numf = va_arg(list, double);
            n += my_put_float_exp_may(numf, s, a);
            break;
        default:
            n = compare4(a, list, n, s);
            break;
    }
    return n;
}

int compare4(char a, va_list list, int n, char *s)
{
    char *str = ""; int z = 0; z = pre_zero(s, a);
    int e = 0; e = pre_num(s, a); int pos = 0; pos = pre_pos(s, a);
    int p = 0; p = pre_pre(s, a); int sp = 0; sp = pre_space(s, a);
    switch (a) {
        case 'c':
            my_putchar(va_arg(list, int)); n++;
            break;
        case 's':
            str = va_arg(list, char *);
            if (str == NULL) {
                n += my_putstr("(null)");
            } else {
                n += my_putstr(str);
            }
            break;
        default:
            n  = compare5(a, list, n, s); break;
    }
    return n;
}

int compare5(char a, va_list list, int n, char *s)
{
    int num = 0; char *str = ""; char *pointer = "";
    int z = 0; z = pre_zero(s, a);
    int e = 0; e = pre_num(s, a); int po = 0; po = pre_pos(s, a);
    int p = 0; p = pre_pre(s, a); int sp = 0; sp = pre_space(s, a);
    switch (a) {
        case 'p':
            num = va_arg(list, long int); my_putstr("0x");
            my_put_hexa(my_getnbr(pointer), z, e, po);
            break;
        case 'n':
            pointer = malloc(sizeof(int *));
            *pointer = va_arg(list, int);
            break;
        default:
            n = compare6(a, list, n, s);
            break;
    }
    return n;
}

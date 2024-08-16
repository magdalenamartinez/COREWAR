/*
** EPITECH PROJECT, 2022
** src/my_put_float_exp.c
** File description:
** funcion which
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"
int num_div(float num);
int my_put_float_exp(float nf, char *s, char a)
{
    int e = pre_num(s, a); int z = pre_zero(s, a);
    int pos = pre_pos(s, a); int h = pre_hag(s, a);
    int p = pre_pre(s, a); float num = nf; int counter = 0;
    int count = 0; counter = num_div(num);
    if (counter < p && counter >= -4) {
        if (h == 0) {
            count = my_put_float_zero(nf);
        } else {
            count = my_put_float(nf);
        }
    } else {
        p = p - 1; count = my_put_exp(nf);
    }
    return count;
}

int num_div(float num)
{
    int counter = 0;
    if (num < 1) {
        while (num < 1) {
            num = num * 10; counter++;
        }
    } else {
        while (num >= 10) {
            num = num / 10; counter++;
        }
    }
    return counter;
}

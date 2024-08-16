/*
** EPITECH PROJECT, 2022
** my_put_exp.c
** File description:
** my_put_exp.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
int left_exp_may(float nf);
int right_exp_may(float nf);

int my_put_exp_may(float nf)
{
    if (nf < 1) {
        left_exp_may(nf);
    } else {
        right_exp_may(nf);
    }
    return 0;
}

int left_exp_may(float nf)
{
    int num = 0;
    int counter = 0;
    while (nf < 1) {
        nf = nf * 10;
        counter++;
    }
    num = num + my_put_float(nf);
    my_putstr("E-");
    if (counter < 10) {
        my_putchar('0');
    }
    num = num + my_put_nbr(counter, 0, 0, 6);
    return (num + 3);
}

int right_exp_may(float nf)
{
    int num = 0;
    int counter = 0;
    while (nf >= 10) {
        nf = nf / 10;
        counter++;
    }
    num = num + my_put_float(nf);
    my_putstr("E+");
    if (counter < 10) {
        my_putchar('0');
    }
    num = num + my_put_nbr(counter, 0, 0, 6);
    return (num + 3);
}

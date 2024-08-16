/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** my_put_float.c
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"
void my_putchar(char c);

float comp_c_z(float nf, int nb, float c);

int counterfunction_z(float num, int d, float nf);

int my_put_float_zero(float nf)
{
    int d = 1; int counter = 0; int c2 = 0; int c1 = 0;
    if (nf < 0) {
        my_putchar('-'); nf = nf * -1;
    }
    float c = 1; counter = counterfunction_z(nf, 1, nf);
    nf = comp_c_z(nf, 0, 1);
    while ((nf / d) >= 10) {
        d *= 10; c2++;
    }
    c2++; c1 = counter;
    while (d > 0) {
        my_putchar((int)(nf / d) % 10 + '0'); d /= 10;
        if (counter == 0) {
            my_putchar('.');
        }
        counter--;
    }
    return 0;
}

float comp_c_z(float nf, int nb, float c)
{
    while (c != 0) {
        nf = nf * 10; nb = (int) nf; c = nf - nb;
    }
    return nf;
}

int counterfunction_z(float num, int d, float nf)
{
    int counter = 0;
    while (num > 1) {
        num = nf / d; d = d * 10; counter++;
    }
    return (counter - 2);
}

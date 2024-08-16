/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"
int pos_previo(int e, int z, int pos);
int neg_fun_n(int nb);
int my_put_nbr_u(int nb, int e, int z, int pos)
{
    int d = 1; int counter = 1; int r = 0;
    if (nb == -2147483648) {
        my_putstr("-2147483648"); r = 11;
    } else {
        nb = neg_fun_n(nb);
        while ((nb / d) >= 10) {
            d *= 10; counter++;
        };
        e = e - counter;
        if (pos == 0 || pos == 2) {
            spaces(e, z, pos);
        }
        while (d > 0) {
            my_putchar((nb / d) % 10 + '0'); d /= 10; r++;
        }
        if (pos == 1) {
            spaces(e, z, pos);
        }
    }
    return (r - 1);
}

int neg_fun_n(int nb)
{
    if (nb < 0) {
        my_putchar('-'); nb *= -1;
    }
    return nb;
}

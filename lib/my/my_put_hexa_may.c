/*
** EPITECH PROJECT, 2022
** my_put_hexa_may.c
** File description:
** my_put_hexa_may.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
int num_zz(int num);
int my_put_hexa_may(int num, int e, int z, int pos)
{
    int counter = 0; char *str; int i = 0; int mod;
    str = malloc(sizeof(char *)); num_zz(num);
    while (num > 0) {
        mod = num % 16; num = num / 16;
        if (mod > 9) {
            str[i] = mod + 55;
        } else {
            str[i] = mod + '0';
        }
        i++; counter++;
    }
    e = e - counter;
    if (pos == 0 || pos == 2) {
        spaces(e, z, pos);
    }
    my_putstr(my_revstr(str));
    if (pos == 1) {
        spaces(e, z, pos);
    }
    return counter;
}

int num_zz(int num)
{
    if (num == 0) {
        my_putchar('0');
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_put_octa.c
** File description:
** my_put_octa.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

int compare_zero(int num);
int my_put_octa(int num, int e, int z, int pos)
{
    int mod; int counter = 0; num = compare_zero(num);
    char *str; int i = 0; str = malloc(sizeof(char *));
    while (num > 0) {
        mod = num % 8; num /= 8;
        str[i] = mod + '0'; i++; counter++;
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

int compare_zero(int num)
{
    if (num < 0) {
        num = num * -1;
    }
    if (num == 0) {
        my_putchar(48);
    }
    return num;
}

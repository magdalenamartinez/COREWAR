/*
** EPITECH PROJECT, 2022
** my_put_octa_char.c
** File description:
** my_put_octa_char.c
*/

#include <stdio.h>
#include <stdlib.h>
char *my_revstr(char *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_octa_char(char num)
{
    int counter = 0; char *str; int i = 0;
    if (num < 0) {
        num = num * -1;
    }
    if (num == 0) {
        my_putchar(48);
    }
    str = malloc(sizeof(char *));
    while (num > 0) {
        int mod = num % 8; num = num / 8;
        str[i] = mod + '0'; i++; counter++;
    }
    my_putstr(my_revstr(str));
    return counter;
}

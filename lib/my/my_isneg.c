/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** function which says if a number is positive or negative
*/

#include <stdio.h>
void my_putchar(char a);
int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}

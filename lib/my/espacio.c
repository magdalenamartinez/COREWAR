/*
** EPITECH PROJECT, 2022
** espacio.c
** File description:
** espacio.c
*/
#include <stdarg.h>
#include "../../include/my.h"
void my_putchar(char a);
int spaces(int e, int z, int pos)
{
    while (e > 0) {
        if (z == 0 || pos == 1) {
            my_putchar(' ');
        } else {
            my_putchar('0');
        }
        e--;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_printf.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"
int my_printf(char const *format, ...)
{
    int l = 0; int i = 0; int c = 0; int n = 0;
    char *s = "";
    if (format == NULL) {
        return -1;
    }
    va_list list; va_start(list, format);
    s = malloc (sizeof(char *));
    while (format[i] != '\0') {
        if (format[i] == '%') {
            s = flags_exist(format, i);
            l = my_strlen(s); i += l;
            c = compare1(format[i + 1], list, n, s); i++;
        } else {
            my_putchar(format[i]); c++;
        }
        i++;
    }
    va_end(list); return c;
}

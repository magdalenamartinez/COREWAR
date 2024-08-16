/*
** EPITECH PROJECT, 2022
** lib/my/int_to_str.c
** File description:
** funcion which
*/

#include "my.h"

void int_to_string(int num, char *str)
{
    int i, isNegative = 0;
    if (num == 0) {
        str[i++] = '0'; str[i] = '\0'; return;
    }
    if (num < 0) {
        isNegative = 1; num = -num;
    }
    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }
    if (isNegative) str[i++] = '-';
    str[i] = '\0';
    int start = 0; int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp; start++; end--;
    }
}

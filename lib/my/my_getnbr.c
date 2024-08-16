/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0; int neg = 0; long num = 0;
    neg = 1;
    while (str[i] == '+' || str[i] == '-')
        neg *= str[i++] == '+' ? 1 : -1;
    while (str[i] != '\0'){
        if (str[i] > 47 && str[i] < 58){
            num = num * 10 + str[i] - 48;
        } else {
            break;
        }
        i++;
    }
    if (num < -2147483648 || num > 2147483647){
        return 0;
    }
    return (num * neg);
}

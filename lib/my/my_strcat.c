/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** concatenate 2 strings
*/
#include <stdlib.h>
#include <stdio.h>
int my_strlen(char const *l);
char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int n = 0;
    char *sol = malloc(sizeof(*sol)*(my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        sol[i] = dest[i];i++;
    }
    while (src[j] != '\0') {
        sol[i + j] = src[j]; j++;
    }
    sol[i + j] = '\0';
    return (sol);
}

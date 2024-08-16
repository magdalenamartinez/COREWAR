/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** funcion which
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strdup(char const *src)
{
    char *str;
    int size = my_strlen(src);
    int i = 0;
    str = malloc(sizeof(char) * size);
    while (i < size){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return &str[0];
}

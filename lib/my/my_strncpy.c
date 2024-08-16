/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** funcion which
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (i <= n){
        if (i == n || src[i] == '\0'){
            dest[i] = '\0';
            break;
        }
        dest[i] = src[i];
        i++;
    }
    return dest;
}
/*
int main (void){
    char *src = "holita";
    char *dest;

    printf("%s\n", my_strncpy(dest, src, -10));
}
*/

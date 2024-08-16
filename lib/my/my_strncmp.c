/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    while (s1[i] != '\0' && i < n){
        if (s2[i] == '\0'){
            return 1;
        }
        i++;
    }
    if (s2[i] == '\0' || i == n){
        return 0;
    }
    return -1;
}
/*
int main (void){
    char *str1 = "12345678";
    char *str2 = "1234";
    printf("%d\n", my_strcmp(str1, str1, 9));
    printf("%d\n", my_strcmp(str2, str2, 9));
    printf("%d\n", my_strcmp(str1, str2, 3));
    printf("%d\n", my_strcmp(str2, str1, 3));
    return 0;
}
*/

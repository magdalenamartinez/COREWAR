/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** funcion which
*/

#include <stdio.h>

int sizer(char const *str);

char *my_strstr(char *src, char const *to_find)
{
    int i = 0;
    int j = 0;
    int found = 0;
    int size = sizer(to_find);
    while (src[i] != '\0' && !found){
        j = 0;
        int n = i;
        while (src[n] == to_find[j]){
            j == size - 2 ? found = 1 : found;
            j++;
            n++;
        }
        i++;
    }
    return &src[--i];
}

int sizer(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return ++i;
}
/*
int main (void){
    char *src = "holita";
    char *to_find = "";

    printf("%s\n", my_strstr(src, to_find));
}
*/

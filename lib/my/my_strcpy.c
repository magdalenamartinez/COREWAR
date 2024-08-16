/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** funcion which
*/

#include <stdio.h>
void my_strcpy(char* dst, const char* src)
{
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
/*
int main (void){
    char *src = "Hello";
    char *dest;
    printf("%s\n", my_strcpy(dest, src));
}
*/

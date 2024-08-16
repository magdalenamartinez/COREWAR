/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** funcion which
*/

#include <stdio.h>
void my_putchar(char a);
int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i++]);
    }
    return 0;
}
/*
int main (void)
{
    char *str = "hello";
    my_putstr(str);
    return 0;
}
*/

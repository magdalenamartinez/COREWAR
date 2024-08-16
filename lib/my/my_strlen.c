/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
/*
void write_number(int i)
{
    if (i / 10)
        write_number(i / 10);
    int c = i % 10 + 48;
    my_putchar(c);
}
int main (void)
{
    char *str = "hello world!";
    printf("%d\n", my_strlen(str));
    return 0;
}
*/

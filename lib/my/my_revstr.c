/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse a string
*/

#include <stdio.h>

char *my_revstr(char *str)
{
    char temp;
    int i = 0;
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    counter--;
    int n = counter / 2;
    while (i <= n) {
        temp = str[i];
        str[i] = str[counter];
        str[counter] = temp;
        i++;
        counter--;
    }
    return (str);
}
/*
int main()
{
    int i = 0;
    char str[20]="abcdefghijklmn";
    char *re=my_revstr(str);
    while(re[i]!='\0')
    {
        putchar(re[i]);
        i++;
            }
    return 0;
}
*/

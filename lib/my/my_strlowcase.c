/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** funcion which
*/

#include <stdio.h>

char *my_strlowcase(char *str)
{
    int i = 0;
    do {
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
        i++;
    } while (str[i] != '\0');
    return (str);
}
/*
int main(void){
    char str[ ] = "h2oLa";
    printf(my_strupcase(str));
    return 0;
}
*/

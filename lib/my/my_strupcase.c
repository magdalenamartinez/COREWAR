/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** funcion which
*/

#include <stdio.h>

char *my_strupcase(char *str)
{
    int i = 0;
    do {
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
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

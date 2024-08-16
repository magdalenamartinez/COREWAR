/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_str_isupper(char const *str)
{
    int i = 0;
    while (str[i] != 0){
        if (str[i] < 'A' || str[i] > 'Z'){
            return 0;
        }
        i++;
    }
    return 1;
}
/*
int main(void)
{
    char str[ ] = "htbnmc";
    printf("%d\n", my_str_isupper(str));
}
*/

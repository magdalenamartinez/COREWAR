/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] != 0){
        if (str[i] < 'a' || str[i] > 'z'){
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
    printf("%d\n", my_str_islower(str));
}
*/

/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != 0){
        int is_low = str[i] >= 'a' && str[i] <= 'z';
        int is_up = str[i] >= 'A' && str[i] <= 'Z';
        if (!is_low && !is_up){
            return 0;
        }
        i++;
    }
    return 1;
}
/*
int main(void)
{
    char str[ ] = "ht-.r¡CGHGHcJcJTc";
    printf("%d\n", my_str_isalpha(str));
}
*/

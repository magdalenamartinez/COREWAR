/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i] != 0){
        if (str[i] < '0' || str[i] > '9'){
            return 0;
        }
        i++;
    }
    return 1;
}
/*
int main(void)
{
    char str[ ] = "56asd78as9";
    printf("%d\n", my_str_isnum(str));
}
*/

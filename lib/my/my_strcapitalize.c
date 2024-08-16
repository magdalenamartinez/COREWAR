/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** funcion which
*/

#include <stdio.h>

char *my_strcapitalize(char *str)
{
    int i = 1;
    if (str[0] >= 'a' && str[0] <= 'z'){
        str[0] = str[0] - 32;
    }
    do {
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+'){
            i++;
            if (str[i] >= 'a' && str[i] <= 'z'){
                str[i] = str[i] - 32;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
        i++;
    } while (str[i] != '\0');
    return str;
}
/*
int main(void)
{
    char str[ ] = "hey, how are you? 42WORds forty-two; fifty+one";
    printf(my_strcapitalize(str));
}
*/

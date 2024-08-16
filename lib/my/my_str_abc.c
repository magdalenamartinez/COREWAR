/*
** EPITECH PROJECT, 2022
** my_str_abc.c
** File description:
** my_str_abc.c
*/

char *help_cod(char *str, int i, int j);
char * my_str_abc(char *str)
{
    int c = 0; char temp;
    while (str[c] != '\0') {
        c++;
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c - 1; j++) {
            str = help_cod(str, i, j);
        }
    }
    return str;
}

char *help_cod(char *str, int i, int j)
{
    char temp;
    if (str[i] > str[j]) {
        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
    }
    return (str);
}

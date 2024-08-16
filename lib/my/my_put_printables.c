/*
** EPITECH PROJECT, 2022
** my_put_printables.c
** File description:
** my_put_printables.c
*/

void my_putchar(char a);
int my_put_octa(int i);
int my_put_printables(char *str)
{
    int i = 0;
    while (str[i] != 0){
        char c = str[i];
        if (c >= 32 && c <= 127){
            my_putchar(c);
        } else {
            my_put_octa(str[i]);
        }
        i++;
    }
    return i;
}

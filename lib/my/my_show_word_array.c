/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** funcion which
*/

#include <stdio.h>

void my_putchar(char a);
int  my_show_word_array(char *const  *tab)
{
    int i = 0; int j = 0;
    while (tab[i] != NULL){
        while (tab[i][j] != '\0') {
            my_putchar(tab[i][j]); j++;
        }
        my_putchar('\n'); i++;
    }
    return 0;
}

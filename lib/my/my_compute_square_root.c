/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int i = 1;
    if (nb < 0)
        return 0;
    while (i * i < nb){
        i++;
    }
    if (i * i == nb){
        return i;
    } else {
        return 0;
    }
}
/*
int main (void){
    printf("%d\n", my_compute_square_root(25));
    printf("%d\n", my_compute_square_root(0));
    printf("%d\n", my_compute_square_root(8));
    printf("%d\n", my_compute_square_root(-3));
}
*/

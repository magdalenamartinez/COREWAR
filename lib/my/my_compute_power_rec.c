/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** funcion which
*/

#include <stdio.h>

long calculator(int nb, int p);

int my_compute_power_rec(int nb, int p)
{
    long num = calculator(nb, p);
    if (num < -2147483648 || num > 2147483647){
        return 0;
    }
    return num;
}

long calculator(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    return nb * calculator(nb, p - 1);
}
/*
int main (void){
    printf("%d\n", my_compute_power_rec(5, 3));
    printf("%d\n", my_compute_power_rec(5, 0));
    printf("%d\n", my_compute_power_rec(5, -3));
    printf("%d\n", my_compute_power_rec(-3, 3));
    printf("%d\n", my_compute_power_rec(0, 3));
    printf("%d\n", my_compute_power_rec(4567890, 73));
}
*/

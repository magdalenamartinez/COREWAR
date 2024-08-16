/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** function which.
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    int i = 2;
    int temp = 0;
    if (nb <= 1) return 0;
    while (i < nb / 2){
        if (nb % i == 0){
            temp++;
        }
        i++;
    }
    if (temp > 0)
        return 0;
    return 1;
}

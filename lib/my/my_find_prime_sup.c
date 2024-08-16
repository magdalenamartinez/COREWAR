/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** funcion which
*/

#include <stdio.h>

int is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int found = 0;
    while (!found){
        if (is_prime(nb))
            return nb;
        nb++;
    }
    return nb;
}

int is_prime(int nb)
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
/*
int main (void){
    printf("%d\n", my_find_prime_sup(5));
    printf("%d\n", my_find_prime_sup(0));
    printf("%d\n", my_find_prime_sup(1));
    printf("%d\n", my_find_prime_sup(2));
    printf("%d\n", my_find_prime_sup(3));
    printf("%d\n", my_find_prime_sup(27));
    printf("%d\n", my_find_prime_sup(8));
    printf("%d\n", my_find_prime_sup(19));
    printf("---");
    printf("%d\n", my_find_prime_sup(814));
    printf("---");
    printf("%d\n", my_find_prime_sup(376819));
}
*/

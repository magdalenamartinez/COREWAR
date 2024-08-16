/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** funcion which
*/

#include <stdio.h>

void my_swap(int *a, int *b)
{
    int temp1 = *a;
    int temp2 = *b;
    *a = temp2;
    *b = temp1;
}
/*
int main (void)
{
    int n1 = 12;
    int n2 = 21;
    int *a, *b;
    a = &n1;
    b = &n2;
    printf("Before swapping\n - a -> %d\n - b -> %d\n", *a, *b);
    my_swap(a, b);
    printf("After swapping\n - a -> %d\n - b -> %d\n", *a, *b);
    return 0;
}
*/

/*
** EPITECH PROJECT, 2022
** libmy.c
** File description:
** funcion which
*/

#include <stdio.h>
#include <unistd.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}

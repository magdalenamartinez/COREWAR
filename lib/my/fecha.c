/*
** EPITECH PROJECT, 2022
** fecha.c
** File description:
** fecha
*/

#include "../../include/my_ls.h"

int mes(char *fecha, int i)
{
    int m; char *f = "EFMAMJJASOND";
    switch (fecha[i]) {
        case 'E': m = 1; break;
        case 'F': m = 2; break;
        case 'M': m = 3; break;
        case 'A': m = 4; break;
        case 'J': m = 6; break;
        case 'S': m = 9; break;
        case 'O': m = 10; break;
        case 'N': m = 11; break;
        case 'D': m = 12; break;
    }
    return (mes2(m, fecha, i));
}

int mes2(int m, char *fecha, int i)
{
    if (m == 3) {
        if (fecha[i + 2] == 'y') {
            m = 5;
        }
    }
    if (m == 4) {
        if (fecha[i + 1] == 'g') {
            m = 8;
        }
    }
    if (m == 6) {
        if (fecha[i + 2] == 'l') {
            m = 7;
        }
    }
    return m;
}

int mes3(int m)
{
    switch (m) {
        case 1: my_putstr("ene"); break;
        case 2: my_putstr("feb"); break;
        case 3: my_putstr("mar"); break;
        case 4: my_putstr("abr"); break;
        case 5: my_putstr("may"); break;
        case 6: my_putstr("jun"); break;
        case 7: my_putstr("jul"); break;
        case 8: my_putstr("ago"); break;
        case 9: my_putstr("sep"); break;
        case 10: my_putstr("oct"); break;
        case 11: my_putstr("nov"); break;
        case 12: my_putstr("dic"); break;
    }
    return 0;
}

int fecha_espacio(char *fecha, int i)
{
    while (fecha[i] != ' ') {
        i++;
    }
    return i;
}

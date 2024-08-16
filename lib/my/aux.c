/*
** EPITECH PROJECT, 2022
** aux.c
** File description:
** aux
*/
#include "../../include/my_ls.h"
int counter_function(char *str)
{
    int counter = 0; int i = 0;
    while (str[i] != '\0') {
        counter++; i++;
    }
    return counter;
}

char** name_array(int argc, char **argv)
{
    int enc = 0; int i = 1; char **str; int j = 0;
    while (argc > i && enc == 0) {
        if (argv[i][0] != '-') {
            enc = 1;
        }
        i++;
    }
    int n = num_names(argc, argv);
    str = malloc (sizeof(str) + sizeof(char*) * (n + 1));
    i--;
    while (argc > i && enc == 1) {
        str[j] = argv[i];
        j++; i++;
    }
    return str;
}

int num_names(int argc, char **argv)
{
    int n = 0; int enc = 0; int i = 1;
    while (argc > i && enc == 0) {
        if (argv[i][0] != '-') {
            enc = 1;
        }
        i++;
    }
    i--;
    if (enc == 1) {
        n = argc - i;
    }
    return n;
}

int intro(char **name, int i, int n)
{
    if (n > 1) {
        my_printf("%s: \n", name[i]);
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** aux2.C
** File description:
** aux2
*/

#include "../../include/my_ls.h"
int num_bloques(char *name)
{
    DIR *p = opendir(name);
    struct stat buf;
    struct dirent *pd; int counter = 0;
    while ((pd = readdir(p)) != NULL) {
        if (pd -> d_name[0] != '.') {
            stat(pd -> d_name, &buf);
            counter = counter + buf.st_blocks;
        }
    }
    if (counter < 0) {
        counter = 0;
    }
    return counter;
}

char** nombres_dir(char *name)
{
    char **nombres; int c = counter_dir(name);
    nombres = malloc(sizeof(nombres)*sizeof(char*)*c);
    DIR *p = opendir(name); int i = 0;
    struct dirent *pd;
    while ((pd = readdir(p)) != NULL) {
        if (pd -> d_name[0] != '.') {
            nombres[i] = pd -> d_name; i++;
        }
    }
    return nombres;
}

int counter_dir(char *name)
{
    int counter = 0;
    DIR *p = opendir(name); int i = 0;
    struct dirent *pd;
    while ((pd = readdir(p)) != NULL) {
        if (pd -> d_name[0] != '.') {
            counter++;
        }
    }
    return counter;
}

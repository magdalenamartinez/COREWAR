/*
** EPITECH PROJECT, 2022
** options2.c
** File description:
** options2
*/

#include "../../include/my_ls.h"
int counter_n(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int option_r2(DIR *p, char *name)
{
    struct dirent *pd; struct stat buf; int i = 0; char *dir;
    dir = malloc(sizeof(dir)); option_default(opendir(name));
    int c = counter_dir(name); my_putchar('\n'); int s = 0;
    int d = 0; char **str = malloc(sizeof(str)+sizeof(char*) * c);
    str = nombres_dir(name); char *t = malloc(sizeof(t));
    my_strcmp2(str,t);
    while (str[i] != NULL) {
        dir = my_strcat(my_strcat(name, "/"), str[i]);
        stat(dir, &buf); s = (buf.st_mode & S_IRUSR) ? 1 : 0;
        d = S_ISDIR(buf.st_mode);
        if (d == 1 && s == 1) {
            my_printf("%s:\n", dir); option_r2(p, dir);
        }
        if (d == 1 && s == 0) {
            my_printf("%s:\n", dir);
            my_printf("ls: %s Permission denied\n\n", dir);
        }
        i++;
    }
    return 0;
}

int option_d(DIR *p, char *name)
{
    DIR *t = opendir("."); struct dirent *pd;
    while ((pd = readdir(t)) != NULL) {
        if (my_strcmp(pd->d_name,name) == 0) {
            my_printf("%s ",pd->d_name);
        }
    }
    return 0;
}

int option_tt(DIR *p, char *name)
{
    struct stat buf; int c = counter_dir(name); char *pr;
    char *seg; char **str = malloc(sizeof(str) + sizeof(char*) * c);
    char *temp = malloc(sizeof(char*)); str = nombres_dir(name);
    int i = 0; char *t;
    t = malloc(sizeof(char*)); pr = malloc(sizeof(char*));
    seg = malloc(sizeof(char*));
    while (str[i]) {
        stat(str[i], &buf);
        stat(str[i + 1], &buf);
        if (seg > pr) {
            t = str[i]; str[i] = str[i + 1];
            str[i + 1] = t; i = 0;
        }
        i++;
    }
    i = 0;
    while (str[i]) {
        my_printf("%s ",str[i]); i++;
    }
    return 0;
}

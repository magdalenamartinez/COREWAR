/*
** EPITECH PROJECT, 2022
** options.c
** File description:
** options
*/

#include "../../include/my_ls.h"

int option_a(DIR *p)
{
    struct dirent *pa;
    char **str; int i = 0;
    char *temp;
    str = malloc(sizeof(str));
    temp = malloc(sizeof(char*));
    while ((pa = readdir(p)) != NULL) {
        str[i] = pa -> d_name;;
        i++;
    }
    my_strcmp2(str,temp);
    i = 0;
    while (str[i] != NULL) {
        my_putstr(str[i]);
        my_putchar(' ');
        i++;
    }
    my_putchar('\n');
    return 0;
}

int option_r1(DIR *p)
{
    struct dirent *pd;
    char **str; int i = 0;
    char *temp;
    str = malloc(sizeof(str));
    temp = malloc(sizeof(char*));
    while ((pd = readdir(p)) != NULL) {
        if (pd -> d_name[0] != '.') {
            str[i] = pd -> d_name;
            i++;
        }
    }
    my_strcmp2(str,temp);
    i--;
    while (i != -1) {
        my_putstr(str[i]); my_putchar('\n');
        i--;
    }
    return 0;
}

int option_default(DIR *p)
{
    struct dirent *pd;
    char **str; int i = 0;
    char *temp;
    str = malloc(sizeof(str));
    temp = malloc(sizeof(char*));
    while ((pd = readdir(p)) != NULL) {
        if (pd->d_name[0] != '.') {
            str[i] = pd -> d_name;
            i++;
        }
    }
    my_strcmp2(str,temp);
    i = 0;
    while (str[i] != NULL) {
        my_putstr(str[i]); my_putchar(' ');
        i++;
    }
    my_putchar('\n');
    return 0;
}

int option_l(DIR *p, char *name)
{
    int i = 0; struct dirent *pd; char *dir;
    dir = malloc(sizeof(dir));
    const char *login; struct passwd *pw;
    time_t *times; struct group *gp; struct stat buf;
    my_printf("total %i\n", num_bloques(name));
    int c = counter_dir(name); char **str;
    str = malloc(sizeof(str) + sizeof(char*) * c);
    str = nombres_dir(name); i = 0; char *temp;
    temp = malloc(sizeof(temp)); my_strcmp2(str,temp);
    while (str[i]) {
            dir = my_strcat(my_strcat(name, "/"), str[i]);
            stat(dir, &buf); pw = getpwuid(buf.st_uid);
            permisos(buf); my_printf(" %d ", buf.st_nlink);
            my_printf("%s ", pw -> pw_name);
            gp = getgrgid(buf.st_gid); my_printf("%s ", gp -> gr_name);
            my_printf("%d ", buf.st_size);
            fecha(ctime(&buf.st_mtime));
            my_printf(" %s", str[i]); my_putchar('\n'); i++;
    }
    return 0;
}

int fecha(char *fecha)
{
    int i = 0; int encontrado = 0; int counter = 0;
    i = fecha_espacio(fecha, i); int m = mes(fecha,i + 1);
    i++; i = fecha_espacio(fecha, i); i++;
    while (fecha[i] != ' ') {
        my_putchar(fecha[i]); i++;
    }
    my_putchar(' '); mes3(m);
    while (encontrado != 1) {
        if (fecha[i] == ':') {
            counter++;
        }
        if (counter == 2) {
            encontrado = 1;
        } else {
            my_putchar(fecha[i]);
        }
        i++;
    }
    return 0;
}

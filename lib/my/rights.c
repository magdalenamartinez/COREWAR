/*
** EPITECH PROJECT, 2022
** rights.c
** File description:
** rights
*/

#include "../../include/my_ls.h"

int my_printf(char const *format, ...);
int permisos(struct stat buf)
{
    buf.st_mode & S_IFDIR ? my_printf("d") : my_printf("-");
    buf.st_mode & S_IRUSR ? my_printf("r") : my_printf("-");
    buf.st_mode & S_IWUSR ? my_printf("w") : my_printf("-");
    buf.st_mode & S_IXUSR ? my_printf("x") : my_printf("-");
    buf.st_mode & S_IRGRP ? my_printf("r") : my_printf("-");
    buf.st_mode & S_IWGRP ? my_printf("w") : my_printf("-");
    buf.st_mode & S_IXGRP ? my_printf("x") : my_printf("-");
    buf.st_mode & S_IROTH ? my_printf("r") : my_printf("-");
    buf.st_mode & S_IWOTH ? my_printf("w") : my_printf("-");
    buf.st_mode & S_IXOTH ? my_printf("x") : my_printf("-");
    return 0;
}

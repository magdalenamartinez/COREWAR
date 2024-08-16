/*
** EPITECH PROJECT, 2022
** my_ls.h
** File description:
** my_ls
*/

#ifndef MY_LS_H_
    #define MY_LS_H_
    #define S_ISUID 0004000  /* set user id on execution */
    #define S_ISGID 0002000  /* set group id on execution */
    #define S_ISVTX 0001000  /* save swapped text even after use */
    #define S_IRUSR 0000400  /* read permission, owner */
    #define S_IWUSR 0000200  /* write permission, owner */
    #define S_IXUSR 0000100
    #define S_IFDIR 0040000  /* directory */
    #include <unistd.h>
    #include <time.h>
    #include <stdio.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include "my.h"
    #include <dirent.h>
    int fecha(char *f);
    int mes3(int m);
    int mes(char *fecha, int i);
    int permisos(struct stat buffer);
    int counter_n(char *str);
    int my_printf(char const *format,...);
    int my_strcmp2(char **str, char *temp);
    int option_r1(DIR *p);
    int option_default(DIR *p);
    char* options_sub2(char *st, char *str, int n);
    char* my_str_abc(char *str);
    int  option_a(DIR *p);
    int option_l(DIR *p, char *name);
    int options_sub(char *str, DIR *p, char *name);
    int options(int argc, char **argv, DIR *p, char *name);
    int option_r2(DIR *p, char *name);
    int read_name(int argc, char **argv);
    int option_d(DIR *p, char *name);
    int option_tt(DIR *p, char* name);
    char ** help(char **str, int i, int j);
    int fecha_espacio(char *fecha, int i);
    int option_al(DIR *p);
    int mes2(int m, char *fecha, int i);
    int counter_function(char *str);
    int options_of_a(DIR *p, char *str);
    int num_bloques(char *name);
    char** nombres_dir(char *name);
    int counter_dir(char *name);
    int num_names(int argc, char **argv);
    char** name_array(int argc, char **argv);
    int intro(char **name, int i, int n);
#endif /*MY_LS_H_*/

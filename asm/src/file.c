/*
** EPITECH PROJECT, 2023
** file
** File description:
** file
*/

#include "../../include/asm.h"

int study_parameters(int argc, char** argv)
{
    if (argv[1][0] == '-') {
        if (argv[1][1] == 'h') {
            display_help();
            return SUCCESS_EXIT;
        }
    }
    return (study_file(argv[1]));
}

void display_help(void)
{
    my_printf("USAGE\n");
    my_printf("./asm file_name[.s]\nDESCRIPTION\n");
    my_printf("file_name file in assembly language to be converted into ");
    my_printf("file_name.cor, an executable in the Virtual Machine.");
}

int study_file(char *filename)
{
    char buffer[MAX_BUFFER];
    int f = open(filename, O_RDONLY);
    if (f == -1) {
        return 84;
    } else {
        int check = read_s(filename);
        if (check != 0) {
            read_file(f, buffer, filename);
        }
        return 0;
    }
}

void read_file(int file, char* buffer, char* filename)
{
    int len = 0;
    int offset = 0;
    while ((len = read(file, buffer + offset, MAX_BUFFER - offset)) > 0) {
        offset += len;
    }
    buffer[offset] = '\0';
    translate_header(buffer, filename);
    close(file);
}

int read_s(char* filename)
{
    int i = 0;
    int check = 0;
    while (filename[i] != '\0') {
        i++;
    }
    if (filename[i - 1] == 's') {
        if (filename[i - 2] == '.') {
            check = 1;
        }
    }
    return check;
}

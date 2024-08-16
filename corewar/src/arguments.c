/*
** EPITECH PROJECT, 2023
** arguments.c
** File description:
** arguments.c
*/

#include "../../include/corewar.h"

int study_args(int argc, char **argv)
{
    int i = 1;
    args_t* args_s = initialise_args();
    memory_t* mem_s = initialise_memory();
    while (i < argc) {
        if (argv[i][0] == '-') {
            i = study_params(args_s, argv[i], argv[i + 1], i);
        } else {
            study_name_prog(args_s, argv[i], mem_s);
        }
        i++;
    }
    if (mem_s->counter < 2) {
        return ERROR_EXIT;
    }
    write_memory(mem_s);
    make_loop(mem_s);
    print_winner(mem_s);
    return 0;
}

void  study_name_prog(args_t* args_s, char* progname, memory_t* mem_s)
{
    if (file_exists(progname) == 1 && check_not_read(progname, mem_s) == 0) {
        int s = mem_s->counter + 1;
        if (mem_s->names == NULL) {
            mem_s->names = malloc(sizeof(char*) * s);
        } else {
            mem_s->names = realloc(mem_s->names, sizeof(char*) * s);
        }
        s = my_strlen(progname);
        mem_s->names[mem_s->counter] = malloc(sizeof(char) * s);
        mem_s->names[mem_s->counter] = progname;
        add_program(args_s, progname, mem_s);
        reset_values(args_s);
    }
}

int check_not_read(char* progname, memory_t* mem)
{
    int i = 0;
    if (mem->names == NULL) {
        return 0;
    }
    while (i < mem->counter) {
        if (my_strcmp(progname, mem->names[i]) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

int file_exists(char* filename)
{
    FILE* file;
    if ((file = fopen(filename, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

int check_number(char* num)
{
    int check = 1;
    int j = 0;
    while (num[j] != '\0' && check == 1) {
        if (num[j] < 48 || num[j] > 58) {
            check = 0;
        }
        j++;
    }
    return check;
}

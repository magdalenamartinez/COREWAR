/*
** EPITECH PROJECT, 2023
** parameters
** File description:
** parameters
*/

#include "../../include/corewar.h"

int study_params(args_t* args_s, char* act, char* num, int i)
{
    int n = 1, j = 0;
    char word[256];
    if (act[1] == 'a' && act[2] == '\0') {
        return (load_address(i, num, args_s));
    }
    if (act[1] == 'n' && act[2] == '\0') {
        return (prog_name(i, num, args_s));
    }
    while (act[n] != '\0') {
        word[j++] = act[n++];
    }
    word[j] = '\0';
    if (my_strcmp(word, "dump") == 0) {
        return (dump_function(i, num, args_s));
    }
    return i;
}

int dump_function(int i, char* num, args_t* args_s)
{
    int check = 0;
    if (num != NULL) {
            check = check_number(num);
        }
        if (check == 1) {
            args_s->nbr_cycle = my_getnbr(num);
        } else {
            return i;
        }
        return ++i;
}

int prog_name(int i, char* num, args_t* args_s)
{
    int check = 0;
    if (num != NULL) {
        check = check_number(num);
    }
    if (check == 1) {
        args_s->program_nbr = my_getnbr(num);
    } else {
        return i;
    }
    return ++i;
}

int load_address(int i, char* num, args_t* args_s)
{
    int check = 0;
    if (num != NULL) {
        check = check_number(num);
    }
    if (check == 1) {
        args_s->load_address = my_getnbr(num);
    } else {
        return i;
    }
    return ++i;
}

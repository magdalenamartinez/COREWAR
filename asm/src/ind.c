/*
** EPITECH PROJECT, 2023
** ind
** File description:
** ind
*/

#include "../../include/asm.h"

int study_ind(lines_t* st, int i)
{
    int check = 0;
    int bit = st->line[st->count].bit_pos;
    st->line[st->count].bits[bit] = '1';
    st->line[st->count].bits[bit + 1] = '1';
    st->line[st->count].bit_pos += 2;
    char a = st->line[st->count].line[i];
    char b = st->line[st->count].line[i];
    int n = i + 1;
    while (a != ' ' && a != '\0') {
        a = st->line[st->count].line[i++];
    }
    int num = st->line[st->count].num_arg;
    st->line[st->count].arg[num].type = 3;
    save_number(b, st, n, num);
    return i;
}

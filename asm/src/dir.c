/*
** EPITECH PROJECT, 2023
** dir
** File description:
** dir
*/

#include "../../include/asm.h"

int study_dir(lines_t* st, int i)
{
    int check = 0;
    int n = i + 2;
    int t = i;
    char b = st->line[st->count].line[i + 1];
    if (b > 47 && b < 58) {
        check = 1;
    } else if (b == ':') {
        check = 2;
    }
    if (check == 1 || check == 2) {
        bit_function(st);
        i = check_function(st, i);
    }
    switch (check) {
        case 1: check_one(st, b, n); break;
        case 2: check_two(st, b, t); break;
    }
    return i;
}

void bit_function(lines_t* st)
{
    int bit = st->line[st->count].bit_pos;
    st->line[st->count].bits[bit] = '1';
    st->line[st->count].bits[bit + 1] = '0';
    st->line[st->count].bit_pos += 2;
}

int check_function(lines_t* st, int i)
{
    char a = st->line[st->count].line[i];
    while (a != ' ' && a != '\0' && a != '\n' && a != '\t') {
        a = st->line[st->count].line[i++];
    }
    return i;
}

void check_one(lines_t* st, char b, int n)
{
    int num = st->line[st->count].num_arg;
    st->line[st->count].arg[num].type = 2;
    save_number(b, st, n, num);
}

void check_two(lines_t* st, char b, int t)
{
    int num = st->line[st->count].num_arg;
        st->line[st->count].arg[num].type = 4;
        st->line[st->count].num_arg++;
        save_word(st, t, num);
}

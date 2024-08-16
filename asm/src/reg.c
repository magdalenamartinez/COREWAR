/*
** EPITECH PROJECT, 2023
** reg.c
** File description:
** reg.c
*/

#include "../../include/asm.h"

int study_reg(lines_t* st, int i)
{
    int check = 0;
    char b = st->line[st->count].line[i + 1];
    if (b > 47 && b < 58) {
        check = 1;
        save_reg(st, i);
    }
    if (check == 1) {
        int bit = st->line[st->count].bit_pos;
        st->line[st->count].bits[bit] = '0';
        st->line[st->count].bits[bit + 1] = '1';
        st->line[st->count].bit_pos += 2;
    }
    if (check == 1) {
        char a = st->line[st->count].line[i];
        while (a != ' ' && a != '\0' ) {
            a = st->line[st->count].line[i++];
        }
    }
    return i;
}

void save_reg(lines_t* st, int i)
{
    char *dir = malloc(sizeof(char) * 3);
    char b = st->line[st->count].line[i + 1];
    dir[0] = b;
    b = st->line[st->count].line[i + 2];
    if (b > 48 && b < 58) {
        dir[1] = b;
        dir[2] = '\0';
    } else {
        dir[1] = '\0';
    }
    int num = st->line[st->count].num_arg;
    int h = sizeof(char) * 3;
    st->line[st->count].arg[num].value = malloc(h);
    my_strcpy(st->line[st->count].arg[num].value, dir);
    st->line[st->count].num_arg++;
    st->line[st->count].arg[num].type = 1;
    st->line[st->count].arg[num].int_value = my_getnbr(dir);
    st->num++;
    free(dir);
}

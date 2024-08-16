/*
** EPITECH PROJECT, 2023
** typeargs
** File description:
** typeargs
*/

#include "../../include/asm.h"

void study_typeargs(lines_t *st, int f)
{
    int i = 0, found = 0, num = 0, save = 0;
    char a = st->line[st->count].line[i];
    while (num < op_tab[f].nbr_args && a != '\0') {
        a = st->line[st->count].line[i];
        save = i;
        i = study_which(a, i, st);
        if (save != i && save != 0) {
            num++;
        } else {
            i++;
        }
    }
    convert_bits(st);
}

int study_which(char a, int i, lines_t* st)
{
    if (a == '%') {
        i = study_dir(st, i);
    } else if (a == 'r') {
        i = study_reg(st, i);
    }
    if (a > 47 && a < 58) {
        i = study_ind(st, i);
    }
    return i;
}

void convert_bits(lines_t* st)
{
    int value = 0;
    for (int i = 0; i < 8; i++) {
        if (st->line[st->count].bits[i] == '1') {
            value += 1 << (7 - i);
        }
    }
    st->line[st->count].type_args = value;
}

void save_number(char b, lines_t *st, int n, int num)
{
    char dir[256];
    int t = 0;
    while (b > 47 && b < 58) {
        dir[t++] = b;
        b = st->line[st->count].line[n++];
    }
    dir[t] = '\0';
    int tam = sizeof(char) * my_strlen(dir);
    st->line[st->count].arg[num].value = malloc(tam);
    my_strcpy(st->line[st->count].arg[num].value, dir);
    st->line[st->count].num_arg++;
    st->line[st->count].arg[num].int_value = my_getnbr(dir);
    char c = st->line[st->count].cod;
    int a = st->line[st->count].arg[num].type;
    change_num(c, st, a);
}

void change_num(char c, lines_t* st, char a)
{
    int f = 0;
    switch (c) {
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 14:
            st->num += 2;
            f = 1;
            break;
    }
    if (f == 0 && a == 3) {
        st->num += 2;
    } else if (f == 0 && a != 3) {
        st->num += 4;
    }
}

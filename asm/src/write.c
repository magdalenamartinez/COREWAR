/*
** EPITECH PROJECT, 2023
** write.c
** File description:
** write
*/

#include "../../include/asm.h"

void write_opcode(lines_t* st, int i, hex_t* hex)
{
    if (st->line[i].cod != '0') {
        char c[2];
        c[0] = st->line[i].cod;
        c[1] = '\0';
        save_hexa(c, hex);
        st->line[st->count].start_byte = hex->l;
    }
}

void write_typeargs(lines_t* st, int i, hex_t* hex)
{
    char a = st->line[i].cod;
    if (a == 1 || a == 9 || a == 12 || a == 15) {
        return;
    }
    if (st->line[i].cod != '0') {
        save_hexa_int((unsigned int)st->line[i].type_args, hex);
    }

}

void write_args(lines_t* st, int i, hex_t* hex)
{
    if (st->line[i].cod != '0') {
        write_args2(st, i, hex);
    }
}

void write_args2(lines_t* st, int i, hex_t* hex)
{
    int j = 0;
    while (j < st->line[i].num_arg) {
        if (st->line[i].arg[j].type == 1) {
            int v = st->line[i].arg[j].int_value;
            save_hexa_int((unsigned int) v, hex);
        }
        if (st->line[i].arg[j].type == 2) {
            check_index(st, i, hex, j);
        }
        if (st->line[i].arg[j].type == 3) {
            int v = st->line[i].arg[j].int_value;
            save_hexa_int_two((unsigned int) v, hex);
        }
        if (st->line[i].arg[j].type == 4) {
            read_label(st, i, j, hex);
        }
        j++;
    }
}

void check_index(lines_t* st, int i, hex_t* hex, int j)
{
    int check = 0;
    switch (st->line[i].cod) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 14:
        case 15:
            check = 1;
            break;
    }
    int v = st->line[i].arg[j].int_value;
    if (check == 1) {
        save_hexa_int_two((unsigned int) v, hex);
    } else {
        save_hexa_int_four((unsigned int) v, hex);
    }
}

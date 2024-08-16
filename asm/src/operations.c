/*
** EPITECH PROJECT, 2023
** operations.c
** File description:
** operations
*/

#include "../../include/asm.h"

int study_operations(char* word, lines_t* st)
{
    int i = 0;
    int found = -1;
    if (word[0] == '\0') {
        return found;
    }
    while (i < 16 && found == -1) {
        if (my_strcmp(word, op_tab[i].mnemonique) == 0) {
            found = i;
        }
        i++;
    }
    if (found != -1) {
        st->line[st->count].etiqueta = 0;
        st->line[st->count].cod = op_tab[found].code;
    } else {
        st->line[st->count].etiqueta = 1;
        st->line[st->count].cod = '0';
    }
    return found;
}

void write_operations(hex_t* hex, lines_t* st)
{
    int i = 0;
    char word[256];
    while (i < st->count) {
        write_opcode(st, i, hex);
        write_typeargs(st, i, hex);
        write_args(st, i, hex);
        i++;
    }
}

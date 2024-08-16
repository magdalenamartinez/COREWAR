/*
** EPITECH PROJECT, 2023
** study_line.c
** File description:
** study_line.c
*/

#include "../../include/asm.h"


void study_line(lines_t* st)
{
    int i = 0;
    st->line[st->count].start_byte = st->num;
    int j = 0;
    int found = -1;
    char word[256];
    word[0] = '\0';
    char b = st->line[st->count].line[i];
    while (b == ' ' || b == '\t') {
        b = st->line[st->count].line[++i];
    }
    study_line2(st, i);
}

void study_line2(lines_t* st, int i)
{
    char word[256];
    int j = 0;
    int found = -1;
    char a = st->line[st->count].line[i++];
    while (a != '\n' && a != '\t' && a != '\0' && a != ' ') {
        word[j++] = a;
        a = st->line[st->count].line[i++];
    }
    word[j] = '\0';
    if (word[0] == '\0') {
        return;
    }
    found = study_operations(word, st);
    study_line3(st, word, i, found);
}

void study_line3(lines_t* st, char* word, int i, int found)
{
    if (st->line[st->count].etiqueta == 1) {
        found = etiquette_line(st, i);
    }
    if (found != -1) {
        st->line[st->count].num_arg = 0;
        st->num++;
        char a = st->line[st->count].cod;
        if (a != 1 && a != 9 && a != 12 && a != 15) {
            st->num++;
        }
        int tam = op_tab[found].nbr_args;
        st->line[st->count].arg = malloc(sizeof(arg_t) * tam);
        study_typeargs(st, found);
    }
    if (word[0] != '\0') {
        st->count++;
    }
}

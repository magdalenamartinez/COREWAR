/*
** EPITECH PROJECT, 2023
** label
** File description:
** label
*/

#include "../../include/asm.h"
int etiqueta(lines_t* st, int j, int i, int t);
void read_label(lines_t* st, int i, int t, hex_t* hex)
{
    char word2[256];
    int n = 0, k = 0, j = 0, found = -1;
    int s = 0;
    while (j < st->count && found == -1) {
        if (st->line[j].etiqueta == 1) {
            found = etiqueta(st, j, i, t);
        }
        j++;
    }
    read_label2(found, st, i, hex);
}

int etiqueta(lines_t* st, int j, int i, int t)
{
    int k = 0, n = 0, s = 0, found = -1;
    char word2[256];
    char c = st->line[j].line[k];
    while (c != ' ' && c != '\0' && c != '\n' && s == 0) {
        if (c == '\t' || c == ':') {
            s = 1; break;
        }
        word2[n++] = c;
        c = st->line[j].line[++k];
    }
    word2[n] = '\0';
    if (my_strcmp(st->line[i].arg[t].label, word2) == 0) {
        found = j;
    }
    return found;
}

void read_label2(int found, lines_t* st, int i, hex_t* hex)
{
    if (found != -1) {
        int v;
        v = st->line[found].start_byte - st->line[i].start_byte;
        save_hexa_int_two((unsigned int) v, hex);
    }
}

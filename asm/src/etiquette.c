/*
** EPITECH PROJECT, 2023
** etiquette
** File description:
** etiquette
*/

#include "../../include/asm.h"

int etiquette_line(lines_t* st, int i)
{
    int j = 0, k = 0;
    i = 0;
    char b = st->line[st->count].line[i];
    while (b != ':' && b != '\0') {
        b = st->line[st->count].line[++i];
    }
    b = st->line[st->count].line[++i];
    while (b == ' ' || b == '\t') {
        b = st->line[st->count].line[++i];
    }
    int found = second_etiquette(st, i);
    if (found != -1) {
        st->line[st->count].cod = op_tab[found].code;
    }
    return found;
}

int second_etiquette(lines_t* st, int i)
{
    char word[256];
    int j = 0;
    char a = st->line[st->count].line[i++];
    while (a != '\n' && a != '\t' && a != '\0' && a != ' ') {
        word[j++] = a;
        a = st->line[st->count].line[i++];
    }
    word[j] = '\0';
    return (third_etiquette(word));
}

int third_etiquette(char* word)
{
    int k = 0;
    int found = -1;
    while (k < 16 && found == -1) {
        if (my_strcmp(word, op_tab[k].mnemonique) == 0) {
            found = k;
        }
        k++;
    }
    return found;
}

void save_word(lines_t* st, int i, int num)
{
    char word[256];
    int j = i + 2;
    int n = 0;
    char b = st->line[st->count].line[j];
    while (b != ' ' && b != '\0' && b != '\n' && b != '\t' && b != ',') {
        word[n++] = b;
        b = st->line[st->count].line[++j];
    }
    word[n] = '\0';
    int l = my_strlen(word);
    st->line[st->count].arg[num].label = malloc(sizeof(char) * l);
    my_strcpy(st->line[st->count].arg[num].label, word);
    st->num += 2;
}

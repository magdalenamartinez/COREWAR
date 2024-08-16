/*
** EPITECH PROJECT, 2023
** lines
** File description:
** lines
*/

#include "../../include/asm.h"

void read_lines(char* buffer, int i, lines_t* lines_st)
{
    i++;
    int a = 0;
    int max = my_strlen(buffer);
    while (buffer[i] != '\0' && i <= max && a == 0) {
        a = read_line(buffer, &i, lines_st);
        if (a != 0) {
            break;
        }
        study_line(lines_st);
    }
}

int read_line(char* buffer, int *i, lines_t* lines_st)
{
    int j = 0;
    char line[256];
    line[0] = '\0';
    while (buffer[*i] == '\n' || buffer[*i] == '\t') {
        (*i)++;
    }
    int a = sizeof(line) - 1;
    while (buffer[*i] != '\n' && buffer[*i] != '\0' && j < a) {
        line[j++] = buffer[(*i)++];
    }
    line[j] = '\0';
    if (line[0] == '\0') {
        return 1;
    }
    allocate_mem(lines_st, j, line);
    return 0;
}

void allocate_mem(lines_t* lines_st, int j, char* line)
{
    int a = 0;
    if (lines_st->line == NULL) {
        lines_st->line = malloc(sizeof(line_t));
    } else {
        a = sizeof(line_t)*(lines_st->count + 1);
        lines_st->line = realloc(lines_st->line, a);
    }
    a = sizeof(char) * (j + 1);
    lines_st->line[lines_st->count].line = malloc(a);
    lines_st->line[lines_st->count].bit_pos = 0;
    strcpy(lines_st->line[lines_st->count].bits, "00000000");
    int t = 0;
    while (t < j) {
        lines_st->line[lines_st->count].line[t] = line[t];
        t++;
    }
    lines_st->line[lines_st->count].line[t] = '\0';
}

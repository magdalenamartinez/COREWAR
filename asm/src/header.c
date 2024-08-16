/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../../include/asm.h"

int translate_header(char* buffer, char* filename)
{
    header_t* header = initialise_header();
    int i = write_name(header, 0, buffer);
    i = write_comment(header, ++i, buffer);
    lines_t *lines_st = initialise_linesstr();
    hex_t* hex = initialise_hex();
    read_lines(buffer, i, lines_st);
    write_header(hex, header);
    write_operations(hex, lines_st);
    save_todo(hex, lines_st, filename);
    return 0;
}

void save_todo(hex_t* hex, lines_t* lines_st, char* filename)
{
    char *aux = malloc(sizeof(char) * PROG_NAME_LENGTH);
    int j = 0;
    while (filename[j] != '.') {
        aux[j] = filename[j];
        j++;
    }
    aux[j++] = '.';
    aux[j++] = 'c';
    aux[j++] = 'o';
    aux[j++] = 'r';
    aux[j] = '\0';
    write_file(hex, lines_st->num, aux);
}

void write_header(hex_t* hex, header_t* header)
{
    magic_number_write(hex);
    save_hexa(header->prog_name, hex);
    size_t pr = hex->l - (size_t)4;
    size_t i;
    size_t t = (hex->l + (PROG_NAME_LENGTH - pr + 8));
    hex->hex = realloc(hex->hex, t * sizeof(unsigned char));
    for (i = 0; i < (size_t)(PROG_NAME_LENGTH - pr + 8); i++) {
        hex->hex[hex->l + i] = (unsigned char) 0;
    }
    hex->l += i;
    save_hexa(header->comment, hex);
    pr = hex->l - (size_t)12 - (size_t)PROG_NAME_LENGTH;
    t = (hex->l + (COMMENT_LENGTH - pr + 4));
    hex->hex = realloc(hex->hex, t * sizeof(unsigned char));
    i = 0;
    for (i = 0; i < (size_t)(COMMENT_LENGTH - pr + 4); i++) {
        hex->hex[hex->l + i] = (unsigned char) 0;
    }
    hex->l += i;
}

int write_name(header_t* header, int i, char* buffer)
{
    int j = 0;
    i = 0;
    while (buffer[i] != '"' && buffer[i] != '\0') {
        i++;
    }
    i++;
    while (buffer[i] != '"' && buffer[i] != '\0') {
        header->prog_name[j++] = buffer[i++];
    }
    header->prog_name[j] = '\0';
    return i;
}

int write_comment(header_t* header, int i, char* buffer)
{
    int j = 0;
    while (buffer[i] != '"' && buffer[i] != '\0') {
        i++;
    }
    i++;
    while (buffer[i] != '"' && buffer[i] != '\0') {
        header->comment[j++] = buffer[i++];
    }
    header->comment[j] = '\0';
    return i;
}

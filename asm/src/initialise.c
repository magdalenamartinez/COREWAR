/*
** EPITECH PROJECT, 2023
** initialise
** File description:
** initialise
*/

#include "../../include/asm.h"

hex_t* initialise_hex(void)
{
    hex_t* hex = malloc(sizeof(hex_t));
    int number = PROG_NAME_LENGTH + COMMENT_LENGTH;
    number += 131;
    hex->hex = NULL;
    hex->l = 0;
    return hex;
}

lines_t* initialise_linesstr(void)
{
    lines_t* struct_lines = malloc(sizeof(lines_t));
    struct_lines->count = 0;
    struct_lines->line = NULL;
    struct_lines->num = 0;
    return struct_lines;
}

header_t* initialise_header(void)
{
    header_t* header = malloc(sizeof(header_t));
    return header;
}

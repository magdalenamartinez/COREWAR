/*
** EPITECH PROJECT, 2023
** save_file.c
** File description:
** save_file.c
*/

#include "../../include/asm.h"

void write_file(hex_t* hex, int num, char* filename)
{
    FILE *f = fopen(filename, "wb");
    fwrite(hex->hex, hex->l, 1, f);
    fseek(f, PROG_NAME_LENGTH + 8, SEEK_SET);
    int pos = PROG_NAME_LENGTH + 8;
    for (int i = 0; i < 4; i++) {
        unsigned char byte = (num >> (8 * (3 - i))) & 0xff;
        fseek(f, pos + i, SEEK_SET);
        fwrite(&byte, sizeof(unsigned char), 1, f);
    }
    fclose(f);
}

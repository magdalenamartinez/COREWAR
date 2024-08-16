/*
** EPITECH PROJECT, 2023
** file
** File description:
** file
*/

#include "../../include/corewar.h"

int size_file(char* nameprog)
{
    int size = 0;
    char c;
    FILE* f = fopen(nameprog, "rb");
    if (f == NULL) {
        return size;
    }
    while (fread(&c, sizeof(char), 1, f) == 1) {
        size++;
    }
    fclose(f);
    return size;
}

char* read_file(char* buffer, char* nameprog)
{
    int size = size_file(nameprog);
    if (size == 0) {
        return NULL;
    }
    FILE* f = fopen(nameprog, "rb");
    if (f == NULL) {
        return NULL;
    }
    buffer = (char*) malloc(sizeof(char) * (size + 1));
    if (buffer == NULL) {
        fclose(f);
        return NULL;
    }
    fread(buffer, sizeof(char), size, f);
    buffer[size] = '\0';
    fclose(f);
    return buffer;
}

void read_instructions(program_t* prog, char* buffer)
{
    prog->code = malloc(sizeof(char) * prog->size);
    int min = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH + 4;
    int max = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH + prog->size + 4;
    int j = 0;
    for (int i = min; i < max; i++) {
        prog->code[j++] = buffer[i];
    }
}

void read_header(program_t* prog, memory_t* mem, char* buffer)
{
    int j = 0;
    for (int i = 4; i < (PROG_NAME_LENGTH + 4); i++) {
        prog->name[j++] = buffer[i];
    }
    prog->name[PROG_NAME_LENGTH] = '\0';
    int max = PROG_NAME_LENGTH + 12;
    for (int i = 8 + PROG_NAME_LENGTH; i < max; i++) {
        prog->size = prog->size << 4;
        prog->size += buffer[i];
    }
    j = 0;
    max += COMMENT_LENGTH;
    for (int i = 12 + PROG_NAME_LENGTH; i < max; i++) {
        prog->comment[j++] = buffer[i];
    }
    prog->comment[COMMENT_LENGTH] = '\0';
}

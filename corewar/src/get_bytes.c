/*
** EPITECH PROJECT, 2023
** getbytes
** File description:
** getbytes
*/

#include "../../include/corewar.h"

int int_four(memory_t* mem, int pos)
{
    int result = 0;
    int shift = 24;
    int i;
    for (i = 0; i < 4; i++) {
        result |= ((unsigned char)mem->memory[i + pos] << shift);
        shift -= 8;
    }
    return result;
}

int int_two(memory_t* mem, int pos)
{
    int result = 0;
    int shift = 8;
    int i;
    for (i = 0; i < 2; i++) {
        result |= ((unsigned char)mem->memory[i + pos] << shift);
        shift -= 8;
    }
    return result;
}

int int_twodos(memory_t* mem, int pos)
{
    int result = 0;
    int shift = 8;
    int i;
    for (i = 0; i < 2; i++) {
        result |= ((unsigned char)mem->memory[i + pos] << shift);
        shift -= 8;
    }
    if (result & 0x8000) {
        result |= 0xFFFF0000;
    }
    return result;
}

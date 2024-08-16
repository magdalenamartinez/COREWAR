/*
** EPITECH PROJECT, 2023
** write_mem.c
** File description:
** write
*/

#include "../../include/corewar.h"

void write_memory(memory_t* mem)
{
    mem->free_space = MEM_SIZE;
    int e = 0;
    for (int i = 0; i < mem->counter; i++) {
        if (mem->program_s[i]->address != -1) {
            check_direction(mem->program_s[i], mem, i);
        }
    }
    write_therest(mem);
}

void write_data(memory_t* mem, program_t* prog)
{
    int i = prog->address;
    int j = 0;
    int max = prog->size + prog->address;
    while (i < max) {
        mem->memory[i++] = (int)(prog->code[j++]);
    }
}

void write_therest(memory_t* mem)
{
    int rest = mem->free_space / mem->counter;
    int i = 0;
    int sp = 0;
    int place = 0;
    while (i < mem->counter) {
        if (mem->program_s[i]->address == -1) {
            place = write_aux(place, mem, i, rest);
            place = place + mem->program_s[i]->size;
        }
        i++;
    }
}

int write_aux(int place, memory_t* mem, int i, int rest)
{
    while (check_ifplace(mem->program_s[i], mem, place) == 1) {
        place++;
    }
    if (place != 0) {
        place = place + rest;
    }
    coloc_address(mem, i, place);
    mem->program_s[i]->address = place;
    return place;
}

void coloc_address(memory_t* mem, int i, int place)
{
    int j = 0;
    while (j < mem->program_s[i]->size) {
        mem->memory[j + place] = mem->program_s[i]->code[j];
        j++;
    }
}

/*
** EPITECH PROJECT, 2023
** check
** File description:
** check
*/

#include "../../include/corewar.h"

int check_ifplace(program_t* prog, memory_t* mem, int place)
{
    int i = 0;
    int f = 0;
    while (i < mem->counter && f == 0) {
        if (mem->program_s[i]->address != -1 && prog != mem->program_s[i]) {
            f = check_place(mem->program_s[i], prog, place);
        }
        i++;
    }
    return f;
}

int check_place(program_t* progmem, program_t* prog, int place)
{
    int max = progmem->address + progmem->size;
    int i = progmem->address, found = 0;
    while (i < max && found == 0) {
        if (place >= i && max >= place + prog->size) {
            found = 1;
        }
        i++;
    }
    return found;
}

void check_direction(program_t* prog, memory_t* mem, int n)
{
    int found = 0, i = 0;
    while (i < mem->counter && found == 0) {
        if (i != n && mem->program_s[i]->address != -1) {
            found = check_ifoccupied(mem->program_s[i], prog);
        }
        i++;
    }
    if (found == 1) {
        my_printf("Error assigning load address for %s\n", prog->name);
    } else {
        write_data(mem, prog);
        change_space(mem, prog);
    }
}

int check_ifoccupied(program_t* progmem, program_t* prog)
{
    int max = progmem->address + progmem->size;
    int i = progmem->address, found = 0;
    while (i < max && found == 0) {
        if (prog->address >= i && max >= prog->address + prog->size) {
            found = 1;
        }
        i++;
    }
    return found;
}

void change_space(memory_t* mem, program_t* prog)
{
    mem->free_space = mem->free_space - prog->size;
}

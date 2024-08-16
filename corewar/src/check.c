/*
** EPITECH PROJECT, 2023
** check
** File description:
** check
*/

#include "../../include/corewar.h"

void check_alive(memory_t* mem)
{
    int i = 0;
    int f = 0;
    int die = mem->diecycle;
    while (i < mem->counter) {
        if (my_abs(mem->actualcycle - mem->program_s[i]->live_cycle) > die) {
            remove_prog(mem, i);
            f = 1;
            break;
        }
        i++;
    }
    if (f == 1) {
        check_alive(mem);
    }
}

int check_condition(memory_t* mem, program_t* prog, int cycles)
{
    if (prog->last_cycle == -1) {
        return 1;
    }
    int quantity = mem->actualcycle - prog->last_cycle;
    if (quantity >= cycles) {
        return 1;
    }
    return 0;
}

int check_end(memory_t* mem)
{
    if (mem->counter < 1) {
        return 1;
    }
    if (mem->nbr_cycle < 1) {
        return 0;
    }
    if (mem->actualcycle >= mem->nbr_cycle ) {
        return 1;
    }
    return 0;
}

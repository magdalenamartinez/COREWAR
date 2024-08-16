/*
** EPITECH PROJECT, 2023
** remove
** File description:
** remove
*/

#include "../../include/corewar.h"

void remove_prog(memory_t* mem, int i)
{
    free(mem->program_s[i]->reg);
    free(mem->program_s[i]->code);
    free(mem->program_s[i]);
    for (int j = i; j < mem->counter - 1; j++) {
        mem->program_s[j] = mem->program_s[j + 1];
    }
    mem->counter--;
}

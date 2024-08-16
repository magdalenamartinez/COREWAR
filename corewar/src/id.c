/*
** EPITECH PROJECT, 2023
** id
** File description:
** id
*/

#include "../../include/corewar.h"


void id_order(memory_t* mem)
{
    for (int i = 0; i < mem->counter - 1; i++) {
        for (int j = 0; j < mem->counter - i - 1; j++) {
            id_order2(mem, j);
        }
    }
}

void id_order2(memory_t* mem, int j)
{
    if (mem->program_s[j]->id_program > mem->program_s[j + 1]->id_program) {
        program_t* temp = mem->program_s[j];
        mem->program_s[j] = mem->program_s[j + 1];
        mem->program_s[j + 1] = temp;
    }
}

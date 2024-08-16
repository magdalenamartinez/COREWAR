/*
** EPITECH PROJECT, 2023
** jmp
** File description:
** zjmp
*/

#include "../../include/corewar.h"

void zjmp_ins(memory_t* mem, program_t* prog, int cycles)
{
    int v1 = int_twodos(mem, prog->address + prog->pc + 1);
    if (prog->carry == 1) {
        prog->pc = prog->pc + v1 % IDX_MOD;
    } else {
        prog->pc += 3;
    }
}

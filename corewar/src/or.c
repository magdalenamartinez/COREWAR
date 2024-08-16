/*
** EPITECH PROJECT, 2023
** or
** File description:
** or
*/

#include "../../include/corewar.h"
void or_ins(memory_t* mem, program_t* prog, int cycles)
{
    int v1 = 0, v2 = 0, v3 = 0;
    if (prog->types[2] != 1) {
        prog->pc++;
        return;
    }
    v1 = or_ins2(mem, prog);
    v2 = or_ins3(mem, prog);
    int orop = v1 | v2;
    v3 = mem->memory[prog->pc + prog->address];
    prog->reg[v3 - 1] = orop;
    prog->carry = 0;
    if (orop == 0) {
        prog->carry = 1;
    }
    prog->pc += 1;
}

int or_ins2(memory_t* mem, program_t* prog)
{
    int v1 = 0;
    if (prog->types[0] == 2) {
        v1 = int_two(mem, prog->address + prog->pc + 2);
        prog->pc += 6;
    } else if (prog->types[0] == 3) {
        v1 = int_two(mem, prog->pc + prog->address + 2);
        v1 = int_four(mem, prog->address + prog->pc + 2 + v1 % IDX_MOD);
        prog->pc += 4;
    }
    return v1;
}

int or_ins3(memory_t* mem, program_t* prog)
{
    int v2 = 0;
    if (prog->types[1] == 2) {
        v2 = int_two(mem, prog->address + prog->pc);
        prog->pc += 4;
    } else if (prog->types[1] == 3) {
        v2 = int_two(mem, prog->pc + prog->address);
        v2 = int_four(mem, prog->address + prog->pc + 2 + v2 % IDX_MOD);
        prog->pc += 2;
    }
    return v2;
}

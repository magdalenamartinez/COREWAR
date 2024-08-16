/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "../../include/corewar.h"

void add_ins(memory_t* mem, program_t* prog, int cycles)
{
    int v1 = 0, v2 = 0, v3 = 0, sum = 0;
    if (prog->types[0] != 1 || prog->types[1] != 1 || prog->types[2] != 1) {
        prog->pc++;
        return;
    }
    v1 = mem->memory[prog->address + prog->pc + 2];
    v2 = mem->memory[prog->address + prog->pc + 3];
    v1 = prog->reg[v1 - 1];
    v2 = prog->reg[v2 - 1];
    sum = v1 + v2;
    v3 = mem->memory[prog->address + prog->pc + 4];
    prog->reg[v3 - 1] = sum;
    prog->carry = 0;
    if (sum == 0) {
        prog->carry = 1;
    }
    prog->pc += 5;
}

void sub_ins(memory_t* mem, program_t* prog, int cycles)
{

    int v1 = 0, v2 = 0, v3 = 0, sub = 0;
    if (prog->types[0] != 1 || prog->types[1] != 1 || prog->types[2] != 1) {
        prog->pc++;
        return;
    }
    v1 = mem->memory[prog->address + prog->pc + 2];
    v2 = mem->memory[prog->address + prog->pc + 3];
    v1 = prog->reg[v1 - 1];
    v2 = prog->reg[v2 - 1];
    sub = v1 - v2;
    v3 = mem->memory[prog->address + prog->pc + 4];
    prog->reg[v3 - 1] = sub;
    prog->carry = 0;
    if (sub == 0) {
        prog->carry = 1;
    }
    prog->pc += 5;
}

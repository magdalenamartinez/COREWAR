/*
** EPITECH PROJECT, 2023
** load
** File description:
** load
*/

#include "../../include/corewar.h"

int ld_ins2(memory_t* mem, program_t* prog, int *v2)
{
    int v1 = 0;
    if (prog->types[0] == 2) {
        v1 = int_four(mem, prog->address + prog->pc + 2);
        v1 = v1 % IDX_MOD;
        *v2 = mem->memory[prog->address + prog->pc + 6];
        prog->pc += 6;
    } else {
        v1 = int_two(mem, prog->address + prog->pc + 2);
        v1 = int_four(mem, prog->address + prog->pc + 2 + v1 % IDX_MOD);
        *v2 = mem->memory[prog->address + prog->pc + 4];
        prog->pc += 4;
    }
    return v1;
}

void ld_ins(memory_t* mem, program_t* prog, int cycles)
{
    int v1 = 0, v2 = 0;
    if ((prog->types[0] != 2 && prog->types[0] != 3) || prog->types[1] != 1) {
        prog->pc++;
        return;
    }
    ld_ins2(mem, prog, &v2);
    prog->reg[v2 - 1] = v1;
    prog->carry = 0;
    if (v1 == 0) {
        prog->carry = 1;
    }
    prog->pc++;
}

int ldi_ins2(memory_t* mem, program_t* prog, int *s)
{
    int v1 = 0;
    if (prog->types[0] == 1) {
        v1 = mem->memory[prog->address + prog->pc + 2];
        v1 = prog->reg[v1 - 1];
        *s += 3;
    } else if (prog->types[0] == 2) {
        v1 = int_two(mem, prog->address + prog->pc + 2);
        *s += 4;
    } else {
        v1 = int_two(mem, prog->address + prog->pc + 2);
        v1 = int_four(mem, prog->address + prog->pc + 2 + v1 % IDX_MOD);
        *s += 4;
    }
    return v1;
}

int ldi_ins3(memory_t* mem, program_t* prog, int *s)
{
    int v2 = 0;
    if (prog->types[1] == 1) {
        v2 = mem->memory[prog->address + prog->pc + *s];
        v2 = prog->reg[v2 - 1];
        *s += 1;
    } else if (prog->types[1] == 2) {
        v2 = int_two(mem, prog->address + prog->pc + *s);
        *s += 2;
    }
    return v2;
}

void ldi_ins(memory_t* mem, program_t* prog, int cycles)
{
    if (prog->types[2] != 1) {
        prog->pc++; return;
    }
    int v1 = 0, v2 = 0, v3 = 0;
    int s = 0;
    v1 = ldi_ins2(mem, prog, &s);
    v2 = ldi_ins3(mem, prog, &s);
    v3 = mem->memory[prog->address + prog->pc + s];
    prog->reg[v3 - 1] = mem->memory[prog->pc + (v1 + v2) % IDX_MOD];
    prog->carry = 0;
    if (prog->reg[v3 - 1] == 0) {
        prog->carry = 1;
    }
    prog->pc = prog->pc + s + 1;
}

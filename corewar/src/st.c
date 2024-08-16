/*
** EPITECH PROJECT, 2023
** or
** File description:
** or
*/

#include "../../include/corewar.h"

void st_ins(memory_t* mem, program_t* prog, int cycles)
{
    int reg = 0, v1 = 0, v2 = 0;
    if (prog->types[0] != 1 || (prog->types[1] != 3 && prog->types[1] != 1)) {
        prog->pc++;
        return;
    }
    reg = mem->memory[prog->address + prog->pc + 2];
    v1 = prog->reg[reg - 1];
    if (prog->types[1] == 1) {
        v2 = mem->memory[prog->address + prog->pc + 3];
        prog->reg[v2 - 1] = v1;
        prog->pc += 4;
    } else {
        v2 = int_two(mem, prog->address + prog->pc + 3);
        v2 = prog->address + prog->pc + v2 % IDX_MOD;
        prog->pc += 5;
        write_fourmem(mem, v2, v1);
    }
}

void sti_ins(memory_t* mem, program_t* prog, int cycles)
{
    int reg = 0, v1 = 0, v2 = 0, v3 = 0, sum = 0;
    if (prog->types[0] != 1) {
        prog->pc++;
        return;
    }
    reg = mem->memory[prog->address + prog->pc + 2];
    v1 = prog->reg[reg - 1];
    v2 = sti_int1(mem, prog, &sum);
    int add = sti_ins2(mem, prog, &sum, v2);
    write_fourmem(mem, prog->address + prog->pc + add % IDX_MOD, v1);
    prog->carry = 0;
    if (v1 == 0) {
        prog->carry = 1;
    }
    prog->pc = prog->pc + sum;
}

int sti_int1(memory_t* mem, program_t* prog, int *sum)
{
    int v2 = 0;
    if (prog->types[1] == 1) {
        v2 = mem->memory[prog->address + prog->pc + 3];
        v2 = prog->reg[v2 - 1];
        *sum += 4;
    } else {
        v2 = int_two(mem, prog->address + prog->pc + 3);
        if (prog->types[1] == 3) {
            v2 = int_four(mem, prog->address + prog->pc + v2 % IDX_MOD);
        }
        *sum += 5;
    }
    return v2;
}

int sti_ins2(memory_t* mem, program_t* prog, int *sum, int v2)
{
    int v3 = 0;
    if (prog->types[2] == 1) {
        v3 = mem->memory[prog->address + prog->pc + *sum ];
        v3 = prog->reg[v3 - 1];
        *sum += 1;
    } else {
        v3 = int_two(mem, prog->address + prog->pc + *sum);
        *sum += 2;
    }
    int add = v2 + v3;
    return add;
}

void write_fourmem(memory_t* mem, int address, int data)
{
    mem->memory[address] = (data >> 24) & 0xFF;
    mem->memory[address + 1] = (data >> 16) & 0xFF;
    mem->memory[address + 2] = (data >> 8) & 0xFF;
    mem->memory[address + 3] = data & 0xFF;
}

/*
** EPITECH PROJECT, 2023
** fork
** File description:
** fork
*/

#include "../../include/corewar.h"

void fork_ins(memory_t* mem, program_t* prog, int cycles)
{
    int v = int_two(mem, prog->address + prog->pc + 1);
    program_t* program = malloc(sizeof(program_t));
    program->address = prog->address + prog->size + v % IDX_MOD;
    program->code = malloc(sizeof(char) * prog->size);
    int i = 0;
    while (i < prog->size) {
        program->code[i] = mem->memory[prog->address + i];
        i++;
    }
    program->size = prog->size;
    program->carry = prog->carry;
    program->last_cycle = prog->last_cycle;
    program->live_cycle = prog->live_cycle;
    my_strcpy(program->name, prog->name);
    my_strcpy(program->comment, prog->comment);
    program->reg = malloc(sizeof(int) * REG_NUMBER);
    fork_dos(mem, prog, program, v);
}

void fork_dos(memory_t* mem, program_t* prog, program_t* program, int v)
{
    int i = 0;
    while (i < 16) {
        program->reg[i] = prog->reg[i];
        i++;
    }
    program->types[0] = 0;
    program->types[1] = 0;
    program->types[2] = 0;
    program->id_program = prog->id_program;
    write_data(mem, program);
    program->pc = prog->pc + v % IDX_MOD;
    prog->pc += 3;
    int a = sizeof(program_t*) * (mem->counter + 1);
    mem->program_s = realloc(mem->program_s, a);
    mem->program_s[mem->counter] = program;
    mem->counter++;
}

void lfork_ins(memory_t* mem, program_t* prog, int cycles)
{
    int v = int_two(mem, prog->address + prog->pc + 1);
    program_t* program = malloc(sizeof(program_t));
    program->address = prog->address + prog->size + v % IDX_MOD;
    program->code = malloc(sizeof(char) * prog->size);
    int i = 0;
    while (i < prog->size) {
        program->code[i] = prog->code[i];
        i++;
    }
    program->size = prog->size;
    program->code[program->size] = '\0';
    program->carry = prog->carry;
    program->last_cycle = prog->last_cycle;
    program->live_cycle = prog->live_cycle;
    my_strcpy(program->name, prog->name);
    my_strcpy(program->comment, prog->comment);
    program->reg = malloc(sizeof(int) * 16);
    lfork_dos(mem, prog, program, v);
}

void lfork_dos(memory_t* mem, program_t* prog, program_t* program, int v)
{
    int i = 0;
    while (i < 16) {
        program->reg[i] = prog->reg[i];
        i++;
    }
    program->pc = 0;
    program->types[0] = 0;
    program->types[1] = 0;
    program->types[2] = 0;
    program->id_program = prog->id_program;
    write_data(mem, program);
    program->pc = prog->pc + v;
    prog->pc += 3;
    i = 0;
    int a = sizeof(program_t*) * mem->counter + 1;
    mem->program_s = realloc(mem->program_s, a);
    mem->program_s[mem->counter] = program;
    mem->counter++;
}

void aff_ins(memory_t* mem, program_t* prog, int cycles)
{
    if (prog->types[0] != 1) {
        prog->pc++;
        return;
    }
    int v = mem->memory[prog->address + prog->pc + 2];
    v = prog->reg[v - 1];
    my_printf("%c\n", v);
    prog->pc += 3;
}

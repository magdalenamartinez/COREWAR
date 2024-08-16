/*
** EPITECH PROJECT, 2023
** initialise
** File description:
** initialise
*/

#include "../../include/corewar.h"

args_t* initialise_args(void)
{
    args_t *args_s = malloc(sizeof(args_t));
    args_s->nbr_cycle = -1;
    args_s->program_nbr = -1;
    args_s->load_address = -1;
    return args_s;
}

memory_t* initialise_memory(void)
{
    memory_t* mem = malloc(sizeof(memory_t));
    mem->memory = malloc(sizeof(int) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++) {
        mem->memory[i] = 0;
    }
    mem->counter = 0;
    mem->diecycle = CYCLE_TO_DIE;
    mem->live_inst = 0;
    mem->actualcycle = 0;
    mem->nbr_cycle = 0;
    mem->last_id = 0;
    mem->names = NULL;
    mem->program_s = NULL;
    mem->live_id = -1;
    return mem;
}

program_t* initialise_program(args_t* args_s, memory_t* mem_s)
{
    program_t* prog = malloc(sizeof(program_t));
    prog->id_program = args_s->program_nbr;
    prog->load_address = args_s->load_address;
    prog->address = args_s->load_address;
    mem_s->nbr_cycle = args_s->nbr_cycle;
    check_program(prog, mem_s);
    prog->live_cycle = 0;
    prog->carry = 0;
    prog->types[0] = 0;
    prog->types[1] = 0;
    prog->types[2] = 0;
    prog->pc = 0;
    write_reg(prog);
    return prog;
}

void write_reg(program_t* prog)
{
    int i = 0;
    prog->reg = malloc(sizeof(int) * REG_NUMBER);
    prog->reg[i++] = prog->id_program;
    while (i < REG_NUMBER) {
        prog->reg[i++] = 0;
    }
}

void reset_values(args_t* args_s)
{
    args_s->nbr_cycle = -1;
    args_s->program_nbr = -1;
    args_s->load_address = -1;
}

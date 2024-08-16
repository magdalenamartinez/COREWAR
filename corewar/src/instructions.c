/*
** EPITECH PROJECT, 2023
** instrucits
** File description:
** instructions
*/

#include "../../include/corewar.h"

void instructions_function(memory_t* mem)
{
    int i = 0;
    while (i < mem->counter) {
        get_instruction(mem->program_s[i], mem, i);
        i++;
    }
}

void get_instruction(program_t* prog, memory_t* mem, int i)
{
    int ins = mem->memory[prog->address + prog->pc];
    int cycles = study_code(ins);
    if (prog->pc == prog->size) {
        remove_prog(mem, i); return;
    }
    if (ins < 1 || ins > 16 || cycles == -1) {
        prog->pc++;
    } else if (check_condition(mem, prog, cycles) == 1) {
        study_instruction(ins, cycles, mem, prog);
    }
}

int switch_function(memory_t* mem, program_t* prog, int cycles, int ins)
{
    int error = 0;
    switch (ins) {
        case 1: live_ins(mem, prog, cycles); break;
        case 2: ld_ins(mem, prog, cycles); break;
        case 3: st_ins(mem, prog, cycles); break;
        case 4: add_ins(mem, prog, cycles); break;
        case 5: sub_ins(mem, prog, cycles); break;
        case 6: and_ins(mem, prog, cycles); break;
        case 7: or_ins(mem, prog, cycles); break;
        case 8: xor_ins(mem, prog, cycles); break;
        case 9: zjmp_ins(mem, prog, cycles); break;
        case 10: ldi_ins(mem, prog, cycles); break;
        case 11: sti_ins(mem, prog, cycles);break;
        case 12: fork_ins(mem, prog, cycles);break;
        case 13: lld_ins(mem, prog, cycles);break;
        case 14: lldi_ins(mem, prog, cycles);break;
        case 15: lfork_ins(mem, prog, cycles);break;
        case 16: aff_ins(mem, prog, cycles);break;
        default: error = 1; break;
    } return error;
}

void study_instruction(int ins, int cycles, memory_t* mem, program_t* prog)
{
    int error = 0;
    if (ins != 1 && ins != 9 && ins != 12 && ins != 15) {
        get_typeargs(mem, prog);
    }
    error = switch_function(mem, prog, cycles, ins);
    if (error == 0) {
        prog->last_cycle = mem->actualcycle;
    }
}

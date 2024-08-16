/*
** EPITECH PROJECT, 2023
** live
** File description:
** live
*/

#include "../../include/corewar.h"

void check_sub(memory_t* mem)
{
    mem->live_inst++;
    if (mem->live_inst >= NBR_LIVE) {
        mem->diecycle -= CYCLE_DELTA;
        mem->live_inst = 0;
    }
}

void live_ins(memory_t* mem, program_t* prog, int cycles)
{
    int i = 0, f = -1;
    int number = int_four(mem, (prog->address + prog->pc + 1));
    while (i < mem->counter && f == -1) {
        if (mem->program_s[i]->id_program == number) {
            f = i; break;
        }
        i++;
    }
    if (f != -1) {
        write_live(f, mem, prog);
    }
    prog->pc += 5;
    check_sub(mem);
}

void write_live(int f, memory_t* mem, program_t* prog)
{
    int i = 0;
    mem->program_s[f]->live_cycle = mem->actualcycle;
    my_printf("The player %i", mem->program_s[f]->id_program);
    my_printf("(%s)is alive.\n", mem->program_s[f]->name);
    int a = mem->program_s[f]->id_program;
    mem->live_id = mem->program_s[f]->id_program;
    my_strcpy(mem->live_name, mem->program_s[f]->name);
}

void print_winner(memory_t* mem_s)
{
    int i = 0;
    if (mem_s->live_id == -1) {
        my_printf("There is no winner\n");
        return;
    }

    char *num;
    int_to_string(mem_s->live_id, num);

    my_printf("the winner is (");
    my_putstr(num);
    my_putstr(")");
    my_putstr(mem_s->live_name);
}

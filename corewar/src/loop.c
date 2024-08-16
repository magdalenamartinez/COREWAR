/*
** EPITECH PROJECT, 2023
** loop
** File description:
** loop
*/

#include "../../include/corewar.h"
void make_loop(memory_t* mem)
{
    int f = 0;
    while (f == 0) {
        f = check_end(mem);
        id_order(mem);
        instructions_function(mem);
        check_alive(mem);
        mem->actualcycle++;
    }
}

int my_abs(int num)
{
    if (num < 0) {
        return -num;
    } else {
        return num;
    }
}

void get_typeargs(memory_t* mem, program_t* prog)
{
    int byte = mem->memory[prog->address + prog->pc + 1];
    int first_arg = (byte >> 6) & 0x03;
    int sec_arg = (byte >> 4) & 0x03;
    int third_arg = (byte >> 2) & 0x03;
    prog->types[0] = first_arg;
    prog->types[1] = sec_arg;
    prog->types[2] = third_arg;
}

int study_code(int ins)
{
    int i = 0;
    int f = -1;
    while (i < 16) {
        int a = op_tab[i].code;
        if (a == ins) {
            f = i; break;
        }
        i++;
    }
    if (f != -1) {
        return (op_tab[f].nbr_cycles);
    } else {
        return f;
    }
}

/*
** EPITECH PROJECT, 2023
** program
** File description:
** program
*/

#include "../../include/corewar.h"

void add_program(args_t* args_s, char* progname, memory_t* mem_s)
{
    program_t* prog_s = initialise_program(args_s, mem_s);
    char* buf = read_file(buf, progname);
    read_header(prog_s, mem_s, buf);
    read_instructions(prog_s, buf);
    if (mem_s->counter == 0) {
        mem_s->program_s = malloc(sizeof(program_t*));
    } else {
        int a = sizeof(program_t*) * mem_s->counter + 1;
        mem_s->program_s = realloc(mem_s->program_s, a);
    }
    mem_s->program_s[mem_s->counter++] = prog_s;
}

void check_program(program_t* prog, memory_t* mem)
{
    if (prog->id_program == -1) {
        change_id(prog, mem);
        check_id(prog, mem);
    } else {
        check_id(prog, mem);
    }
    if (prog->load_address > MEM_SIZE) {
        prog->load_address = prog->load_address % MEM_SIZE;
    }
}

void check_loadaddress(program_t* prog, memory_t* mem)
{
    prog->load_address = prog->load_address % MEM_SIZE;
}

void check_id(program_t* prog,  memory_t* mem)
{
    int i = 0, found = 0;
    if (mem->program_s == NULL) {
        return;
    }
    while (i < mem->counter && found == 0) {
        if (prog->id_program == mem->program_s[i]->id_program) {
            found = 1;
        }
        i++;
    }
    if (found == 1) {
        prog->id_program = mem->last_id++;
        check_id(prog, mem);
    }
}

void change_id(program_t* prog, memory_t* mem)
{
    prog->id_program = mem->last_id++;
}

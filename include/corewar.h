/*
** EPITECH PROJECT, 2023
** corewar.h
** File description:
** corewar.g
*/


#ifndef _COREWAR_H_
    #define _COREWAR_H_
    #include "op.h"
    #include "stdio.h"
    #define ERROR_EXIT 84
    #define SUCCESS_EXIT 0
    #define MAX_BUFFER 2000000
    #include "unistd.h"
    #include "fcntl.h"
    #include "string.h"
    #include "my.h"
    #include "stdlib.h"
    typedef struct args_struct {
        int nbr_cycle; // -dump
        int program_nbr; // -prog_number
        int load_address; // -load_address
    } args_t;
    typedef struct program_struct {
        char name[PROG_NAME_LENGTH + 1];
        char comment[COMMENT_LENGTH + 1];
        int address;
        int last_cycle;
        int size;
        int id_program;
        int load_address;
        int live_cycle;
        int carry;
        int pc;
        int *reg;
        int types[3];
        char* code;
    } program_t;
    typedef struct memory_struct {
        int last_id;
        char live_name[PROG_NAME_LENGTH + 1];
        int nbr_cycle;
        int live_inst;
        int live_id;
        int counter;
        int actualcycle;
        int diecycle;
        char** names;
        int last_address;
        program_t **program_s;
        int* memory;
        int free_space;
    } memory_t;
void print_winner(memory_t* mem_s);
void write_live(int f, memory_t* mem, program_t* prog);
void get_instruction(program_t* prog, memory_t* mem, int i);
void remove_prog(memory_t* mem, int i);
void check_alive(memory_t* mem);
int my_abs(int num);
void fork_dos(memory_t* mem, program_t* prog, program_t* program, int v);
void lfork_dos(memory_t* mem, program_t* prog, program_t* program, int v);
void write_fourmem(memory_t* mem, int address, int data);
void st_ins(memory_t* mem, program_t* prog, int cycles);
void zjmp_ins(memory_t* mem, program_t* prog, int cycles);
void lldi_ins(memory_t* mem, program_t* prog, int cycles);
void sti_ins(memory_t* mem, program_t* prog, int cycles);
void ld_ins(memory_t* mem, program_t* prog, int cycles);
void lld_ins(memory_t* mem, program_t* prog, int cycles);
void ldi_ins(memory_t* mem, program_t* prog, int cycles);
void lfork_ins(memory_t* mem, program_t* prog, int cycles);
void fork_ins(memory_t* mem, program_t* prog, int cycles);
void aff_ins(memory_t* mem, program_t* prog, int cycles);
void add_ins(memory_t* mem, program_t* prog, int cycles);
void sub_ins(memory_t* mem, program_t* prog, int cycles);
void and_ins(memory_t* mem, program_t* prog, int cycles);
void or_ins(memory_t* mem, program_t* prog, int cycles);
void xor_ins(memory_t* mem, program_t* prog, int cycles);
int sti_int1(memory_t* mem, program_t* prog, int *sum);
int int_two(memory_t* mem, int pos);
void get_typeargs(memory_t* mem, program_t* prog);
void study_instruction(int ins, int cycles, memory_t* mem, program_t* prog);
void live_ins(memory_t* mem, program_t* prog, int cycles);
int int_four(memory_t* mem, int pos);
void make_loop(memory_t* mem);
void id_order2(memory_t* mem, int j);
void id_order(memory_t* mem);
void instructions_function(memory_t* mem);
int check_condition(memory_t* mem, program_t* prog, int cycles);
int int_twodos(memory_t* mem, int pos);
int study_code(int ins);
int check_end(memory_t* mem);
void write_reg(program_t* prog);
int write_aux(int place, memory_t* mem, int i, int rest);
int check_not_read(char* progname, memory_t* mem);
void change_space(memory_t* mem, program_t* prog);
void write_data(memory_t* mem, program_t* prog);
int check_ifoccupied(program_t* progmem, program_t* prog);
void write_therest(memory_t* mem);
void coloc_address(memory_t* mem, int i, int place);
int check_ifplace(program_t* prog, memory_t* mem, int place);
void write_memory(memory_t* mem);
int check_ifplace(program_t* prog, memory_t* mem, int place);
int check_place(program_t* progmem, program_t* prog, int place);
void check_direction(program_t* prog, memory_t* mem, int n);
void read_instructions(program_t* prog, char* buffer);
int study_params(args_t* args_s, char* act, char* num, int i);
int dump_function(int i, char* num, args_t* args_s);
int prog_name(int i, char* num, args_t* args_s);
int load_address(int i, char* num, args_t* args_s);
void  study_name_prog(args_t* args_s, char* progname, memory_t* mem_s);
int check_number(char* num);
int or_ins3(memory_t* mem, program_t* prog);
int or_ins2(memory_t* mem, program_t* prog);
int file_exists(char* filename);
void reset_values(args_t* args_s);
int sti_ins2(memory_t* mem, program_t* prog, int *sum, int v2);
int ldi_ins2(memory_t* mem, program_t* prog, int *s);
int ldi_ins3(memory_t* mem, program_t* prog, int *s);
int ld_ins2(memory_t* mem, program_t* prog, int *v2);
int lld_ins2(memory_t* mem, program_t* prog, int *v2);
int lldi_ins2(memory_t* mem, program_t* prog, int *s);
int lldi_ins3(memory_t* mem, program_t* prog, int *s);
int and_ins2(memory_t* mem, program_t* prog);
int and_ins3(memory_t* mem, program_t* prog);
args_t* initialise_args(void);
int study_args(int argc, char **argv);
void read_header(program_t* prog, memory_t* mem, char* buffer);
int size_file(char* nameprog);
char* read_file(char* nameprog, char* buffer);
void add_program(args_t* args_s, char* progname, memory_t* mem_s);
void check_program(program_t* prog, memory_t* mem);
memory_t* initialise_memory(void);
void change_loadaddress(program_t* prog, memory_t* mem);
void check_loadaddress(program_t* prog, memory_t* mem);
void check_id(program_t* prog,  memory_t* mem);
void change_id(program_t* prog, memory_t* mem);
program_t* initialise_program(args_t* args_s, memory_t* mem_s);
#endif /*_COREWAR_H_*/

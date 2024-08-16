/*
** EPITECH PROJECT, 2023
** corewar.h
** File description:
** corewar.g
*/


#ifndef _ASM_H_
    #define _ASM_H_
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
    typedef struct hex {
        char* buffer;
        unsigned char *hex;
        size_t l;
        int line;
        int label;
        char* word2;
        int num;
    } hex_t;
    typedef struct arg_struct{
        char* value; //sera asi: XXXXXXXX o XXXX o XX
        int int_value;
        int type;
        char* label;
    } arg_t;
    typedef struct line_st {
        char* line; //linea actual
        int etiqueta; //si comienza con etiqueta o no
        int start_byte; //byte en el que comienza
        char cod; //codigo de operation
        char bits[9]; //para el tipo de argumento
        int bit_pos; //para saber cual es el ult bit actualizado
        int type_args;
        int num_arg;
        arg_t* arg;

    }line_t;
    typedef struct lines_struct {
        int count; //numero de la linea
        line_t *line;
        int num;
    }lines_t;
    void write_args2(lines_t* st, int i, hex_t* hex);
    void change_num(char c, lines_t* st, char a);
    int study_which(char a, int i, lines_t* st);
    int study_dir(lines_t* st, int i);
    void bit_function(lines_t* st);
    void read_label2(int found, lines_t* st, int i, hex_t* hex);
    int check_function(lines_t* st, int i);
    void check_one(lines_t* st, char b, int n);
    void check_two(lines_t* st, char b, int t);
    void save_word(lines_t* st, int i, int num);
    void read_label(lines_t* st, int i, int t, hex_t* hex);
    void save_number(char b, lines_t *st, int n, int num);
    void save_hexa_int_four(unsigned int v, hex_t* hex);
    void save_hexa_int_two(unsigned int v, hex_t* hex);
    void write_args(lines_t* st, int i, hex_t* hex);
    void check_index(lines_t* st, int i, hex_t* hex, int j);
    int study_dir(lines_t* st, int i);
    void save_reg(lines_t* st, int i);
    int study_reg(lines_t* st, int i);
    int study_ind(lines_t* st, int i);
    void study_typeargs(lines_t *st, int f);
    int study_parameters(int argc, char** argv);
    void display_help(void);
    int study_file(char* filename);
    void read_file(int file, char* buffer, char* filename);
    int write_name(header_t* header, int i, char* buffer);
    int write_comment(header_t* header, int i, char* buffer);
    int translate_header(char* buffer, char* filename);
void save_todo(hex_t* hex, lines_t* lines_st, char* filename);
    int read_line(char* buffer, int *i, lines_t* lines_st);
    void read_lines(char* buffer, int i, lines_t* lines_st);
    void study_line(lines_t* st);
    int etiquette_line(lines_t* st, int i);
    void save_hexa(char* buffer, hex_t* hex);
    void magic_number_write(hex_t* hex);
    hex_t* initialise_hex(void);
    lines_t* initialise_linesstr(void);
    header_t* initialise_header(void);
    void write_file(hex_t* hex, int num, char* filename);
void concatenar(char destino[], const char origen[]);
    void write_header(hex_t* hex, header_t* header);
    int study_operations(char* word, lines_t* st);
    int read_s(char* filename);
    void write_operations(hex_t* hex, lines_t* st);
    void write_opcode(lines_t* st, int i, hex_t* hex);
    void write_typeargs(lines_t* st, int i, hex_t* hex);
    void study_typeargs(lines_t *st, int f);
    void save_hexa_int(unsigned int v, hex_t* hex);
    void convert_bits(lines_t* st);
    int second_etiquette(lines_t* st, int i);
    int third_etiquette(char* word);
    void study_line2(lines_t* st, int i);
    void allocate_mem(lines_t* lines_st, int j, char *line);
    void study_line3(lines_t* st, char* word, int i, int found);
#endif /*_ASM_H_*/

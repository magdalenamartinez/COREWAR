/*
** EPITECH PROJECT, 2022
** include/my.h
** File description:
** funcion which
*/
#include <stdarg.h>
#ifndef MY_H_
    #define MY_H_
    #define ERROR_EXIT 84
void int_to_string(int num, char *str);
int my_printf(char const *format, ...);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb, int e, int z, int pos);
int my_put_nbr_u(int nb, int e, int z, int pos);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
void my_strcpy(char* dst, const char* src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
long calculator(int nb, int p);
void orderer (int *array, int i, int j);
int sizer(char const *str);
char *my_strdup(char const *src);
int  my_show_word_array(char * const * tab);
int my_isalphanum(char c);
int my_count_words(char const *str);
int  my_show_word_array(char * const * tab);
char *write_word(char const *str);
char **my_str_to_word_array(char const *str);
int my_put_octa(int num, int e, int z, int pos);
int my_put_hexa(int num, int e, int z, int pos);
char* flags_exist(char const *format, int i);
int spaces(int e, int z, int pos);
int compare1(char a, va_list l, int n, char *s);
int compare2(char a, va_list l, int n, char *s);
int compare3(char a, va_list l, int n, char *s);
int compare4(char a, va_list l, int n, char *s);
int compare5(char a, va_list l, int n, char *s);
int compare6(char a, va_list l, int n, char *s);
int compare7(char a, va_list l, int n, char *s);
int compare8(char a, va_list l, int n, char *s);
int compare9(char a, va_list l, int n, char *s);
int compare10(char a, va_list l, int n, char *s);
int pre_hag(char *str, char a);
int pre_hag2(char a, int change);
int pre_zero(char *str, char a);
int pre_num(char *str, char a);
int pre_pre(char *str, char a);
int pre_pos(char *str, char a);
int pre_space(char *str, char a);
int my_put_printables(char *str);
int my_put_hexa_may(int num, int e, int z, int pos);
int my_put_float(float nf);
int my_put_float_zero(float nf);
int my_put_exp(float nf);
int my_put_exp_may(float nf);
int my_put_float_exp(float nf, char *s, char a);
int my_put_float_exp_may(float nf, char *s, char a);
#endif /* MY_H_ */

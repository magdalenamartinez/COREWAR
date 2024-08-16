/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** funcion which
*/

#include <stdlib.h>
#include <stdio.h>

int my_isalphanum(char c);
int my_count_words(char const *str);
int  my_show_word_array(char * const * tab);
char *write_word(char const *str);
int my_strlen(char const *str);
char **my_str_to_word_array(char const *str)
{
    char **arr;
    int i, j, k = 0;
    arr = malloc(sizeof(char*) * (my_count_words(str) + 1));
    while (str[i] != '\0'){
        if (!my_isalphanum(str[i])){
            i++;
        } else {
            char *word = write_word(&str[i]);
            arr[j] = malloc(sizeof(char) * (my_strlen(word) + 1));
            arr[j] = word;
            i += my_strlen(word);
            j++;
        }
    }
    arr[j + 1] = 0;
    return arr;
}

char *write_word(char const *str)
{
    int i, n = 0;
    char *word;
    while (my_isalphanum(str[n])){
        n++;
    }
    word = malloc(sizeof(char) * (n + 1));
    while (i < n){
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

int my_count_words(char const *str)
{
    int i = 0;
    int j = 1;
    while (str[i] != '\0'){
        if (!my_isalphanum(str[i]) && my_isalphanum(str[i + 1])){
            j++;
        }
        i++;
    }
    return j;
}

int my_isalphanum(char c)
{
    int is_num = c >= '0' && c <= '9';
    int is_low = c >= 'a' && c <= 'z';
    int is_up = c >= 'A' && c <= 'Z';
    if (is_num || is_low || is_up)
        return 1;
    return 0;
}

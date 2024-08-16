/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare 2 strings
*/
#include <stdio.h>
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}
/*
int main()
{
    int i = 0;
    char a[ ]="hell";
    char b[ ]="h";
    int n=my_strcmp(a,b);
    if(n==0){
        printf("iguales");
    }else if(n<0){
        printf("s1 es menor");
    }else{printf("s1 es mayor");}
    return 0;
}
*/

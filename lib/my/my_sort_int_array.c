/*
** EPITECH PROJECT, 2022
** my_sort_int_array.c
** File description:
** funcion which
*/

#include <stdio.h>

void orderer (int *array, int i, int j);

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    while (i < size){
        while (j < size){
            orderer(array, i, j);
            j++;
        }
        j = ++i;
    }
}

void orderer (int *array, int i, int j)
{
    if (*(array + j) < *(array + i)){
        int t = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = t;
    }
}
/*
int main(void)
{
    int size = 5;
    int array[] = {4, 0, 90, 17, 21};
    my_sort_int_array(array, size);
    return 0;
}
*/

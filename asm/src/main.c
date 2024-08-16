/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../include/asm.h"

int main(int argc, char** argv)
{
    if (argc != 2) {
        return ERROR_EXIT;
    } else {
        return (study_parameters(argc, argv));
    }
}

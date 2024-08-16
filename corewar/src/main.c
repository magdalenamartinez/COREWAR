/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../include/corewar.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        return EXIT_FAILURE;
    } else {
        return study_args(argc, argv);
    }
}

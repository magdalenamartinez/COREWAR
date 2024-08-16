/*
** EPITECH PROJECT, 2023
** save
** File description:
** save
*/

#include "../../include/asm.h"

void save_hexa(char* buffer, hex_t* hex)
{
    int i = 0;
    size_t n;
    while (buffer[i] != '\0') {
        n++; i++;
    }
    size_t longitud = my_strlen(buffer) / sizeof(unsigned char);
    size_t a = hex->l + longitud;
    hex->hex = realloc(hex->hex, a * sizeof(unsigned char));
    for (size_t i = 0; i < longitud; i++) {
        unsigned char v = (unsigned char) buffer[i];
        hex->hex[hex->l + i] = v;
    }
    hex->l += longitud;
}

void save_hexa_int(unsigned int v, hex_t* hex)
{
    hex->hex = realloc(hex->hex, sizeof(unsigned char) * (hex->l + 1));
    (hex->hex)[hex->l] = v & 0xFF;
    hex->l += (size_t)1;
    hex->num += 1;
}

void save_hexa_int_two(unsigned int v, hex_t* hex)
{
    hex->hex = realloc(hex->hex, sizeof(unsigned char) * (hex->l + 2));
    (hex->hex)[hex->l] = (v >> 8) & 0xFF;
    hex->l += 1;
    (hex->hex)[hex->l] = v & 0xFF;
    hex->l += (size_t)1;
    hex->num += 2;
}

void save_hexa_int_four(unsigned int v, hex_t* hex)
{
    hex->hex = realloc(hex->hex, sizeof(unsigned char) * (hex->l + 4));
    (hex->hex)[hex->l] = (v >> 24) & 0xFF;
    (hex->hex)[hex->l + 1] = (v >> 16) & 0xFF;
    (hex->hex)[hex->l + 2] = (v >> 8) & 0xFF;
    (hex->hex)[hex->l + 3] = v & 0xFF;
    hex->l += (size_t)4;
    hex->num += 4;
}

void magic_number_write(hex_t* hex)
{
    unsigned char m_number[] = {0x00, 0xea, 0x83, 0xf3};
    size_t num_long = sizeof(m_number) / sizeof(unsigned char);
    if (hex->hex == NULL) {
        hex->hex = malloc(sizeof(unsigned char) * (hex->l + num_long));
    } else {
        int a = (hex->l + num_long);
        hex->hex = realloc(hex->hex, a * sizeof(unsigned char));
    }
    if (hex->hex == NULL) {
        return;
    }
    for (size_t i = 0; i < num_long; i++) {
        hex->hex[i] = m_number[i];
    }
    hex->l += num_long;
}

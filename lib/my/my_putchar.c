/*
** EPITECH PROJECT, 2019
** library
** File description:
** my_putchar.c
*/

#include <unistd.h>

int my_putchar(const char c)
{
    if (write(1, &c, 1) < 0)
        return (84);
    return (0);
}
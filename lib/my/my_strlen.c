/*
** EPITECH PROJECT, 2019
** library
** File description:
** my_strlen.c
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i])
        i += 1;
    return (i);
}
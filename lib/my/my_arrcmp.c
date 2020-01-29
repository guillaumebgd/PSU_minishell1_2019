/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** compares two arrays between each others
*/

#include "my.h"

int my_arrcmp(char **first, char **second)
{
    int len_first = my_arrlen(first);
    int len_second = my_arrlen(second);
    int index = 0;

    if (len_first != len_second)
        return (len_first - len_second);
    while (first[index] && second[index]) {
        if (my_strcmp(first[index], second[index]))
            return (1);
        index += 1;
    }
    return (0);
}
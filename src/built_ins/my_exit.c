/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** exit for the minishell program
*/

#include "my.h"

int my_exit(char **parsed_input)
{
    int size = my_arrlen(parsed_input);

    if (size != 1) {
        my_putstr("exit: Expression Syntax.\n");
        return (0);
    }
    my_putstr("exit\n");
    return (1);
}
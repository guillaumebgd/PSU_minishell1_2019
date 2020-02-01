/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** exits the minishell program
*/

#include "my.h"
#include "minishell.h"

int my_exit(char **parsed_input)
{
    int size = my_arrlen(parsed_input);

    if (size != 1) {
        my_putstr("exit: Expression Syntax.\n");
        return (FALSE);
    }
    my_putstr("exit\n");
    return (TRUE);
}
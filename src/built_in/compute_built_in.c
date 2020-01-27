/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes a build-in if a sent input matches with one
*/

#include "minishell.h"

static const char *list_built_in[] = {
    "exit"
};

static void (*redir_built_in[])(void) = {
    &my_exit
};

static enum bool_e compare_input_built_in(const char *cmd)
{
    if (my_strcmp(list_built_in[0], cmd) == 0)
        return (0);
    return (-1);
}

int compute_built_in(const char * const *parsed_input)
{
    int index_function = compare_input_built_in(parsed_input[0]);

    if (index_function == -1)
        return (-1);
    redir_built_in[index_function]();
}
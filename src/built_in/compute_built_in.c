/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes a build-in if a sent input matches with one
*/

#include "minishell.h"

static int compare_input_built_in(const char *cmd)
{
    static const char *built_ins[] = {"exit", "cd", "env",
                                    "setenv", "unsetenv"};
    int index = 0;

    while (built_ins[index]) {
        if (my_strcmp(built_ins[index], cmd) == 0)
            return (index);
        index += 1;
    }
    return (-1);
}

int compute_built_in(const char * const *parsed_input)
{
    static const void (*redir_built_in[])(void) = {&my_exit, &my_cd, &my_env
                                                &my_setenv, &my_unsetenv};
    int function_index = compare_input_built_in(parsed_input[0]);

    if (function_index == -1)
        return (-1);
    redir_built_in[function_index]();
}
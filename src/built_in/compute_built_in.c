/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes a build-in if a sent input matches with one
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"

static int compare_input_built_in(const char *cmd)
{
    static const char *built_ins[] = {"exit", "cd", "env",
                                    "setenv", "unsetenv", NULL};
    int index = 0;

    while (built_ins[index]) {
        if (!my_strcmp(built_ins[index], cmd, 0))
            return (index);
        index += 1;
    }
    return (-1);
}

int compute_built_in(envg_list_t **envg_list, char **parsed_input)
{
    int function_index = compare_input_built_in(parsed_input[0]);

    if (function_index == -1)
        return (-1);
    if (function_index == 0)
        return (my_exit(parsed_input));
    if (function_index == 2)
        my_env(envg_list);
    return (0);
}
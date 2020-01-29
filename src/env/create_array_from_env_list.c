/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** creates an array from an env list
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static char *get_var(const envg_list_t *envg_list)
{
    char *var_equals = NULL;
    char *variable = NULL;

    var_equals = my_strcat(envg_list->var_name, "=");
    variable = my_strcat(var_equals, envg_list->var_value);
    if (var_equals)
        free(var_equals);
    return (variable);
}

char **create_array_from_env_list(envg_list_t *envg_list)
{
    char **envg = NULL;
    char *var = NULL;
    int size = env_list_size(envg_list);
    int index = 0;

    if (size == 0)
        return (NULL);
    while (index < size) {
        var = get_var(envg_list);
        envg = my_append_to_array(envg, var, 1);
        envg_list = envg_list->next;
        index += 1;
    }
    return (envg);
}
/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** shows the environment
*/

#include <stddef.h>
#include "minishell.h"
#include "my.h"

void show_env(envg_list_t **envg_list)
{
    envg_list_t *tmp = NULL;

    for (tmp = (*envg_list); tmp; tmp = tmp->next)
        my_printf("%s=%s\n", tmp->var_name, tmp->var_value);
}
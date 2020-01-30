/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** shows the environment
*/

#include <stddef.h>
#include "minishell.h"
#include "my.h"

void show_env(envg_list_t **head)
{
    envg_list_t *tmp = NULL;

    if (!(*head))
        return;
    for (tmp = (*head); tmp != (*head)->prev; tmp = tmp->next)
        my_printf("%s=%s\n", tmp->var_name, tmp->var_value);
    my_printf("%s=%s\n", tmp->var_name, tmp->var_value);
}
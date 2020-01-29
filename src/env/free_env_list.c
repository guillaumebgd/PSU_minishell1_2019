/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** frees allocated memory for env_list
*/

#include <stdlib.h>
#include "minishell.h"

void free_env_list(envg_list_t **head)
{
    envg_list_t *tmp = NULL;

    if (!(*head))
        return;
    for (tmp = (*head); tmp; tmp = (*head)) {
        (*head) = (*head)->next;
        if (tmp->var_name)
            free(tmp->var_name);
        if (tmp->var_value)
            free(tmp->var_value);
        if (tmp)
            free(tmp);
    }
}
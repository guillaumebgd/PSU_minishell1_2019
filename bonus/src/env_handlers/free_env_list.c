/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** frees allocated memory for env_list
*/

#include <stdlib.h>
#include "minishell.h"

void free_node(envg_list_t *tmp)
{
    if (!tmp)
        return;
    if (tmp->var_name)
        free(tmp->var_name);
    if (tmp->var_value)
        free(tmp->var_value);
    if (tmp)
        free(tmp);
}

void free_env_list(envg_list_t **head)
{
    envg_list_t *tmp = NULL;
    envg_list_t *end = NULL;

    if (!(*head))
        return;
    end = (*head)->prev;
    for (tmp = (*head); tmp != end; tmp = (*head)) {
        (*head) = (*head)->next;
        free_node(tmp);
    }
    free_node(tmp);
}
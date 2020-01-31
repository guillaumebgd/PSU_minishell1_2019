/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** adds a new variable to the env
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static envg_list_t *get_var_in_env(envg_list_t **head, const char *var_name)
{
    envg_list_t *tmp = NULL;

    if (!(*head))
        return (NULL);
    for (tmp = (*head); tmp != (*head)->prev; tmp = tmp->next) {
        if (!my_strcmp(tmp->var_name, var_name, 0))
            return (tmp);
    }
    if (!my_strcmp(tmp->var_name, var_name, 0))
        return (tmp);
    return (NULL);
}

int destroy_env_var(envg_list_t **envg_list, const char *var_name)
{
    envg_list_t *variable = NULL;
    int size = env_list_size(*envg_list);

    if (!(*envg_list) || !var_name)
        return (84);
    variable = get_var_in_env(envg_list, var_name);
    if (!variable)
        return (FALSE);
    if (variable == (*envg_list)) {
        (*envg_list) = (*envg_list)->next;
        if ((*envg_list) == (*envg_list)->next) {
            free_node(variable);
            (*envg_list) = NULL;
            return (FALSE);
        }
    }
    variable->prev->next = variable->next;
    variable->next->prev = variable->prev;
    free_node(variable);
    return (TRUE);
}
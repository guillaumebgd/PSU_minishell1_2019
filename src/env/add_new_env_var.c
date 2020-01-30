/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** adds a new variable to the env
*/

#include <stdlib.h>
#include "minishell.h"

static void add_node(envg_list_t **head, const char *var_name,
                    const char *var_value)
{
    envg_list_t *node = NULL;

    if (!(*head))
        return;
    node = malloc(sizeof(envg_list_t));
    if (!node)
        return;
    node->var_name = my_strdup(var_name);
    node->var_value = my_strdup(var_value);
    node->next = (*head);
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
}

static void add_first_node(envg_list_t **head, const char *var_name,
                            const char *var_value)
{
    envg_list_t *node = NULL;

    node = malloc(sizeof(envg_list_t));
    if (!node)
        return;
    node->var_name = my_strdup(var_name);
    node->var_value = my_strdup(var_value);
    node->next = node;
    node->prev = node;
    (*head) = node;
}

void add_new_env_var(envg_list_t **envg_list, const char *var_name,
                    const char *var_value)
{
    if (!(*envg_list))
        add_first_node(envg_list, var_name, var_value);
    else
        add_node(envg_list, var_name, var_value);
}
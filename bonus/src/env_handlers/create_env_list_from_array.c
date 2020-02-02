/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** creates a linked list of env variables from an array
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static void add_node(envg_list_t **head, const char *env_lign)
{
    envg_list_t *node = NULL;
    int index = 0;

    if (!(*head))
        return;
    node = malloc(sizeof(envg_list_t));
    if (!node)
        return;
    node->var_name = my_strdup_char(env_lign, '=');
    while (env_lign[index] && env_lign[index] != '=')
        index += 1;
    node->var_value = my_strdup(&env_lign[index + 1]);
    node->next = (*head);
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
}

static void add_first_node(envg_list_t **head, const char *env_lign)
{
    envg_list_t *node = NULL;
    int index = 0;

    node = malloc(sizeof(envg_list_t));
    if (!node)
        return;
    node->var_name = my_strdup_char(env_lign, '=');
    while (env_lign[index] && env_lign[index] != '=')
        index += 1;
    node->var_value = my_strdup(&env_lign[index + 1]);
    node->next = node;
    node->prev = node;
    (*head) = node;
}

void create_env_list_from_array(envg_list_t **envg_list,
                                const char * const *env)
{
    int index = 0;

    if (!env || !env[0])
        return;
    while (env[index]) {
        if (!(*envg_list))
            add_first_node(envg_list, env[index]);
        else
            add_node(envg_list, env[index]);
        index += 1;
    }
}
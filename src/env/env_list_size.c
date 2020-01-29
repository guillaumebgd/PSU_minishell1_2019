/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** returns an int corresponding to the length of an env array
*/

#include <stddef.h>
#include "minishell.h"

int env_list_size(const envg_list_t *env_list)
{
    envg_list_t *tmp = NULL;
    int index = 1;

    if (!env_list)
        return (0);
    for (tmp = (envg_list_t *)env_list; tmp->next; tmp = tmp->next)
        index += 1;
    return (index);
}
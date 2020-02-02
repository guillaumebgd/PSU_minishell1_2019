/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** returns an int corresponding to the length of an env array
*/

#include <stddef.h>
#include "minishell.h"

int env_list_size(envg_list_t *head)
{
    envg_list_t *tmp = NULL;
    int index = 0;

    if (!head)
        return (0);
    for (tmp = head; tmp != head->prev; tmp = tmp->next)
        index += 1;
    index += 1;
    return (index);
}
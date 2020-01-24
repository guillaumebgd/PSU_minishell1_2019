/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** gets information from the user
*/

#include "my.h"

char *print_prompt_get_input(void)
{
    my_putstr("$> ");
    return (get_next_line(0, 4096));
}
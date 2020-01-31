/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsets variables from env
*/

#include "my.h"
#include "minishell.h"

void my_unsetenv(envg_list_t **head, char **parsed_input)
{
    int ac = my_arrlen(parsed_input);
    int index = 1;

    if (ac <= 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return;
    }
    while (index < ac) {
        destroy_env_var(head, parsed_input[index]);
        index += 1;
    }
}
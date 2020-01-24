/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** main track of what is happening the in process
*/

#include <stddef.h>
#include "minishell.h"
#include "my.h"

static bool_t special_input(const char *input, char **env)
{
    int len_input = my_strlen(input);

    if (len_input <= 0) {
        if (len_input == 0)
            minishell(env);
        if (len_input < 0)
            my_putstr("exit\n");
        return (FALSE);
    }
    return (TRUE);
}

void minishell(char **env)
{
    static char **parsed_input = NULL;
    static char *input = NULL;

    input = print_prompt_get_input();
    if (!special_input(input, env))
        return;
    parsed_input = my_str_to_word_array(input, ' ', 1);
    //compute_built_in(parsed_input);
    if (!compute_cmd(parsed_input, env))
        return;
    minishell(env);
}
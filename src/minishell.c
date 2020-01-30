/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main track of what is happening the in process
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"

static bool_t special_input(const char *input, envg_list_t **envg_list)
{
    int len_input = my_strlen(input);

    if (len_input <= 0) {
        if (len_input == 0)
            minishell(envg_list);
        else
            my_putstr("exit\n");
        return (FALSE);
    }
    return (TRUE);
}

void minishell(envg_list_t **envg_list)
{
    static char **parsed_input = NULL;
    static char *input = NULL;

    print_prompt();
    input = get_next_line(0, 4096);
    if (!special_input(input, envg_list))
        return;
    parsed_input = my_str_to_word_array(input, " \t", 1);
    //compute_built_in(parsed_input);
    if (!compute_cmd(parsed_input, envg_list))
        return;
    minishell(envg_list);
}

void setup_minishell(const char * const *env)
{
    envg_list_t *envg_list = NULL;

    create_env_list_from_array(&envg_list, env);
    minishell(&envg_list);
    free_env_list(&envg_list);
}
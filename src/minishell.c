/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main track of what is happening the in process
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"

static bool_t check_empty_input(const char *input)
{
    int index = 0;

    if (!input || !input[0])
        return (FALSE);
    while (input[index]) {
        if (!find_char_in_str(" \t", input[index]))
            return (FALSE);
        index += 1;
    }
    return (TRUE);
}

static bool_t special_input(const char *input, envg_list_t **envg_list)
{
    bool_t empty_input = check_empty_input(input);
    int len_input = my_strlen(input);
    int index = 0;

    if (len_input <= 0 || empty_input) {
        if (len_input == 0 || empty_input)
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
    int is_built_in = 0;

    print_prompt();
    input = get_next_line(0, 4096);
    if (!special_input(input, envg_list))
        return;
    parsed_input = my_str_to_word_array(input, " \t", 1);
    is_built_in = compute_built_in(envg_list, parsed_input);
    if (is_built_in == 1)
        return;
    if (is_built_in == -1 && !compute_cmd(parsed_input, envg_list))
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
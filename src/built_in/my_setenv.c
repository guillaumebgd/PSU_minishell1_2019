/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** sets a variable in my env
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static envg_list_t *is_var_in_env(envg_list_t **head, const char *var_name)
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

static void set_var(const int ac, envg_list_t **head, char **parsed_input)
{
    envg_list_t *var_ptr = is_var_in_env(head, parsed_input[1]);

    if (var_ptr) {
        if (var_ptr->var_value)
            free(var_ptr->var_value);
        if (ac == 2)
            var_ptr->var_value = my_strdup(NULL);
        else
            var_ptr->var_value = my_strdup(parsed_input[2]);
        return;
    }
    if (ac == 2)
        add_new_env_var(head, parsed_input[1], NULL);
    else
        add_new_env_var(head, parsed_input[1], parsed_input[2]);
}

static void handle_setenv(envg_list_t **head, const int ac, char **parsed_input)
{
    if (!my_isalpha(parsed_input[1][0]))
        my_putstr("setenv: Variable name must begin with a letter.\n");
    else if (!my_str_is_alphanum(parsed_input[1]))
        my_putstr("setenv: Variable name must contain"
                    " alphanumeric characters.\n");
    else
        set_var(ac, head, parsed_input);
}

void my_setenv(envg_list_t **head, char **parsed_input)
{
    int ac = my_arrlen(parsed_input);

    if (ac <= 0)
        return;
    if (ac == 1) {
        my_env(head);
        return;
    }
    if (ac == 2 || ac == 3)
        handle_setenv(head, ac, parsed_input);
    else
        my_putstr("setenv: Too many arguments.\n");
}
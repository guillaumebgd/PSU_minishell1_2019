/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the compute cmd function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(compute_cmd, wrong_path)
{
    envg_list_t *envg_list = NULL;
    char *parsed_input[] = {"ls"};
    char *envg[] = {"PATH=/bin/ls", NULL};

    cr_redirect_stdout();
    create_env_list_from_array(&envg_list, (const char * const *)envg);
    compute_cmd(parsed_input, &envg_list);
    cr_expect_stdout_eq_str("ls: Command not found.\n");
    free_env_list(&envg_list);
}

Test(compute_cmd, no_path_variable)
{
    envg_list_t *envg_list = NULL;
    char *parsed_input[] = {"ls"};
    char *envg[] = {NULL};

    cr_redirect_stdout();
    create_env_list_from_array(&envg_list, (const char * const *)envg);
    compute_cmd(parsed_input, &envg_list);
    cr_expect_stdout_eq_str("ls: Command not found.\n");
    free_env_list(&envg_list);
}
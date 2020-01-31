/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests my_env function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(my_env, basic_env_not_null)
{
    const char *envg[] = {"my=env", "is=clean", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    my_env(&head);
    cr_expect_stdout_eq_str("my=env\n"
                            "is=clean\n");
    free_env_list(&head);
}

Test(my_env, null_env)
{
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, NULL);
    my_env(&head);
    free_env_list(&head);
}
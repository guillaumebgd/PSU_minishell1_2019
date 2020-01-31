/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests none working phase of compute_built_in
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(compute_built_in, try_none_existing)
{
    const char *envg[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    if (compute_built_in(&head, (char *[]){"ls", NULL}) == -1)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 2);
    free_env_list(&head);
}
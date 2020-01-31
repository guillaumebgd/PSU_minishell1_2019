/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the compute_built_in function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(compute_built_in, try_my_env)
{
    const char *envg[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    compute_built_in(&head, (char *[]){"env", NULL});
    cr_expect_stdout_eq_str("Test=one\n");
    free_env_list(&head);
}

Test(compute_built_in, try_my_cd)
{
    const char *envg[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    compute_built_in(&head, (char *[]){"cd", NULL});
    cr_expect_stdout_eq_str("cd: No home directory.\n");
    free_env_list(&head);
}

Test(compute_built_in, try_my_setenv)
{
    const char *envg[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    compute_built_in(&head, (char *[]){"setenv", NULL});
    cr_expect_stdout_eq_str("Test=one\n");
    free_env_list(&head);
}

Test(compute_built_in, try_my_unsetenv)
{
    const char *envg[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    compute_built_in(&head, (char *[]){"unsetenv", "Test", NULL});
    if (head)
        cr_expect_eq(1, 2);
    else
        cr_expect_eq(1, 1);
    free_env_list(&head);
}

Test(compute_built_in, try_my_exit)
{
    const char *envg[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    compute_built_in(&head, (char *[]){"exit", NULL});
    cr_expect_stdout_eq_str("exit\n");
    free_env_list(&head);
}
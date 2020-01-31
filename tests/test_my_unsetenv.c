/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the my_setenv function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(my_unsetenv, unsetenv_existing_vars)
{
    const char *envg[] = {"TEST=one", "Test=two", NULL};
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, envg);
    my_unsetenv(&head, (char *[]){"unsetenv", "TEST", "Test", NULL});
    if (head)
        cr_expect_neq(1, 1);
    else
        cr_expect_eq(1, 1);
    free_env_list(&head);
}

Test(my_unsetenv, too_few_arguments)
{
    const char *envg[] = {"TEST=one", "Test=two", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    my_unsetenv(&head, (char *[]){"unsetenv", NULL});
    cr_expect_stdout_eq_str("unsetenv: Too few arguments.\n");
    free_env_list(&head);
}

Test(my_unsetenv, unset_none_existing_var)
{
    const char *envg[] = {"TEST=one", "Test=two", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    my_unsetenv(&head, (char *[]){"unsetenv", "yes", NULL});
    show_env(&head);
    cr_expect_stdout_eq_str("TEST=one\n"
                            "Test=two\n");
    free_env_list(&head);
}
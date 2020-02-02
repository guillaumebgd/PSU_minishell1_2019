/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the my_setenv function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(my_setenv, add_new_variable)
{
    const char *envg[] = {"TEST=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    my_setenv(&head, (char *[]){"setenv", "New", "two", NULL});
    show_env(&head);
    cr_expect_stdout_eq_str("TEST=one\n"
                            "New=two\n");
    free_env_list(&head);
}

Test(my_setenv, change_an_already_existing_var)
{
    const char *envg[] = {"TEST=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    my_setenv(&head, (char *[]){"setenv", "TEST", "two", NULL});
    show_env(&head);
    cr_expect_stdout_eq_str("TEST=two\n");
    free_env_list(&head);
}

Test(my_setenv, add_new_var_to_null_env)
{
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, NULL);
    my_setenv(&head, (char *[]){"setenv", "TEST", "two", NULL});
    show_env(&head);
    cr_expect_stdout_eq_str("TEST=two\n");
    free_env_list(&head);
}

Test(my_setenv, invalid_first_char)
{
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, NULL);
    my_setenv(&head, (char *[]){"setenv", "/EST", "two", NULL});
    cr_expect_stdout_eq_str("setenv: Variable name"
                            " must begin with a letter.\n");
    free_env_list(&head);
}

Test(my_setenv, invalid_char_in_var)
{
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, NULL);
    my_setenv(&head, (char *[]){"setenv", "E/ST", "two", NULL});
    cr_expect_stdout_eq_str("setenv: Variable name must "
                            "contain alphanumeric characters.\n");
    free_env_list(&head);
}
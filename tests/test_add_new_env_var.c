/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the add_new_env_var function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(add_new_env_var, simple_add)
{
    const char *envg[] = {"Test=one", NULL};
    const char *expect[] = {"Test=one", "New=two", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    add_new_env_var(&head, "New", "two");
    show_env(&head);
    cr_expect_stdout_eq_str("Test=one\n"
                            "New=two\n");
    free_env_list(&head);
}

Test(add_new_env_var, env_was_null)
{
    const char *expect[] = {"Test=one", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, NULL);
    add_new_env_var(&head, "Test", "one");
    show_env(&head);
    cr_expect_stdout_eq_str("Test=one\n");
    free_env_list(&head);
}
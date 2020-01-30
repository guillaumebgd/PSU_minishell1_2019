/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the show_env function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(show_env, basic_env_shown)
{
    const char * const envg[] = {"First=one", "Second=two",
                                "Third=three", NULL};
    envg_list_t *head = NULL;

    cr_redirect_stdout();
    create_env_list_from_array(&head, envg);
    show_env(&head);
    cr_expect_stdout_eq_str("First=one\n"
                            "Second=two\n"
                            "Third=three\n");
    free_env_list(&head);
}

Test(show_env, null_env)
{
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, NULL);
    show_env(&head);
    free_env_list(&head);
}
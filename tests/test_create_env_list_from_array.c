/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the create_env_list_from_array function
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(create_env_list_from_array, basic_create)
{
    const char * const envg[] = {"VAR=first_val", "OH=second_val", NULL};
    envg_list_t *my_env = NULL;
    int index = 0;

    create_env_list_from_array(&my_env, envg);
    if (!my_env || !(my_env->next))
        cr_expect_neq(1, 1);
    else {
        cr_expect_eq(my_env->prev, my_env->next->next->next);
        cr_expect_str_eq(my_env->var_name, "VAR");
        cr_expect_str_eq(my_env->var_value, "first_val");
        cr_expect_str_eq(my_env->next->var_name, "OH");
        cr_expect_str_eq(my_env->next->var_value, "second_val");
        cr_expect_eq(my_env->prev->next, my_env);
    }
    free_env_list(&my_env);
}

Test(create_env_list_from_array, null_sent_but_envg_exists)
{
    const char * const envg[] = {NULL};
    envg_list_t *my_env = NULL;
    int index = 0;

    create_env_list_from_array(&my_env, envg);
    if (!my_env)
        cr_assert_eq(1, 1);
    else
        cr_expect_neq(1, 1);
    free_env_list(&my_env);
}
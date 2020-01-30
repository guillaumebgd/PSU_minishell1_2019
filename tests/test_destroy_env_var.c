/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the destroy_env_var function
*/

#include <criterion/criterion.h>
#include "my.h"
#include "minishell.h"

Test(destroy_env_var, simple_test)
{
    const char * const test[] = {"First=one", "Second=two",
                                "Third=three", NULL};
    const char * const expect[] = {"First=one", "Third=three", NULL};
    envg_list_t *envg_list = NULL;
    char **result = NULL;

    create_env_list_from_array(&envg_list, test);
    destroy_env_var(&envg_list, "Second");
    result = create_array_from_env_list(envg_list);
    cr_expect_eq(my_arrcmp(result, (char **)expect), 0);
    free_env_list(&envg_list);
    my_free_arr(result);
}

Test(destroy_env_var, rm_first_node)
{
    const char * const test[] = {"First=one", "Second=two", NULL};
    const char * const expect[] = {"Second=two", NULL};
    envg_list_t *envg_list = NULL;
    char **result = NULL;

    create_env_list_from_array(&envg_list, test);
    destroy_env_var(&envg_list, "First");
    result = create_array_from_env_list(envg_list);
    cr_expect_eq(my_arrcmp(result, (char **)expect), 0);
    free_env_list(&envg_list);
    my_free_arr(result);
}

Test(destroy_env_var, rm_the_only_node)
{
    const char * const test[] = {"First=one", NULL};
    envg_list_t *envg_list = NULL;
    char **result = NULL;

    create_env_list_from_array(&envg_list, test);
    destroy_env_var(&envg_list, "First");
    result = create_array_from_env_list(envg_list);
    cr_expect_eq(my_arrcmp(result, NULL), 0);
    free_env_list(&envg_list);
    my_free_arr(result);
}

Test(destroy_env_var, none_existing_variable)
{
    const char * const test[] = {"First=one", "Second=two",
                                "Third=three", NULL};
    envg_list_t *envg_list = NULL;
    char **result = NULL;

    create_env_list_from_array(&envg_list, test);
    destroy_env_var(&envg_list, "not_a_var");
    result = create_array_from_env_list(envg_list);
    cr_expect_eq(my_arrcmp(result, (char **)test), 0);
    free_env_list(&envg_list);
    my_free_arr(result);
}

Test(destroy_env_var, env_is_null)
{
    envg_list_t *envg_list = NULL;
    char **result = NULL;

    create_env_list_from_array(&envg_list, NULL);
    destroy_env_var(&envg_list, "not_a_var");
    result = create_array_from_env_list(envg_list);
    cr_expect_eq(my_arrcmp(result, NULL), 0);
    free_env_list(&envg_list);
    my_free_arr(result);
}
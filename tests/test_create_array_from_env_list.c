/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the create_array_from_env_list function
*/

#include <criterion/criterion.h>
#include "my.h"
#include "minishell.h"

Test(create_array_from_env_list, simple_test)
{
    const char * const test[] = {"First=one", "Second=two", NULL};
    envg_list_t *envg_list = NULL;
    char **result = NULL;

    create_env_list_from_array(&envg_list, test);
    result = create_array_from_env_list(envg_list);
    cr_expect_eq(my_arrcmp(result, (char **)test), 0);
    free_env_list(&envg_list);
    my_free_arr(result);
}
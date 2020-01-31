/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_my_cd_special_cases.c
*/

#include <criterion/criterion.h>
#include "my.h"
#include "minishell.h"

Test(my_cd, home_exists_no_value)
{
    const char *envg[] = {"HOME=", NULL};
    char *path = NULL;
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, envg);
    my_cd(&head, (char *[]){"cd", NULL});
    path = get_current_pwd();
    if (my_strlen(path) < 19)
        cr_expect_eq(1, 2);
    else
        cr_expect_str_eq(&path[my_strlen(path) - 19], "PSU_minishell1_2019");
    if (path)
        free(path);

}
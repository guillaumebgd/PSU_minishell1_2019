/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the my_cd function
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "my.h"
#include "minishell.h"

Test(my_cd, simple_cd)
{
    const char *envg[] = {"HOME=/home/", NULL};
    char *path = NULL;
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, envg);
    my_cd(&head, (char *[]){"cd", "include", NULL});
    path = get_current_pwd();
    if (my_strlen(path) < 7)
        cr_expect_eq(1, 2);
    else
        cr_expect_str_eq(&path[my_strlen(path) - 7], "include");
    if (path)
        free(path);
}

Test(my_cd, false_directory)
{
    const char *envg[] = {"HOME=/home/", NULL};
    char *path = NULL;
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, envg);
    my_cd(&head, (char *[]){"cd", "idontexist", NULL});
    path = get_current_pwd();
    if (my_strlen(path) < 19)
        cr_expect_eq(1, 2);
    else
        cr_expect_str_eq(&path[my_strlen(path) - 19], "PSU_minishell1_2019");
    if (path)
        free(path);
}

Test(my_cd, test_cd_minus)
{
    const char *envg[] = {"HOME=/home/", NULL};
    char *path = NULL;
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, envg);
    my_cd(&head, (char *[]){"cd", "include", NULL});
    my_cd(&head, (char *[]){"cd", "-", NULL});
    path = get_current_pwd();
    if (my_strlen(path) < 7)
        cr_expect_eq(1, 2);
    else
        cr_expect_str_eq(&path[my_strlen(path) - 19], "PSU_minishell1_2019");
    if (path)
        free(path);
}

Test(my_cd, test_cd_minus_with_oldpwd)
{
    const char *envg[] = {"OLDPWD=include", NULL};
    char *path = NULL;
    envg_list_t *head = NULL;

    create_env_list_from_array(&head, envg);
    my_cd(&head, (char *[]){"cd", "-", NULL});
    path = get_current_pwd();
    if (my_strlen(path) < 7)
        cr_expect_eq(1, 2);
    else
        cr_expect_str_eq(&path[my_strlen(path) - 7], "include");
    if (path)
        free(path);
}
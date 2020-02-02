/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_find_path_cmd.c
*/

#include <criterion/criterion.h>
#include "my.h"
#include "minishell.h"

Test(find_path_cmd, existant_file_in_path)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/local/sbin:/usr/bin", NULL};
    char *path = find_path_cmd(env, "ls");

    if (path != NULL)
        cr_expect_eq(1, 1);
    else
        cr_expect_neq(1, 1);
    if (path)
        free(path);
}

Test(find_path_cmd, existant_file_in_curdir)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/local/sbin:/usr/bin", NULL};
    char *path = find_path_cmd(env, "main.c");

    if (path == NULL)
        cr_expect_eq(1, 1);
    else
        cr_expect_neq(1, 1);
    if (path)
        free(path);
    is_in_dir(&path, "./src/main.c");
    if (path != NULL)
        cr_expect_eq(1, 1);
    else
        cr_expect_neq(1, 1);
    if (path)
        free(path);
}

Test(find_path_cmd, none_existant_file)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/local/sbin:/usr/bin", NULL};
    char *path = find_path_cmd(env, "iamnotexistant");

    if (path == NULL)
        cr_assert_eq(1, 1);
    else
        cr_assert_neq(1, 1);
    if (path)
        free(path);
}

Test(find_path_cmd, no_path)
{
    char *path = find_path_cmd(NULL, "ls");

    if (path == NULL)
        cr_assert_eq(1, 1);
    else
        cr_assert_neq(1, 1);
    if (path)
        free(path);
}
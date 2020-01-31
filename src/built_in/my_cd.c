/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes built-in cd
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static void set_old_pwd(envg_list_t **head, char *oldpwd)
{
    my_setenv(head, (char *[]){"setenv", "OLDPWD", oldpwd, NULL});
    if (oldpwd)
        free(oldpwd);
}

static void set_new_pwd(envg_list_t **head)
{
    char *new_cur_pwd = get_current_pwd();

    my_setenv(head, (char *[]){"setenv", "PWD", new_cur_pwd, NULL});
    if (new_cur_pwd)
        free(new_cur_pwd);
}

static void change_working_dir(const char *pathway)
{
    if (chdir(pathway) == -1)
        my_printf("%s: %s\n", pathway, strerror(errno));
}

static void compute_cd(envg_list_t **head, char **parsed_input, const int ac)
{
    envg_list_t *tmp = NULL;

    if (ac == 1 || !my_strcmp(parsed_input[1], "~", 0)) {
        tmp = is_var_in_env(head, "HOME");
        if (!tmp)
            my_putstr("cd: No home directory.\n");
        else
            change_working_dir(tmp->var_value);
    } else if (!my_strcmp(parsed_input[1], "-", 0))
        change_working_dir(is_var_in_env(head, "OLDPWD")->var_value);
    else
        change_working_dir(parsed_input[1]);
}

void my_cd(envg_list_t **head, char **parsed_input)
{
    char *oldpwd = get_current_pwd();
    int ac = my_arrlen(parsed_input);

    if (ac < 1)
        return;
    if (ac > 2) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    compute_cd(head, parsed_input, ac);
    set_old_pwd(head, oldpwd);
    set_new_pwd(head);
}
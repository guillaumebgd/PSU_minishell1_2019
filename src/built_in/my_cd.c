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

static char *get_current_pwd(void)
{
    char *pwd = NULL;

    pwd = malloc(sizeof(char) * 1025);
    if (pwd) {
        pwd[1024] = '\0';
        getcwd(pwd, 1025);
    } else
        return (NULL);
    return (pwd);
}

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

static void compute_cd(const char *pathway)
{
    if (chdir(pathway) == -1)
        my_printf("%s: %s\n", pathway, strerror(errno));
}

void my_cd(envg_list_t **head, char **parsed_input)
{
    char *oldpwd = get_current_pwd();
    envg_list_t *tmp = NULL;
    int ac = my_arrlen(parsed_input);

    if (ac < 1)
        return;
    if (ac > 2) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    if (ac == 1 || !my_strcmp(parsed_input[1], "~", 0)) {
        tmp = is_var_in_env(head, "HOME");
        if (!tmp)
            my_putstr("cd: No home directory.\n");
        else
            compute_cd(tmp->var_value);
    } else if (!my_strcmp(parsed_input[1], "-", 0))
        compute_cd(is_var_in_env(head, "OLDPWD")->var_value);
    else
        compute_cd(parsed_input[1]);
    set_old_pwd(head, oldpwd);
    set_new_pwd(head);
}
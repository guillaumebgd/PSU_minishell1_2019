/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes built-in cd
*/

#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static void change_working_dir(const char *pathway, const int home)
{
    struct stat file_stat;

    if (!pathway || !pathway[0])
        return;
    if (chdir(pathway) == -1) {
        if (stat(pathway, &file_stat) == -1) {
            my_printf("%s: Not a directory.\n", pathway);
            return;
        }
        if (!S_ISDIR(file_stat.st_mode))
            my_printf("%s: Not a directory.\n", pathway);
        else if (home)
            my_printf("cd: %s\n", strerror(errno));
        else
            my_printf("%s: %s\n", pathway, strerror(errno));
    }
}

static void compute_cd(envg_list_t **head, char **parsed_input, const int ac)
{
    envg_list_t *home = NULL;
    envg_list_t *last_dir = NULL;

    if (ac == 1 || !my_strcmp(parsed_input[1], "~", 0)) {
        home = is_var_in_env(head, "HOME");
        if (!home)
            my_putstr("cd: No home directory.\n");
        else
            change_working_dir(home->var_value, 1);
    } else if (!my_strcmp(parsed_input[1], "-", 0)) {
        last_dir = is_var_in_env(head, "OLDPWD");
        if (last_dir)
            change_working_dir(last_dir->var_value, 0);
        else
            my_printf(": %s.\n", strerror(ENOENT));
    } else
        change_working_dir(parsed_input[1], 0);
}

void my_cd(envg_list_t **head, char **parsed_input)
{
    char *oldpwd = get_current_pwd();
    char *new_cur_pwd = NULL;
    int ac = my_arrlen(parsed_input);

    if (ac < 1)
        return;
    if (ac > 2) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    compute_cd(head, parsed_input, ac);
    new_cur_pwd = get_current_pwd();
    my_setenv(head, (char *[]){"setenv", "OLDPWD", oldpwd, NULL});
    if (oldpwd)
        free(oldpwd);
    my_setenv(head, (char *[]){"setenv", "PWD", new_cur_pwd, NULL});
    if (new_cur_pwd)
        free(new_cur_pwd);
}
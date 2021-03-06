/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets information from the user
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

char *get_current_pwd(void)
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

static char *get_curdir(void)
{
    char *current_directory = NULL;
    char **split_pwd = NULL;
    char *pwd = NULL;

    pwd = get_current_pwd();
    if (!pwd)
        return (NULL);
    split_pwd = my_str_to_word_array(pwd, "/", 1);
    if (my_arrlen(split_pwd) == 0) {
        if (split_pwd)
            my_free_arr(split_pwd);
        return (NULL);
    }
    current_directory = my_strdup(split_pwd[my_arrlen(split_pwd) - 1]);
    my_free_arr(split_pwd);
    return (current_directory);
}

void print_prompt(const bool_t success)
{
    char *cur_dir = NULL;

    cur_dir = get_curdir();
    if (success)
        my_putstr("<[\e[0;92mSUCCESS\e[0m]>");
    else
        my_putstr("<[\e[0;31mFAILURE\e[0m]>");
    if (cur_dir) {
        my_printf(" \e[0;34m%s", cur_dir);
        free(cur_dir);
    }
    my_printf("\e[0;94m >>\e[0m ");
}
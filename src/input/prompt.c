/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets information from the user
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char *get_curdir(void)
{
    char *current_directory = NULL;
    char **split_pwd = NULL;
    char *pwd = NULL;

    pwd = malloc(sizeof(char) * 1025);
    if (pwd) {
        pwd[1024] = '\0';
        getcwd(pwd, 1025);
    } else
        return (NULL);
    split_pwd = my_str_to_word_array(pwd, "/", 1);
    current_directory = my_strdup(split_pwd[my_arrlen(split_pwd) - 1]);
    my_free_arr(split_pwd);
    return (current_directory);
}

char *print_prompt_get_input(void)
{
    char *cur_dir = NULL;

    cur_dir = get_curdir();
    if (cur_dir) {
        my_printf("$ %s >> ", cur_dir);
        free(cur_dir);
    } else
        my_printf("$ >> ");
    return (get_next_line(0, 4096));
}
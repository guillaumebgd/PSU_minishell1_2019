/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a binary is in a directory
*/

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static void get_given_path(char **given_path, const char *bin)
{
    int index = my_strlen(bin);
    int len_path = 0;

    while (index >= 0 && bin[index] != '/')
        index -= 1;
    while (index >= 0 && bin[index] == '/')
        index -= 1;
    index += 1;
    if (index == -1)
        return;
    *given_path = my_strndup(bin, index);
}

static bool_t check_existence(char **right_path, const char *given_path,
                            const struct dirent *dir_stat, const char *bin)
{
    char *file_path = NULL;
    struct stat file;

    file_path = get_correct_pwd(given_path, dir_stat->d_name);
    stat(file_path, &file);
    if (!my_strcmp(file_path, bin, '/')) {
        *right_path = file_path;
        return (TRUE);
    }
    free(file_path);
    return (FALSE);
}

static int straight_dir_path(char **right_path, const char *bin)
{
    struct stat file_stat;

    if (!bin)
        return (0);
    stat(bin, &file_stat);
    if (S_ISDIR(file_stat.st_mode)) {
        *right_path = my_strdup(bin);
        return (1);
    }
    return (0);
}

void is_in_dir(char **right_path, const char *bin)
{
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;
    char *given_path = NULL;

    if (straight_dir_path(right_path, bin))
        return;
    get_given_path(&given_path, bin);
    directory = opendir(given_path);
    if (!directory)
        return;
    dir_stat = readdir(directory);
    while (dir_stat) {
        if (check_existence(right_path, given_path, dir_stat, bin))
            break;
        dir_stat = readdir(directory);
    }
    if (given_path)
        free(given_path);
    closedir(directory);
}
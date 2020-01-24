/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** cd.c
*/

#include "minishell.h"
#include "my.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stddef.h>

static int is_in_path(const char *env_path,
                        const char *to_find,
                        bool_t *found)
{
    struct stat file_stat;
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;

    directory = opendir(env_path);
    if (!directory)
        return (0);
    dir_stat = readdir(directory);
    while (directory) {
        stat(env_path, &file_stat);
        if (S_ISREG(file_stat.st_mode)
            && my_strcmp(dir_stat->d_name, to_find) == 0) {
            (*found) = TRUE;
            return (1);
        }
        dir_stat = readdir(directory);
    }
    closedir(directory);
    return (0);
}

static char *get_path_in_env(const char * const *env)
{
    int i = 0;

    while (env[i]) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return (env[i]);
        i += 1;
    }
    return (NULL);
}

static int get_count_paths(char *path_var)
{
    int count = 1;
    int i = 0;

    if (!path_var)
        return (0);
    while (path_var[i]) {
        if (path_var[i] == ':' && path_var[i + 1])
            count += 1;
        i += 1;
    }
    return (count);
}

static void parse_and_check_path(const char *path_var,
                                const char *to_find,
                                bool_t *found)
{
    int count_paths = get_count_paths(path_var);
    int path_len = 0;
    int pathway_len = 0;
    int count_calls = 0;

    if (path_len <= 0)
        return;
    while (count_calls < count_paths) {
        if (is_in_path(&path_var[path_len], to_find, found) == 1)
            return;
        my_strlen_char(path_var, ':');
        count_calls += 1;
    }
}

bool_t check_cmd_in_path(const char * const *env, const char *to_find)
{
    char *path_var = get_path_in_env(env);
    bool_t found = FALSE;

    if (!path_var)
        return (FALSE);
    parse_and_check_path(&path_var[4], to_find, &found);
    return (found);
}
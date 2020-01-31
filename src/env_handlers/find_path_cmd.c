/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** finds the path where a binary cmd is located
*/

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

static char *get_path_in_env(char **env)
{
    int i = 0;

    if (!env)
        return (NULL);
    while (env[i]) {
        if (!(my_strncmp(env[i], "PATH=", 5)))
            return (&env[i][5]);
        i += 1;
    }
    return (NULL);
}

char *get_correct_pwd(const char *env_path, const char *binary_name)
{
    char *env_path_slash = NULL;
    char *path_dir = NULL;
    char *final_path_dir = NULL;
    int len_envpath = my_strlen(env_path);

    if (len_envpath <= 0)
        return (NULL);
    if (env_path[len_envpath - 1] != '/')
        env_path_slash = my_strdup("/");
    path_dir = my_strcat(env_path, env_path_slash);
    final_path_dir = my_strcat(path_dir, binary_name);
    if (path_dir)
        free(path_dir);
    return (final_path_dir);
}

static void is_in_path(const char *env_path, const char *bin, char **path)
{
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;
    struct stat file;
    char *file_path = NULL;

    directory = opendir(env_path);
    if (!directory)
        return;
    dir_stat = readdir(directory);
    while (dir_stat) {
        file_path = get_correct_pwd(env_path, dir_stat->d_name);
        stat(file_path, &file);
        if (!my_strcmp(dir_stat->d_name, bin, '/')) {
            *path = file_path;
            break;
        }
        free(file_path);
        dir_stat = readdir(directory);
    }
    closedir(directory);
}

static char *check_each_path_var(char *path_var, const char *binary_name)
{
    char **parsed_paths = my_str_to_word_array(path_var, ":", 0);
    char *right_path = NULL;
    int index = 0;

    while (parsed_paths[index]) {
        is_in_path(parsed_paths[index], binary_name, &right_path);
        if (right_path)
            return (right_path);
        index += 1;
    }
    if (!right_path) {
        if (!find_char_in_str(binary_name, '/'))
            return (NULL);
        is_in_dir(&right_path, binary_name);
    }
    return (right_path);
}

char *find_path_cmd(char **env, const char *binary_name)
{
    char *path_var = get_path_in_env(env);

    if (!path_var || !path_var[0]) {
        if (!find_char_in_str(binary_name, '/'))
            return (NULL);
        is_in_dir(&path_var, binary_name);
        return (path_var);
    }
    return (check_each_path_var(path_var, binary_name));
}
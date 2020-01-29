/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes a cmd with correct path, args and env
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

int compute_cmd(char **parsed_input, envg_list_t **envg_list)
{
    char **envg = create_array_from_env_list(*envg_list);
    char *src = NULL;
    int wstatus = 0;
    pid_t pid = 0;

    src = find_path_cmd(envg, parsed_input[0]);
    if (!src) {
        my_printf("%s: Command not found.\n", parsed_input[0]);
        return (1);
    }
    pid = fork();
    if (!pid) {
        if (execve(src, parsed_input, envg) == -1)
            my_printf("%s: Permission denied.\n", parsed_input[0]);
        return (0);
    }
    waitpid(pid, &wstatus, 0);
    free(src);
    return (1);
}
/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** computes a cmd with correct path, args and env
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int compute_cmd(char **parsed_input, char **env)
{
    char *pathway = NULL;
    int wstatus = 0;
    pid_t pid = 0;

    pathway = my_strcat("/bin/", parsed_input[0]);
    pid = fork();
    if (!pid) {
        execve(pathway, parsed_input, env);
        return (0);
    }
    waitpid(pid, &wstatus, 0);
    free(pathway);
    return (1);
}
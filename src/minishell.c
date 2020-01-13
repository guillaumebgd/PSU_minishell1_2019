/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell.c
*/

#include "my.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static char *print_prompt_get_input(void)
{
    my_putstr("$> ");
    return (get_next_line(0, 4096));
}

static int compute_cmd(char **parsed_input, char **env)
{
    char *pathway = NULL;
    int wstatus;
    pid_t pid;

    pathway = my_strcat("/bin/", parsed_input[0]);
    pid = fork();
    if (pid == 0) {
        execve(pathway, parsed_input, env);
        return (0);
    }
    waitpid(pid, &wstatus, 0);
    return (1);
}

void minishell(char **env)
{
    static char **parsed_input = NULL;

    parsed_input = my_str_to_word_array(print_prompt_get_input());
    if (!parsed_input)
        return;
    if (compute_cmd(parsed_input, env) == 0)
        return;
    minishell(env);
}
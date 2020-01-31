/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** computes a cmd with correct path, args and env
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

static int check_error(char **src, const char *cmd)
{
    struct stat file_stat;

    if (!(*src)) {
        my_printf("%s: Command not found.\n", cmd);
        return (1);
    }
    stat(*src, &file_stat);
    if (access(*src, X_OK) != 0 || S_ISDIR(file_stat.st_mode)) {
        my_printf("%s: Permission denied.\n", cmd);
        free(*src);
        return (1);
    }
    return (0);
}

static void child_process_work(char *src, char **parsed_input, char **envg)
{
    if (execve(src, parsed_input, envg) == -1) {
        if (errno == ENOEXEC)
            my_printf("%s: Exec format error. Wrong Architecture.\n",
                        parsed_input[0]);
        else
            my_printf("%s: %s\n", parsed_input[0], strerror(errno));
    }
    kill(getpid(), SIGCHLD);
}

static void check_wstatus_error(const int wstatus)
{
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == SIGFPE)
            my_putstr("Floating exception");
        else if (WTERMSIG(wstatus) == SIGSTOP || WTERMSIG(wstatus) == SIGINT)
            return;
        else
            my_putstr(strsignal(WTERMSIG(wstatus)));
        if (__WCOREDUMP(wstatus))
            my_putstr(" (core dumped)");
        my_putchar('\n');
    }
}

int compute_cmd(char **parsed_input, envg_list_t **envg_list)
{
    char **envg = create_array_from_env_list(*envg_list);
    char *src = NULL;
    int wstatus = 0;
    pid_t pid = 0;

    src = find_path_cmd(envg, parsed_input[0]);
    if (check_error(&src, parsed_input[0]))
        return (1);
    pid = fork();
    if (!pid) {
        child_process_work(src, parsed_input, envg);
        return (0);
    }
    waitpid(pid, &wstatus, 0);
    check_wstatus_error(wstatus);
    if (src)
        free(src);
    return (1);
}
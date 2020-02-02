/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** prints the usage onto the stdout
*/

#include "my.h"

static void print_built_in_details(void)
{
    my_putstr("     Built-in's:\n"
            "\n"
            "     cd 'TARGETED DIRECTORY':\n"
            "         allows you to move between directories.\n"
            "         -> run with '-' to go back to the directory you\n"
            "         previously visited.\n"
            "         -> run with '~' (or no target) to go to your home\n"
            "         directory.\n\n"
            "     env:\n"
            "         shows the current state of your environment.\n\n"
            "     setenv 'VARIABLE' 'VALUE':\n"
            "         sets an environment variable to a certain value.\n\n"
            "     unsetenv 'VAR1' 'VAR2' 'VAR3' ...:\n"
            "         unsets variables from your environment.\n\n"
            "     exit:\n"
            "         exits from the shell.\n");
}

void usage(void)
{
    my_putstr("USAGE\n"
            "     ./mysh\n"
            "DESCRITION\n"
            "     A small instance of a shell containing basic\n"
            "     functionnalities.\n"
            "\n"
            "     Computes commands using the prompt by typing on your\n"
            "     keyboard.\n\n\n");
    print_built_in_details();
}
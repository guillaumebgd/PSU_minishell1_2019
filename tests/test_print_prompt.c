/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the print_prompt function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(print_prompt, basic_prompt_printing)
{
    cr_redirect_stdout();
    print_prompt();
    cr_assert_stdout_eq_str("$ PSU_minishell1_2019 >> ");
}
/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the my_str_to_word_array function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_str_to_word_array, splitter_spaces)
{
    char **result = NULL;

    cr_redirect_stdout();
    result = my_str_to_word_array("ls    -l", " ", 0);
    my_show_arr(result);
    cr_expect_stdout_eq_str("ls\n-l\n");
    my_free_arr(result);
}

Test(my_str_to_word_array, splitter_spaces_tabs)
{
    char **result = NULL;

    cr_redirect_stdout();
    result = my_str_to_word_array("ls \t  \t\t-l\t", " \t", 0);
    my_show_arr(result);
    cr_expect_stdout_eq_str("ls\n-l\n");
    my_free_arr(result);
}
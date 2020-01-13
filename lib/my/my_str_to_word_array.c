/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>

static int get_nb_words(char *sentence)
{
    int nb_words = 0;
    int i = 0;

    while (sentence[i] && sentence[i] == ' ')
        i += 1;
    while (sentence[i]) {
        while (sentence[i] && sentence[i] != ' ')
            i += 1;
        while (sentence[i] && sentence[i] == ' ')
            i += 1;
        nb_words += 1;
    }
    return (nb_words);
}

static char **fill_result(char *sentence, char ***res)
{
    int j = 0;
    int i = 0;

    while (sentence[i] && sentence[i] == ' ')
        i += 1;
    while (sentence[i]) {
        (*res)[j] = my_strdup_char(&sentence[i], ' ');
        while (sentence[i] && sentence[i] != ' ')
            i += 1;
        while (sentence[i] && sentence[i] == ' ')
            i += 1;
        j += 1;
    }
    return (*res);
}

char **my_str_to_word_array(char *sentence)
{
    char **res = NULL;
    int nb_words = 0;

    if (sentence == NULL)
        return (NULL);
    nb_words = get_nb_words(sentence);
    if (nb_words == 0)
        return (NULL);
    res = malloc(sizeof(char *) * nb_words);
    if (!res)
        return (NULL);
    return (fill_result(sentence, &res));
}
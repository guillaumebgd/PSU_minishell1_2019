/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** converts a string into an array from its words
*/

#include <stdlib.h>
#include "my.h"

static int get_nb_words(const char *sentence, const char splitter)
{
    int nb_words = 0;
    int i = 0;

    while (sentence[i] && sentence[i] == splitter)
        i += 1;
    while (sentence[i]) {
        while (sentence[i] && sentence[i] != splitter)
            i += 1;
        while (sentence[i] && sentence[i] == splitter)
            i += 1;
        nb_words += 1;
    }
    return (nb_words);
}

static char **fill_result(char *sentence, const char splitter, char **res,
                            const int freer)
{
    int i = 0;
    int j = 0;

    while (sentence[i] && sentence[i] == splitter)
        i += 1;
    while (sentence[i]) {
        res[j] = my_strdup_char(&sentence[i], splitter);
        while (sentence[i] && sentence[i] != splitter)
            i += 1;
        while (sentence[i] && sentence[i] == splitter)
            i += 1;
        j += 1;
    }
    if (sentence && freer)
        free(sentence);
    return (res);
}

char **my_str_to_word_array(char *sentence, const char splitter,
                                const int freer)
{
    char **res = NULL;
    int nb_words = 0;

    if (!sentence)
        return (NULL);
    nb_words = get_nb_words(sentence, splitter);
    if (nb_words == 0)
        return (NULL);
    res = malloc(sizeof(char *) * (nb_words + 1));
    if (!res)
        return (NULL);
    res[nb_words] = NULL;
    return (fill_result(sentence, splitter, res, freer));
}
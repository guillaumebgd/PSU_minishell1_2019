/*
** EPITECH PROJECT, 2019
** library
** File description:
** my.h
*/

#ifndef MY_H_

#define MY_H_

int my_putchar(const char);
int my_getnbr(char const *);
void my_put_nbr(int, char const *, unsigned int);
int my_strlen(char const *);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, const unsigned int);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
char *get_next_line(const int, int);
int my_strlen_char(const char *, const char);
char *my_strdup_char(const char *, const char);
char **my_str_to_word_array(char *);

#endif /* MY_H_ */
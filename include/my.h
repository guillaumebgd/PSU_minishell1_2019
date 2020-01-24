/*
** EPITECH PROJECT, 2019
** library
** File description:
** header for libmy
*/

#ifndef MY_H_

#define MY_H_

//returns NULL if there's nothing (left) to read.
char *get_next_line(const int fd, const int read_size);

//0 if everything is written, 84 otherwise.
int my_putchar(const char c);
int my_putstr(const char *str);

//0 if there's an issue.
int my_getnbr(const char *str);
//doesn't write if there's an error.
void my_put_nbr(int nb, const char *base);

//-1 if there's an error, positive integer otherwise.
int my_strlen(const char *str);
//computes with a limit of itterations.
int my_strnlen(const char *str, const int n);
//computes with a limit set by a certain char c.
int my_strlen_char(const char *str, const char c);

//-1 if there's an error, positive integer otherwise.
int my_arrlen(char **array);
//frees an array.
void my_free_arr(char **array);

//returns NULL if there's an issue or if template if NULL.
char *my_strdup(const char *template);
//computes with a limit of itterations.
char *my_strndup(const char *template, int n);
//computes with a limit set by a certain char c.
char *my_strdup_char(const char *template, const char c);

//returns comparing first and second Negative Integer if first < second,
//0 if first = second, Positive Interger if first > second.
int my_strcmp(const char *first, const char *second);
//computes with a limit of itterations.
int my_strncmp(const char *first, char const *second, const unsigned int n);

//returns NULL if there's an issue.
char *my_strcat(const char *core, const char *to_append);

//returns NULL if there's an issue.
char **my_str_to_word_array(char *sentence, const char splitter,
                                const int freer);

int find_char_in_str(const char *str, const char c);

#endif /* MY_H_ */
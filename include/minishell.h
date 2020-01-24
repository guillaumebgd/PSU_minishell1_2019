/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2020
** File description:
** header for the minishell1 project
*/

#ifndef MINISHELL_H_

#define MINISHELL_H_

typedef enum bool_e {
    FALSE,
    TRUE
} bool_t;

//oversees the program proccess
void minishell(char **env);

//prints the prompt and get the input given by the user
char *print_prompt_get_input(void);

//checks if the given command can be found in folders listed in path
char *find_path_cmd(char **env, const char *binary_name);

//computes the command found in path
int compute_cmd(char **parsed_input, char **env);
//
char *get_correct_pwd(const char *env_path, const char *binary_name);
//
void is_in_curdir(char **right_path, const char *bin);

// Built-in's
//exits from the mysh program
void my_exit(void);

#endif /* MINISHELL_H_ */
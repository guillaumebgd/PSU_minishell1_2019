/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** header for the minishell1 project
*/

#ifndef MINISHELL_H_

#define MINISHELL_H_

typedef enum bool_e {
    FALSE,
    TRUE
} bool_t;

typedef struct envg_list_s {
    char *var_name;
    char *var_value;
    struct envg_list_s *next;
} envg_list_t;

//oversees the program processes
void setup_minishell(const char * const *env);
//minishell loop
void minishell(envg_list_t **envg_list);

//prints the prompt and get the input given by the user
void print_prompt(void);

//checks if the given command can be found in folders listed in path
char *find_path_cmd(char **env, const char *binary_name);

//computes the command found in path
int compute_cmd(char **parsed_input, envg_list_t **envg_list);
//tries to find if a binary is located in path given into the PATH variable
char *get_correct_pwd(const char *env_path, const char *binary_name);
//fills the right_path buffer if a binary is found in the current directory.
void is_in_dir(char **right_path, const char *bin);

//creates the env list from a given char **
void create_env_list_from_array(envg_list_t **envg_list,
                                const char * const *env);
//creates a char ** corresponding to an env from the env list.
char **create_array_from_env_list(envg_list_t *envg_list);
//gets the size of the env list.
int env_list_size(const envg_list_t *env_list);
//shows the environment.
void show_env(envg_list_t **envg_list);
//frees the allocated memory for the env list.
void free_env_list(envg_list_t **head);

// Built-in's

//exits from the mysh program.
void my_exit(void);

#endif /* MINISHELL_H_ */
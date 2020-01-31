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
    struct envg_list_s *prev;
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
int env_list_size(envg_list_t *head);
//shows the environment.
void show_env(envg_list_t **envg_list);
//adds a new variable to the environment.
void add_new_env_var(envg_list_t **envg_list, const char *var_name,
                    const char *var_value);
//destroys a node targeted by unsetenv.
int destroy_env_var(envg_list_t **envg_list, const char *var_name);
//frees a node from the env list.
void free_node(envg_list_t *tmp);
//frees the allocated memory for the env list.
void free_env_list(envg_list_t **head);

// Built-in's

//computes a built-in
int compute_built_in(envg_list_t **envg_list, char **parsed_input);
//returns a pointer to a variable in env list.
envg_list_t *is_var_in_env(envg_list_t **head, const char *var_name);
//allows to change working directory.
void my_cd(envg_list_t **head, char **parsed_input);
//exits from the mysh program.
int my_exit(char **parsed_input);
//shows the current state of the env.
void my_env(envg_list_t **envg_list);
//sets a variable into the env list with a value.
void my_setenv(envg_list_t **head, char **parsed_input);
//removes variables from env.
void my_unsetenv(envg_list_t **head, char **parsed_input);

#endif /* MINISHELL_H_ */
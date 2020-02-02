/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** header for the first minishell project
*/

#ifndef MINISHELL_H_

#define MINISHELL_H_

//Boolean enum.

typedef enum bool_e {
    FALSE,
    TRUE
} bool_t;

//Enum for the compute_built_in function redirection.

typedef enum built_ins_e {
    NO_MATCH = -1,
    MY_EXIT,
    MY_CD,
    MY_ENV,
    MY_SETENV,
    MY_UNSETENV
} built_ins_t;

//One node of the env_list.

typedef struct envg_list_s {
    char *var_name;
    char *var_value;
    struct envg_list_s *next;
    struct envg_list_s *prev;
} envg_list_t;



/*
** ******************************************
** | Special cases from the given arguments |
** ******************************************
*/

//Prints the usage of the shell.
void usage(void);



/*
**  ***************************
**  | Main loop and instances |
**  ***************************
*/

//Creates the envg_list from the given env then call the minishell function.
void setup_minishell(const char * const *env);

//Computes the sequences from the asked input with the prompt interface to
//the execution of a built-in or binary file.
void minishell(envg_list_t **envg_list, bool_t success);



/*
** **********************
** | Prompt Information |
** **********************
*/

//Returns a string containing the current directory where the user is.
//
//Returns NULL if an error occured.
char *get_current_pwd(void);

//Prints the shell prompt onto the stdout.
void print_prompt(const bool_t success);



/*
** ****************
** | Command side |
** ****************
*/

//Returns a string with the path of a binary if it has been found in the
//PATH variable values.
//
//Returns NULL if it fails.
char *find_path_cmd(char **env, const char *binary_name);

//Computes a command if it manages to find its binary file.
//
//Returns 1 if the prompt needs to be called back.
//Returns 0 if the function terminates from the child process.
//
//Writes the corresponding error if a signal is sent from the child process.
int compute_cmd(char **parsed_input, envg_list_t **envg_list, bool_t *success);

//Computes the boundary between a value of the PATH variable
//and the binary name.
//
//   Example:
//
//         env_path = "/bin/"
//         binary_name = "ls"
//         Returns: "/bin/ls"
//
//Returns NULL if env_path is NULL.
char *get_correct_pwd(const char *env_path, const char *binary_name);

//Fills the (*right_path) string if the given binary is given
//with a '/' in it, looks for it in the given path.
//
//Doesn't change anything to the pointer if the conditions
//aren't filled.
void is_in_dir(char **right_path, const char *bin);



/*
** ************************
** | Environment handling |
** ************************
*/

//Sets up an doubly linked env list from an array.
//A 'NULL terminated' array is mandatory.
//
//   Example:
//
//         given: {"HOME=/home/", NULL};
//         results in:
//              One node with a variable HOME and its
//              value set as "/home/".
//
//The head pointer will point towards NULL if the given
//array is NULL.
void create_env_list_from_array(envg_list_t **envg_list,
                                const char * const *env);

//Sets up an array from a given doubly linked env list.
//The returned array is NULL terminated.
//
//Returns NULL if the given head pointer points towards NULL.
char **create_array_from_env_list(envg_list_t *envg_list);

//Returns the number of nodes of an env list.
//
//Returns 0 if the list is NULL.
int env_list_size(envg_list_t *head);

//Prints the list as a usual environment onto the stdout.
void show_env(envg_list_t **envg_list);

//Adds a variable, discarding its already possible presence in the env list,
//to the env list.
void add_new_env_var(envg_list_t **envg_list, const char *var_name,
                    const char *var_value);

//Destroys an env_list node corresponding to the var_name.
//Readjusts pointers accordingly.
//
//Doesn't do anything if the variable doesn't exist in the env list.
int destroy_env_var(envg_list_t **envg_list, const char *var_name);

//Frees memory of a node from the env list.
//
//If the given pointer is NULL, doesn't access uninitialized values
//inside of the node.
void free_node(envg_list_t *tmp);

//Frees the allocated memory for the env list.
void free_env_list(envg_list_t **head);



/*
** **************
** | Built-in's |
** **************
*/

//Redirects, whether the user input matches to them, towards the correct
//built-in function.
int compute_built_in(envg_list_t **envg_list, char **parsed_input,
                    bool_t *success);

//Returns a pointer to the given variable inside of the env_list.
//
//Returns NULL if it hasn't been found.
envg_list_t *is_var_in_env(envg_list_t **head, const char *var_name);

//Changes working directory depending of the given arguments.
//Prints the corresponding error if an error occurs.
//
//Sets the OLDPWD and PWD variables in the environment.
void my_cd(envg_list_t **head, char **parsed_input, bool_t *success);

//Returns 1 and prints "exit\n" if a single argument is given or
//returns 0 and prints "exit: Expression Syntax.\n".
int my_exit(char **parsed_input, bool_t *success);

//Shows the current state of the environment.
void my_env(envg_list_t **envg_list);

//Whether a variable already exists or not, creates it and sets it the
//given value or changes the previous value to the newly attributed one.
void my_setenv(envg_list_t **head, char **parsed_input, bool_t *success);

//Removes one, or multiple, variables from the environment.
void my_unsetenv(envg_list_t **head, char **parsed_input, bool_t *success);

#endif /* MINISHELL_H_ */
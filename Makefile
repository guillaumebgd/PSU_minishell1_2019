##
## EPITECH PROJECT, 2019
## Makefile minishell_1
## File description:
## compiles c files with libs into the minishell1 program
##

SRC	=	src/minishell.c							\
		src/input/compute_cmd.c					\
		src/input/prompt.c						\
		src/built_in/compute_built_in.c			\
		src/built_in/my_cd.c					\
		src/built_in/my_env.c					\
		src/built_in/my_setenv.c				\
		src/built_in/my_unsetenv.c				\
		src/built_in/my_exit.c					\
		src/env/find_path_cmd.c					\
		src/env/is_in_dir.c						\
		src/env/create_env_list_from_array.c	\
		src/env/create_array_from_env_list.c	\
		src/env/add_new_env_var.c				\
		src/env/destroy_env_var.c				\
		src/env/show_env.c						\
		src/env/env_list_size.c					\
		src/env/free_env_list.c

MAIN	=	main.c

VPATH	=	/usr/local/lib/

NAME	=	mysh

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS	=	-L./lib/

LDLIBS	=	-lmy

LDLIBTEST	=	-lmy -lcriterion

all:	$(NAME)

$(NAME):
	$(MAKE) -sC lib/my
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	$(MAKE) -sC lib/my
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(MAKE) -sC lib/my
	$(CC) -o $@ $(SRC) tests/*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBTEST) --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(NAME)
	$(RM) debug
	$(RM) tests_run
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*

fclean:	clean
	$(MAKE) fclean -sC lib/my

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re
##
## EPITECH PROJECT, 2019
## Makefile minishell_1
## File description:
## compiles c files with libs into the minishell1 program
##

SRC	=	src/minishell.c									\
		src/input_handlers/compute_cmd.c				\
		src/input_handlers/prompt.c						\
		src/built_ins/compute_built_in.c				\
		src/built_ins/my_cd.c							\
		src/built_ins/my_env.c							\
		src/built_ins/my_setenv.c						\
		src/built_ins/my_unsetenv.c						\
		src/built_ins/my_exit.c							\
		src/env_handlers/find_path_cmd.c				\
		src/env_handlers/is_in_dir.c					\
		src/env_handlers/create_env_list_from_array.c	\
		src/env_handlers/create_array_from_env_list.c	\
		src/env_handlers/add_new_env_var.c				\
		src/env_handlers/destroy_env_var.c				\
		src/env_handlers/show_env.c						\
		src/env_handlers/env_list_size.c				\
		src/env_handlers/free_env_list.c

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
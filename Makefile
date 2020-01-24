##
## EPITECH PROJECT, 2020
## Makefile minishell_1
## File description:
## compiles c files with libs into the minishell1 program
##

SRC	=	src/minishell.c				\
		src/input/compute_cmd.c		\
		src/input/prompt.c			\
		src/env/find_path_cmd.c		\

MAIN	=	main.c

VPATH	=	/usr/local/lib/

NAME	=	mysh

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS	=	-L./lib/my

LDLIBS	=	-lmy

LDLIBTEST	=	-lmy -lcriterion

all:	$(NAME)

$(NAME):
	$(MAKE) -C lib/my
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	$(MAKE) -C lib/my
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(MAKE) -C lib/my
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
	$(RM) lib/my/*.a
	$(RM) lib/my/*.o

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re
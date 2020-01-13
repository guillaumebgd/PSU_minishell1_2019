##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## makefile for lib
##

SRC	=	./my_getnbr.c				\
		./my_putchar.c				\
		./my_put_nbr.c				\
		./my_putstr.c				\
		./my_strlen.c				\
		./my_strcmp.c				\
		./my_strncmp.c				\
		./my_strdup.c				\
		./my_strcat.c				\
		./get_next_line.c			\
		./my_strlen_char.c			\
		./my_strdup_char.c			\
		./my_str_to_word_array.c	\

CFLAGS	=	-Wall -Wextra -I./../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

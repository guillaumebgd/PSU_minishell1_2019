##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## proccess compilation for this lib
##

SRC	=	./get_next_line.c			\
		./my_putchar.c				\
		./my_strlen.c				\
		./my_strnlen.c				\
		./my_strlen_char.c			\
		./my_getnbr.c				\
		./my_put_nbr.c				\
		./my_putstr.c				\
		./my_strcmp.c				\
		./my_strncmp.c				\
		./my_strdup.c				\
		./my_strndup.c				\
		./my_strdup_char.c			\
		./my_strcat.c				\
		./my_str_to_word_array.c

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./../../include/

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

.NOTPARALLEL:
.PHONY: all clean fclean re
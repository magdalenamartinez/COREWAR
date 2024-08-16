##
## EPITECH PROJECT, 2022
## lib/my/Makefile
## File description:
## funcion which
##

SRC = *.c	\

NAME = libmy.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

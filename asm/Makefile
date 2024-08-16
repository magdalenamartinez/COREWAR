##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##


NAME	=	asm

LIB	=	-L ../lib/my/ -lmy

INCLUDE	=	-I ./../include/

SRC	= 	src/main.c	\
		src/header.c	\
		src/op.c	\
		src/ind.c	\
		src/save.c	\
		src/initialise.c	\
		src/study_line.c	\
		src/file.c	\
		src/save_file.c	\
		src/etiquette.c	\
		src/lines.c	\
		src/operations.c	\
		src/write.c	\
		src/type_args.c	\
		src/dir.c	\
		src/reg.c	\
		src/label.c	\

OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJ)
	gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)

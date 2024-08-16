##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	corewar

LIB	=	-L ../lib/my/ -lmy

INCLUDE	=	-I ./../include/

SRC	= 	src/main.c	\
		src/initialise.c	\
		src/arguments.c	\
		src/parameters.c	\
		src/program.c	\
		src/write_mem.c	\
		src/check_dir.c	\
		src/check.c	\
		src/remove.c	\
		src/file.c	\
		src/id.c	\
		src/loop.c	\
		src/lldi.c	\
		src/live.c	\
		src/get_bytes.c	\
		src/load.c	\
		src/st.c	\
		src/logic.c	\
		src/fork.c	\
		src/add.c	\
		src/zjmp.c	\
		src/or.c	\
		src/xor.c	\
		src/instructions.c	\
		../asm/src/op.c	\

OBJ	=	$(SRC:.c=.o)

BINDIR = ../

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

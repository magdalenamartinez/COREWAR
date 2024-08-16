##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## d
##

NAME	=	make

CC		=	gcc

CPPFLAGS	=	-I include

LIB	=	-L lib/my/ -lmy

INCLUDE	=	-I ./include/

all: $(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		make -C ./asm
		make -C ./corewar
clean:
	make -C ./lib/my fclean
	rm -f libmy.a
	make -C ./asm fclean
	make -C ./corewar fclean

fclean: clean
	rm -f libmy.a
	rm -f lib/my/libmy.a
	rm -f ./lib/my/*.o

re: fclean all

exec:
	re
	./$(NAME)

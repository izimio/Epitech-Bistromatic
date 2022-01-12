##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Bistro's Makefile
##

SRC	=	sources/bistro_main.c	\
		sources/error_handling/check_expr.c	\
		sources/error_handling/check_two_identical_char.c	\
		sources/error_handling/general_error_handling.c	\
		sources/error_handling/check_operators.c	\
		sources/convert_base.c	\
		sources/convert_base_custom.c	\
		sources/eval/evalexpr.c	\
		sources/eval/evaluator.c	\
		sources/eval/parenthesis.c	\
		sources/calculation/addition.c	\
		sources/calculation/substraction.c	\
		sources/calculation/multiplication.c	\
		sources/calculation/divmod.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/eval
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -leval

clean:
	make clean -C lib/my
	make clean -C lib/eval
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/my
	make fclean -C lib/eval
	rm -f $(NAME)

re: fclean all

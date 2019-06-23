##
## EPITECH PROJECT, 2019
## Makefile minishell1
## File description:
## Makefile
##

SRC_DIR	=	src/
PRINT	=	print/
TESTS_DIR	=	test/

NAME	=	navy

SRC	=	$(SRC_DIR)/my_strlen.c	\
		$(SRC_DIR)/boat_map.c	\
		$(SRC_DIR)/file_check.c	\
		$(SRC_DIR)/mallocation.c	\
		$(SRC_DIR)/print_map.c	\
		$(SRC_DIR)/my_getnbr.c	\
		$(SRC_DIR)/test.c	\
		$(SRC_DIR)/game.c	\
		$(SRC_DIR)/signal_game.c	\
		$(SRC_DIR)/defense.c	\
		$(SRC_DIR)/my_atoi.c	\
		$(SRC_DIR)/missed.c	\
		$(PRINT)/functions.c	\
		$(PRINT)/functions2.c	\
		$(PRINT)/functions3.c	\
		$(PRINT)/my_printf.c	\
		$(PRINT)/my_put_nbr_unsigned.c	\
		$(PRINT)/my_put_nbr.c	\
		$(PRINT)/my_putchar.c	\
		$(PRINT)/my_putstr.c	\
		$(PRINT)/my_strcpy.c	\

CFLAGS	=	-I ./include -Wall -Wextra

SRCS	=	$(SRC) $(SRC_DIR)main.c

SRC_TESTS	=	$(TESTS_DIR)test_navy.c	\

TESTS_SRC	=	$(SRC)$(SRC_TESTS)

OBJ	=	$(SRCS:.c=.o)

OBJ_TESTS	=	$(TESTS_SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

#make clean rule
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TESTS)

#make fclean rule
fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

#make re rule
re:	fclean all

#make tests run criterion
tests_run:	$(OBJ_TESTS)
	$(CC) -o unit_tests $(OBJ_TESTS) -lcriterion

.PHONY:	all clean fclean re
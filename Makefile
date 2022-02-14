NAME = push_swap

SRC =	./src/main.c\
	./src/check_args.c\
	./src/check_args2.c\
	./src/create_piles.c\
	./src/push_piles.c\
	./src/swap_piles.c\
	./src/reverse_piles.c\
	./src/rotate_piles.c\
	./src/algo.c\
	./src/algo_quick.c\
	./src/median.c\
	./src/search_first.c\
	./src/algo2.c\
	./src/algo_low.c

LIB_PATH = libft/

CC = @clang

CFLAGS = -g -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

%.o:%.c push_swap.h
	@$(CC) -o $@ -c $< $(CFLAGS)

all: subsystem $(NAME)

subsystem:
	@cd $(LIB_PATH) && make all

$(NAME): begin $(OBJ)
	@$(CC) $(OBJ) $(LIB_PATH)libft.a -o $(NAME)
	@echo "\033[106;32mcompilation de push_swap terminées\033[0m"	

clean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(OBJ)
	@echo "\033[101;30msuppression des fichier *.o de push_swap\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[101;30msuppression de l'executable push_spawp\033[0m"

re: fclean all

begin:
	@echo "\033[106;35mdebut de la compilation de push_swap\033[0m"

.PHONY: all clean fclean re

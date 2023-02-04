NAME = push_swap

SRC = ps.c push_swap.c stack_functions.c free_stuff.c index_set.c parsing.c algorithm.c holder_functions.c

LIBFT = libft/libft.a

FLAGS=-Wall -Wextra -Werror -fsanitize=address

TEST = test.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cc $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft
	@make bonus -C ./libft

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME) a.out
	@make fclean -C ./libft

re: fclean all 

.PHONY: all clean fclean re
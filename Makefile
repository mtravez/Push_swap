NAME = push_swap

SRC = ps.c push_swap.c stack_functions.c free_stuff.c index_set.c parsing.c algorithm.c holder_functions.c

BONUS = checker

BONUS_SRC = bonus/instructions.c bonus/checker.c bonus/double_function.c

LIBFT = libft/libft.a

FLAGS=-Wall -Wextra -Werror -fsanitize=address

TEST = test.c

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cc $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft
	@make bonus -C ./libft

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ_BONUS)
	@make clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME) $(BONUS)
	@make fclean -C ./libft

re: fclean all 

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(OBJ_BONUS)
	cc $(BONUS_SRC) $(LIBFT) ps.c stack_functions.c parsing.c free_stuff.c holder_functions.c index_set.c -o $(BONUS)

.PHONY: all clean fclean re
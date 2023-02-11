NAME = push_swap

SRC = src/ps.c src/push_swap.c src/stack_functions.c src/free_stuff.c \
	src/index_set.c src/parsing.c src/algorithm.c src/holder_functions.c src/swap_functions.c src/short_algo.c

BONUS = checker

BONUS_SRC = bonus/instructions.c bonus/checker.c bonus/double_function.c

LIBFT = libft/libft.a

FLAGS=-Wall -Wextra -Werror

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cc $(SRC) $(LIBFT) $(FLAGS) -o $(NAME)

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
	@cc $(BONUS_SRC) $(LIBFT) $(FLAGS) src/ps.c src/stack_functions.c src/parsing.c src/free_stuff.c \
	src/holder_functions.c src/index_set.c -o $(BONUS)

.PHONY: all clean fclean re
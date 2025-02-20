SRC = check_nd_join.c sort_stack.c handle_nd_convert.c push_swap.c sorting.c sort_small_ones.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
CC = cc
NAME = push_swap
LIBFT = ./libft/libft.a

all: $(NAME)	

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

.PHONY: re clean fclean


SRC = check_nd_join.c first_sort_stack.c second_sort_stack.c \
	handle_nd_convert.c push_swap.c sorting.c sort_small_ones.c
BSRC = checker.c get_next_line_bonus.c check_nd_join_bonus.c \
	handle_nd_convert_bonus.c check_helper_bonus.c instructions_one_bonus.c \
	instructions_three_bonus.c instructions_two_bonus.c read_nd_check_bonus.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I ./includes/ -g3
CC = cc
NAME = push_swap
CHECK= checker
LIBFT = libft.a

all: $(NAME)	

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./libft -lft -o $(NAME)

$(LIBFT):
	make -C libft bonus

bonus: $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -L./libft -lft -o $(CHECK)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

re: fclean all

clean:
	make -C libft clean
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME) $(CHECK)

.PHONY: re clean fclean 
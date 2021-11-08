CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = ft_atoi.c	\
	  ft_chunk.c	\
	  ft_error.c	\
	  ft_five.c	\
	  ft_four.c	\
	  ft_is_int.c	\
	  ft_list.c	\
	  ft_list_str.c	\
	  ft_list_utils.c	\
	  ft_push.c	\
	  ft_push_swap.c	\
	  ft_reverse_rotate.c	\
	  ft_rotate.c	\
	  ft_small.c	\
	  ft_smart_rotate_a.c	\
	  ft_smart_rotate_b.c	\
	  ft_smart_set_a.c	\
	  ft_sort.c	\
	  ft_str.c	\
	  ft_swap.c	\
	  ft_three.c	\
	  main.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) -g3 $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

flemme: re
	make clean

.PHONY: clean fclean all re

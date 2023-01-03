NAME = push_swap
BONUS_NAME = checker
CC=gcc
CFLAGS = -Wall -Wextra -Werror
SRC = arr_utils.c ft_atoi.c max_number.c push_operations.c get_next_line_utils_bonus.c \
		push_swap.c rotate_operations.c reverse_rotate.c pu-shsw-ap.c ft_split.c sort_smallnbr.c\
		sort_list.c sort_min_number.c sort_utils.c  swap_operations.c

SRCB = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_atoi_bonus.c error_bonus.c\
	  pu-shsw-ap.c swap_operations.c push_operations.c rotate_operations.c reverse_rotate.c check_list_bonus.c ft_split.c
	  
SRCS = ${SRC:.c=.o}
SRCBS = ${SRCB:.c=.o}

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME):$(SRCBS)
	$(CC) $(CFLAGS) $(SRCBS) -o $(BONUS_NAME)

clean:
	rm -f $(SRCS) $(SRCBS)
fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
re: fclean all
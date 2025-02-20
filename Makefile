CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECK = checker

SRC = check_function.c ft_algor_sorting.c ft_parse.c ft_push.c ft_reverse_rotate.c ft_rotate.c \
	ft_sort_array.c ft_sort_small_numbers.c ft_splite.c ft_swap.c utils_function_a.c utils_function_b.c

SRC_BNS = ./checker_bonus/check_function_bonus.c ./checker_bonus/ft_parse_bonus.c ./checker_bonus/ft_push_bonus.c \
	./checker_bonus/ft_reverse_rotate_bonus.c ./checker_bonus/ft_rotate_bonus.c ./checker_bonus/ft_splite_bonus.c \
	./checker_bonus/ft_swap_bonus.c ./checker_bonus/utils_function_a_bonus.c ./checker_bonus/utils_function_b_bonus.c \
	./checker_bonus/get_next_line_utils.c ./checker_bonus/get_next_line.c \

OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	${CC} ${CFLAGS} $(OBJ) -o ${NAME}

bonus: ${CHECK}

${CHECK}: $(OBJ_BNS)
	${CC} ${CFLAGS} $(OBJ_BNS) -o ${CHECK}

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) ${CHECK}

re: fclean all
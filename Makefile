NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I include

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= main.c \
			  bench/print_bench.c \
			  parser/parse_args.c \
			  parser/parse_number.c \
			  parser/validate.c \
			  sort/adaptive.c \
			  sort/complex.c \
			  sort/disorder.c \
			  sort/medium.c \
			  sort/normalize.c \
			  sort/simple.c \
			  stack/op_push.c \
			  stack/op_rev_rotate.c \
			  stack/op_rotate.c \
			  stack/op_buffer.c \
			  stack/op_swap.c \
			  stack/operation.c \
			  stack/stack_init.c \
			  stack/stack_utils.c \
			  utils/error.c \
			  utils/ft_split.c \
			  utils/ft_strcmp.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

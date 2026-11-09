NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I include

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= main.c \
			  bench/print_bench.c \
			  context/context.c \
			  parser/duplicate_check.c \
			  parser/parse_args.c \
			  parser/parse_number.c \
			  stack/stack_lifecycle.c \
			  stack/stack_push.c \
			  stack/stack_query.c \
			  stack/stack_rev_rotate.c \
			  stack/stack_rotate.c \
			  stack/stack_swap.c \
			  ops/op_apply.c \
			  ops/op_buffer.c \
			  ops/op_buffer_flush.c \
			  ops/op_execute.c \
			  sort/adaptive.c \
			  sort/complex.c \
			  sort/disorder.c \
			  sort/dispatch.c \
			  sort/medium.c \
			  sort/normalize.c \
			  sort/simple.c \
			  sort/sort_utils.c \
			  utils/error.c \
			  utils/ft_putsize.c \
			  utils/ft_putstr.c \
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

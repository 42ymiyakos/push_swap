#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define OPS_INIT_CAP 256

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}	t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_context
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	double		disorder;
	size_t		counts[OP_COUNT];
	int			bench;
	t_op		*ops;
	size_t		ops_len;
	size_t		ops_cap;
}	t_context;

/* context */
void	ctx_init(t_context *ctx);

/* parser */
void	parse_args(int argc, char **argv, t_context *ctx);
int		parse_number(const char *s, int *out);
int		has_duplicate(const t_stack *a);

/* sort */
double	disorder_compute(const t_stack *a);

/* stack */
t_node	*node_new(int value);
void	stack_init(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
void	stack_append(t_stack *stack, t_node *node);
void	stack_clear(t_stack *stack);
int		op_buffer_add(t_context *ctx, t_op op);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *dst, t_stack *src);
void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);
int		apply_op(t_op op, t_stack *a, t_stack *b);
void	execute_op(t_context *ctx, t_op op);
void	op_buffer_flush(t_context *ctx);

/* bench */

/* utils */
void	context_clear(t_context *ctx);
void	error_exit(t_context *ctx);
char	**ft_split(char const *s, char c);
void	free_split(char **ss);
int		ft_strcmp(const char *s1, const char *s2);

#endif

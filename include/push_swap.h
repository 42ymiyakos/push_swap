#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

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

/* parser */

/* sort */

/* stack */
void	free_stack(t_stack *stack);
int		op_buffer_add(t_context *ctx, t_op op);
void	op_buffer_optimize(t_context *ctx);
void	op_buffer_flush(t_context *ctx);

/* bench */

/* utils */
void	free_context(t_context *ctx);
void	error_exit(t_context *ctx);
char	**ft_split(char const *s, char c);

#endif

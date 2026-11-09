/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:59:53 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 02:20:06 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define OPS_INIT_CAP 256
# define DISORDER_LOW 0.2
# define DISORDER_HIGH 0.5

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

typedef struct s_rotation
{
	t_op	op;
	size_t	count;
	int		possible;
}	t_rotation;

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
void	ctx_clear(t_context *ctx);

/* parser */
void	parse_args(int argc, char **argv, t_context *ctx);
int		parse_number(const char *s, int *out);
int		stack_has_duplicate(const t_stack *stack);

/* stack */
t_node	*node_new(int value);
void	stack_init(t_stack *stack);
void	stack_append(t_stack *stack, t_node *node);
void	stack_clear(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_push(t_stack *dst, t_stack *src);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);
int		stack_is_sorted(const t_stack *stack);
size_t	stack_min_pos(const t_stack *stack);
size_t	stack_max_pos(const t_stack *stack);

/* ops */
int		op_apply(t_op op, t_stack *a, t_stack *b);
void	op_execute(t_context *ctx, t_op op);
int		op_buffer_add(t_context *ctx, t_op op);
void	op_buffer_flush(t_context *ctx);

/* sort */
void	sort_dispatch(t_context *ctx);
void	sort_adaptive(t_context *ctx);
void	sort_simple(t_context *ctx);
void	sort_medium(t_context *ctx);
void	sort_complex(t_context *ctx);
double	disorder_compute(const t_stack *stack);
void	stack_normalize(t_context *ctx);
void	stack_move_to_top(t_context *ctx, t_stack *stack, size_t pos);

/* bench */

/* utils */
void	error_exit(t_context *ctx);
char	**ft_split(char const *s, char c);
void	split_free(char **ss);
int		ft_strcmp(const char *s1, const char *s2);

#endif

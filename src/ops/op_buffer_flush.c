/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_buffer_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:46:57 by arendo            #+#    #+#             */
/*   Updated: 2026/11/06 16:07:46 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_print(t_op op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}

static void	push_print(t_op op)
{
	if (op == PA)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

static void	rotate_print(t_op op)
{
	if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}

static void	rev_rotate_print(t_op op)
{
	if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void	op_buffer_flush(t_context *ctx)
{
	size_t	i;

	if (!ctx)
		return ;
	i = 0;
	while (i < ctx->ops_len)
	{
		if (ctx->ops[i] <= SS)
			swap_print(ctx->ops[i]);
		else if (ctx->ops[i] <= PB)
			push_print(ctx->ops[i]);
		else if (ctx->ops[i] <= RR)
			rotate_print(ctx->ops[i]);
		else
			rev_rotate_print(ctx->ops[i]);
		ctx->counts[ctx->ops[i]]++;
		i++;
	}
}

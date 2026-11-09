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

static void	swap_print(t_context *ctx, t_op op)
{
	if (op == SA)
		ft_putstr_fd(ctx, "sa\n", 1);
	else if (op == SB)
		ft_putstr_fd(ctx, "sb\n", 1);
	else
		ft_putstr_fd(ctx, "ss\n", 1);
}

static void	push_print(t_context *ctx, t_op op)
{
	if (op == PA)
		ft_putstr_fd(ctx, "pa\n", 1);
	else
		ft_putstr_fd(ctx, "pb\n", 1);
}

static void	rotate_print(t_context *ctx, t_op op)
{
	if (op == RA)
		ft_putstr_fd(ctx, "ra\n", 1);
	else if (op == RB)
		ft_putstr_fd(ctx, "rb\n", 1);
	else
		ft_putstr_fd(ctx, "rr\n", 1);
}

static void	rev_rotate_print(t_context *ctx, t_op op)
{
	if (op == RRA)
		ft_putstr_fd(ctx, "rra\n", 1);
	else if (op == RRB)
		ft_putstr_fd(ctx, "rrb\n", 1);
	else
		ft_putstr_fd(ctx, "rrr\n", 1);
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
			swap_print(ctx, ctx->ops[i]);
		else if (ctx->ops[i] <= PB)
			push_print(ctx, ctx->ops[i]);
		else if (ctx->ops[i] <= RR)
			rotate_print(ctx, ctx->ops[i]);
		else
			rev_rotate_print(ctx, ctx->ops[i]);
		i++;
	}
}

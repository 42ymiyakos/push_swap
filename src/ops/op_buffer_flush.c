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
		ft_putstr_fd("sa\n", 1);
	else if (op == SB)
		ft_putstr_fd("sb\n", 1);
	else
		ft_putstr_fd("ss\n", 1);
}

static void	push_print(t_op op)
{
	if (op == PA)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

static void	rotate_print(t_op op)
{
	if (op == RA)
		ft_putstr_fd("ra\n", 1);
	else if (op == RB)
		ft_putstr_fd("rb\n", 1);
	else
		ft_putstr_fd("rr\n", 1);
}

static void	rev_rotate_print(t_op op)
{
	if (op == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (op == RRB)
		ft_putstr_fd("rrb\n", 1);
	else
		ft_putstr_fd("rrr\n", 1);
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
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:00:44 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/15 11:37:16 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_context *ctx)
{
	size_t	disorder_fmt;

	ft_putstr_fd(ctx, "[bench] disorder: ", 2);
	disorder_fmt = (size_t)(ctx->disorder * 10000 + 0.5);
	ft_putsize_fd(ctx, disorder_fmt / 100, 2);
	ft_putstr_fd(ctx, ".", 2);
	if (disorder_fmt % 100 < 10)
		ft_putstr_fd(ctx, "0", 2);
	ft_putsize_fd(ctx, disorder_fmt % 100, 2);
	ft_putstr_fd(ctx, "%\n", 2);
}

static void	print_strategy(t_context *ctx)
{
	t_strategy	strategy;

	ft_putstr_fd(ctx, "[bench] strategy: ", 2);
	strategy = ctx->strategy;
	if (strategy == SIMPLE)
		ft_putstr_fd(ctx, "Simple / ", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd(ctx, "Medium / ", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd(ctx, "Complex / ", 2);
	else
	{
		ft_putstr_fd(ctx, "Adaptive / ", 2);
		strategy = adaptive_select(ctx);
	}
	if (strategy == SIMPLE)
		ft_putstr_fd(ctx, "O(n^2)\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd(ctx, "O(n√n)\n", 2);
	else
		ft_putstr_fd(ctx, "O(n log n)\n", 2);
}

static void	print_total_ops(t_context *ctx)
{
	ft_putstr_fd(ctx, "[bench] total_ops: ", 2);
	ft_putsize_fd(ctx, ctx->ops_len, 2);
	ft_putstr_fd(ctx, "\n", 2);
}

static void	print_ops(t_context *ctx)
{
	size_t	i;

	ft_putstr_fd(ctx, "[bench] ", 2);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_putstr_fd(ctx, op_name((t_op)i), 2);
		ft_putstr_fd(ctx, ": ", 2);
		ft_putsize_fd(ctx, ctx->counts[i], 2);
		if (i == PB)
			ft_putstr_fd(ctx, "\n[bench] ", 2);
		else if (i == OP_COUNT - 1)
			ft_putstr_fd(ctx, "\n", 2);
		else
			ft_putstr_fd(ctx, " ", 2);
		++i;
	}
}

void	print_bench(t_context *ctx)
{
	print_disorder(ctx);
	print_strategy(ctx);
	print_total_ops(ctx);
	print_ops(ctx);
}

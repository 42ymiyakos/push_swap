/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:00:44 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 18:53:34 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_context *ctx, double disorder, int fd)
{
	size_t	disorder_fmt;

	ft_putstr_fd(ctx, "[bench] disorder: ", fd);
	disorder_fmt = (size_t)(disorder * 10000);
	ft_putsize_fd(ctx, disorder_fmt / 100, fd);
	ft_putstr_fd(ctx, ".", fd);
	if (disorder_fmt % 100 < 10)
		ft_putstr_fd(ctx, "0", fd);
	ft_putsize_fd(ctx, disorder_fmt % 100, fd);
	ft_putstr_fd(ctx, "%\n", fd);
}

static void	print_strategy(t_context *ctx, t_strategy strategy, int fd)
{
	ft_putstr_fd(ctx, "[bench] strategy: ", fd);
	if (strategy == SIMPLE)
		ft_putstr_fd(ctx, "Simple / O(n^2)\n", fd);
	else if (strategy == MEDIUM)
		ft_putstr_fd(ctx, "Medium / O(n√n)\n", fd);
	else if (strategy == COMPLEX)
		ft_putstr_fd(ctx, "Complex / O(n log n)\n", fd);
	else
	{
		ft_putstr_fd(ctx, "Adaptive / ", fd);
		if (ctx->disorder < DISORDER_LOW || ctx->a.size <= 5)
			ft_putstr_fd(ctx, "O(n^2)\n", fd);
		else if (ctx->disorder < DISORDER_HIGH)
			ft_putstr_fd(ctx, "O(n√n)\n", fd);
		else
			ft_putstr_fd(ctx, "O(n log n)\n", fd);
	}
}

static void	print_total_ops(t_context *ctx, size_t ops_len, int fd)
{
	ft_putstr_fd(ctx, "[bench] total_ops: ", fd);
	ft_putsize_fd(ctx, ops_len, fd);
	ft_putstr_fd(ctx, "\n", fd);
}

static void	print_ops(t_context *ctx, const size_t *counts, int fd)
{
	size_t				i;
	static const char	*name[OP_COUNT] = {
		"sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	ft_putstr_fd(ctx, "[bench] ", fd);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_putstr_fd(ctx, name[i], fd);
		ft_putstr_fd(ctx, ": ", fd);
		ft_putsize_fd(ctx, counts[i], fd);
		if (i == PB)
			ft_putstr_fd(ctx, "\n[bench] ", fd);
		else if (i == OP_COUNT - 1)
			ft_putstr_fd(ctx, "\n", fd);
		else
			ft_putstr_fd(ctx, " ", fd);
		++i;
	}
}

void	print_bench(t_context *ctx)
{
	print_disorder(ctx, ctx->disorder, 2);
	print_strategy(ctx, ctx->strategy, 2);
	print_total_ops(ctx, ctx->ops_len, 2);
	print_ops(ctx, ctx->counts, 2);
}

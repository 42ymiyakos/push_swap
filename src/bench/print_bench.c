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

static void	print_disorder(double disorder, int fd)
{
	size_t	disorder_fmt;

	ft_putstr_fd("[bench] disorder: ", fd);
	disorder_fmt = (size_t)(disorder * 10000);
	ft_putsize_fd(disorder_fmt / 100, fd);
	ft_putstr_fd(".", fd);
	if (disorder_fmt % 100 < 10)
		ft_putstr_fd("0", fd);
	ft_putsize_fd(disorder_fmt % 100, fd);
	ft_putstr_fd("%\n", fd);
}

static void	print_strategy(const t_context *ctx, t_strategy strategy, int fd)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", fd);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", fd);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", fd);
	else
	{
		ft_putstr_fd("Adaptive / ", fd);
		if (ctx->disorder < DISORDER_LOW || ctx->a.size <= 5)
			ft_putstr_fd("O(n^2)\n", fd);
		else if (ctx->disorder < DISORDER_HIGH)
			ft_putstr_fd("O(n√n)\n", fd);
		else
			ft_putstr_fd("O(n log n)\n", fd);
	}
}

static void	print_total_ops(size_t ops_len, int fd)
{
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putsize_fd(ops_len, fd);
	ft_putstr_fd("\n", fd);
}

static void	print_ops(const size_t *counts, int fd)
{
	size_t				i;
	static const char	*name[OP_COUNT] = {
		"sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	ft_putstr_fd("[bench] ", fd);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_putstr_fd(name[i], fd);
		ft_putstr_fd(": ", fd);
		ft_putsize_fd(counts[i], fd);
		if (i == PB)
			ft_putstr_fd("\n[bench] ", fd);
		else if (i == OP_COUNT - 1)
			ft_putstr_fd("\n", fd);
		else
			ft_putstr_fd(" ", fd);
		++i;
	}
}

void	print_bench(const t_context *ctx)
{
	print_disorder(ctx->disorder, 2);
	print_strategy(ctx, ctx->strategy, 2);
	print_total_ops(ctx->ops_len, 2);
	print_ops(ctx->counts, 2);
}

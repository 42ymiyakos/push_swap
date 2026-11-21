/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:07:28 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/12 17:53:19 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_count_only(t_context *ctx)
{
	ft_putsize_fd(ctx, ctx->ops_len, 1);
	ft_putstr_fd(ctx, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc < 2)
		return (0);
	ctx_init(&ctx);
	parse_args(&ctx, argc, argv);
	if (ctx.a.size == 0)
	{
		ctx_clear(&ctx);
		return (0);
	}
	sort_dispatch(&ctx);
	if (!ctx.count_only)
		op_buffer_flush(&ctx);
	if (ctx.bench)
		print_bench(&ctx);
	if (ctx.count_only)
		print_count_only(&ctx);
	ctx_clear(&ctx);
	return (0);
}

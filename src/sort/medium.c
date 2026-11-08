/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:06:34 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/08 16:47:29 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	chunk_size(size_t n)
{
	size_t	k;

	k = 0;
	while (k * k <= n)
		++k;
	return (k);
}

static void	chunks_push(t_context *ctx, size_t k)
{
	size_t	i;
	size_t	top;

	i = 0;
	while (ctx->a.size)
	{
		top = (size_t)ctx->a.head->value;
		if (top <= i)
		{
			op_execute(ctx, PB);
			op_execute(ctx, RB);
			++i;
		}
		else if (top <= i + k)
		{
			op_execute(ctx, PB);
			++i;
		}
		else
			op_execute(ctx, RA);
	}
}

static void	chunks_push_back(t_context *ctx)
{
	size_t	max_pos;

	while (ctx->b.size)
	{
		max_pos = stack_max_pos(&ctx->b);
		stack_move_to_top(ctx, max_pos, RB, RRB);
		op_execute(ctx, PA);
	}
}

void	sort_medium(t_context *ctx)
{
	if (stack_is_sorted(&ctx->a))
		return ;
	chunks_push(ctx, chunk_size(ctx->a.size));
	chunks_push_back(ctx);
}

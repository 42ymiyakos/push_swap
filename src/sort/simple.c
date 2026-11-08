/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:05:55 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/07 11:45:41 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_context *ctx)
{
	size_t	pos;

	pos = stack_min_pos(&ctx->a);
	if (pos <= ctx->a.size / 2)
	{
		while (pos > 0)
		{
			execute_op(ctx, RA);
			--pos;
		}
	}
	else
	{
		while (pos < ctx->a.size)
		{
			execute_op(ctx, RRA);
			++pos;
		}
	}
}

static void	sort_three(t_context *ctx)
{
	size_t	max_pos;

	max_pos = stack_max_pos(&ctx->a);
	if (max_pos == 0)
		execute_op(ctx, RA);
	else if (max_pos == 1)
		execute_op(ctx, RRA);
	if (ctx->a.head->value > ctx->a.head->next->value)
		execute_op(ctx, SA);
}

void	sort_simple(t_context *ctx)
{
	if (stack_is_sorted(&ctx->a))
		return ;
	if (ctx->a.size == 2)
	{
		execute_op(ctx, SA);
		return ;
	}
	while (ctx->a.size > 3)
	{
		move_min_to_top(ctx);
		execute_op(ctx, PB);
	}
	sort_three(ctx);
	while (ctx->b.size)
		execute_op(ctx, PA);
}

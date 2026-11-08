/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:05:55 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 02:21:33 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_context *ctx)
{
	size_t	max_pos;

	max_pos = stack_max_pos(&ctx->a);
	if (max_pos == 0)
		op_execute(ctx, RA);
	else if (max_pos == 1)
		op_execute(ctx, RRA);
	if (ctx->a.head->value > ctx->a.head->next->value)
		op_execute(ctx, SA);
}

void	sort_simple(t_context *ctx)
{
	if (stack_is_sorted(&ctx->a))
		return ;
	if (ctx->a.size == 2)
	{
		op_execute(ctx, SA);
		return ;
	}
	while (ctx->a.size > 3)
	{
		stack_move_to_top(ctx, &ctx->a, stack_min_pos(&ctx->a));
		op_execute(ctx, PB);
	}
	sort_three(ctx);
	while (ctx->b.size)
		op_execute(ctx, PA);
}

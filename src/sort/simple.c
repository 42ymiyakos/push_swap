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

static int	get_max(const t_stack *a)
{
	const t_node	*cur;
	int				max;

	cur = a->head->next;
	max = a->head->value;
	while (cur)
	{
		if (cur->value > max)
			max = cur->value;
		cur = cur->next;
	}
	return (max);
}

static size_t	find_min_pos(const t_stack *a)
{
	const t_node	*cur;
	size_t			i;
	size_t			min_pos;
	int				min;

	cur = a->head->next;
	min = a->head->value;
	i = 1;
	min_pos = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_pos = i;
		}
		cur = cur->next;
		++i;
	}
	return (min_pos);
}

static void	move_min_to_top(t_context *ctx)
{
	size_t	pos;

	pos = find_min_pos(&ctx->a);
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
	int	max;

	max = get_max(&ctx->a);
	if (ctx->a.head->value == max)
		execute_op(ctx, RA);
	else if (ctx->a.head->next->value == max)
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

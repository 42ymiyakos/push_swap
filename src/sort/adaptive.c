/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:32:03 by arendo            #+#    #+#             */
/*   Updated: 2026/11/08 20:44:24 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the position of the minimum if the stack is a rotated sorted
** sequence, otherwise stack->size. Assumes the stack is not sorted.
*/
static size_t	rotation_start_find(const t_stack *stack)
{
	const t_node	*cur;
	size_t			i;
	size_t			start;
	size_t			drops;

	cur = stack->head;
	i = 0;
	start = 0;
	drops = 0;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
		{
			drops++;
			start = i + 1;
		}
		cur = cur->next;
		i++;
	}
	if (drops != 1 || stack->head->value <= stack->tail->value)
		return (stack->size);
	return (start);
}

t_strategy	adaptive_select(const t_context *ctx)
{
	if (ctx->disorder < DISORDER_LOW || ctx->a.size <= 5)
		return (SIMPLE);
	if (ctx->disorder < DISORDER_HIGH)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_adaptive(t_context *ctx)
{
	size_t		start;
	t_strategy	strategy;

	if (!ctx)
		return ;
	start = rotation_start_find(&ctx->a);
	if (start < ctx->a.size)
	{
		stack_move_to_top(ctx, &ctx->a, start);
		return ;
	}
	strategy = adaptive_select(ctx);
	if (strategy == SIMPLE)
		sort_simple(ctx);
	else if (strategy == MEDIUM)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}

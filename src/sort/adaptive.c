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

static size_t	rotation_index_find(t_stack *stack, size_t *drops)
{
	t_node	*cur;
	size_t	i;
	size_t	start;

	cur = stack->head;
	i = 0;
	start = 0;
	*drops = 0;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
		{
			(*drops)++;
			start = i + 1;
		}
		cur = cur->next;
		i++;
	}
	return (start);
}

static t_rotation	rotation_analyze(t_stack *stack)
{
	t_rotation	result;
	size_t		start;
	size_t		drops;

	result.op = RA;
	result.count = 0;
	result.possible = 0;
	if (!stack || stack->size < 2)
		return (result);
	start = rotation_index_find(stack, &drops);
	if (drops != 1 || stack->head->value <= stack->tail->value)
		return (result);
	result.possible = 1;
	result.count = start;
	if (start > stack->size - start)
	{
		result.op = RRA;
		result.count = stack->size - start;
	}
	return (result);
}

static void	rotation_apply(t_context *ctx, t_rotation rotation)
{
	size_t	i;

	i = 0;
	while (i < rotation.count)
	{
		op_execute(ctx, rotation.op);
		i++;
	}
}

void	sort_adaptive(t_context *ctx)
{
	t_rotation	rotation;

	if (!ctx || stack_is_sorted(&ctx->a))
		return ;
	rotation = rotation_analyze(&ctx->a);
	if (rotation.possible)
	{
		rotation_apply(ctx, rotation);
		return ;
	}
	if (ctx->disorder < DISORDER_LOW || ctx->a.size <= 5)
		sort_simple(ctx);
	else if (ctx->disorder < DISORDER_HIGH)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}

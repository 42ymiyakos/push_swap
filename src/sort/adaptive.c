/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:32:03 by arendo            #+#    #+#             */
/*   Updated: 2026/11/07 18:32:03 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_rotation_index(t_stack *stack, size_t *drops)
{
	t_node	*node;
	size_t	i;
	size_t	result;

	node = stack->head;
	i = 0;
	result = 0;
	*drops = 0;
	while (node->next)
	{
		if (node->value > node->next->value)
		{
			(*drops)++;
			result = i + 1;
		}
		node = node->next;
		i++;
	}
	return (result);
}

static t_rotation	analyze_rotation(t_stack *stack)
{
	t_rotation	result;
	size_t		i;
	size_t		drops;

	result.op = RA;
	result.count = 0;
	result.possible = 0;
	if (!stack || stack->size < 2)
		return (result);
	i = find_rotation_index(stack, &drops);
	if (drops != 1 || stack->head->value <= stack->tail->value)
		return (result);
	result.possible = 1;
	result.count = i;
	if (i > stack->size - i)
	{
		result.op = RRA;
		result.count = stack->size - i;
	}
	return (result);
}

static void	apply_rotation(t_context *ctx, t_rotation rotation)
{
	size_t	i;

	i = 0;
	while (i < rotation.count)
	{
		execute_op(ctx, rotation.op);
		i++;
	}
}

void	adaptive_sort(t_context *ctx)
{
	t_rotation	rotation;

	if (!ctx || stack_is_sorted(&ctx->a))
		return ;
	rotation = analyze_rotation(&ctx->a);
	if (rotation.possible)
	{
		apply_rotation(ctx, rotation);
		return ;
	}
	if (ctx->disorder < DISORDER_LOW)
		simple_sort(ctx);
	else if (ctx->disorder < DISORDER_HIGH)
		medium_sort(ctx);
	else
		complex_sort(ctx);
}

void	sort_dispatch(t_context *ctx)
{
	if (!ctx)
		return ;
	ctx->disorder = disorder_compute(&ctx->a);
	normalize(&ctx->a);
	if (ctx->strategy == SIMPLE)
		simple_sort(ctx);
	else if (ctx->strategy == MEDIUM)
		medium_sort(ctx);
	else if (ctx->strategy == COMPLEX)
		complex_sort(ctx);
	else if (ctx->strategy == ADAPTIVE)
		adaptive_sort(ctx);
}

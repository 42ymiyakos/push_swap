/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_query.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:55:48 by arendo            #+#    #+#             */
/*   Updated: 2026/11/09 02:38:38 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(const t_stack *stack)
{
	const t_node	*cur;

	if (!stack)
		return (0);
	if (!stack->size)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

size_t	stack_min_pos(const t_stack *stack)
{
	const t_node	*cur;
	size_t			i;
	size_t			pos;
	int				min;

	if (!stack || !stack->size)
		return (0);
	cur = stack->head->next;
	min = stack->head->value;
	i = 1;
	pos = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			pos = i;
		}
		cur = cur->next;
		++i;
	}
	return (pos);
}

size_t	stack_max_pos(const t_stack *stack)
{
	const t_node	*cur;
	size_t			i;
	size_t			pos;
	int				max;

	if (!stack || !stack->size)
		return (0);
	cur = stack->head->next;
	max = stack->head->value;
	i = 1;
	pos = 0;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			pos = i;
		}
		cur = cur->next;
		++i;
	}
	return (pos);
}

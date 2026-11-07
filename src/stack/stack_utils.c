/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:55:48 by arendo            #+#    #+#             */
/*   Updated: 2026/11/07 12:29:17 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return (0);
	if (!stack->size)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

size_t	stack_min_pos(const t_stack *stack)
{
	const t_node	*cur;
	size_t			i;
	size_t			pos;
	int				min;

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

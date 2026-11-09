/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:40:00 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/07 13:42:24 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder_compute(const t_stack *stack)
{
	const t_node	*cur;
	const t_node	*other;
	size_t			total_pairs;
	size_t			inversions;

	cur = stack->head;
	total_pairs = 0;
	inversions = 0;
	while (cur)
	{
		other = cur->next;
		while (other)
		{
			if (cur->value > other->value)
				++inversions;
			++total_pairs;
			other = other->next;
		}
		cur = cur->next;
	}
	if (total_pairs == 0)
		return ((double)0);
	return ((double)inversions / (double)total_pairs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:16:42 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/03 18:41:07 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_has_duplicate(const t_stack *a)
{
	const t_node	*cur;
	const t_node	*other;

	cur = a->head;
	while (cur)
	{
		other = cur->next;
		while (other)
		{
			if (cur->value == other->value)
				return (1);
			other = other->next;
		}
		cur = cur->next;
	}
	return (0);
}

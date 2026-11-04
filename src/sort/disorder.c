/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:40:00 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/04 19:43:45 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 初期状態の乱雑度 (逆順ペア数 / 全ペア数) を計算
double	disorder_compute(const t_stack *a)
{
	const t_node	*cur;
	const t_node	*other;
	size_t			total_pairs;
	size_t			mistake;

	cur = a->head;
	total_pairs = 0;
	mistake = 0;
	while (cur)
	{
		other = cur->next;
		while (other)
		{
			if (cur->value > other->value)
				++mistake;
			++total_pairs;
			other = other->next;
		}
		cur = cur->next;
	}
	if (total_pairs == 0)
		return ((double)0);
	return ((double)mistake / (double)total_pairs);
}

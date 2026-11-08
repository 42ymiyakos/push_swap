/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 02:39:25 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 02:39:25 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_move_to_top(t_context *ctx, t_stack *stack, size_t pos)
{
	t_op	rot;
	t_op	rev;
	t_op	op;
	size_t	count;

	rot = RA;
	rev = RRA;
	if (stack == &ctx->b)
	{
		rot = RB;
		rev = RRB;
	}
	op = rot;
	count = pos;
	if (pos > stack->size / 2)
	{
		count = stack->size - pos;
		op = rev;
	}
	while (count)
	{
		op_execute(ctx, op);
		--count;
	}
}

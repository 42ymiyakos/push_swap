/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:18 by arendo            #+#    #+#             */
/*   Updated: 2026/11/09 02:12:16 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_by_bit(t_context *ctx, size_t bit_index)
{
	size_t	remaining;

	remaining = ctx->a.size;
	while (remaining)
	{
		if ((ctx->a.head->value >> bit_index) & 1)
			op_execute(ctx, RA);
		else
			op_execute(ctx, PB);
		remaining--;
	}
	while (ctx->b.size)
		op_execute(ctx, PA);
}

void	sort_complex(t_context *ctx)
{
	size_t	bit_index;

	bit_index = 0;
	while ((ctx->a.size - 1) >> bit_index)
	{
		sort_by_bit(ctx, bit_index);
		bit_index++;
	}
}

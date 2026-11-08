/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:18 by arendo            #+#    #+#             */
/*   Updated: 2026/11/07 14:16:18 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_value)
{
	int	bits;

	bits = 0;
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

static void	sort_by_bit(t_context *ctx, size_t bit_index, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((ctx->a.head->value >> bit_index) & 1)
			op_execute(ctx, RA);
		else
			op_execute(ctx, PB);
		i++;
	}
	while (ctx->b.size)
		op_execute(ctx, PA);
}

void	sort_complex(t_context *ctx)
{
	size_t	bit_index;
	size_t	size;
	size_t	max_bits;

	if (ctx->a.size < 2)
		return ;
	bit_index = 0;
	max_bits = get_max_bits(ctx->a.size - 1);
	size = ctx->a.size;
	while (bit_index < max_bits)
	{
		sort_by_bit(ctx, bit_index, size);
		bit_index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_buffer_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:46:57 by arendo            #+#    #+#             */
/*   Updated: 2026/11/06 16:07:46 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*op_name(t_op op)
{
	static const char	*names[OP_COUNT] = {
		"sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	return (names[op]);
}

void	op_buffer_flush(t_context *ctx)
{
	size_t	i;

	if (!ctx)
		return ;
	i = 0;
	while (i < ctx->ops_len)
	{
		ft_putstr_fd(ctx, op_name(ctx->ops[i]), 1);
		ft_putstr_fd(ctx, "\n", 1);
		i++;
	}
}

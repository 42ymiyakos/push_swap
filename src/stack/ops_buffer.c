/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:46:46 by arendo            #+#    #+#             */
/*   Updated: 2026/11/04 22:00:15 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	expand_ops_capacity(t_context *ctx)
{
	t_op	*new_ops;
	size_t	new_cap;
	size_t	i;

	if (!ctx->ops_cap)
		new_cap = OPS_INIT_CAP;
	else
		new_cap = ctx->ops_cap * 2;
	new_ops = malloc(sizeof(t_op) * (new_cap));
	if (!new_ops)
		return (0);
	ctx->ops_cap = new_cap;
	i = 0;
	while (i < ctx->ops_len)
	{
		new_ops[i] = ctx->ops[i];
		i++;
	}
	free(ctx->ops);
	ctx->ops = new_ops;
	return (1);
}

int	op_buffer_add(t_context *ctx, t_op op)
{
	if (!ctx)
		return (0);
	if (ctx->ops_len == ctx->ops_cap && !expand_ops_capacity(ctx))
		return (0);
	ctx->ops[ctx->ops_len] = op;
	ctx->ops_len++;
	return (1);
}

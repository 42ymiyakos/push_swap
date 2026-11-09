/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:23:45 by arendo            #+#    #+#             */
/*   Updated: 2026/11/04 16:41:06 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ctx_init(t_context *ctx)
{
	size_t	i;

	if (!ctx)
		return ;
	stack_init(&ctx->a);
	stack_init(&ctx->b);
	ctx->strategy = ADAPTIVE;
	ctx->disorder = 0;
	ctx->bench = 0;
	ctx->ops = NULL;
	ctx->ops_len = 0;
	ctx->ops_cap = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		ctx->counts[i] = 0;
		i++;
	}
}

void	ctx_clear(t_context *ctx)
{
	stack_clear(&ctx->a);
	stack_clear(&ctx->b);
	free(ctx->ops);
	ctx->ops = NULL;
}

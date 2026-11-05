/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:11:13 by arendo            #+#    #+#             */
/*   Updated: 2026/11/05 15:27:39 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_context(t_context *ctx)
{
	if (!ctx)
		return ;
	stack_clear(&ctx->a);
	stack_clear(&ctx->b);
	free(ctx->ops);
}

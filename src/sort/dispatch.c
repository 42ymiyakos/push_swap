/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:32:03 by arendo            #+#    #+#             */
/*   Updated: 2026/11/08 20:44:24 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_context *ctx)
{
	if (!ctx)
		return ;
	ctx->disorder = disorder_compute(&ctx->a);
	stack_normalize(ctx);
	if (ctx->strategy == SIMPLE)
		sort_simple(ctx);
	else if (ctx->strategy == MEDIUM)
		sort_medium(ctx);
	else if (ctx->strategy == COMPLEX)
		sort_complex(ctx);
	else if (ctx->strategy == ADAPTIVE)
		sort_adaptive(ctx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 02:42:05 by arendo            #+#    #+#             */
/*   Updated: 2026/11/07 12:36:07 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_op(t_context *ctx, t_op op)
{
	if (!apply_op(op, &ctx->a, &ctx->b))
		error_exit(ctx);
	if (!op_buffer_add(ctx, op))
		error_exit(ctx);
}

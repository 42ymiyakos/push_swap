/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:31:28 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/03 18:42:05 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	context_clear(t_context *ctx)
{
	stack_clear(&ctx->a);
	stack_clear(&ctx->b);
	free(ctx->ops);
	ctx->ops = NULL;
}

void	error_exit(t_context *ctx)
{
	context_clear(ctx);
	write(2, "Error\n", 6);
	exit(1);
}

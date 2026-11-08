/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:51:49 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/07 19:25:42 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ranks_compute(t_context *ctx, int *ranks)
{
	t_node	*cur;
	t_node	*other;
	int		rank;
	size_t	i;

	cur = ctx->a.head;
	i = 0;
	while (cur)
	{
		rank = 0;
		other = ctx->a.head;
		while (other)
		{
			if (cur->value > other->value)
				++rank;
			other = other->next;
		}
		ranks[i] = rank;
		++i;
		cur = cur->next;
	}
}

static void	ranks_apply(t_context *ctx, int *ranks)
{
	t_node	*cur;
	size_t	i;

	cur = ctx->a.head;
	i = 0;
	while (cur)
	{
		cur->value = ranks[i];
		cur = cur->next;
		++i;
	}
}

void	stack_normalize(t_context *ctx)
{
	int		*ranks;

	if (ctx->a.size == 0)
		return ;
	ranks = malloc(ctx->a.size * sizeof(*ranks));
	if (!ranks)
		error_exit(ctx);
	ranks_compute(ctx, ranks);
	ranks_apply(ctx, ranks);
	free(ranks);
}

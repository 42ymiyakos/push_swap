/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:36:22 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/12 18:00:13 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_count_only(t_context *ctx)
{
	ft_putsize_fd(ctx, ctx->ops_len, 1);
	ft_putstr_fd(ctx, "\n", 1);
}

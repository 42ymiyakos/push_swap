/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:07:28 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/12 17:53:19 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc < 2)
		return (0);
	ctx_init(&ctx);
	parse_args(&ctx, argc, argv);
	sort_dispatch(&ctx);
	if (!ctx.count_only)
		op_buffer_flush(&ctx);
	if (ctx.bench)
		print_bench(&ctx);
	if (ctx.count_only)
		print_count_only(&ctx);
	ctx_clear(&ctx);
	return (0);
}

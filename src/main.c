/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:07:28 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/08 19:59:42 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc < 2)
		return (0);
	ctx_init(&ctx);
	parse_args(argc, argv, &ctx);
	sort_dispatch(&ctx);
	op_buffer_flush(&ctx);
	ctx_clear(&ctx);
	return (0);
}

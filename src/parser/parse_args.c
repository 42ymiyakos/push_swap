/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:20:35 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/05 14:32:17 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_apply(t_context *ctx, const char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		ctx->strategy = SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		ctx->strategy = MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		ctx->strategy = COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		ctx->strategy = ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		ctx->bench = 1;
	else
		return (0);
	return (1);
}

static void	split_error(t_context *ctx, char **nums)
{
	split_free(nums);
	error_exit(ctx);
}

static void	numbers_add(t_context *ctx, const char *arg)
{
	char	**nums;
	t_node	*node;
	size_t	i;
	int		value;

	nums = ft_split(arg, ' ');
	if (!nums || !nums[0])
		split_error(ctx, nums);
	i = 0;
	while (nums[i])
	{
		node = NULL;
		if (parse_number(nums[i], &value))
			node = node_new(value);
		if (!node)
			split_error(ctx, nums);
		stack_append(&ctx->a, node);
		++i;
	}
	split_free(nums);
}

void	parse_args(t_context *ctx, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!flag_apply(ctx, argv[i]))
			numbers_add(ctx, argv[i]);
		++i;
	}
	if (stack_has_duplicate(&ctx->a))
		error_exit(ctx);
}

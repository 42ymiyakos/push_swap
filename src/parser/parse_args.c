/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:20:35 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/03 18:42:29 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	apply_flag(const char *arg, t_context *ctx)
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

static void	split_error(char **nums, t_context *ctx)
{
	free_split(nums);
	error_exit(ctx);
}

static void	add_numbers(const char *arg, t_context *ctx)
{
	char	**nums;
	t_node	*node;
	size_t	i;
	int		value;

	nums = ft_split(arg, ' ');
	if (!nums || !nums[0])
		split_error(nums, ctx);
	i = 0;
	while (nums[i])
	{
		node = NULL;
		if (parse_number(nums[i], &value))
			node = node_new(value);
		if (!node)
			split_error(nums, ctx);
		stack_add_back(&ctx->a, node);
		++i;
	}
	free_split(nums);
}

void	parse_args(int argc, char **argv, t_context *ctx)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!apply_flag(argv[i], ctx))
			add_numbers(argv[i], ctx);
		++i;
	}
	if (has_duplicate(&ctx->a))
		error_exit(ctx);
}

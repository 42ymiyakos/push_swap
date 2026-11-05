/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 01:54:29 by arendo            #+#    #+#             */
/*   Updated: 2026/11/05 01:54:29 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == SA || op == SS)
		swap_stack(a);
	if (op == SB || op == SS)
		swap_stack(b);
}

static void	push_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == PA)
		push_stack(a, b);
	else
		push_stack(b, a);
}

static void	rotate_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == RA || op == RR)
		rotate_stack(a);
	if (op == RB || op == RR)
		rotate_stack(b);
}

static void	rev_rotate_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == RRA || op == RRR)
		rev_rotate_stack(a);
	if (op == RRB || op == RRR)
		rev_rotate_stack(b);
}

int	apply_op(t_op op, t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (op < SA || OP_COUNT <= op)
		return (0);
	if (op <= SS)
		swap_apply(op, a, b);
	else if (op <= PB)
		push_apply(op, a, b);
	else if (op <= RR)
		rotate_apply(op, a, b);
	else
		rev_rotate_apply(op, a, b);
	return (1);
}

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
		stack_swap(a);
	if (op == SB || op == SS)
		stack_swap(b);
}

static void	push_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == PA)
		stack_push(a, b);
	else
		stack_push(b, a);
}

static void	rotate_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == RA || op == RR)
		stack_rotate(a);
	if (op == RB || op == RR)
		stack_rotate(b);
}

static void	rev_rotate_apply(t_op op, t_stack *a, t_stack *b)
{
	if (op == RRA || op == RRR)
		stack_rev_rotate(a);
	if (op == RRB || op == RRR)
		stack_rev_rotate(b);
}

int	op_apply(t_op op, t_stack *a, t_stack *b)
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

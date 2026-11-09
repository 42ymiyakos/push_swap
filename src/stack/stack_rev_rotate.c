/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:04:45 by arendo            #+#    #+#             */
/*   Updated: 2026/11/04 15:48:08 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rev_rotate(t_stack *stack)
{
	t_node	*move;

	if (!stack || stack->size < 2)
		return ;
	move = stack->tail;
	move->prev->next = NULL;
	stack->tail = move->prev;
	stack->head->prev = move;
	move->next = stack->head;
	move->prev = NULL;
	stack->head = move;
}

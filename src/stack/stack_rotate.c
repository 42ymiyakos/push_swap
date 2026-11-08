/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:57:23 by arendo            #+#    #+#             */
/*   Updated: 2026/11/04 15:48:14 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(t_stack *stack)
{
	t_node	*move;

	if (!stack || stack->size < 2)
		return ;
	move = stack->head;
	stack->head = move->next;
	stack->head->prev = NULL;
	stack->tail->next = move;
	move->prev = stack->tail;
	stack->tail = move;
	move->next = NULL;
}

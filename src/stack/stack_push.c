/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendo <arendo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:46:36 by arendo            #+#    #+#             */
/*   Updated: 2026/11/03 18:48:23 by arendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *dst, t_stack *src)
{
	t_node	*move;

	if (!dst || !src || !src->size)
		return ;
	move = src->head;
	src->head = move->next;
	if (src->head)
		move->next->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	if (!dst->size)
	{
		dst->tail = move;
		move->next = NULL;
	}
	else
	{
		dst->head->prev = move;
		move->next = dst->head;
	}
	dst->head = move;
	dst->size++;
}

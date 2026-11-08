/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:00:45 by arendo            #+#    #+#             */
/*   Updated: 2026/11/09 02:41:48 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	stack_append(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->size)
		stack->head = node;
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
	}
	stack->size++;
	stack->tail = node;
}

void	stack_clear(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:04:23 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 20:41:40 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_size(*stack) <= 1)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = second;
	first->next = second->next;
	(*stack)->next = first;
}

void	push_stack(t_stack **from, t_stack **to)
{
	if (!(*from))
		return ;
	push((*from)->number, (*from)->index, to);
	pop(from);
}

void	rotate(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	put_last(*stack, stack);
	*stack = second;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	prev->next = NULL;
}

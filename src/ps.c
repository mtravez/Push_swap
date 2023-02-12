/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:04:23 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 18:07:50 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function swaps the first and second elements in a stack*/
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

/*This function pushes the first element from one stack to another*/
void	push_stack(t_stack **from, t_stack **to)
{
	if (!(*from))
		return ;
	push((*from)->number, (*from)->index, to);
	pop(from);
}

/*This function moves the second element to the head of the stack and
puts the first element as last. It won't do anything if the stack is
empty or only has one element*/
void	rotate(t_stack **stack)
{
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	second = (*stack)->next;
	put_last(*stack, stack);
	*stack = second;
}

/*This function will move the last element of a stack to head of the stack.
It won't do anything if the stack is empty or only has one element*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	current = *stack;
	if (!current || !current->next)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	prev->next = NULL;
}

/*This function checks that a stack is sorted correctly*/
int	is_sorted(t_stack *stack)
{
	t_stack	*current;
	int		index;

	current = stack;
	if (!current)
		return (0);
	index = current->index;
	while (current)
	{
		if (index != current->index)
			return (0);
		current = current->next;
		index++;
	}
	return (1);
}

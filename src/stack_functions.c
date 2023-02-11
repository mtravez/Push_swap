/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:35:57 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 20:45:17 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_cell(int number, int index)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack *) * 2);
	if (!stack)
		return (NULL);
	stack->number = number;
	stack->index = index;
	stack->next = NULL;
	return (stack);
}

void	push(int number, int index, t_stack **stack)
{
	t_stack	*head;

	head = new_cell(number, index);
	head->next = *stack;
	*stack = head;
}

void	pop(t_stack **stack)
{
	t_stack	*head;

	head = (*stack)->next;
	free(*stack);
	*stack = head;
}

int	stack_size(t_stack *stack)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	put_last(t_stack *to_last, t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
		current = current->next;
	current->next = to_last;
	to_last->next = NULL;
}

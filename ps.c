/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:04:23 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 17:30:43 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	while (temp)
	{
		ft_printf("[%i, %i] -> ", ((int)(temp->number)), temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
}

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
	t_stack *second;

	second = (*stack)->next;
	put_last(*stack, stack);
	*stack = second;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *current;
	t_stack *prev;

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

// int main()
// {
// 	t_stack *hi = newCell(0);
// 	hi->next = newCell(1);
// 	hi->next->next = newCell(2);
// 	t_stack *bye;
// 	bye = NULL;
	
// 	printlist(hi);
// 	reverse_rotate(&hi);
// 	printlist(hi);
// 	// printlist(bye);
// 	return (0);
// }

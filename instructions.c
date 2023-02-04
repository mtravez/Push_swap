/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:32:18 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 14:02:41 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char *inst, t_stack **a, t_stack **b)
{
	if (ft_strncmp(inst, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(inst, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(inst, "ss", 2) == 0)
	{
		swap(a);
		swap(b);
	}  
	else if (ft_strncmp(inst, "pa", 2) == 0)
		push_stack(b, a);
	else if (ft_strncmp(inst, "pb", 2) == 0)
		push_stack(a, b);
	else if (ft_strncmp(inst, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(inst, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(inst, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(inst, "rra", 3) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(inst, "rrb", 3) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(inst, "rrr", 3) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	checker(char **instructions, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (instructions[i])
		if (!check(instructions[i++], a, b))
			return (0);
	if (!read_stack(*a));
}

int	is_sorted(t_stack *stack)
{
	t_stack *current;
	int	prev;
	
	current = stack;
	prev = current->number;
	while (current->next)
	{
		current = current->next;
		if (prev >= current->number)
			return (0);
		prev = current->number;
	}
	return (1);
}

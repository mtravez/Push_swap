/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:11:21 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/11 18:59:07 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nr_rot(t_holder *holder, int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		if (stack_size(holder->a) / 2 != get_half(stack_size(holder->a)))
			nbr = stack_size(holder->a) / 2 * -1;
	if (nbr < 0)
	{
		nbr *= -1;
		while (i < nbr)
		{
			rra(holder);
			i++;
		}
	}
	else
	{
		nbr = get_half(stack_size(holder->a)) - nbr;
		while (i < nbr)
		{
			ra(holder);
			i++;
		}
	}
}

t_stack	**get_first_last(t_holder *holder)
{
	t_stack	*temp;
	t_stack	**fl;

	temp = holder->a;
	fl = malloc(sizeof(t_stack *) * 2);
	fl[0] = temp;
	fl[1] = temp;
	while (temp)
	{
		if (temp->index < fl[0]->index)
			fl[0] = temp;
		if (temp->index > fl[1]->index)
			fl[1] = temp;
		temp = temp->next;
	}
	return (fl);
}

void	three_sort(t_holder *holder)
{
	t_stack	**first_last;

	first_last = get_first_last(holder);
	if (first_last[0]->next && !first_last[1])
		return ;
	if (!first_last[1]->next || \
	first_last[1]->next->index != first_last[0]->index)
		sa(holder);
	free(first_last);
	first_last = get_first_last(holder);
	if (!first_last[0]->next)
		rra(holder);
	else if (first_last[1]->next)
		ra(holder);
	free(first_last);
}

int	get_smallest_distance(t_holder *holder)
{
	int		distance;
	int		small;
	t_stack	*temp;

	distance = 0;
	temp = holder->a;
	small = holder->size - stack_size(holder->a);
	while (temp)
	{
		if (temp->index == small)
			break ;
		distance++;
		temp = temp->next;
	}
	return (distance);
}

void	sort_short(t_holder *holder)
{
	int		i;

	i = 0;
	while (i < holder->size - 3)
	{
		nr_rot(holder, get_half(stack_size(holder->a)) \
		- get_smallest_distance(holder));
		pb(holder);
		i++;
	}
	three_sort(holder);
	while (holder->b)
		pa(holder);
}

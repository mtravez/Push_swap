/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:11:21 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 13:38:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function determines whether to rotate or reverse rotate
a stack to move an element to top of the list depending on which would
need the least amount of instructions.*/
void	nr_rot(t_holder *holder, int nbr)
{
	int	i;

	i = 0;
	if (stack_size(holder->a) - nbr <= stack_size(holder->a) / 2)
	{
		nbr = stack_size(holder->a) - nbr;
		while (i < nbr)
		{
			rra(holder);
			i++;
		}
	}
	else
	{
		while (i < nbr)
		{
			ra(holder);
			i++;
		}
	}
}

/*This function returns a stack array of size 2 containing the smallest
and the largest elements currently in stack A. The first element of the 
array would be the smallest and the second the largest*/
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

/*This is an algorithm to sort an array of size 3*/
void	three_sort(t_holder *holder)
{
	t_stack	**first_last;

	if (is_sorted(holder->a))
		return ;
	first_last = get_first_last(holder);
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

/*This function returns the distance of the smallest element
in stack a from the head of the list*/
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

/*This function sorts a shorter list than sor using a different
algorithm. It works by pushing elements from smallest to biggest
to stack B until there's only three remaining. Then, the three sort
algorithm is used and every element in B is pushed back to A.*/
void	sort_short(t_holder *holder)
{
	int		i;

	i = 0;
	while (i < holder->size - 3)
	{
		nr_rot(holder, get_smallest_distance(holder));
		pb(holder);
		i++;
	}
	three_sort(holder);
	while (holder->b)
		pa(holder);
}

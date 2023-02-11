/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:42:59 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/11 15:15:48 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_holder *holder)
{
	push_stack(&holder->b, &holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("pa\n")));
}

void	pb(t_holder *holder)
{
	push_stack(&holder->a, &holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("pb\n")));
}

void	ra(t_holder *holder)
{
	rotate(&holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("ra\n")));
}

void	rb(t_holder *holder)
{
	rotate(&holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("rb\n")));
}

t_holder	*init_holder(char **numbers)
{
	t_holder	*newh;
	int			bits;
	int			max;

	newh = malloc(sizeof(t_holder *) + sizeof(t_stack) \
	* 2 + sizeof(t_list *) * 2);
	newh->a = NULL;
	newh->b = NULL;
	if (!put_stack(numbers, newh))
	{
		free_holder(newh);
		return (NULL);
	}
	max = newh->size;
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	newh->n = bits - 1;
	newh->instructions = NULL;
	put_index(newh);
	return (newh);
}

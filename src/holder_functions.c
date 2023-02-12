/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:42:59 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/11 21:28:15 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function pushes the first element in stack B to stack A.
It also adds the string "pa\n" to the holder's instruction list*/
void	pa(t_holder *holder)
{
	push_stack(&holder->b, &holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("pa\n")));
}

/*This function pushes the first element in stack A to stack B.
It also adds the string "pb\n" to the holder's instruction list*/
void	pb(t_holder *holder)
{
	push_stack(&holder->a, &holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("pb\n")));
}

/*This function moves the first element in A to the last position
It also adds the string "ra\n" to the holder's instruction list*/
void	ra(t_holder *holder)
{
	rotate(&holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("ra\n")));
}

/*This function moves the first element in B to the last position
It also adds the string "rb\n" to the holder's instruction list*/
void	rb(t_holder *holder)
{
	rotate(&holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("rb\n")));
}

/*This function creates a new holder with all the numbers put
correctly in stack A and assigning every number its index.*/
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

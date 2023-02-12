/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:40:50 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 13:23:48 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function swaps the first and second elements in A.
It also adds the string "sa\n" to the holder's instruction list*/
void	sa(t_holder *holder)
{
	swap(&holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("sa\n")));
}

/*This function swaps the first and second elements in B.
It also adds the string "sb\n" to the holder's instruction list*/
void	sb(t_holder *holder)
{
	swap(&holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("sb\n")));
}

/*This function moves the last element in A to the head.
It also adds the string "rra\n" to the holder's instruction list*/
void	rra(t_holder *holder)
{
	reverse_rotate(&holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("rra\n")));
}

/*This function moves the last element in B to the head.
It also adds the string "rrb\n" to the holder's instruction list*/
void	rrb(t_holder *holder)
{
	reverse_rotate(&holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("rrb\n")));
}

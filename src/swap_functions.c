/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:40:50 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/11 18:40:51 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_holder *holder)
{
	swap(&holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("sa\n")));
}

void	sb(t_holder *holder)
{
	swap(&holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("sb\n")));
}

void	rra(t_holder *holder)
{
	reverse_rotate(&holder->a);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("rra\n")));
}

void	rrb(t_holder *holder)
{
	reverse_rotate(&holder->b);
	ft_lstadd_back(&holder->instructions, ft_lstnew(ft_strdup("rrb\n")));
}

int	get_half(int n)
{
	int	half;

	half = n / 2;
	if (n % 2 != 0)
		half++;
	return (half);
}
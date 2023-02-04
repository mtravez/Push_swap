/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:42:59 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 20:36:02 by mtravez          ###   ########.fr       */
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

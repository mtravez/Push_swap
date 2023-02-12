/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:32:18 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 13:22:17 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*This function checks if the instruction given is valid and executes
it accordingly if so.*/
int	check(char *inst, t_holder *holder)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		swap(&holder->a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		swap(&holder->b);
	else if (ft_strncmp(inst, "ss\n", 3) == 0)
		ss(holder);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		push_stack(&holder->b, &holder->a);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		push_stack(&holder->a, &holder->b);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		rotate(&holder->a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		rotate(&holder->b);
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
		rr(holder);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		reverse_rotate(&holder->a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		reverse_rotate(&holder->b);
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
		rrr(holder);
	else
		return (0);
	return (1);
}
